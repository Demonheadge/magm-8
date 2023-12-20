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
    givemon SPECIES_HATTERENE, 50, ITEM_LEFTOVERS
    setflag FLAG_SYS_POKEMON_GET
    setflag FLAG_SYS_POKEDEX_GET
    setflag FLAG_SYS_NATIONAL_DEX
    setflag FLAG_CATAS_START
    end