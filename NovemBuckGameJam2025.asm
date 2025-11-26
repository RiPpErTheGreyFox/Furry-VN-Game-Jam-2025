INCLUDE "include/hardware.inc"			; include all the hardware definitions
										; and other out of file definitions

INCLUDE "include/vnEngineConstants.inc"
INCLUDE "include/vnEngineStructs.inc"	; include all the main data needed for the engine
INCLUDE "include/vnEngineUtilitySubroutines.inc"
INCLUDE "include/vnEngineSoundSubroutines.inc"

; gameplay definitions
SECTION "Counter", WRAM0
wFrameCounter: db
wButtonDebounce: db
wYScrollCounter: db

SECTION "Input Variables", WRAM0		; set labels in Work RAM for easy variable use
wCurKeys: db							; label: declare byte, reserves a byte for use later
wNewKeys: db

SECTION "NumberStringData", WRAM0
wNumberStringData: db
	:db
	:db

SECTION "Gameplay Data", WRAM0
wBoxInPlay: db							; treat as a bool
wBoxBeingHeld: db						; bool
wBoxTileIndex: db						; starting tile index for the box graphics
wBoxesRemainingInLevel: db				; the amount of boxes we need to spawn
wBoxesRemainingFlammable: db			; the amount of flammable boxes left to spawn
wBoxesRemainingRadioactive: db			; the amount of radioactive boxes left to spawn
wVictoryFlagSet: db
	dstruct PLAYER, mainCharacter		; declare our structs
	dstruct BOX, currentActiveBox
	dstruct CURSOR, boxCursor	
wCurrentScene: db						; 0=MainMenu, 1=Cutscene, 2=HowToPlay, 3=Game

SECTION "Animation Data", WRAM0
wPlayerOAMOffset: db
wPlayerTileFirstIndex: db
wPlayerCurrentFrame: db

SECTION "Managed Variables", WRAM0
wTileBankZero: dw						; variables that hold the current count of tiles loaded by the manager
wTileBankOne: dw
wTileBankTwo: dw
wFontFirstTileOffset: db				; where in Bank one the font starts

; System definitions
SECTION "System Type", WRAM0
wCGB: db
wAGB: db
wSGB: db
	
SECTION "Random Seed", WRAM0
wSeed0: db
wSeed1: db
wSeed3: db

; Jump table for interrupts

SECTION "StatInterrupt", ROM0[$0048]
	jp ScanlineInterruptHandler

SECTION "Header", ROM0[$100]

	jp EntryPoint

	ds $150 - @, 0 ; Make room for the header


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;	MAIN PROGRAM
;;	BLOCK
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


EntryPoint:
	call SystemDetection		; first thing to do is check what kind of system game's running on
	call EnableSound
	call InitOAMDMARoutine
	ld a, 0 
	ld [wCurrentScene], a

ReloadGame:
	ld sp, $FFFE				; reset the stack pointer

	jp ProgramEntry			; Jump to the main menu

ProgramEntry:							; main game loop
	; Wait until it's *not* VBlank
	ld a, [rLY]			; loads into the A register, the current scanline (rLY)
	cp 144				; compares the value in the A register, against 144
	jp nc, ProgramEntry; jump if carry not set (if a > 144)
.WaitVBlank2:
	ld a, [rLY]			; loads into the A register, the current scanline (rLY)
	cp 144				; compares the value in the A register, against 144
	jp c, .WaitVBlank2	; jump if carry set (if a < 144)
	; above is waiting for a full complete frame

.WaitVBlank:
	ld a, [rLY]					; loads into the A register, the current scanline (rLY)
	cp 144						; compares the value in the A register, against 144
	jp c, .WaitVBlank			; jump if carry set (if a < 144)

	; Turn the LCD off
	ld a, 0
	ld [rLCDC], a
	ld [rSCY], a				; reset the scroll registers
	ld [rSCX], a
	
	call ClearOAM
	call ClearShadowOAM

	call InitTestMetaSprite

	; once the OAM is clear, we can draw an object by writing its properties
	call SetDefaultDMGPalette
	call LoadDefaultCGBPalette
	
	; check which scene is gunna be loaded and load that
	; 0=MainMenu, 1=Cutscene, 2=HowToPlay, 3=Game
	ld a, [wCurrentScene]
	cp a, 0
	jp z, .MainMenuLoading
	

.MainMenuLoading
	call InitialiseMainMenu
	jp .FinishedLoadingScene
.FinishedLoadingScene

	call InitialiseFont

	; Initialise variables
	ld a, 0
	ld [wButtonDebounce], a

	call EnableLCD

	ld c, 15
	call FadeFromWhite

ProgramMain:
	; Wait until it's *not* VBlank
	ld a, [rLY]			; loads into the A register, the current scanline (rLY)
	cp 144				; compares the value in the A register, against 144
	jp nc, ProgramMain			; jump if carry not set (if a > 144)
