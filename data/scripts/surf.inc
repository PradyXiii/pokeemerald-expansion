@ Hunter: the hover board glides over water - surf without an HM.
EventScript_UseSurf::
	lockall
	setfieldeffectargument 0, 0
	goto_if_set FLAG_UNUSED_0x270, EventScript_HunterGlideAsk
	setflag FLAG_UNUSED_0x270
	msgbox HunterBoard_Text_GlideFirstTime, MSGBOX_DEFAULT
EventScript_HunterGlideAsk::
	msgbox HunterBoard_Text_WantToGlide, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
	msgbox HunterBoard_Text_BoardGlides, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end

HunterBoard_Text_GlideFirstTime:
	.string "The HOVER BOARD hums over the\n"
	.string "waterline.\p"
	.string "Its field can carry you across\n"
	.string "open water.$"

HunterBoard_Text_WantToGlide:
	.string "Glide out on the HOVER BOARD?$"

HunterBoard_Text_BoardGlides:
	.string "{PLAYER} kicked the HOVER BOARD\n"
	.string "onto the water!$"


EventScript_CurrentTooFast::
	lockall
	checkfieldmove FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, FALSE, EventScript_CurrentTooFastEndMsg
	playse SE_SELECT
	msgbox Text_CurrentTooFast
EventScript_CurrentTooFastEndMsg::
	releaseall
	end
