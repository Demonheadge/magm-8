CrystalCave_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, CrystalCave_OnTransition
	.byte 0

CrystalCave_OnTransition:
    goto_if_unset FLAG_CATAS_START, CrystalCave_Start
    end

CrystalCave_Start:
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