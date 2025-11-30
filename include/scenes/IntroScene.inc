SECTION "IntroScene", ROM0

RunIntroScene:
	fade_to_new_background 2, BlackBackgroundData, BlackBackgroundDataEnd, BlackBackgroundTilemap, BlackBackgroundTilemapEnd
    delay_frames 60
	call ShowTextBox
	draw_text_delay 10, $99E1, "123456789012345678"
    draw_text_delay 10, $9A01, "123456789012345678"
	call WaitForAPress
	call ClearTextBox

	hide_textbox 2, BlackBackgroundTilemap
	delay_frames 60
    ret