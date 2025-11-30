SECTION "IntroScene", ROM0

RunIntroScene:
    fade_to_new_background 2, BlackBackgroundData, BlackBackgroundDataEnd, BlackBackgroundTilemap, BlackBackgroundTilemapEnd
    delay_frames 60
    
	call ShowTextBox

	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "you ever see"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "something weird?"
	call WaitForAPress
	call ClearTextBox

	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "something so"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "unexplainable?"
	call WaitForAPress
	call ClearTextBox

	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "that no one will"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "believe you?"
	call WaitForAPress
	call ClearTextBox

	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "that was me,"
    draw_text_delay SLOW_TEXT_SPEED, $9A01, "20 years ago"
	call WaitForAPress
	call ClearTextBox

	hide_textbox 2, BlackBackgroundTilemap
	delay_frames 60
    ret