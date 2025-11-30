SECTION "MonsterSpottedScene", ROM0

RunMonsterSpottedScene:
    fade_to_new_background 2, ComputerData, ComputerDataEnd, ComputerTilemap, ComputerTilemapEnd

; 	Scene Collection 4:
; -play footstep noise
; -play breaking noise
; *hear vase break and go look down the stairs*
; 

	call ShowTextBox
; Oh no, what the
; hell is it now?

	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "oh no, what the"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "hell is it now?"
	call WaitForAPress
	call ClearTextBox
	delay_frames 60

    fade_to_new_background 3, StairwellDownData, StairwellDownDataEnd, StairwellDownTilemap, StairwellDownTilemapEnd
    delay_frames 240
	delay_frames 240
    
	call ShowTextBox


; -switch to downstairs broken vase
; What!?
; Obviously I'm
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "what!?"
	delay_frames 240
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "obviously i'm"
	call WaitForAPress
	call ClearTextBox
; just imagining
; things, screw
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "just imagining"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "things, screw"
	call WaitForAPress
	call ClearTextBox
; this, I'm going
; to bed...
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "this, i'm going"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "to bed..."
	call WaitForAPress
	call ClearTextBox
; - switch to laying in bed
; *decide to go to bed because obviously imagining shit*
; *laying in bed hear another noise*
    fade_to_new_background 2, BedroomData, BedroomDataEnd, BedroomTilemap, BedroomTilemapEnd
    delay_frames 240
	delay_frames 240

	call ShowTextBox
    
; Maybe I shouldn't
; be reading creepy
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "maybe i shouldn't"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "be reading creepy"
	call WaitForAPress
	call ClearTextBox
; stuff online,
; it's probably not
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "stuff online,"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "it's probably not"
	call WaitForAPress
	call ClearTextBox
; good for me.
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "good for me"
	call WaitForAPress
	call ClearTextBox

	hide_textbox 2, BedroomTilemap
; - play footstep sound again

	delay_frames 240
	delay_frames 240

	call ShowTextBox
; Wait, the stairs?
; Is my room-mate
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "wait, the stairs?"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "is my room-mate"
	call WaitForAPress
	call ClearTextBox
; home already?
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "home already?"
	call WaitForAPress
	call ClearTextBox
	delay_frames 60

	hide_textbox 2, BedroomTilemap
	delay_frames 240
; *go look down stairs, monster is down there peeking around corner*
; - switch to the down stairs view

    fade_to_new_background 3, StairwellDownData, StairwellDownDataEnd, StairwellDownTilemap, StairwellDownTilemapEnd
; - monster visible on the stairs
	load_new_actor 1, MonsterFullViewData, MonsterFullViewDataEnd - MonsterFullViewData
	set_actor_in_middle
	set_actor_pos 24, 36
	delay_frames 10
; - play growl effect
; 
	call ShowTextBox
	draw_text_delay FAST_TEXT_SPEED, $99E1, "!!!"
	delay_frames 240
	call ClearTextBox
	hide_textbox 3, StairwellDownTilemap

	delay_frames 30
; *immediately go to hide under the bed*
; - switch to the under bed background
	call HideMetasprite
	delay_frames 2
    fade_to_new_background 2, HidingUnderBedData, HidingUnderBedDataEnd, HidingUnderBedTilemap, HidingUnderBedTilemapEnd

; What the hell was
; that!?
; 
	call ShowTextBox
	draw_text_delay SLOW_TEXT_SPEED, $99E1, "what the hell was"
    draw_text_delay SLOW_TEXT_SPEED, $9A01, "that!?"
	call WaitForAPress
	call ClearTextBox
	hide_textbox 2, HidingUnderBedTilemap

	delay_frames 240
; - play footstep sound a few times
; 
; *monster is outside looking away, before turning back, reaching out again*
; - show side view monster
	load_new_actor 1, MonsterSideViewData, MonsterSideViewDataEnd - MonsterSideViewData
	set_actor_in_middle
	delay_frames 240
; !!!!
	call ShowTextBox
	draw_text_delay FAST_TEXT_SPEED, $99E1, "!!!!"
	call WaitForAPress
	call ClearTextBox
	hide_textbox 2, HidingUnderBedTilemap
; - show forward view monster
	load_new_actor 1, MonsterFullViewData, MonsterFullViewDataEnd - MonsterFullViewData
	set_actor_in_middle
; *room mate comes home yelling about the vase*
; - dialogue with roommate sound
; hey! I'm home!
; What the hell
; 
	delay_frames 240
	
	call ShowTextBox
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "hey! i'm home!"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "what the hell"
	call WaitForAPress
	call ClearTextBox
; happened to the
; vase!?
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "happened to the"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "vase!?"
	call WaitForAPress
	call ClearTextBox
; -fade to black background
	call QuickFadeToWhite
	call HideMetasprite
	call QuickFadeFromWhite
; -hide actor
; -fade back to under bed view
; it's gone!?
; 
	draw_text_delay FAST_TEXT_SPEED, $99E1, "it's gone!?"
	call WaitForAPress
	call ClearTextBox
; -switch view to bedroom
    fade_to_new_background 2, BedroomData, BedroomDataEnd, BedroomTilemap, BedroomTilemapEnd

; -actor roommate show standing
; -transition from right into middle
	load_new_actor 1, DoeStandingData, DoeStandingDataEnd - DoeStandingData
	set_actor_pos 180, 32
	move_actor_to_pos 64, 32, 1, 1
; wait, she didn't
; see it!?
;
	call ShowTextBox
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "wait, she didn't"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "see it!?"
	call WaitForAPress
	call ClearTextBox
; -actor roommate talking
	load_new_actor 1, DoeTalkingData, DoeTalkingDataEnd - DoeTalkingData
; See what?
; A monster!?
; 
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "see what?"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "a monster!?"
	call WaitForAPress
	call ClearTextBox
; What are you
; talking about!?
	draw_text_delay NORMAL_TEXT_SPEED, $99E1, "what are you"
    draw_text_delay NORMAL_TEXT_SPEED, $9A01, "talking about!?"
	call WaitForAPress
	call ClearTextBox

	ld c, 30
	call FadeToWhite
	call HideMetasprite
	force_render_update

    ret