RustboroCity_PokemonSchool_MapScripts::
	.byte 0

@ Hunter Guild, Rustboro Branch
@ VAR_UNUSED_0x409B tracks the ladder: 0-3 = next fighter index, 4 = ladder clear, 5 = rewarded

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	compare VAR_UNUSED_0x409B, 4
	goto_if_eq RustboroCity_PokemonSchool_EventScript_TeacherReward
	compare VAR_UNUSED_0x409B, 5
	goto_if_eq RustboroCity_PokemonSchool_EventScript_TeacherDone
	msgbox RustboroCity_PokemonSchool_Text_ReceptionistIntro, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherReward::
	msgbox RustboroCity_PokemonSchool_Text_ReceptionistReward, MSGBOX_DEFAULT
	giveitem ITEM_TM39
	setvar VAR_UNUSED_0x409B, 5
	msgbox RustboroCity_PokemonSchool_Text_ReceptionistMasterAway, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherDone::
	msgbox RustboroCity_PokemonSchool_Text_ReceptionistMasterAway, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	lock
	faceplayer
	compare VAR_UNUSED_0x409B, 0
	goto_if_eq RustboroCity_PokemonSchool_EventScript_Fighter1Battle
	msgbox RustboroCity_PokemonSchool_Text_Fighter1Beaten, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_Fighter1Battle::
	msgbox RustboroCity_PokemonSchool_Text_Fighter1Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GUILD_ROOKIE, RustboroCity_PokemonSchool_Text_Fighter1Defeat
	setvar VAR_UNUSED_0x409B, 1
	msgbox RustboroCity_PokemonSchool_Text_Fighter1After, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	lock
	faceplayer
	compare VAR_UNUSED_0x409B, 1
	goto_if_eq RustboroCity_PokemonSchool_EventScript_Fighter2Battle
	compare VAR_UNUSED_0x409B, 1
	goto_if_lt RustboroCity_PokemonSchool_EventScript_Fighter2Wait
	msgbox RustboroCity_PokemonSchool_Text_Fighter2Beaten, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_Fighter2Wait::
	msgbox RustboroCity_PokemonSchool_Text_FighterWaitTurn, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_Fighter2Battle::
	msgbox RustboroCity_PokemonSchool_Text_Fighter2Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GUILD_SCRAPPER, RustboroCity_PokemonSchool_Text_Fighter2Defeat
	setvar VAR_UNUSED_0x409B, 2
	msgbox RustboroCity_PokemonSchool_Text_Fighter2After, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	lock
	faceplayer
	compare VAR_UNUSED_0x409B, 2
	goto_if_eq RustboroCity_PokemonSchool_EventScript_Fighter3Battle
	compare VAR_UNUSED_0x409B, 2
	goto_if_lt RustboroCity_PokemonSchool_EventScript_Fighter3Wait
	msgbox RustboroCity_PokemonSchool_Text_Fighter3Beaten, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_Fighter3Wait::
	msgbox RustboroCity_PokemonSchool_Text_FighterWaitTurn, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_Fighter3Battle::
	msgbox RustboroCity_PokemonSchool_Text_Fighter3Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GUILD_TACTICIAN, RustboroCity_PokemonSchool_Text_Fighter3Defeat
	setvar VAR_UNUSED_0x409B, 3
	msgbox RustboroCity_PokemonSchool_Text_Fighter3After, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	lock
	faceplayer
	compare VAR_UNUSED_0x409B, 3
	goto_if_eq RustboroCity_PokemonSchool_EventScript_Fighter4Battle
	compare VAR_UNUSED_0x409B, 3
	goto_if_lt RustboroCity_PokemonSchool_EventScript_Fighter4Wait
	msgbox RustboroCity_PokemonSchool_Text_Fighter4Beaten, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_Fighter4Wait::
	msgbox RustboroCity_PokemonSchool_Text_FighterWaitTurn, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_Fighter4Battle::
	msgbox RustboroCity_PokemonSchool_Text_Fighter4Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GUILD_VETERAN, RustboroCity_PokemonSchool_Text_Fighter4Defeat
	setvar VAR_UNUSED_0x409B, 4
	msgbox RustboroCity_PokemonSchool_Text_Fighter4After, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox RustboroCity_PokemonSchool_Text_InfoClerk, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	addvar VAR_UNUSED_0x4091, 1
	msgbox RustboroCity_PokemonSchool_Text_Outfitter, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_LadderRules, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_PokemonSchool_Text_LadderRules:
	.string "Chalked on the board:\p"
	.string "LADDER RULES. Challenge in\n"
	.string "order. No items mid-bout.\l"
	.string "Rank is earned, never given.$"

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_GuildCharter, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_PokemonSchool_Text_ReceptionistIntro:
	.string "Hunter Guild, GUILDSTONE main hall.\p"
	.string "Four ranked fighters hold this\n"
	.string "floor. Beat them in order-\l"
	.string "Rank V first.\p"
	.string "Clear the ladder and the Guild\n"
	.string "will recognize your rank, Hunter.$"