.WaitVBlank2:
	ld a, [rLY]			; loads into the A register, the current scanline (rLY)
	cp 144				; compares the value in the A register, against 144
	jp c, .WaitVBlank2	; jump if carry set (if a < 144)
	; above is waiting for a full complete frame

	; call the OAM DMA routine the second we hit the start of VBlank to get it out of the way and stay out of mode 3
	ld a, HIGH(wShadowOAM)
	call hOAMDMA

	call RenderMetaSprite

	; check which scene we're on and tick that
	; 0=MainMenu, 1=Cutscene, 2=HowToPlay, 3=Game
	ld a, [wCurrentScene]
	cp a, 0
	jp z, .MainMenuTick

.MainMenuTick
	call UpdateMainMenuScene
	jp .FinishedTickingScene
.FinishedTickingScene

jp ProgramMain

; Test subs, TODO: delete

; placeholder init sub for testing the base program works
InitialiseMainMenu:
	call TileLoaderReset
    call SetBlankDMGPalette

	; load up the test background
	ld de, TestBackgroundTilemap
	ld bc, TestBackgroundTilemapEnd - TestBackgroundTilemap
	push de
	push bc
	ld a, 2
	ld bc, TestBackgroundDataEnd - TestBackgroundData
	ld de, TestBackgroundData
	call LoadNewBackground

	; setup the actor with a default sprite
	ld de, TestActorData
	ld bc, TestActorDataEnd - TestActorData
	ld a, 2 ; set the bank variable
	call LoadToMetasprite

	; set how scrolled the screen is
	ld a, 0
	ld [wYScrollCounter], a
	ld [rSCY], a

	; initialise the sound driver and start the song
	ld hl, mainmenu_song
	call hUGE_init

	ret

; placeholder tick sub for testing the base program works
UpdateMainMenuScene:
	; tick the music driver for the frame
	call hUGE_dosound

	; check if the scroll counter is above zero, if it is, scroll up 1
	ld a, [wYScrollCounter]
	cp a, 1
	jp nc, .KeepScrollingScreen

    call UpdateKeys

    ld a, [wCurKeys]
	and a, PADF_START
	jp z, .CheckAPressed
	jp .ReloadBackground
.CheckAPressed:
	ld a, [wCurKeys]
	and a, PADF_A
	jp z, .CheckBPressed
	jp .ChangeActorToStanding
.CheckBPressed:
	ld a,[wCurKeys]
	and a, PADF_B
	jp z, .CheckUpPressed
	jp .ChangeActorToTalking
.CheckUpPressed:
    ld a, [wCurKeys]
	and a, PADF_UP
	jp z, .CheckDownPressed
	ld hl, globalMetaSprite_YPos
	dec [hl]
	jp .EndOfFunc
.CheckDownPressed:
    ld a, [wCurKeys]
	and a, PADF_DOWN
	jp z, .CheckLeftPressed
	ld hl, globalMetaSprite_YPos
	inc [hl]
	jp .EndOfFunc
.CheckLeftPressed:
    ld a, [wCurKeys]
	and a, PADF_LEFT
	jp z, .checkRightPressed
	ld hl, globalMetaSprite_XPos
	dec [hl]
	jp .EndOfFunc
.checkRightPressed:
    ld a, [wCurKeys]
	and a, PADF_RIGHT
	jp z, .EndOfFunc
	ld hl, globalMetaSprite_XPos
	inc [hl]
	jp .EndOfFunc

    jp .EndOfFunc

.ReloadBackground
	; load up the test background
	ld de, TestBackgroundTilemap2
	ld bc, TestBackgroundTilemap2End - TestBackgroundTilemap2
	push de
	push bc
	ld a, 2
	ld bc, TestBackground2DataEnd - TestBackground2Data
	ld de, TestBackground2Data
	call FadeToNewBackground
	ret

.ChangeActorToStanding
	; setup the actor with a default sprite
	ld de, TestActorData
	ld bc, TestActorDataEnd - TestActorData
	ld a, 2 ; set the bank variable
	call LoadToMetasprite

	ret
.ChangeActorToTalking
	; setup the actor with a default sprite
	ld de, TestActor2Data
	ld bc, TestActor2DataEnd - TestActor2Data
	ld a, 2 ; set the bank variable
	call LoadToMetasprite
	ret

.KeepScrollingScreen
	dec a
	ld [rSCY], a
	ld [wYScrollCounter], a

.EndOfFunc
	ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;	DATA
;;	BLOCK
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SECTION "SceneData", ROMX

SECTION "Graphics Data", ROMX, BANK[2]

TestSpriteData: INCBIN "gfx/spritesheettest.2bpp"
TestSpriteDataEnd:

AlphabetTiles: INCBIN "gfx/backgrounds/text-font.2bpp"
AlphabetTilesEnd:

TestBackgroundData: INCBIN "gfx/backgrounds/TestBackground.2bpp"
TestBackgroundDataEnd: 

TestBackgroundTilemap: INCBIN "gfx/backgrounds/TestBackground.tilemap"
TestBackgroundTilemapEnd:

TestBackground2Data: INCBIN "gfx/backgrounds/TestBackground2.2bpp"
TestBackground2DataEnd:

TestBackgroundTilemap2: INCBIN "gfx/backgrounds/Testbackground2.tilemap"
TestBackgroundTilemap2End:

TestActorData: INCBIN "gfx/actors/DoeStanding.2bppactor"
TestActorDataEnd:

TestActor2Data: INCBIN "gfx/actors/DoeTalking.2bppactor"
TestActor2DataEnd: