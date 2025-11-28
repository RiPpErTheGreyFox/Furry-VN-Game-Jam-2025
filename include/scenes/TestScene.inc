SECTION "TestSceneCode", ROM0
; placeholder tick sub for testing the base program works
RunTestScene:

	draw_text_delay 2, $99E1, "single line macro?"

	force_render_update

	draw_text_delay 10, $99E1, "i am speaking     "
	draw_text_delay 30, $9A01, "very slowly"


	ld b, 100
	ld c, 100
	ld d, 1
	ld e, 1
	call MoveMetaspriteToPosition

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
	; load up the second test background
	fade_to_new_background 2, TestBackground2Data, TestBackground2DataEnd, TestBackgroundTilemap2, TestBackgroundTilemap2End
	draw_text_delay 10, $99E1, "wow a new place"

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

SECTION "TestScene Graphics Data", ROMX, BANK[2]

TestSpriteData: INCBIN "gfx/spritesheettest.2bpp"
TestSpriteDataEnd:

TestBackgroundData: INCBIN "gfx/backgrounds/TestBackground.2bpp"
TestBackgroundDataEnd: 

TestBackgroundTilemap: INCBIN "gfx/backgrounds/TestBackground.tilemap"
TestBackgroundTilemapEnd:

TestBackground2Data: INCBIN "gfx/backgrounds/TestBackground2.2bpp"
TestBackground2DataEnd:

TestBackgroundTilemap2: INCBIN "gfx/backgrounds/TestBackground2.tilemap"
TestBackgroundTilemap2End:

TestActorData: INCBIN "gfx/actors/DoeStanding.2bppactor"
TestActorDataEnd:

TestActor2Data: INCBIN "gfx/actors/DoeTalking.2bppactor"
TestActor2DataEnd: