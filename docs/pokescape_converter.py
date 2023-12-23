# Python program to read
# json file

import json

# Opening JSON file
f = open('PokeScape.json')

# returns JSON object as 
# a dictionary
data = json.load(f)

Bloodveld_Mutated_Special_Form_Index = "399"
Runemon_Indexes = [Bloodveld_Mutated_Special_Form_Index]
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

with open('output.txt', 'w') as w:
    for Runemon_Index in Runemon_Indexes:
        w.write('    [SPECIES_' + data[NAME][Runemon_Index].upper() + '] =\n')
        w.write('    {\n        .baseHP = ' + str(data[HP][Runemon_Index]) + ',\n')
        w.write('        .baseAttack = ' + str(data[Attack][Runemon_Index]) + ',\n')
        w.write('        .baseDefense = ' + str(data[Defense][Runemon_Index]) + ',\n')
        w.write('        .baseSpeed = ' + str(data[Speed][Runemon_Index]) + ',\n')
        w.write('        .baseSpAttack = ' + str(data[Special_Attack][Runemon_Index]) + ',\n')
        w.write('        .baseSpDefense = ' + str(data[Special_Defense][Runemon_Index]) + ',\n')
        w.write('        .types = { TYPE_' + str(data[Type_1][Runemon_Index]) + ', TYPE_' + str(data[Type_2][Runemon_Index]) + ' },\n')
        w.write('        .catchRate = ' + str(data[Catch_Rate][Runemon_Index]) + ',\n')
        w.write('        .expYield = ' + str(data[Exp_Yield][Runemon_Index]) + ',\n')
        w.write('        .evYield_HP = ' + str(data[HP_EV_Yield][Runemon_Index]) + ',\n')
        w.write('        .evYield_Attack = ' + str(data[Attack_EV_Yield][Runemon_Index]) + ',\n')
        w.write('        .evYield_Defense = ' + str(data[Defense_EV_Yield][Runemon_Index]) + ',\n')
        w.write('        .evYield_Speed = ' + str(data[Speed_EV_Yield][Runemon_Index]) + ',\n')
        w.write('        .evYield_SpecialAttack = ' + str(data[Special_Attack_EV_Yield][Runemon_Index]) + ',\n')
        w.write('        .evYield_SpecialDefense = ' + str(data[Special_Defense_EV_Yield][Runemon_Index]) + ',\n')
        w.write('        .genderRatio = ' + str(data[Gender_ratio][Runemon_Index]) + ',\n')
        w.write('        .eggCycles = ' + str(data[Egg_Cycles][Runemon_Index]) + ',\n')
        w.write('        .friendship = ' + str(data[Friendship][Runemon_Index]) + ',\n')
        w.write('        .growthRate = ' + str(data[Exp_Growth][Runemon_Index]).upper().replace(' ', '_') + ',\n')
        w.write('        .eggGroups = { EGG_GROUP_' + str(data[Egg_Group_1][Runemon_Index]) + ', EGG_GROUP_' + str(data[Egg_Group_2][Runemon_Index]) + ' },\n')
        w.write('        .abilities = { ABILITY_' + str(data[Ability_1][Runemon_Index]) + ', ABILITY_' + str(data[Ability_2][Runemon_Index]) + ', ABILITY_' + str(data[Hidden_Ability][Runemon_Index]) + ' },\n')
        w.write('        .bodyColor = BODY_COLOR_BLACK,\n')

# Closing file
f.close()
w.close()