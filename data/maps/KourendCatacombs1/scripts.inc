KourendCatacombs1_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, KourendCatacombs1_OnTransition
	.byte 0

KourendCatacombs1_OnTransition:
    goto_if_unset FLAG_CATAS_START, KourendCatacombs1_Start
    end

KourendCatacombs1_Start:
    givemon SPECIES_AEGISLASH, 50, ITEM_LEFTOVERS
    // givemon SPECIES_BLAZIKEN, 50, ITEM_LEFTOVERS
    givemon SPECIES_GARGANACL, 50, ITEM_LEFTOVERS
    givemon SPECIES_DECIDUEYE, 50, ITEM_LEFTOVERS
    // givemon SPECIES_BLISSEY, 50, ITEM_LEFTOVERS
    // givemon SPECIES_HATTERENE, 50, ITEM_LEFTOVERS
    setflag FLAG_SYS_POKEMON_GET
    setflag FLAG_SYS_POKEDEX_GET
    special EnableNationalPokedex
    setflag FLAG_SYS_FRONTIER_PASS
    additem ITEM_ULTRA_BALL, 10
    setflag FLAG_SYS_B_DASH
    setflag FLAG_SYS_QUEST_MENU_GET
    setrespawn HEAL_LOCATION_CATACOMBS_OF_KOUREND
    setflag FLAG_CATAS_START
    end

KourendCatacombs1_Text_RightTutorIntro:
	.string "Ihihihi!\p"
	.string "I know it's hard to see now, but I used\n"
	.string "to be one fantastic TRAINER.\p"
	.string "I had a reputation as the most\n"
	.string "invincible SWIMMER around, I tell you!\p"
	.string "… … … … … …\p"
	.string "What's wrong?\n"
	.string "You don't believe me.\p"
	.string "I'm not like that buffoonish woman over\n"
	.string "there. I'm actually experienced!\p"
	.string "I can prove it to you.\n"
	.string "I can teach your POKéMON hard and\l"
	.string "yet pretty moves.\p"
	.string "But my lessons don't come free.\n"
	.string "How about paying for the moves I teach\l"
	.string "with a wee bit of Battle Points?$"

KourendCatacombs1_SlayerCounter::
    lock
    faceplayer
    buffernumberstring STR_VAR_1, VAR_SLAYER_COUNTER
    msgbox KourendCatacombs1_Text_SlayerCounter, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_SlayerTutor::
    lock
    faceplayer
    msgbox KourendCatacombs1_Text_RightTutorIntro, MSGBOX_DEFAULT
    special ShowBattlePointsWindow
	setvar VAR_0x8004, SCROLL_SLAYER_TUTOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
    case 0, KourendCatacombs1_EventScript_AbyssalDagger
    case 1, KourendCatacombs1_EventScript_AbyssalWhip
    case 2, KourendCatacombs1_EventScript_AncientStaff
    case 3, KourendCatacombs1_EventScript_Augury
    case 4, KourendCatacombs1_EventScript_BloodBarrage
    case 5, KourendCatacombs1_EventScript_DragonCrossbow
    case 6, KourendCatacombs1_EventScript_DragonScimitar
    case 7, KourendCatacombs1_EventScript_EarthSurge
    case 8, KourendCatacombs1_EventScript_FireSurge
    case 9, KourendCatacombs1_EventScript_IbansStaff
    case 10, KourendCatacombs1_EventScript_IceBarrage
    case 11, KourendCatacombs1_EventScript_LeafBladedBattleaxe
    case 12, KourendCatacombs1_EventScript_LeafBladedSpear
    case 13, KourendCatacombs1_EventScript_LeafBladedSword
    case 14, KourendCatacombs1_EventScript_MagicShortbow
    case 15, KourendCatacombs1_EventScript_Piety
    case 16, KourendCatacombs1_EventScript_ProtectFromMagic
    case 17, KourendCatacombs1_EventScript_ProtectFromMelee
    case 18, KourendCatacombs1_EventScript_ProtectFromMissiles
    case 19, KourendCatacombs1_EventScript_Rigour
    case 20, KourendCatacombs1_EventScript_ShadowBarrage
    case 21, KourendCatacombs1_EventScript_SlayersStaff
    case 22, KourendCatacombs1_EventScript_SmokeBarrage
    case 23, KourendCatacombs1_EventScript_ToxicBlowpipe
    case 24, KourendCatacombs1_EventScript_TwistedBow
    case 25, KourendCatacombs1_EventScript_WaterSurge
    case 26, KourendCatacombs1_EventScript_WindSurge
    case 27, KourendCatacombs1_EventScript_ZamorakianHasta
    case 28, KourendCatacombs1_EventScript_Crunch
    case 29, KourendCatacombs1_EventScript_DarkPulse
    case 30, KourendCatacombs1_EventScript_EnergyBall
    case 31, KourendCatacombs1_EventScript_Hex
    case 32, KourendCatacombs1_EventScript_Hurricane
    case 33, KourendCatacombs1_EventScript_LavaPlume
    case 34, KourendCatacombs1_EventScript_LeechLife
    case 35, KourendCatacombs1_EventScript_PsychoCut
    case 36, KourendCatacombs1_EventScript_RazorShell
    case 37, KourendCatacombs1_EventScript_SteelWing
    case 38, KourendCatacombs1_EventScript_SwordsDance
    case 39, KourendCatacombs1_EventScript_Tailwind
    case 40, KourendCatacombs1_EventScript_UTurn
	case MULTI_B_PRESSED, KourendCatacombs1_EventScript_ExitTutorMoveSelect
	end

KourendCatacombs1_EventScript_ExitTutorMoveSelect::
	special CloseBattlePointsWindow
	msgbox KourendCatacombs1_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

KourendCatacombs1_EventScript_Crunch::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_CRUNCH
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_DarkPulse::
	setvar VAR_0x8008, 36
	setvar VAR_0x8005, MOVE_DARK_PULSE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_EnergyBall::
	setvar VAR_0x8008, 36
	setvar VAR_0x8005, MOVE_ENERGY_BALL
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_Hex::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_HEX
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_Hurricane::
	setvar VAR_0x8008, 60
	setvar VAR_0x8005, MOVE_HURRICANE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_LavaPlume::
	setvar VAR_0x8008, 36
	setvar VAR_0x8005, MOVE_LAVA_PLUME
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_LeechLife::
	setvar VAR_0x8008, 12
	setvar VAR_0x8005, MOVE_LEECH_LIFE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_PsychoCut::
	setvar VAR_0x8008, 36
	setvar VAR_0x8005, MOVE_PSYCHO_CUT
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_RazorShell::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_RAZOR_SHELL
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_SteelWing::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_STEEL_WING
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_SwordsDance::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_SWORDS_DANCE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_Tailwind::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_TAILWIND
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_UTurn::
	setvar VAR_0x8008, 24
	setvar VAR_0x8005, MOVE_U_TURN
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_AbyssalDagger::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_ABYSSAL_DAGGER
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_AbyssalWhip::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_ABYSSAL_WHIP
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_AncientStaff::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_ANCIENT_STAFF
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_Augury::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_AUGURY
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_BloodBarrage::
	setvar VAR_0x8008, 84
	setvar VAR_0x8005, MOVE_BLOOD_BARRAGE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_DragonCrossbow::
	setvar VAR_0x8008, 60
	setvar VAR_0x8005, MOVE_DRAGON_CROSSBOW
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_DragonScimitar::
	setvar VAR_0x8008, 60
	setvar VAR_0x8005, MOVE_DRAGON_SCIMITAR
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_EarthSurge::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_EARTH_SURGE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_FireSurge::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_FIRE_SURGE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_IbansStaff::
	setvar VAR_0x8008, 84
	setvar VAR_0x8005, MOVE_IBANS_STAFF
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_IceBarrage::
	setvar VAR_0x8008, 84
	setvar VAR_0x8005, MOVE_ICE_BARRAGE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_LeafBladedBattleaxe::
	setvar VAR_0x8008, 84
	setvar VAR_0x8005, MOVE_LEAF_BLADED_BATTLEAXE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_LeafBladedSpear::
	setvar VAR_0x8008, 84
	setvar VAR_0x8005, MOVE_LEAF_BLADED_SPEAR
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_LeafBladedSword::
	setvar VAR_0x8008, 84
	setvar VAR_0x8005, MOVE_LEAF_BLADED_SWORD
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_MagicShortbow::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_MAGIC_SHORTBOW
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_Piety::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_PIETY
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_ProtectFromMagic::
	setvar VAR_0x8008, 60
	setvar VAR_0x8005, MOVE_PROTECT_FROM_MAGIC
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_ProtectFromMelee::
	setvar VAR_0x8008, 60
	setvar VAR_0x8005, MOVE_PROTECT_FROM_MELEE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_ProtectFromMissiles::
	setvar VAR_0x8008, 60
	setvar VAR_0x8005, MOVE_PROTECT_FROM_MISSILES
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_Rigour::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_RIGOUR
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_ShadowBarrage::
	setvar VAR_0x8008, 84
	setvar VAR_0x8005, MOVE_SHADOW_BARRAGE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_SlayersStaff::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_SLAYERS_STAFF
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_SmokeBarrage::
	setvar VAR_0x8008, 84
	setvar VAR_0x8005, MOVE_SMOKE_BARRAGE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_ToxicBlowpipe::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_TOXIC_BLOWPIPE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_TwistedBow::
	setvar VAR_0x8008, 96
	setvar VAR_0x8005, MOVE_TWISTED_BOW
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_WaterSurge::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_WATER_SURGE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_WindSurge::
	setvar VAR_0x8008, 72
	setvar VAR_0x8005, MOVE_WIND_SURGE
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_ZamorakianHasta::
	setvar VAR_0x8008, 84
	setvar VAR_0x8005, MOVE_ZAMORAKIAN_HASTA
	goto KourendCatacombs1_EventScript_ConfirmMoveSelection
	end

KourendCatacombs1_EventScript_ConfirmMoveSelection::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, KourendCatacombs1_EventScript_TeachTutorMove
	msgbox KourendCatacombs1_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto KourendCatacombs1_SlayerTutor
	end

KourendCatacombs1_EventScript_TeachTutorMove::
	msgbox KourendCatacombs1_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, KourendCatacombs1_EventScript_CancelChooseMon
	msgbox KourendCatacombs1_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

KourendCatacombs1_EventScript_CancelChooseMon::
	msgbox KourendCatacombs1_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

KourendCatacombs1_Text_YouDontWantTo:
	.string "What's that?\n"
	.string "You don't want to…\p"
	.string "If you want to see how skilled I am,\n"
	.string "you come see me anytime!$"

KourendCatacombs1_Text_IllTakeBattlePoints:
	.string "Do you see how skilled I am now?\n"
	.string "I'll take your Battle Points, thanks!$"

KourendCatacombs1_Text_HaventGotEnoughPoints:
	.string "What the…\n"
	.string "You haven't got enough Battle Points!$"

KourendCatacombs1_Text_TeachMoveToWhichMon:
	.string "Fine, fine, now pick the POKéMON\n"
	.string "I should teach the move to.$"

KourendCatacombs1_Text_WelcomePleaseChoosePrize:
	.string "Hello, this is the EXCHANGE SERVICE\n"
	.string "CORNER.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

KourendCatacombs1_SlayerShop::
    lock
    faceplayer
    msgbox KourendCatacombs1_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
    special ShowBattlePointsWindow
	setvar VAR_0x8004, SCROLL_SLAYER_SHOP
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
    case 0, KourendCatacombs1_EventScript_AntifirePotion24SP
    case 1, KourendCatacombs1_EventScript_AntiDragonShield36SP
    case 2, KourendCatacombs1_EventScript_BlackMask48SP
    case 3, KourendCatacombs1_EventScript_BlessedSet72SP
    case 4, KourendCatacombs1_EventScript_BroadArrows24SP
    case 5, KourendCatacombs1_EventScript_BroadBolts24SP
    case 6, KourendCatacombs1_EventScript_EternalBoots36SP
    case 7, KourendCatacombs1_EventScript_FireCape60SP
    case 8, KourendCatacombs1_EventScript_GodCape60SP
    case 9, KourendCatacombs1_EventScript_InfernalCape72SP
    case 10, KourendCatacombs1_EventScript_MirrorShield24SP
    case 11, KourendCatacombs1_EventScript_MythicalCape48SP
    case 12, KourendCatacombs1_EventScript_ObsidianSet84SP
    case 13, KourendCatacombs1_EventScript_SalveAmulet60SP
    case 14, KourendCatacombs1_EventScript_SlayerHelmet72SP
    case 15, KourendCatacombs1_EventScript_AssaultVest60SP
    case 16, KourendCatacombs1_EventScript_ChoiceBand84SP
    case 17, KourendCatacombs1_EventScript_ChoiceScarf84SP
    case 18, KourendCatacombs1_EventScript_ChoiceSpecs84SP
    case 19, KourendCatacombs1_EventScript_Eviolite60SP
    case 20, KourendCatacombs1_EventScript_ExpertBelt48SP
    case 21, KourendCatacombs1_EventScript_FocusSash48SP
    case 22, KourendCatacombs1_EventScript_HeavyDutyBoots36SP
    case 23, KourendCatacombs1_EventScript_Leftovers84SP
    case 24, KourendCatacombs1_EventScript_LifeOrb72SP
    case 25, KourendCatacombs1_EventScript_LumBerry48SP
    case 26, KourendCatacombs1_EventScript_RockyHelmet48SP
    case 27, KourendCatacombs1_EventScript_SalacBerry36SP
    case 28, KourendCatacombs1_EventScript_AirBalloon12SP
    case 29, KourendCatacombs1_EventScript_DampRock12SP
    case 30, KourendCatacombs1_EventScript_ElectricSeed12SP
    case 31, KourendCatacombs1_EventScript_GrassySeed12SP
    case 32, KourendCatacombs1_EventScript_HeatRock12SP
    case 33, KourendCatacombs1_EventScript_IcyRock12SP
    case 34, KourendCatacombs1_EventScript_LiechiBerry24SP
    case 35, KourendCatacombs1_EventScript_LightClay24SP
    case 36, KourendCatacombs1_EventScript_MistySeed12SP
    case 37, KourendCatacombs1_EventScript_PetayaBerry24SP
    case 38, KourendCatacombs1_EventScript_PsychicSeed12SP
    case 39, KourendCatacombs1_EventScript_SmoothRock12SP
    case 40, KourendCatacombs1_EventScript_TerrainExtender24SP
    case 41, KourendCatacombs1_EventScript_ThroatSpray12SP
    case 42, KourendCatacombs1_EventScript_WhiteHerb24SP
	case MULTI_B_PRESSED, KourendCatacombs1_EventScript_ClerkGoodbye
	end

KourendCatacombs1_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

KourendCatacombs1_Text_ThankYouVisitWithPoints:
	.string "Thank you very much.\p"
	.string "Please visit me when you have\n"
	.string "saved up Slayer Points.$"

