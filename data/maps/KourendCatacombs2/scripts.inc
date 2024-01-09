KourendCatacombs2_MapScripts::
	.byte 0

KourendCatacombs2_HillGiant::
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

KourendCatacombs2_Hellhound::
    lock
    faceplayer
    setwildbattle SPECIES_HELLHOUND, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs2_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs2_AbyssalDemon::
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

KourendCatacombs2_IronDragon::
    lock
    faceplayer
    setwildbattle SPECIES_SKARMORY, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs2_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs2_BronzeDragon::
    lock
    faceplayer
    setwildbattle SPECIES_NOIVERN, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs2_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs2_MutatedBloodveld::
    lock
    faceplayer
    setwildbattle SPECIES_BLOODVELD_MUTATED_SPECIAL_FORM, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs2_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs2_GreaterDemon::
    lock
    faceplayer
    setwildbattle SPECIES_DEMON_GREATER_OSRS_FORM, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs2_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs2_GreaterNechrayael::
    lock
    faceplayer
    setwildbattle SPECIES_LICKILICKY, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs2_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs2_BlackDemon::
    lock
    faceplayer
    setwildbattle SPECIES_DEMON_GREATER_BLACK_FORM, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs2_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs2_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs2_FireGiant::
    lock
    faceplayer
    setwildbattle SPECIES_EMBOAR, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs2_AnimatedPickaxe::
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

KourendCatacombs2_EventScript_RemoveStaticPokemon::
	goto Common_EventScript_RemoveStaticPokemon
	end