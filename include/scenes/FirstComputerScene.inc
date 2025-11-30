SECTION "FirstComputerScene", ROM0

RunFirstComputerScene:
; *go up to room*
; -fade to bedroom
    fade_to_new_background 2, BedroomData, BedroomDataEnd, BedroomTilemap, BedroomTilemapEnd
    delay_frames 60
; -play stair footstep sounds
; 
; the early 'net
; really was a wild
; 
	call ShowTextBox
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "the early 'net"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "really was a wild"
	call WaitForAPress
	call ClearTextBox
; place, you could
; find a chatroom
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "place, you could"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "find a chatroom"
	call WaitForAPress
	call ClearTextBox
; for anything,
; that night though
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "for anything,"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "that night though"
	call WaitForAPress
	call ClearTextBox
; I decided on a
; cryptid chatroom
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "i decided on a"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "cryptid chatroom"
	call WaitForAPress
	call ClearTextBox
; like I had many
; times before
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "like i had many"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "times before"
	call WaitForAPress
	call ClearTextBox
	hide_textbox 2, BedroomTilemap

; -switch to computer

    fade_to_new_background 2, ComputerData, ComputerDataEnd, ComputerTilemap, ComputerTilemapEnd
    delay_frames 60
; *talk on IRC*
; *$9842 is first line
	
; D> Anyone got any
	draw_text_delay NORMAL_TEXT_SPEED, $9842, "d>anyone got any"
	delay_frames 60
; crazy stories
	draw_text_delay NORMAL_TEXT_SPEED, $9862, "crazy stories"
	delay_frames 60

; to tell tonight?
	draw_text_delay NORMAL_TEXT_SPEED, $9882, "to tell tonight?"
	delay_frames 240
; M> yeah, we were
	draw_text_delay FAST_TEXT_SPEED, $98C2, "m>yeah, we were"
	delay_frames 20

; talking about
	draw_text_delay FAST_TEXT_SPEED, $98E2, "talking about"
	delay_frames 20

; the half deer
	draw_text_delay FAST_TEXT_SPEED, $9902, "the half deer"
	delay_frames 20

	delay_frames 240
; D> the half deer?
	draw_text_delay NORMAL_TEXT_SPEED, $9942, "d>the half deer?"
	delay_frames 60

	delay_frames 240
; K> an evil spirit
	draw_text_delay FAST_TEXT_SPEED, $9982, "k>an evil spirit"
	delay_frames 20

; for sure, not one
	draw_text_delay FAST_TEXT_SPEED, $99A2, "for sure not one"
	delay_frames 20

; to mess with
	draw_text_delay FAST_TEXT_SPEED, $99C2, "to mess with."
	delay_frames 20

call WaitForAPress
; *get told about le creachur*

    ret