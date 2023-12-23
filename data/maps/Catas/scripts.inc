Catas_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, Catas_OnTransition
	.byte 0

Catas_OnTransition:
    goto_if_unset FLAG_CATAS_START, Catas_Start
    end

Catas_Start:
    givemon SPECIES_AEGISLASH, 50, ITEM_LEFTOVERS
    givemon SPECIES_BLAZIKEN, 50, ITEM_LEFTOVERS
    givemon SPECIES_GARGANACL, 50, ITEM_LEFTOVERS
    givemon SPECIES_DECIDUEYE, 50, ITEM_LEFTOVERS
    givemon SPECIES_BLISSEY, 50, ITEM_LEFTOVERS
    // givemon SPECIES_HATTERENE, 50, ITEM_LEFTOVERS
    setflag FLAG_SYS_POKEMON_GET
    setflag FLAG_SYS_POKEDEX_GET
    special EnableNationalPokedex
    additem ITEM_MASTER_BALL
    setflag FLAG_CATAS_START
    end

Catas_HillGiant::
    lock
    faceplayer
    setwildbattle SPECIES_PANGORO, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Catas_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Catas_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Catas_EventScript_RemoveStaticPokemon
	release
	end

Catas_Skeleton::
    lock
    faceplayer
    setwildbattle SPECIES_DUSKULL, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Catas_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Catas_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Catas_EventScript_RemoveStaticPokemon
	release
	end

Catas_EventScript_RemoveStaticPokemon::
	goto Common_EventScript_RemoveStaticPokemon
	end