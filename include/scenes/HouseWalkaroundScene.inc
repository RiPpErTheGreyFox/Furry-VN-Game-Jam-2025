SECTION "HouseWalkaroundScene", ROM0

RunHouseWalkaroundScene:

    delay_frames 240
    
	call ShowTextBox

; Scene Collection 2:
; *walk around the house to get the layout*
; well, I might as
; well figure out
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "well, i might as"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "well figure out"
	call WaitForAPress
	call ClearTextBox
; what to do for
; the night
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "what to do for"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "the night,"
	call WaitForAPress
	call ClearTextBox
; first I better
; get the glass
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "first, i better"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "get the glass"
	call WaitForAPress
	call ClearTextBox
; from my room.
;
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "from my room"
	call WaitForAPress
	call ClearTextBox

 	hide_textbox 3, KitchenMissingGlassTilemap
	delay_frames 60

; -fade to bedroom
	fade_to_new_background 2, BedroomData, BedroomDataEnd, BedroomTilemap, BedroomTilemapEnd
    delay_frames 240
    
	call ShowTextBox
; Ah there it is.
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "ah there it is."
	call WaitForAPress
	call ClearTextBox

; -delay for a bit
	hide_textbox 2, BedroomTilemap
	delay_frames 240
	delay_frames 240
; I think another
; night of checking
; 
	call ShowTextBox

	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "i think another"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "night of checking"
	call WaitForAPress
	call ClearTextBox
; out IRC is the
; plan for tonight
;
 	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "out irc is the"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "plan for tonight"
	call WaitForAPress
	call ClearTextBox
 	hide_textbox 2, BedroomTilemap
	delay_frames 240

; -switch to stairs down
	fade_to_new_background 3, StairwellDownData, StairwellDownDataEnd, StairwellDownTilemap, StairwellDownTilemapEnd
    delay_frames 240
	call ShowTextBox
; god, these stairs
; are gunna dump
;
  	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "god, these stairs"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "are gunna dump"
	call WaitForAPress
	call ClearTextBox
; me at the bottom
; of them one day
;
 	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "me at the bottom"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "of them one day"
	call WaitForAPress
	call ClearTextBox
 	hide_textbox 3, StairwellDownTilemap
	delay_frames 240
; -play stair footstep sounds
; -switch to kitchen with glass
; 
	fade_to_new_background 2, KitchenData, KitchenDataEnd, KitchenTilemap, KitchenTilemapEnd
    delay_frames 240
; there we go,
; time to go waste
; 
	call ShowTextBox
 	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "there we go,"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "time to go waste"
	call WaitForAPress
	call ClearTextBox
; my youth on the
; internet, again.

 	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "my youth on the"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "internet, again."
	call WaitForAPress
	call ClearTextBox

 	hide_textbox 2, KitchenTilemap
	delay_frames 240
; *end walk around the house to get the layout*

    ret