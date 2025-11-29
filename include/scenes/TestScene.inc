SECTION "TestSceneCode", ROM0

; placeholder init sub for testing the base program works
InitialiseTestScene:
	call DisableLCD
	; load up the test background
	ld de, TestBackgroundTilemap
	ld bc, TestBackgroundTilemapEnd - TestBackgroundTilemap
	push de
	push bc
	ld a, 1
	ld bc, TestBackgroundDataEnd - TestBackgroundData
	ld de, TestBackgroundData
	call LoadNewBackground

	; setup the actor with a default sprite
	ld de, TestActorData
	ld bc, TestActorDataEnd - TestActorData
	ld a, 1 ; set the bank variable
	call LoadToMetasprite

	set_actor_in_middle

	; set how scrolled the screen is
	ld a, 0
	ld [wYScrollCounter], a
	ld [rSCY], a

	; initialise the sound driver and start the song
	ld hl, mainmenu_song
	call hUGE_init

	call EnableLCD

	ret

; placeholder tick sub for testing the base program works
RunTestScene:

	draw_text_delay 2, $99E1, "test scene"
	delay_frames 60

	

	;draw_text_delay 10, $99E1, "i am speaking     "
	;draw_text_delay 30, $9A01, "very slowly"

	;ld b, 100
	;ld c, 100
	;ld d, 1
	;ld e, 1
	;call MoveMetaspriteToPosition

	call HideMetasprite

	force_render_update

	call .RunBackgroundSlideshow

    call UpdateKeys

    ;ld a, [wCurKeys]
	;and a, PADF_START
	;jp z, .CheckAPressed
	;jp .RunBackgroundSlideshow
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

.RunBackgroundSlideshow
	; load up every background in order
	fade_to_new_background 2, BedroomData, BedroomDataEnd, BedroomTilemap, BedroomTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "bedroom"
	delay_frames 60

	fade_to_new_background 2, BlackBackgroundData, BlackBackgroundDataEnd, BlackBackgroundTilemap, BlackBackgroundTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "blackbackground"
	delay_frames 60
	
	fade_to_new_background 2, BrokenGlassCloseupData, BrokenGlassCloseupDataEnd, BrokenGlassCloseupTilemap, BrokenGlassCloseupTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "brokenglasscloseup"
	delay_frames 60
	
	fade_to_new_background 2, ComputerData, ComputerDataEnd, ComputerTilemap, ComputerTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "computer"
	delay_frames 60
	
	fade_to_new_background 2, HidingUnderBedData, HidingUnderBedDataEnd, HidingUnderBedTilemap, HidingUnderBedTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "hidingunderbed"
	delay_frames 60
	
	fade_to_new_background 2, KitchenData, KitchenDataEnd, KitchenTilemap, KitchenTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "kitchen"
	delay_frames 60

	; bank change here
	
	fade_to_new_background 3, KitchenMissingGlassData, KitchenMissingGlassDataEnd, KitchenMissingGlassTilemap, KitchenMissingGlassTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "kitchenmissingglass"
	delay_frames 60
	
	fade_to_new_background 3, LyingInBedData, LyingInBedDataEnd, LyingInBedTilemap, LyingInBedTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "lyinginbed"
	delay_frames 60
	
	fade_to_new_background 3, StairwellDownData, StairwellDownDataEnd, StairwellDownTilemap, StairwellDownTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "stairwelldown"
	delay_frames 60
	
	fade_to_new_background 3, StairwellDownBrokenVaseData, StairwellDownBrokenVaseDataEnd, StairwellDownBrokenVaseTilemap, StairwellDownBrokenVaseTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "stairwelldownbrokenvase"
	delay_frames 60
	
	fade_to_new_background 3, TitleSceneData, TitleSceneDataEnd, TitleSceneTilemap, TitleSceneTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "titlescene"
	delay_frames 60
	
	fade_to_new_background 1, TestBackgroundData, TestBackgroundDataEnd, TestBackgroundTilemap, TestBackgroundTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "testbackground"
	delay_frames 60

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
