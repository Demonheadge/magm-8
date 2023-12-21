static const struct ItemDrops sTyranitarDrops[] = 
{
    {ITEM_CHOPLE_BERRY, 50},
    {ITEM_SHUCA_BERRY, 50},
};

const struct ItemDropSpecies gItemDropSpecies[] = {
    [SPECIES_TYRANITAR] = {
        .drops = sTyranitarDrops,
        .dropCount = 2,
        .numDropsLower = 1,
        .numDropsUpper = 2,
    },
};