static const struct ItemDrops sTyranitarDrops[] = 
{
    {ITEM_CHOPLE_BERRY, 50},
    {ITEM_SHUCA_BERRY, 50},
};

static const struct ItemDrops sMetagrossDrops[] = 
{
    {ITEM_LIFE_ORB, 50},
    {ITEM_EXPERT_BELT, 50},
};

const struct ItemDropSpecies gItemDropSpecies[] = {
    [SPECIES_TYRANITAR] = {
        .drops = sTyranitarDrops,
        .dropCount = 2,
        .numDropsLower = 1,
        .numDropsUpper = 2,
    },
    [SPECIES_METAGROSS] = {
        .drops = sMetagrossDrops,
        .dropCount = 2,
        .numDropsLower = 1,
        .numDropsUpper = 2,
    },
};