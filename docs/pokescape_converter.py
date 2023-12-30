# Python program to read
# json file

import json
import textwrap

wrapper = textwrap.TextWrapper(width=37)

# Opening JSON file
f = open('PokeScape.json')
f2 = open('PokeScape_Dex.json')
f3 = open('PokeScape_Evos.json')

# returns JSON object as 
# a dictionary
data = json.load(f)
data2 = json.load(f2)
data3 = json.load(f3)

Bloodveld_Mutated_Special_Form_Index = "399"
Demon_Lesser_OSRS_Form = "697"
Jelly_Normal_Form = "384"
Abyssal_Minion_Form = "270"
Giant_Rat_Crypt_Form = "59"
Hellhound = "150"
Bloodveld_Insatiable_Physical_Form = "396"
Bloodveld_Insatiable_Special_Form = "397"
Demon_Greater_OSRS_Form = "698"
Abyssal_Demon_Form = "271"
Basilisk_OSRS_Form = "754"
Cockatrice = "254"
Demon_Greater_Black_Form = "708"
Runemon_Indexes = [Bloodveld_Mutated_Special_Form_Index, Demon_Lesser_OSRS_Form, Jelly_Normal_Form, Abyssal_Minion_Form, Giant_Rat_Crypt_Form, Hellhound, Bloodveld_Insatiable_Physical_Form, Bloodveld_Insatiable_Special_Form, Demon_Greater_OSRS_Form, Abyssal_Demon_Form, Basilisk_OSRS_Form, Cockatrice, Demon_Greater_Black_Form]
NAME = 0
Type_1 = 1
Type_2 = 2
Ability_1 = 3
Ability_2 = 4
Hidden_Ability = 5
Stats_Total = 7
HP = 8
Attack = 9
Defense = 10
Special_Attack = 11
Special_Defense = 12
Speed = 13
Held_Item_1 = 15
Held_Item_2 = 16
Exp_Yield = 17
Exp_Growth = 18
Gender_ratio = 19
Catch_Rate = 20
Friendship = 21
Egg_Cycles = 22
Egg_Group_1 = 23
Egg_Group_2 = 24
Flee_Rate = 25
HP_EV_Yield = 27
Attack_EV_Yield = 28
Defense_EV_Yield = 29
Special_Attack_EV_Yield = 30
Special_Defense_EV_Yield = 31
Speed_EV_Yield = 32
Pokedex_Number = 34
Footprint = 35
Egg_Steps = 36
FAMILY_LINE = 37
INGAME_NAME = 38

NAME_DEX = 0
DEX_ENTRY_DEX = 1
HEIGHT_DEX = 2
WEIGHT_DEX = 3
DEX_NUMBER_DEX = 4
CATEGORY_DEX = 5
COUNT_DEX = 6
Creature_in_RuneScape_DEX = 7

