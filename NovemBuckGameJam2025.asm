INCLUDE "include/hardware.inc"			; include all the hardware definitions
										; and other out of file definitions

INCLUDE "include/vnEngineConstants.inc"
INCLUDE "include/vnEngineMacros.inc"
INCLUDE "include/vnEngineStructs.inc"	; include all the main data needed for the engine
INCLUDE "include/vnEngineUtilitySubroutines.inc"
INCLUDE "include/vnEngineSoundSubroutines.inc"

; Scene files
INCLUDE "include/scenes/TestScene.inc"

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
wFirstTextBoxOffset: db					; where in bank one the textbox starts

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
	call HideMetasprite

	call TileLoaderReset
    call SetBlankDMGPalette

	; once the OAM is clear, we can draw an object by writing its properties
	call SetDefaultDMGPalette
	call LoadDefaultCGBPalette

	call InitialiseTextBoxGraphicsFixedAddress
	call InitialiseFontFixedAddress

	; Initialise variables
	ld a, 0
	ld [wButtonDebounce], a

	call EnableLCD
	call EnableSound
	

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

	call DisableSound
	call EnableSound

	; start running through all the scenes
	; here we just have the big pile of every scene
	call RunTestScene
.FinishedTickingScene

jp ProgramMain


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;	ENGINE DATA
;;	BLOCK
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SECTION "Font Data", ROMX, BANK[1]

AlphabetTiles: INCBIN "gfx/backgrounds/text-font.2bpp"
AlphabetTilesEnd:

TextBoxTiles: INCBIN "gfx/backgrounds/TextBoxtiles.2bpp"
TextBoxTilesEnd:

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;	GAME DATA
;;	BLOCK
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

SECTION "TestScene Graphics Data", ROMX, BANK[1]

TestSpriteData: INCBIN "gfx/spritesheettest.2bpp"
TestSpriteDataEnd:

TestBackgroundData: INCBIN "gfx/backgrounds/TestBackground.2bpp"
TestBackgroundDataEnd: 
TestBackgroundTilemap: INCBIN "gfx/backgrounds/TestBackground.tilemap"
TestBackgroundTilemapEnd:

TestActorData: INCBIN "gfx/actors/DoeStanding.2bppactor"
TestActorDataEnd:

TestActor2Data: INCBIN "gfx/actors/DoeTalking.2bppactor"
TestActor2DataEnd:

SECTION "All Actor Data", ROMX, BANK[1]

DoeStandingData: INCBIN "gfx/actors/DoeStanding.2bppactor"
DoeStandingDataEnd:

DoeTalkingData: INCBIN "gfx/actors/DoeTalking.2bppactor"
DoeTalkingDataEnd:

MonsterFullViewData: INCBIN "gfx/actors/MonsterFullView.2bppactor"
MonsterFullViewDataEnd:

MonsterSideViewData: INCBIN "gfx/actors/MonsterSideView.2bppactor"
MonsterSideViewDataEnd:

MonsterPeekingData: INCBIN "gfx/actors/MonsterPeeking.2bppactor"
MonsterPeekingDataEnd:

MonsterPeekingWindowData: INCBIN "gfx/actors/MonsterPeekingWindow.2bppactor"
MonsterPeekingWindowDataEnd:

MonsterReachingData: INCBIN "gfx/actors/MonsterReaching.2bppactor"
MonsterReachingDataEnd:


SECTION "Background Data 1", ROMX, BANK[2]

BedroomData: INCBIN "gfx/backgrounds/Bedroom.2bpp"
BedroomDataEnd: 
BedroomTilemap: INCBIN "gfx/backgrounds/Bedroom.tilemap"
BedroomTilemapEnd:

BlackBackgroundData: INCBIN "gfx/backgrounds/BlackBackground.2bpp"
BlackBackgroundDataEnd: 
BlackBackgroundTilemap: INCBIN "gfx/backgrounds/BlackBackground.tilemap"
BlackBackgroundTilemapEnd:

BrokenGlassCloseupData: INCBIN "gfx/backgrounds/BrokenGlassCloseup.2bpp"
BrokenGlassCloseupDataEnd: 
BrokenGlassCloseupTilemap: INCBIN "gfx/backgrounds/BrokenGlassCloseup.tilemap"
BrokenGlassCloseupTilemapEnd:

ComputerData: INCBIN "gfx/backgrounds/Computer.2bpp"
ComputerDataEnd: 
ComputerTilemap: INCBIN "gfx/backgrounds/Computer.tilemap"
ComputerTilemapEnd:

HidingUnderBedData: INCBIN "gfx/backgrounds/HidingUnderBed.2bpp"
HidingUnderBedDataEnd: 
HidingUnderBedTilemap: INCBIN "gfx/backgrounds/HidingUnderBed.tilemap"
HidingUnderBedTilemapEnd:

KitchenData: INCBIN "gfx/backgrounds/Kitchen.2bpp"
KitchenDataEnd: 
KitchenTilemap: INCBIN "gfx/backgrounds/Kitchen.tilemap"
KitchenTilemapEnd:

	SECTION "Background Data 2", ROMX, BANK[3]

KitchenMissingGlassData: INCBIN "gfx/backgrounds/KitchenMissingGlass.2bpp"
KitchenMissingGlassDataEnd: 
KitchenMissingGlassTilemap: INCBIN "gfx/backgrounds/KitchenMissingGlass.tilemap"
KitchenMissingGlassTilemapEnd:

LyingInBedData: INCBIN "gfx/backgrounds/LyingInBed.2bpp"
LyingInBedDataEnd: 
LyingInBedTilemap: INCBIN "gfx/backgrounds/LyingInBed.tilemap"
LyingInBedTilemapEnd:

StairwellDownData: INCBIN "gfx/backgrounds/StairwellDown.2bpp"
StairwellDownDataEnd: 
StairwellDownTilemap: INCBIN "gfx/backgrounds/StairwellDown.tilemap"
StairwellDownTilemapEnd:

StairwellDownBrokenVaseData: INCBIN "gfx/backgrounds/StairwellDownBrokenVase.2bpp"
StairwellDownBrokenVaseDataEnd: 
StairwellDownBrokenVaseTilemap: INCBIN "gfx/backgrounds/StairwellDownBrokenVase.tilemap"
StairwellDownBrokenVaseTilemapEnd:

TitleSceneData: INCBIN "gfx/backgrounds/TitleScene.2bpp"
TitleSceneDataEnd: 
TitleSceneTilemap: INCBIN "gfx/backgrounds/TitleScene.tilemap"
TitleSceneTilemapEnd:
