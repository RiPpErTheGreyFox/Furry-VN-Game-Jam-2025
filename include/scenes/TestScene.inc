SECTION "TestSceneCode", ROM0

; placeholder tick sub for testing the base program works
RunTestScene:

	draw_text_delay 2, $99E1, "test scene"
	delay_frames 60

	;draw_text_delay 10, $99E1, "i am speaking     "
	;draw_text_delay 30, $9A01, "very slowly"

	;ld b, 100
	;ld c, 100
	;ld d, 1
	;ld e, 1
	;call MoveMetaspriteToPosition

	call HideMetasprite

	force_render_update

	call .RunBackgroundSlideshow

.RunBackgroundSlideshow
	; load up every background in order
	fade_to_new_background 2, BedroomData, BedroomDataEnd, BedroomTilemap, BedroomTilemapEnd
	delay_frames 60
	call ShowTextBox
	draw_text_delay 10, $99E1, "bedroom"
	call WaitForAPress
	call ClearTextBox
	draw_text_delay_custom_sound 10, $99E1, "testing clear", sound_item_grab
	draw_text_delay_custom_sound 10, $9A01, "functionality", sound_item_grab
	call WaitForAPress
	delay_frames 60
	hide_textbox 2, BedroomTilemap
	delay_frames 60

	fade_to_new_background 2, BlackBackgroundData, BlackBackgroundDataEnd, BlackBackgroundTilemap, BlackBackgroundTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "blackbackground"
	delay_frames 60
	
	fade_to_new_background 2, BrokenGlassCloseupData, BrokenGlassCloseupDataEnd, BrokenGlassCloseupTilemap, BrokenGlassCloseupTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "brokenglasscloseup"
	delay_frames 60
	
	fade_to_new_background 2, ComputerData, ComputerDataEnd, ComputerTilemap, ComputerTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "computer"
	delay_frames 60
	
	fade_to_new_background 2, HidingUnderBedData, HidingUnderBedDataEnd, HidingUnderBedTilemap, HidingUnderBedTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "hidingunderbed"
	delay_frames 60
	
	fade_to_new_background 2, KitchenData, KitchenDataEnd, KitchenTilemap, KitchenTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "kitchen"
	delay_frames 60

	; bank change here
	
	fade_to_new_background 3, KitchenMissingGlassData, KitchenMissingGlassDataEnd, KitchenMissingGlassTilemap, KitchenMissingGlassTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "kitchenmissingglass"
	delay_frames 60
	
	fade_to_new_background 3, LyingInBedData, LyingInBedDataEnd, LyingInBedTilemap, LyingInBedTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "lyinginbed"
	delay_frames 60
	
	fade_to_new_background 3, StairwellDownData, StairwellDownDataEnd, StairwellDownTilemap, StairwellDownTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "stairwelldown"
	delay_frames 60
	
	fade_to_new_background 3, StairwellDownBrokenVaseData, StairwellDownBrokenVaseDataEnd, StairwellDownBrokenVaseTilemap, StairwellDownBrokenVaseTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "stairwelldownbrokenvase"
	delay_frames 60
	
	fade_to_new_background 3, TitleSceneData, TitleSceneDataEnd, TitleSceneTilemap, TitleSceneTilemapEnd
	delay_frames 60
	draw_text_delay 10, $99E1, "titlescene"
	delay_frames 60

	ret

.EndOfFunc
	ret
