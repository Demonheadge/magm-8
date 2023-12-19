#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItems[ITEM_QUICK_CLAW].holdEffect == HOLD_EFFECT_QUICK_CLAW);
}

SINGLE_BATTLE_TEST("Quick Claw activates 10% of the time")
{
    PASSES_RANDOMLY(2, 10, RNG_QUICK_CLAW);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); Item(ITEM_QUICK_CLAW); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("Wobbuffet used Tackle!");
        MESSAGE("Foe Wobbuffet used Celebrate!");
    }
}