KourendCatacombs1_EventScript_AntifirePotion24SP::
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_ANTIFIRE_POTION
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_AntiDragonShield36SP::
	setvar VAR_0x8008, 36
	setvar VAR_0x8009, ITEM_ANTI_DRAGON_SHIELD
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_BlackMask48SP::
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_BLACK_MASK
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_BlessedSet72SP::
	setvar VAR_0x8008, 72
	setvar VAR_0x8009, ITEM_BLESSED_SET
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_BroadArrows24SP::
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_BROAD_ARROWS
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_BroadBolts24SP::
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_BROAD_BOLTS
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_EternalBoots36SP::
	setvar VAR_0x8008, 36
	setvar VAR_0x8009, ITEM_ETERNAL_BOOTS
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_FireCape60SP::
	setvar VAR_0x8008, 60
	setvar VAR_0x8009, ITEM_FIRE_CAPE
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_GodCape60SP::
	setvar VAR_0x8008, 60
	setvar VAR_0x8009, ITEM_GOD_CAPE
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_InfernalCape72SP::
	setvar VAR_0x8008, 72
	setvar VAR_0x8009, ITEM_INFERNAL_CAPE
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_MirrorShield24SP::
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_MIRROR_SHIELD
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_MythicalCape48SP::
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MYTHICAL_CAPE
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_ObsidianSet84SP::
	setvar VAR_0x8008, 84
	setvar VAR_0x8009, ITEM_OBSIDIAN_SET
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_SalveAmulet60SP::
	setvar VAR_0x8008, 60
	setvar VAR_0x8009, ITEM_SALVE_AMULET
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_SlayerHelmet72SP::
	setvar VAR_0x8008, 72
	setvar VAR_0x8009, ITEM_SLAYER_HELMET
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_AssaultVest60SP::
	setvar VAR_0x8008, 60
	setvar VAR_0x8009, ITEM_ASSAULT_VEST
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_ChoiceBand84SP::
	setvar VAR_0x8008, 84
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_ChoiceScarf84SP::
	setvar VAR_0x8008, 84
	setvar VAR_0x8009, ITEM_CHOICE_SCARF
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_ChoiceSpecs84SP::
	setvar VAR_0x8008, 84
	setvar VAR_0x8009, ITEM_CHOICE_SPECS
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_Eviolite60SP::
	setvar VAR_0x8008, 60
	setvar VAR_0x8009, ITEM_EVIOLITE
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_ExpertBelt48SP::
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_EXPERT_BELT
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_FocusSash48SP::
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_FOCUS_SASH
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_HeavyDutyBoots36SP::
	setvar VAR_0x8008, 36
	setvar VAR_0x8009, ITEM_HEAVY_DUTY_BOOTS
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_Leftovers84SP::
	setvar VAR_0x8008, 84
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_LifeOrb72SP::
	setvar VAR_0x8008, 72
	setvar VAR_0x8009, ITEM_LIFE_ORB
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_LumBerry48SP::
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LUM_BERRY
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_RockyHelmet48SP::
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_ROCKY_HELMET
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_SalacBerry36SP::
	setvar VAR_0x8008, 36
	setvar VAR_0x8009, ITEM_SALAC_BERRY
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_AirBalloon12SP::
	setvar VAR_0x8008, 12
	setvar VAR_0x8009, ITEM_AIR_BALLOON
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_DampRock12SP::
	setvar VAR_0x8008, 12
	setvar VAR_0x8009, ITEM_DAMP_ROCK
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_ElectricSeed12SP::
	setvar VAR_0x8008, 12
	setvar VAR_0x8009, ITEM_ELECTRIC_SEED
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_GrassySeed12SP::
	setvar VAR_0x8008, 12
	setvar VAR_0x8009, ITEM_GRASSY_SEED
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_HeatRock12SP::
	setvar VAR_0x8008, 12
	setvar VAR_0x8009, ITEM_HEAT_ROCK
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_IcyRock12SP::
	setvar VAR_0x8008, 12
	setvar VAR_0x8009, ITEM_ICY_ROCK
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_LiechiBerry24SP::
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_LIECHI_BERRY
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_LightClay24SP::
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_LIGHT_CLAY
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_MistySeed12SP::
	setvar VAR_0x8008, 12
	setvar VAR_0x8009, ITEM_MISTY_SEED
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_PetayaBerry24SP::
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_PETAYA_BERRY
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_PsychicSeed12SP::
	setvar VAR_0x8008, 12
	setvar VAR_0x8009, ITEM_PSYCHIC_SEED
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_SmoothRock12SP::
	setvar VAR_0x8008, 12
	setvar VAR_0x8009, ITEM_SMOOTH_ROCK
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_TerrainExtender24SP::
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_TERRAIN_EXTENDER
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_ThroatSpray12SP::
	setvar VAR_0x8008, 12
	setvar VAR_0x8009, ITEM_THROAT_SPRAY
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_WhiteHerb24SP::
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto KourendCatacombs1_EventScript_TryPurchasePrize
	end

KourendCatacombs1_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, KourendCatacombs1_EventScript_TryGiveItem
	msgbox KourendCatacombs1_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto KourendCatacombs1_SlayerShop
	end

KourendCatacombs1_Text_DontHaveEnoughPoints:
	.string "I'm so sorry…\n"
	.string "You don't have enough Battle Points…$"

KourendCatacombs1_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, KourendCatacombs1_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox KourendCatacombs1_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto KourendCatacombs1_SlayerShop
	end

KourendCatacombs1_Text_HereIsYourPrize:
	.string "Here is your prize!$"

KourendCatacombs1_EventScript_BagFull::
	msgbox KourendCatacombs1_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

KourendCatacombs1_Text_DontHaveSpaceToHoldIt:
	.string "I'm so sorry…\n"
	.string "You don't have space to hold it…$"

KourendCatacombs1_Nieve::
    lock
    faceplayer
    goto_if_quest_reward QUEST_1, KourendCatacombs1_GiveSlayerPointsAbyssalDemons
    goto_if_quest_reward QUEST_2, KourendCatacombs1_GiveSlayerPointsBlackDemons
    goto_if_quest_reward QUEST_3, KourendCatacombs1_GiveSlayerPointsGreaterDemons
    goto_if_quest_reward QUEST_4, KourendCatacombs1_GiveSlayerPointsGreaterNechrayael
    goto_if_quest_reward QUEST_5, KourendCatacombs1_GiveSlayerPointsBloodvelds
    goto_if_quest_reward QUEST_6, KourendCatacombs1_GiveSlayerPointsBlackDragons
    goto_if_quest_reward QUEST_7, KourendCatacombs1_GiveSlayerPointsBlueDragons
    goto_if_quest_reward QUEST_8, KourendCatacombs1_GiveSlayerPointsRedDragons
    goto_if_quest_reward QUEST_9, KourendCatacombs1_GiveSlayerPointsFireGiants
    goto_if_quest_reward QUEST_10, KourendCatacombs1_GiveSlayerPointsHellhounds
    goto_if_quest_reward QUEST_11, KourendCatacombs1_GiveSlayerPointsIronDragons
    goto_if_quest_reward QUEST_12, KourendCatacombs1_GiveSlayerPointsSteelDragons
    goto_if_quest_reward QUEST_13, KourendCatacombs1_GiveSlayerPointsAnkou
    goto_if_quest_reward QUEST_14, KourendCatacombs1_GiveSlayerPointsSpectres
    goto_if_quest_reward QUEST_15, KourendCatacombs1_GiveSlayerPointsDagannoth
    goto_if_quest_reward QUEST_16, KourendCatacombs1_GiveSlayerPointsDustDevils
    questmenu QUEST_MENU_SET_INACTIVE QUEST_1
    questmenu QUEST_MENU_SET_INACTIVE QUEST_2
    questmenu QUEST_MENU_SET_INACTIVE QUEST_3
    questmenu QUEST_MENU_SET_INACTIVE QUEST_4
    questmenu QUEST_MENU_SET_INACTIVE QUEST_5
    questmenu QUEST_MENU_SET_INACTIVE QUEST_6
    questmenu QUEST_MENU_SET_INACTIVE QUEST_7
    questmenu QUEST_MENU_SET_INACTIVE QUEST_8
    questmenu QUEST_MENU_SET_INACTIVE QUEST_9
    questmenu QUEST_MENU_SET_INACTIVE QUEST_10
    questmenu QUEST_MENU_SET_INACTIVE QUEST_11
    questmenu QUEST_MENU_SET_INACTIVE QUEST_12
    questmenu QUEST_MENU_SET_INACTIVE QUEST_13
    questmenu QUEST_MENU_SET_INACTIVE QUEST_14
    questmenu QUEST_MENU_SET_INACTIVE QUEST_15
    questmenu QUEST_MENU_SET_INACTIVE QUEST_16
    random 16
    switch VAR_RESULT
    case 0, KourendCatacombs1_AssignAbyssalDemons
    case 1, KourendCatacombs1_AssignBlackDemons
    case 2, KourendCatacombs1_AssignGreaterDemons
    case 3, KourendCatacombs1_AssignGreaterNechrayael
    case 4, KourendCatacombs1_AssignBloodvelds
    case 5, KourendCatacombs1_AssignBlackDragons
    case 6, KourendCatacombs1_AssignBlueDragons
    case 7, KourendCatacombs1_AssignRedDragons
    case 8, KourendCatacombs1_AssignFireGiants
    case 9, KourendCatacombs1_AssignHellhounds
    case 10, KourendCatacombs1_AssignIronDragons
    case 11, KourendCatacombs1_AssignSteelDragons
    case 12, KourendCatacombs1_AssignAnkou
    case 13, KourendCatacombs1_AssignSpectres
    case 14, KourendCatacombs1_AssignDagannoth
    case 15, KourendCatacombs1_AssignDustDevils
    release
    end

KourendCatacombs1_AssignAbyssalDemons::
    setflag FLAG_ABYSSAL_DEMONS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_1
    msgbox KourendCatacombs1_Text_AssignedAbyssalDemons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignBlackDemons::
    setflag FLAG_BLACK_DEMONS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_2
    msgbox KourendCatacombs1_Text_AssignedBlackDemons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignGreaterDemons::
    setflag FLAG_GREATER_DEMONS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_3
    msgbox KourendCatacombs1_Text_AssignedGreaterDemons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignGreaterNechrayael::
    setflag FLAG_GREATER_NECHRAYAEL
    random 4
    addvar VAR_RESULT, 4
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_4
    msgbox KourendCatacombs1_Text_AssignedGreaterNechrayael, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignBloodvelds::
    setflag FLAG_BLOODVELDS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_5
    msgbox KourendCatacombs1_Text_AssignedBloodvelds, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignBlackDragons::
    setflag FLAG_BLACK_DRAGONS
    random 2
    addvar VAR_RESULT, 1
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_6
    msgbox KourendCatacombs1_Text_AssignedBlackDragons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignBlueDragons::
    setflag FLAG_BLUE_DRAGONS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_7
    msgbox KourendCatacombs1_Text_AssignedBlueDragons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignRedDragons::
    setflag FLAG_RED_DRAGONS
    random 3
    addvar VAR_RESULT, 2
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_8
    msgbox KourendCatacombs1_Text_AssignedRedDragons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignFireGiants::
    setflag FLAG_FIRE_GIANTS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_9
    msgbox KourendCatacombs1_Text_AssignedFireGiants, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignHellhounds::
    setflag FLAG_HELLHOUNDS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_10
    msgbox KourendCatacombs1_Text_AssignedHellhounds, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignIronDragons::
    setflag FLAG_IRON_DRAGONS
    random 3
    addvar VAR_RESULT, 2
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_11
    msgbox KourendCatacombs1_Text_AssignedIronDragons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignSteelDragons::
    setflag FLAG_STEEL_DRAGONS
    random 3
    addvar VAR_RESULT, 2
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_12
    msgbox KourendCatacombs1_Text_AssignedSteelDragons, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignAnkou::
    setflag FLAG_ANKOU
    random 3
    addvar VAR_RESULT, 3
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_13
    msgbox KourendCatacombs1_Text_AssignedAnkou, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignSpectres::
    setflag FLAG_SPECTRES
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_4
    msgbox KourendCatacombs1_Text_AssignedSpectres, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignDagannoth::
    setflag FLAG_DAGANNOTH
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_15
    msgbox KourendCatacombs1_Text_AssignedDagannoth, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_AssignDustDevils::
    setflag FLAG_DUST_DEVILS
    random 4
    addvar VAR_RESULT, 5
    copyvar VAR_SLAYER_LEFT_TO_DEFEAT, VAR_RESULT
    buffernumberstring STR_VAR_1, VAR_RESULT
    questmenu QUEST_MENU_SET_ACTIVE QUEST_16
    msgbox KourendCatacombs1_Text_AssignedDustDevils, MSGBOX_DEFAULT
    release
    end

KourendCatacombs1_GiveSlayerPointsAbyssalDemons::
    clearflag FLAG_ABYSSAL_DEMONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_1
    release
    end

KourendCatacombs1_GiveSlayerPointsBlackDemons::
    clearflag FLAG_BLACK_DEMONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_2
    release
    end

KourendCatacombs1_GiveSlayerPointsGreaterDemons::
    clearflag FLAG_GREATER_DEMONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_3
    release
    end

KourendCatacombs1_GiveSlayerPointsGreaterNechrayael::
    clearflag FLAG_GREATER_NECHRAYAEL
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_4
    release
    end

KourendCatacombs1_GiveSlayerPointsBloodvelds::
    clearflag FLAG_BLOODVELDS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_5
    release
    end

KourendCatacombs1_GiveSlayerPointsBlackDragons::
    clearflag FLAG_BLACK_DRAGONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_6
    release
    end

KourendCatacombs1_GiveSlayerPointsBlueDragons::
    clearflag FLAG_BLUE_DRAGONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_7
    release
    end

KourendCatacombs1_GiveSlayerPointsRedDragons::
    clearflag FLAG_RED_DRAGONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_8
    release
    end

KourendCatacombs1_GiveSlayerPointsFireGiants::
    clearflag FLAG_FIRE_GIANTS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_9
    release
    end

KourendCatacombs1_GiveSlayerPointsHellhounds::
    clearflag FLAG_HELLHOUNDS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_10
    release
    end

KourendCatacombs1_GiveSlayerPointsIronDragons::
    clearflag FLAG_IRON_DRAGONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_11
    release
    end

KourendCatacombs1_GiveSlayerPointsSteelDragons::
    clearflag FLAG_STEEL_DRAGONS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_12
    release
    end

KourendCatacombs1_GiveSlayerPointsAnkou::
    clearflag FLAG_ANKOU
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_13
    release
    end

KourendCatacombs1_GiveSlayerPointsSpectres::
    clearflag FLAG_SPECTRES
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_14
    release
    end

