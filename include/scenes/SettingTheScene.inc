SECTION "SettingTheScene", ROM0

RunSettingTheScene:

; *setting the scene*
; -show kitchen no glass
	ld c, 30
	call FadeToWhite
	call DisableLCD
    load_new_background 3, KitchenMissingGlassData, KitchenMissingGlassDataEnd, KitchenMissingGlassTilemap, KitchenMissingGlassTilemapEnd
    call EnableLCD
	ld c, 30
	call FadeFromWhite
	delay_frames 240
    
	call ShowTextBox

; This is where I
; was living, near
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "this is where i"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "was living, near"
	call WaitForAPress
	call ClearTextBox
; college with all
; the other deer in
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "college with all"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "the other deer in"
	call WaitForAPress
	call ClearTextBox
; the area, I guess
; it felt like home
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "the area, i guess"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "it felt like home"
	call WaitForAPress
	call ClearTextBox
; I always thought
; it was weird that
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "i always thought"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "it was weird that"
	call WaitForAPress
	call ClearTextBox
; similar species
; would choose to
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "similar species"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "would choose to"
	call WaitForAPress
	call ClearTextBox
; live near each
; other, but
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "live near each"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "other, but"
	call WaitForAPress
	call ClearTextBox
; I guess it was
; to feel safe
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "i guess it was"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "to feel safer"
	call WaitForAPress
	call ClearTextBox
; although I don't
; feel safe around
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "although after"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "last night,"
	call WaitForAPress
	call ClearTextBox
; other deer these
; days, not anymore
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "i think it's"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "just to throw more"
	call WaitForAPress
	call ClearTextBox
	
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "parties all the"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "time..."
	call WaitForAPress
	call ClearTextBox
; -switch to roommate
	load_new_actor 1, DoeStandingData, DoeStandingDataEnd - DoeStandingData
	set_actor_pos 180, 32
	move_actor_to_pos 64, 32, 1, 1
; -transition in from right

; speaking of deer,
; my room mate also
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "speaking of deer,"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "my room mate also"
	call WaitForAPress
	call ClearTextBox
; happened to be
; one.
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "happened to be"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "one."
	call WaitForAPress
	call ClearTextBox
; -switch to room mate talking
	load_new_actor 1, DoeTalkingData, DoeTalkingDataEnd - DoeTalkingData
; Hi there sleepy
; head, I see you
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "hi there sleepy"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "head, i see you"
	call WaitForAPress
	call ClearTextBox
; are finally up
; and about
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "are finally up"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "and about"
	call WaitForAPress
	call ClearTextBox
; you've slept all
; day, it's past
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "you've slept all"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "day, it's past"
	call WaitForAPress
	call ClearTextBox
; sunset! I was
; about to head out
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "sunset! i was"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "about to head out"
	call WaitForAPress
	call ClearTextBox
; to a movie night.
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "to a movie night!"
	call WaitForAPress
	call ClearTextBox
; -switch to room mate standing
	load_new_actor 1, DoeStandingData, DoeStandingDataEnd - DoeStandingData
; I guess I'd be
; getting the house
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "i guess i'd be"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "getting the house"
	call WaitForAPress
	call ClearTextBox
; to myself for the
; night for once.
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "to myself for the"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "night for once"
	call WaitForAPress
	call ClearTextBox
; -switch to room mate talking
	load_new_actor 1, DoeTalkingData, DoeTalkingDataEnd - DoeTalkingData
; Try not to have
; any wild parties
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "try not to have"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "any wild parties"
	call WaitForAPress
	call ClearTextBox
; while I'm gone
; okay?
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "while i'm gone"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "okay?"
	call WaitForAPress
	call ClearTextBox
; Byyeeeee!
; 
; -transition off screen to the right
; -hide actor
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "byyeeeee"
	move_actor_to_pos 180, 32, 1, 1
	call WaitForAPress
	call ClearTextBox

; yeah right, like
; that'll ever
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "yeah right, like"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "that'll ever"
	call WaitForAPress
	call ClearTextBox
; happen, not after
; last night
; *end setting the scene*
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "happen, not after"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "last night..."
	call WaitForAPress
	call ClearTextBox

	hide_textbox 3, KitchenMissingGlassTilemap
	delay_frames 240

    ret