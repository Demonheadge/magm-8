#include "global.h"
#include "heal_location.h"
#include "constants/heal_locations.h"

#include "data/heal_locations.h"

u32 GetHealLocationIndexByMap(u16 mapGroup, u16 mapNum)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sSpawnPoints); i++)
    {
        if (sSpawnPoints[i].group == mapGroup && sSpawnPoints[i].map == mapNum)
            return i + 1;
    }
    return HEAL_LOCATION_NONE;
}

const struct HealLocation *GetHealLocationByMap(u16 mapGroup, u16 mapNum)
{
    u32 index = GetHealLocationIndexByMap(mapGroup, mapNum);

    if (index == HEAL_LOCATION_NONE)
        return NULL;
    else
        return &sSpawnPoints[index - 1];
}

const struct HealLocation *GetHealLocation(u32 index)
{
    if (index == HEAL_LOCATION_NONE)
        return NULL;
    else if (index > ARRAY_COUNT(sSpawnPoints))
        return NULL;
    else
        return &sSpawnPoints[index - 1];
}
