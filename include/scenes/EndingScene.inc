SECTION "EndingScene", ROM0

RunEndingScene:
    fade_to_new_background 2, BlackBackgroundData, BlackBackgroundDataEnd, BlackBackgroundTilemap, BlackBackgroundTilemapEnd
    delay_frames 60
    
	call ShowTextBox
;	*ending*
;- fade back to black background
;There's just one 
;problem though,
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "there's just one"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "problem though,"
	call WaitForAPress
	call ClearTextBox

;It's still
;hunting me today,
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "it's still"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "hunting me today,"
	call WaitForAPress
	call ClearTextBox

;because it only
;hunts people who
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "because it only"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "hunts people who"
	call WaitForAPress
	call ClearTextBox
	
;know about it.
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "know about it."
	call WaitForAPress
	call ClearTextBox
	
;Luckily, for me,
;it usually only
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "luckily, for me,"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "it usually only"
	call WaitForAPress
	call ClearTextBox
	
;hunts for whoever
;was the last
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "hunts for whoever"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "was the last"
	call WaitForAPress
	call ClearTextBox
	
;person who heard
;about it...
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "person who heard"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "about it..."
	call WaitForAPress
	call ClearTextBox
	
;I sure hope you
;got a friend to
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "i sure hope you"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "got a friend to"
	call WaitForAPress
	call ClearTextBox
	
;tell the story to
;next, either that
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "tell the story to"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "next, either that"
	call WaitForAPress
	call ClearTextBox
	
;or learn to sleep
;lightly...
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "or learn to sleep"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "lightly..."
	call WaitForAPress
	call ClearTextBox

	hide_textbox 2, BlackBackgroundTilemap
	delay_frames 60

	ld c, 10
	call FadeToWhite
;*end ending*

;*queue up title scene again*
    ret