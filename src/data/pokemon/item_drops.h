static const struct ItemDrops sBloodveldMDrops[] = 
{
    {ITEM_CHOPLE_BERRY, 25},
    {ITEM_SHUCA_BERRY, 25},
    {ITEM_LIFE_ORB, 25},
    {ITEM_EXPERT_BELT, 25},
};

static const struct ItemDrops sMetagrossDrops[] = 
{
    {ITEM_LIFE_ORB, 25},
    {ITEM_EXPERT_BELT, 25},
    {ITEM_CHOPLE_BERRY, 25},
    {ITEM_SHUCA_BERRY, 25},
};

const struct ItemDropSpecies gItemDropSpecies[] = {
    [SPECIES_BLOODVELD_MUTATED_SPECIAL_FORM] = {
        .drops = sBloodveldMDrops,
        .dropCount = 4,
        .numDropsLower = 4,
        .numDropsUpper = 4,
    },
    [SPECIES_METAGROSS] = {
        .drops = sMetagrossDrops,
        .dropCount = 4,
        .numDropsLower = 4,
        .numDropsUpper = 4,
    },
};