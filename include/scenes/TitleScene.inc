SECTION "TitleScene", ROM0

RunTitleScene:
    fade_to_new_background 1, TitleSceneData, TitleSceneDataEnd, TitleSceneTilemap, TitleSceneTilemapEnd
    delay_frames 60
    
	call ShowTextBox

	draw_text_delay FAST_TEXT_SPEED, $99E1, "press a to begin"
	call WaitForAPress
	call ClearTextBox

	hide_textbox 1, TitleSceneTilemap
	delay_frames 60
    ret