RustboroCity_PokemonSchool_Text_ReceptionistReward:
	.string "Ladder clear!\p"
	.string "By Guild charter, you now hold\n"
	.string "Rank II in GUILDSTONE.\p"
	.string "Your issue: TM39 Rock Tomb.$"

RustboroCity_PokemonSchool_Text_ReceptionistMasterAway:
	.string "The Guild Master's seat is empty-\n"
	.string "she's out ranging the far routes.\p"
	.string "Champions travel. You'll meet her\n"
	.string "on the road, Rank II.$"

RustboroCity_PokemonSchool_Text_Fighter1Intro:
	.string "Rank V. Nobody skips me.$"

RustboroCity_PokemonSchool_Text_Fighter1Defeat:
	.string "Clean hit…!$"

RustboroCity_PokemonSchool_Text_Fighter1After:
	.string "You fight like a ranger.\n"
	.string "Rank IV is by the shelves.$"

RustboroCity_PokemonSchool_Text_Fighter1Beaten:
	.string "Go on. The ladder's waiting.$"

RustboroCity_PokemonSchool_Text_Fighter2Intro:
	.string "Rank IV. My migrants hit harder\n"
	.string "than anything native.$"

RustboroCity_PokemonSchool_Text_Fighter2Defeat:
	.string "Harder than mine…$"

RustboroCity_PokemonSchool_Text_Fighter2After:
	.string "Rank III dresses rich but\n"
	.string "battles mean.$"

RustboroCity_PokemonSchool_Text_Fighter2Beaten:
	.string "I want a rematch someday.\n"
	.string "Victory Road, maybe.$"

RustboroCity_PokemonSchool_Text_Fighter3Intro:
	.string "Rank III. I bought the best\n"
	.string "migrants money can catch.$"

RustboroCity_PokemonSchool_Text_Fighter3Defeat:
	.string "Money can't buy that…$"

RustboroCity_PokemonSchool_Text_Fighter3After:
	.string "Rank II is the strongest\n"
	.string "fighter on this floor. Careful.$"

RustboroCity_PokemonSchool_Text_Fighter3Beaten:
	.string "I'm restocking my roster.\n"
	.string "See you on Victory Road.$"

RustboroCity_PokemonSchool_Text_Fighter4Intro:
	.string "Rank II. Last rung before\n"
	.string "the Master's seat.\p"
	.string "Show me exam form-set rules,\n"
	.string "no coaching.$"

RustboroCity_PokemonSchool_Text_Fighter4Defeat:
	.string "…That's rank-worthy.$"

RustboroCity_PokemonSchool_Text_Fighter4After:
	.string "Report to the receptionist.\n"
	.string "The Guild owes you a rank.$"

RustboroCity_PokemonSchool_Text_Fighter4Beaten:
	.string "Rank II is yours now.\n"
	.string "Wear it well, Hunter.$"

RustboroCity_PokemonSchool_Text_FighterWaitTurn:
	.string "Ladder rules: lower ranks first.$"

RustboroCity_PokemonSchool_Text_InfoClerk:
	.string "Guild intel, free of charge:\p"
	.string "ROXANNE wards this city's exams.\n"
	.string "Level cap 15 until you pass her.\p"
	.string "Half the wild migrants around here\n"
	.string "punish Rock. Hunt smart.$"

RustboroCity_PokemonSchool_Text_Outfitter:
	.string "Guild outfitter!\p"
	.string "I've issued you the next uniform\n"
	.string "color-six in rotation.\p"
	.string "It shows the moment you step\n"
	.string "through a door.$"

RustboroCity_PokemonSchool_Text_LensDisabled:
	.string "You adjust the region lens.\p"
	.string "True colors restored-the sepia\n"
	.string "glow fades as you travel on.$"

RustboroCity_PokemonSchool_Text_LensEnabled:
	.string "You adjust the region lens.\p"
	.string "Sun-kissed sepia returns-\n"
	.string "Hoenn's evening glow.$"

RustboroCity_PokemonSchool_Text_GuildCharter:
	.string "GUILD CHARTER, Article I:\p"
	.string "Hunters catch, catalog, and\n"
	.string "relocate. We never harm.\p"
	.string "Article II: exam battles are\n"
	.string "set format. No mid-turn coaching.$"