KourendCatacombs1_GiveSlayerPointsDagannoth::
    clearflag FLAG_DAGANNOTH
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_15
    release
    end

KourendCatacombs1_GiveSlayerPointsDustDevils::
    clearflag FLAG_DUST_DEVILS
    setvar VAR_0x8004, 12
    special GiveFrontierBattlePoints
    buffernumberstring STR_VAR_1, 12
    msgbox KourendCatacombs1_Text_ObtainedXSlayerPoints, MSGBOX_GETPOINTS
    questmenu QUEST_MENU_COMPLETE_QUEST QUEST_16
    release
    end

KourendCatacombs1_Text_SlayerCounter::
	.string "You have completed {STR_VAR_1} Slayer task(s).$"

KourendCatacombs1_Text_ObtainedXSlayerPoints::
	.string "{PLAYER} obtained {STR_VAR_1} Slayer Point(s).$"

KourendCatacombs1_Text_AssignedAbyssalDemons::
	.string "You have been assigned {STR_VAR_1}\nAbyssal Demons.$"

KourendCatacombs1_Text_AssignedBlackDemons::
	.string "You have been assigned {STR_VAR_1}\nBlack Demons.$"

KourendCatacombs1_Text_AssignedGreaterDemons::
	.string "You have been assigned {STR_VAR_1}\nGreater Demons.$"

KourendCatacombs1_Text_AssignedGreaterNechrayael::
	.string "You have been assigned {STR_VAR_1}\nGreater Nechrayael.$"

KourendCatacombs1_Text_AssignedBloodvelds::
	.string "You have been assigned {STR_VAR_1}\nBloodvelds.$"

KourendCatacombs1_Text_AssignedBlackDragons::
	.string "You have been assigned {STR_VAR_1}\nBrutal Black Dragons.$"

KourendCatacombs1_Text_AssignedBlueDragons::
	.string "You have been assigned {STR_VAR_1}\nBrutal Blue Dragons.$"

KourendCatacombs1_Text_AssignedRedDragons::
	.string "You have been assigned {STR_VAR_1}\nBrutal Red Dragons.$"

KourendCatacombs1_Text_AssignedFireGiants::
	.string "You have been assigned {STR_VAR_1}\nFire Giants.$"

KourendCatacombs1_Text_AssignedHellhounds::
	.string "You have been assigned {STR_VAR_1}\nHellhounds.$"

KourendCatacombs1_Text_AssignedIronDragons::
	.string "You have been assigned {STR_VAR_1}\nIron Dragons.$"

KourendCatacombs1_Text_AssignedSteelDragons::
	.string "You have been assigned {STR_VAR_1}\nSteel Dragons.$"

KourendCatacombs1_Text_AssignedAnkou::
	.string "You have been assigned {STR_VAR_1}\nAnkou.$"

KourendCatacombs1_Text_AssignedSpectres::
	.string "You have been assigned {STR_VAR_1}\nSpectres.$"

KourendCatacombs1_Text_AssignedDagannoth::
	.string "You have been assigned {STR_VAR_1}\nDagannoth.$"

KourendCatacombs1_Text_AssignedDustDevils::
	.string "You have been assigned {STR_VAR_1}\nDust Devils.$"

KourendCatacombs1_HillGiant::
    lock
    faceplayer
    setwildbattle SPECIES_PANGORO, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs1_Skeleton::
    lock
    faceplayer
    setwildbattle SPECIES_DUSKULL, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs1_Cyclops::
    lock
    faceplayer
    setwildbattle SPECIES_DUSCLOPS, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs1_Ghost::
    lock
    faceplayer
    setwildbattle SPECIES_FROSLASS, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs1_AbyssalDemon::
    lock
    faceplayer
    setwildbattle SPECIES_ABYSSAL_DEMON_FORM, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs1_MagicAxe::
    lock
    faceplayer
    setwildbattle SPECIES_EXORAXE, 45
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, KourendCatacombs1_EventScript_RemoveStaticPokemon
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, KourendCatacombs1_EventScript_RemoveStaticPokemon
	release
	end

KourendCatacombs1_EventScript_RemoveStaticPokemon::
	goto Common_EventScript_RemoveStaticPokemon
	end

KourendCatacombs1_Text_LeftoversDesc::
	.string "A hold item that gradually restores\n"
	.string "HP in battle.$"
