KourendCatacombs7_MapScripts::
	.byte 0

KourendCatacombs7_BlackDemon::
    lock
    faceplayer
    setwildbattle SPECIES_DEMON_GREATER_BLACK_FORM, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs7_EventScript_RemoveStaticPokemon::
	goto Common_EventScript_RemoveStaticPokemon
	end