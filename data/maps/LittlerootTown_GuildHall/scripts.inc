LittlerootTown_GuildHall_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_GuildHall_OnTransition
	.byte 0

LittlerootTown_GuildHall_OnTransition:
	call_if_set FLAG_UNUSED_0x26C, HunterGuildHall_EventScript_KiraGoneFlag
	call_if_set FLAG_UNUSED_0x26D, HunterGuildHall_EventScript_KiraGoneFlag
	end

HunterGuildHall_EventScript_KiraGoneFlag::
	setflag FLAG_UNUSED_0x26B
	return

@ Standings board: reads ladder var + Kira result for live-ish rankings
HunterGuildHall_EventScript_Leaderboard::
	lockall
	goto_if_set FLAG_UNUSED_0x26D, HunterGuildHall_EventScript_BoardBeatKira
	goto_if_eq VAR_UNUSED_0x40A1, 0, HunterGuildHall_EventScript_BoardFresh
	goto_if_eq VAR_UNUSED_0x40A1, 1, HunterGuildHall_EventScript_BoardMid
	msgbox HunterGuildHall_Text_BoardClear, MSGBOX_DEFAULT
	releaseall
	end

HunterGuildHall_EventScript_BoardFresh::
	msgbox HunterGuildHall_Text_BoardFresh, MSGBOX_DEFAULT
	releaseall
	end

HunterGuildHall_EventScript_BoardMid::
	msgbox HunterGuildHall_Text_BoardMid, MSGBOX_DEFAULT
	releaseall
	end

HunterGuildHall_EventScript_BoardBeatKira::
	msgbox HunterGuildHall_Text_BoardBeatKira, MSGBOX_DEFAULT
	releaseall
	end

HunterGuildHall_Text_BoardFresh:
	.string "DRAGONFALL BRANCH STANDINGS\p"
	.string "1. KIRA - officer, unbeaten\n"
	.string "2. REY - Rank IV\l"
	.string "3. TOMAS - Rank V\p"
	.string "{PLAYER}: unranked.\n"
	.string "Clear the floor to be listed.$"

HunterGuildHall_Text_BoardMid:
	.string "DRAGONFALL BRANCH STANDINGS\p"
	.string "1. KIRA - officer, unbeaten\n"
	.string "2. REY - Rank IV\l"
	.string "3. {PLAYER} - climbing\l"
	.string "4. TOMAS - beaten\p"
	.string "One fighter left.$"

HunterGuildHall_Text_BoardClear:
	.string "DRAGONFALL BRANCH STANDINGS\p"
	.string "1. KIRA - officer, unbeaten\n"
	.string "2. {PLAYER} - RANK III, floor clear\l"
	.string "3. REY - beaten\l"
	.string "4. TOMAS - beaten\p"
	.string "Challenge KIRA on ROUTE 103\n"
	.string "to take the top slot.$"

HunterGuildHall_Text_BoardBeatKira:
	.string "DRAGONFALL BRANCH STANDINGS\p"
	.string "1. {PLAYER} - TOP BLADE\n"
	.string "2. KIRA - officer\l"
	.string "3. REY  4. TOMAS\p"
	.string "The GUILDSTONE main hall ladder\n"
	.string "awaits the branch champion.$"
