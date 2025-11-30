; If all of these are already defined, don't do it again.

    IF !DEF(VNENGINEMACROS_INC)
DEF VNENGINEMACROS_INC EQU 1

; a file full of all the macros for use in this project

; macro to make text rendering a single line
; @params 1: number of frames between text tiles to render (speed)
; @params 2: destination address for the text to start rendering ($99E1 is top line of dialogue box, $9A01 is lower line)
; @params 3: pointer to the string array
MACRO draw_text_delay
    jr .code\@
.data\@
    db \3
    db 255
.code\@
    ld hl,.data\@
	ld de, \2
	ld c, \1
	call DrawTextTilesWithDelays
ENDM


; macro to make text rendering a single line
; @params 1: number of frames between text tiles to render (speed)
; @params 2: destination address for the text to start rendering ($99E1 is top line of dialogue box, $9A01 is lower line)
; @params 3: pointer to the string array
; @params 4: pointer to the custom sound
MACRO draw_text_delay_custom_sound
    ld hl, \4
    ld a, h
    ld [hScratchArea], a
    ld a, l
    ld [hScratchArea + 1], a
    jr .code\@
.data\@
    db \3
    db 255
.code\@
    ld hl,.data\@
	ld de, \2
	ld c, \1
	call DrawTextTilesWithDelaysCustomSound
ENDM

; hard sets the actor position to hard reposition them
; @params 1: X position
; @params 2: Y position
MACRO set_actor_pos
    ld b, \1
    ld c, \2
    call SetMetaspritePosition
ENDM

; animates an actor to their new position
; @params 1: X position
; @params 2: Y position
; @params 3: time between steps
; @params 4: step amount
MACRO move_actor_to_pos
	ld b, \1
	ld c, \2
	ld d, \3
	ld e,\4
	call MoveMetaspriteToPosition
ENDM

; loads a new metasprite
; @params 1: bank the actor resides in
; @params 2: address of the tile data
; @params 3: size of the tile data
MACRO load_new_actor
	ld de, \2
	ld bc, \3
	ld a, \1
	call LoadToMetasprite
ENDM
	

; hard sets the actor position to the centre of the screen
MACRO set_actor_in_middle
    ld b, 64
    ld c, 32
    call SetMetaspritePosition
ENDM

; updates OAM's and wait a frame
MACRO force_render_update
	call RenderMetaSprite
    
    ld a, HIGH(wShadowOAM)
	call hOAMDMA

    ld b, 1
    call WaitFrames
ENDM

; loads the param into band calls WaitFrames, register safe because pushes everything to the stack
; @params \1: number of frames to wait for (minimum 1)
MACRO delay_frames
    push af
    push bc
    push de
    push hl
    ld b, \1
    call WaitFramesWithUpdate
    pop hl
    pop de
    pop bc
    pop af
ENDM

; sets up and fades into a new background
; @params 1: which ROM bank the new background resides in (will be switched back to 1 when finished just to keep a sane state)
; @params 2: pointer to tile data of new background
; @params 3: pointer to the end of the tile data of new background
; @params 4: pointer to the tilemap of the new background
; @params 5: pointer to the end of the tilemap of the new background
MACRO fade_to_new_background
    ld de, \4
	ld bc, \5 - \4
	push de
	push bc
	ld a, \1                            ; bank number
	ld bc, \3 - \2
	ld de, \2
	call FadeToNewBackground
ENDM

; sets up and loads a new background
; @params 1: which ROM bank the new background resides in (will be switched back to 1 when finished just to keep a sane state)
; @params 2: pointer to tile data of new background
; @params 3: pointer to the end of the tile data of new background
; @params 4: pointer to the tilemap of the new background
; @params 5: pointer to the end of the tilemap of the new background
MACRO load_new_background
    ld de, \4
	ld bc, \5 - \4
	push de
	push bc
	ld a, \1                            ; bank number
	ld bc, \3 - \2
	ld de, \2
	call LoadNewBackground
ENDM

; hides the text box and replaces the tiles under it with the tiles from the current level
; @params 1: which ROM bank the original background resides in (will be switched back to 1 when finished just to keep a sane state)
; @params 2: pointer to the beginning of the tilemap of the original background
MACRO hide_textbox
    ld a, \1
	ld bc, \2
	call HideTextBox
ENDM

    ENDC ;VNENGINEMACROS_INC
