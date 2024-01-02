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
    setflag FLAG_SYS_B_DASH
    setflag FLAG_SYS_QUEST_MENU_GET
    setflag FLAG_CATAS_START
    end

KourendCatacombs1_Nieve::
    lock
    faceplayer
    goto_if_quest_reward QUEST_1, KourendCatacombs1_GiveSlayerPointsAbyssalDemons
    goto_if_quest_reward QUEST_2, KourendCatacombs1_GiveSlayerPointsBlackDemons
    goto_if_quest_reward QUEST_3, KourendCatacombs1_GiveSlayerPointsGreaterDemons
    goto_if_quest_reward QUEST_4, KourendCatacombs1_GiveSlayerPointsGreaterNechrayael
    goto_if_quest_reward QUEST_5, KourendCatacombs1_GiveSlayerPointsMutatedBloodvelds
    goto_if_quest_reward QUEST_6, KourendCatacombs1_GiveSlayerPointsBlackDragons
    goto_if_quest_reward QUEST_7, KourendCatacombs1_GiveSlayerPointsBlueDragons
    goto_if_quest_reward QUEST_8, KourendCatacombs1_GiveSlayerPointsRedDragons
    goto_if_quest_reward QUEST_9, KourendCatacombs1_GiveSlayerPointsFireGiants
    questmenu QUEST_MENU_SET_INACTIVE QUEST_1
    questmenu QUEST_MENU_SET_INACTIVE QUEST_2
    questmenu QUEST_MENU_SET_INACTIVE QUEST_3
    questmenu QUEST_MENU_SET_INACTIVE QUEST_4
    questmenu QUEST_MENU_SET_INACTIVE QUEST_5
    questmenu QUEST_MENU_SET_INACTIVE QUEST_6
    questmenu QUEST_MENU_SET_INACTIVE QUEST_7
    questmenu QUEST_MENU_SET_INACTIVE QUEST_8
    questmenu QUEST_MENU_SET_INACTIVE QUEST_9
    random 9
    switch VAR_RESULT
    case 0, KourendCatacombs1_AssignAbyssalDemons
    case 1, KourendCatacombs1_AssignBlackDemons
    case 2, KourendCatacombs1_AssignGreaterDemons
    case 3, KourendCatacombs1_AssignGreaterNechrayael
    case 4, KourendCatacombs1_AssignMutatedBloodvelds
    case 5, KourendCatacombs1_AssignBlackDragons
    case 6, KourendCatacombs1_AssignBlueDragons
    case 7, KourendCatacombs1_AssignRedDragons
    case 8, KourendCatacombs1_AssignFireGiants
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

KourendCatacombs1_AssignMutatedBloodvelds::
    setflag FLAG_MUTATED_BLOODVELDS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_5
    msgbox KourendCatacombs1_Text_AssignedMutatedBloodvelds, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignBlackDragons::
    setflag FLAG_BLACK_DRAGONS
    random 2
    addvar VAR_RESULT, 1
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_6
    msgbox KourendCatacombs1_Text_AssignedBlackDragons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignBlueDragons::
    setflag FLAG_BLUE_DRAGONS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_7
    msgbox KourendCatacombs1_Text_AssignedBlueDragons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignRedDragons::
    setflag FLAG_RED_DRAGONS
    random 3
    addvar VAR_RESULT, 2
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_8
    msgbox KourendCatacombs1_Text_AssignedRedDragons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignFireGiants::
    setflag FLAG_FIRE_GIANTS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_9
    msgbox KourendCatacombs1_Text_AssignedFireGiants, MSGBOX_DEFAULT
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

KourendCatacombs1_GiveSlayerPointsMutatedBloodvelds::
    clearflag FLAG_MUTATED_BLOODVELDS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_5
    release
    end

KourendCatacombs1_GiveSlayerPointsBlackDragons::
    clearflag FLAG_BLACK_DRAGONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_6
    release
    end

KourendCatacombs1_GiveSlayerPointsBlueDragons::
    clearflag FLAG_BLUE_DRAGONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_7
    release
    end

KourendCatacombs1_GiveSlayerPointsRedDragons::
    clearflag FLAG_RED_DRAGONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_8
    release
    end

KourendCatacombs1_GiveSlayerPointsFireGiants::
    clearflag FLAG_FIRE_GIANTS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_9
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

KourendCatacombs1_Text_AssignedMutatedBloodvelds::
	.string "You have been assigned {STR_VAR_1}\nMutated Bloodvelds.$"

KourendCatacombs1_Text_AssignedBlackDragons::
	.string "You have been assigned {STR_VAR_1}\nBrutal Black Dragons.$"

KourendCatacombs1_Text_AssignedBlueDragons::
	.string "You have been assigned {STR_VAR_1}\nBrutal Blue Dragons.$"

KourendCatacombs1_Text_AssignedRedDragons::
	.string "You have been assigned {STR_VAR_1}\nBrutal Red Dragons.$"

KourendCatacombs1_Text_AssignedFireGiants::
	.string "You have been assigned {STR_VAR_1}\nFire Giants.$"

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