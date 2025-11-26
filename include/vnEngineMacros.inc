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

; hard sets the actor position to hard reposition them
; @params 1: X position
; @params 2: Y position
MACRO set_actor_pos
    ld c, \1
    ld b, \2
    call SetMetaspritePosition
ENDM

; hard sets the actor position to the centre of the screen
MACRO set_actor_in_middle
    ld c, 32
    ld b, 64
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

    ENDC ;VNENGINEMACROS_INC
