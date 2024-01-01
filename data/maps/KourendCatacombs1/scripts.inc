KourendCatacombs1_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, KourendCatacombs1_OnTransition
	.byte 0

KourendCatacombs1_OnTransition:
    goto_if_unset FLAG_CATAS_START, KourendCatacombs1_Start
    end

KourendCatacombs1_Start:
    givemon SPECIES_AEGISLASH, 50, ITEM_LEFTOVERS
    givemon SPECIES_BLAZIKEN, 50, ITEM_LEFTOVERS
    givemon SPECIES_GARGANACL, 50, ITEM_LEFTOVERS
    givemon SPECIES_DECIDUEYE, 50, ITEM_LEFTOVERS
    givemon SPECIES_BLISSEY, 50, ITEM_LEFTOVERS
    // givemon SPECIES_HATTERENE, 50, ITEM_LEFTOVERS
    setflag FLAG_SYS_POKEMON_GET
    setflag FLAG_SYS_POKEDEX_GET
    special EnableNationalPokedex
    setflag FLAG_SYS_FRONTIER_PASS
    additem ITEM_MASTER_BALL
    setflag FLAG_SYS_QUEST_MENU_GET
    setflag FLAG_CATAS_START
    end

KourendCatacombs1_Nieve::
    lock
    faceplayer
    goto_if_quest_reward QUEST_1, KourendCatacombs1_GiveSlayerPointsAbyssalDemons
    goto_if_quest_reward QUEST_1, KourendCatacombs1_GiveSlayerPointsBlackDemons
    goto_if_quest_reward QUEST_1, KourendCatacombs1_GiveSlayerPointsGreaterDemons
    goto_if_quest_reward QUEST_1, KourendCatacombs1_GiveSlayerPointsGreaterNechrayael
    questmenu QUEST_MENU_SET_INACTIVE QUEST_1
    questmenu QUEST_MENU_SET_INACTIVE QUEST_2
    questmenu QUEST_MENU_SET_INACTIVE QUEST_3
    questmenu QUEST_MENU_SET_INACTIVE QUEST_4
    random 4
    switch VAR_RESULT
    case 0, KourendCatacombs1_AssignAbyssalDemons
    case 1, KourendCatacombs1_AssignBlackDemons
    case 2, KourendCatacombs1_AssignGreaterDemons
    case 3, KourendCatacombs1_AssignGreaterNechrayael
    release
    end

KourendCatacombs1_AssignAbyssalDemons::
    setflag FLAG_ABYSSAL_DEMONS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_1
    msgbox KourendCatacombs1_Text_AssignedAbyssalDemons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignBlackDemons::
    setflag FLAG_BLACK_DEMONS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_2
    msgbox KourendCatacombs1_Text_AssignedBlackDemons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignGreaterDemons::
    setflag FLAG_GREATER_DEMONS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_3
    msgbox KourendCatacombs1_Text_AssignedGreaterDemons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignGreaterNechrayael::
    setflag FLAG_GREATER_NECHRAYAEL
    random 4
    addvar VAR_RESULT, 4
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_4
    msgbox KourendCatacombs1_Text_AssignedGreaterNechrayael, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_GiveSlayerPointsAbyssalDemons::
    clearflag FLAG_ABYSSAL_DEMONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_1
    release
    end

KourendCatacombs1_GiveSlayerPointsBlackDemons::
    clearflag FLAG_BLACK_DEMONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_2
    release
    end

KourendCatacombs1_GiveSlayerPointsGreaterDemons::
    clearflag FLAG_GREATER_DEMONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_3
    release
    end

KourendCatacombs1_GiveSlayerPointsGreaterNechrayael::
    clearflag FLAG_GREATER_NECHRAYAEL
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_4
    release
    end

KourendCatacombs1_Text_ObtainedXSlayerPoints::
	.string "{PLAYER} obtained {STR_VAR_1} Slayer Point(s).$"

KourendCatacombs1_Text_AssignedAbyssalDemons::
	.string "You have been assigned {STR_VAR_1}\nAbyssal Demons.$"

KourendCatacombs1_Text_AssignedBlackDemons::
	.string "You have been assigned {STR_VAR_1}\nBlack Demons.$"

KourendCatacombs1_Text_AssignedGreaterDemons::
	.string "You have been assigned {STR_VAR_1}\nGreater Demons.$"

KourendCatacombs1_Text_AssignedGreaterNechrayael::
	.string "You have been assigned {STR_VAR_1}\nGreater Nechrayael.$"

KourendCatacombs1_HillGiant::
    lock
    faceplayer
    setwildbattle SPECIES_PANGORO, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs1_Skeleton::
    lock
    faceplayer
    setwildbattle SPECIES_DUSKULL, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs1_Cyclops::
    lock
    faceplayer
    setwildbattle SPECIES_DUSCLOPS, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs1_Ghost::
    lock
    faceplayer
    setwildbattle SPECIES_FROSLASS, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs1_AbyssalDemon::
    lock
    faceplayer
    setwildbattle SPECIES_ABYSSAL_DEMON_FORM, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs1_MagicAxe::
    lock
    faceplayer
    setwildbattle SPECIES_SPOOKAXE, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs1_EventScript_RemoveStaticPokemon::
	goto Common_EventScript_RemoveStaticPokemon
	end