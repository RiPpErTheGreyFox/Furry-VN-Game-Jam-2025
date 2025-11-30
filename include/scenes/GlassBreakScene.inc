SECTION "GlassBreakScene", ROM0

RunGlassBreakScene:


; - play stair footstep noise
; - play glass break noise
; *hear a noise*
; Huh? What the
; hell was that?
	call ShowTextBox

	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "huh? what the"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "hell was that?"
	call WaitForAPress
	call ClearTextBox

; *go downstairs find broken glass*
; - switch to downstairs scene
    fade_to_new_background 3, StairwellDownData, StairwellDownDataEnd, StairwellDownTilemap, StairwellDownTilemapEnd
    delay_frames 60
    
; - monster actor showing slightly before retreating into darkness
; - hide actor
	call ShowTextBox
; It sounded like
; something broke
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "it sounded like"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "something broke"
	call WaitForAPress
	call ClearTextBox

; - switch to kitchen with broken glass
; - actor monster in the window
    fade_to_new_background 3, KitchenBrokenGlassData, KitchenBrokenGlassDataEnd, KitchenBrokenGlassTilemap, KitchenBrokenGlassTilemapEnd
    delay_frames 60
    
; huh, that's weird
; I must've put it
; 
	call ShowTextBox
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "huh, that's weird"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "i must've put it"
	call WaitForAPress
	call ClearTextBox

; too close to the
; edge, crap.
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "too close to the"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "edge, dang it"
	call WaitForAPress
	call ClearTextBox

; - fade to black
	ld c, 30
	call FadeToWhite
; - play sound
; - switch to kitchen no glass
    fade_to_new_background 3, KitchenMissingGlassData, KitchenMissingGlassDataEnd, KitchenMissingGlassTilemap, KitchenMissingGlassTilemapEnd
    delay_frames 60
  
; *clean it up go back upstairs*
; well that's all
; sorted out
; 
	call ShowTextBox
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "well, that's all"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "sorted out"
	call WaitForAPress
	call ClearTextBox

; -switch to bedroom
    fade_to_new_background 2, BedroomData, BedroomDataEnd, BedroomTilemap, BedroomTilemapEnd
    delay_frames 60
; I didn't think it
; was that close to
; 
	call ShowTextBox

	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "i didn't think it"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "was that close to"
	call WaitForAPress
	call ClearTextBox

; the edge, wonder
; if they know
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "the edge, wonder"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "if they know"
	call WaitForAPress
	call ClearTextBox

; anything about
; what happened
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "anything about"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "what happened"
	call WaitForAPress
	call ClearTextBox

; *check computer again and say what happened*
; - switch to computer
; *IRC text*
    fade_to_new_background 2, ComputerData, ComputerDataEnd, ComputerTilemap, ComputerTilemapEnd
    delay_frames 60


; D> somehow a
	draw_text_delay NORMAL_TEXT_SPEED, $9842, "d>somehow a"
	delay_frames 60
; glass just broke
	draw_text_delay NORMAL_TEXT_SPEED, $9862, "glass just broke"
	delay_frames 60
; in my kitchen
	draw_text_delay NORMAL_TEXT_SPEED, $9882, "in my kitchen"
	delay_frames 240
; K> oh hey,
	draw_text_delay FAST_TEXT_SPEED, $98C2, "k>oh hey,"
	delay_frames 20

; guess that means
	draw_text_delay FAST_TEXT_SPEED, $98E2, "guess that means"
	delay_frames 20

; someone is being
	draw_text_delay FAST_TEXT_SPEED, $9902, "someone is being"
	delay_frames 20

; paid a visit
	draw_text_delay NORMAL_TEXT_SPEED, $9922, "paid a visit"
	delay_frames 20

call WaitForAPress
    ret