with open('output.txt', 'w') as w:
    for Runemon_Index in Runemon_Indexes:
        w.write('    [SPECIES_' + data[NAME][Runemon_Index].upper() + '] =\n')
        w.write('    {\n        .baseHP = ' + str(data[HP][Runemon_Index]) + ',\n')
        w.write('        .baseAttack = ' + str(data[Attack][Runemon_Index]) + ',\n')
        w.write('        .baseDefense = ' + str(data[Defense][Runemon_Index]) + ',\n')
        w.write('        .baseSpeed = ' + str(data[Speed][Runemon_Index]) + ',\n')
        w.write('        .baseSpAttack = ' + str(data[Special_Attack][Runemon_Index]) + ',\n')
        w.write('        .baseSpDefense = ' + str(data[Special_Defense][Runemon_Index]) + ',\n')
        type2 = data[Type_2][Runemon_Index]
        if type2 == "0":
            type2 = data[Type_1][Runemon_Index]
        w.write('        .types = { TYPE_' + str(data[Type_1][Runemon_Index]) + ', TYPE_' + str(type2) + ' },\n')
        w.write('        .catchRate = ' + str(data[Catch_Rate][Runemon_Index]) + ',\n')
        w.write('        .expYield = ' + str(data[Exp_Yield][Runemon_Index]) + ',\n')
        w.write('        .evYield_HP = ' + str(data[HP_EV_Yield][Runemon_Index]) + ',\n')
        w.write('        .evYield_Attack = ' + str(data[Attack_EV_Yield][Runemon_Index]) + ',\n')
        w.write('        .evYield_Defense = ' + str(data[Defense_EV_Yield][Runemon_Index]) + ',\n')
        w.write('        .evYield_Speed = ' + str(data[Speed_EV_Yield][Runemon_Index]) + ',\n')
        w.write('        .evYield_SpAttack = ' + str(data[Special_Attack_EV_Yield][Runemon_Index]) + ',\n')
        w.write('        .evYield_SpDefense = ' + str(data[Special_Defense_EV_Yield][Runemon_Index]) + ',\n')
        w.write('        .genderRatio = PERCENT_FEMALE(' + str(data[Gender_ratio][Runemon_Index]) + '),\n')
        w.write('        .eggCycles = ' + str(data[Egg_Cycles][Runemon_Index]) + ',\n')
        w.write('        .friendship = ' + str(data[Friendship][Runemon_Index]) + ',\n')
        w.write('        .growthRate = GROWTH_' + str(data[Exp_Growth][Runemon_Index]).upper().replace(' ', '_') + ',\n')
        eggGroup2 = data[Egg_Group_2][Runemon_Index]
        if eggGroup2 == "0":
            eggGroup2 = data[Egg_Group_1][Runemon_Index]
        w.write('        .eggGroups = { EGG_GROUP_' + str(data[Egg_Group_1][Runemon_Index]) + ', EGG_GROUP_' + str(eggGroup2) + ' },\n')
        w.write('        .abilities = { ABILITY_' + str(data[Ability_1][Runemon_Index]) + ', ABILITY_' + str(data[Ability_2][Runemon_Index]) + ', ABILITY_' + str(data[Hidden_Ability][Runemon_Index]) + ' },\n')
        w.write('        .bodyColor = BODY_COLOR_BLACK,\n')
        w.write('        .speciesName = _("' + data[NAME][Runemon_Index].replace('_', ' ') + '"),\n')
        w.write('        .cryId = CRY_BULBASAUR,\n')
        w.write('        .natDexNum = NATIONAL_DEX_' + data[NAME][Runemon_Index].upper() + ',\n')
        w.write('        .categoryName = _("' + data2[CATEGORY_DEX][Runemon_Index] + '"),\n')
        w.write('        .height = ' + str(data2[HEIGHT_DEX][Runemon_Index]) + ',\n')
        w.write('        .weight = ' + str(data2[WEIGHT_DEX][Runemon_Index]) + ',\n')
        description = wrapper.fill(text=data2[DEX_ENTRY_DEX][Runemon_Index])
        w.write('        .description = COMPOUND_STRING(' + repr(description) + '),\n')
        w.write('        .pokemonScale = 256,\n')
        w.write('        .pokemonOffset = 0,\n')
        w.write('        .trainerScale = 256,\n')
        w.write('        .trainerOffset = 0,\n')
        w.write('        FRONT_PIC(' + data[NAME][Runemon_Index] + ', 64, 64),\n')
        w.write('        .frontPicYOffset = 0,\n')
        w.write('        .frontAnimFrames = sAnims_None,\n')
        w.write('        .enemyMonElevation = 0,\n')
        w.write('        BACK_PIC(' + data[NAME][Runemon_Index] + ', 64, 64),\n')
        w.write('        .backPicYOffset = 0,\n')
        w.write('        .backAnimId = BACK_ANIM_NONE,\n')
        w.write('        PALETTES(' + data[NAME][Runemon_Index] + '),\n')
        w.write('        ICON(' + data[NAME][Runemon_Index] + ', 0),\n')
        w.write('        LEARNSETS(' + data[NAME][Runemon_Index] + '),\n')
        w.write('    },\n')

num = -100

with open('pokedex.ts', 'w') as w2:
	w2.write('export const Pokedex: {[speciesid: string]: SpeciesData} = {\n')
	for Runemon_Index in range(1, len(data2[0])):
		Runemon_Index = str(Runemon_Index)
		w2.write('	' + data[NAME][Runemon_Index].lower().replace('_', '') + ': \n')
		w2.write('	{\n		num: ' + str(num) + ',\n')
		w2.write('		name: "' + data[NAME][Runemon_Index].replace('_', ' ') + '",\n')
		w2.write('		baseStats: {')
		w2.write('hp: ' + str(data[HP][Runemon_Index]) + ', ')
		w2.write('atk: ' + str(data[Attack][Runemon_Index]) + ', ')
		w2.write('def: ' + str(data[Defense][Runemon_Index]) + ', ')
		w2.write('spa: ' + str(data[Special_Attack][Runemon_Index]) + ', ')
		w2.write('spd: ' + str(data[Special_Defense][Runemon_Index]) + ', ')
		w2.write('spe: ' + str(data[Speed][Runemon_Index]) + '},\n')
		type2 = data[Type_2][Runemon_Index]
		if type2 == "0":
			type2 = data[Type_1][Runemon_Index]
		w2.write('		types: ["' + str(data[Type_1][Runemon_Index].title()))
		if type2 != data[Type_1][Runemon_Index]:
			w2.write('", "' + str(type2).title())
		w2.write('"],\n')
		# w2.write('		.genderRatio = PERCENT_FEMALE(' + str(data[Gender_ratio][Runemon_Index]) + '),\n')
		# eggGroup2 = data[Egg_Group_2][Runemon_Index]
		# if eggGroup2 == "0":
			# eggGroup2 = data[Egg_Group_1][Runemon_Index]
		# w2.write('		.eggGroups = { EGG_GROUP_' + str(data[Egg_Group_1][Runemon_Index]) + ', EGG_GROUP_' + str(eggGroup2) + ' },\n')
		w2.write('		abilities: {0: "' + str(data[Ability_1][Runemon_Index].replace('_', ' ').title()) + '", 1: "' + str(data[Ability_2][Runemon_Index].replace('_', ' ').title()) + '", H: "' + str(data[Hidden_Ability][Runemon_Index].replace('_', ' ').title()) + '"},\n')
		w2.write('		weight: ' + str(data2[WEIGHT_DEX][Runemon_Index]) + ',\n')
		w2.write('	},\n')
		num = num - 1

# Closing file
f.close()
f2.close()
f3.close()
w.close()
w2.close()