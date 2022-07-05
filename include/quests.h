#ifndef GUARD_QUESTS_H
#define GUARD_QUESTS_H

//#include constants/quests.h       //included in global.h

//#define FLAG_QUEST_MENU_ACTIVE    0x264 //added to constants/flags.h

#define SORT_DEFAULT 0
#define SORT_INACTIVE 1
#define SORT_ACTIVE 2
#define SORT_REWARD 3
#define SORT_DONE 4
#define SORT_DEFAULT_AZ 10
#define SORT_INACTIVE_AZ 11
#define SORT_ACTIVE_AZ 12
#define SORT_REWARD_AZ 13
#define SORT_DONE_AZ 14
#define SORT_SUBQUEST 100

#define INCREMENT 1
#define ALPHA 2 
#define SUB 3

struct SubQuest
{
	/*0x00*/ const u8 *name;
	/*0x04*/ const u8 *desc;
	/*0x0C*/ const u8 *map;
	/*0x18*/ const u8 object;
}; /* size = 0x22 */

struct SideQuest
{
	/*0x00*/ const u8 *name;
	/*0x04*/ const u8 *desc;
	/*0x04*/ const u8 *donedesc;
	/*0x0C*/ const u8 *map;
	u8 object;
	const struct SubQuest *subquests;
	const u8 childtype;
	const u8 numSubquests;
}; /* size = 0x18 */

extern const struct SubQuest gSubQuests1[SUB_QUEST_1_COUNT];
extern const struct SubQuest gSubQuests2[SUB_QUEST_1_COUNT];
extern const struct SideQuest gSideQuests[SIDE_QUEST_COUNT];

enum QuestCases
{
	FLAG_GET_UNLOCKED,      // check if quest is unlocked
	FLAG_GET_INACTIVE, //check if quest is unlocked but has no other state
	FLAG_GET_ACTIVE,        // check if quest is active
	FLAG_GET_REWARD,     // check if quest is ready for reward
	FLAG_GET_COMPLETED,     // check if quest is completed
	FLAG_GET_FAVORITE,     // check if quest is favorited
	FLAG_SET_UNLOCKED,      // mark quest as unlocked
	FLAG_SET_INACTIVE, //mark quest as inactive
	FLAG_SET_ACTIVE,        // mark quest as active
	FLAG_SET_REWARD,     // mark quest ready for reward
	FLAG_SET_COMPLETED,     // mark completed quest
	FLAG_SET_FAVORITE,     // mark quest as a favorite
	FLAG_REMOVE_INACTIVE, //remove inactive flag from quest
	FLAG_REMOVE_ACTIVE, //remove active flag from quest
	FLAG_REMOVE_REWARD, //remove reward flag from quest
	FLAG_REMOVE_FAVORITE, //remove favorite flag from quest
};
enum SubQuestTypes
{
	SUBQUEST_NONE,
	SUBQUEST_CATCH,
	SUBQUEST_FIND,
	SUBQUEST_READ,
};

// functions
void CreateQuestSprite(u16, u8, bool8);
void ResetQuestSpriteState(void);
void DestroyQuestSprite(u8 idx);
void Task_OpenQuestMenuFromStartMenu(u8);
s8 ChangeSubQuestFlags(u8 quest, u8 caseId, u8 childQuest);
s8 QuestMenu_ManageFavoriteQuests(u8 index);
s8 GetSetQuestFlag(u8 quest, u8 caseId);
s8 GetActiveQuestIndex(void);
void QuestMenu_Init(u8 a0, MainCallback callback);
void SetQuestMenuActive(void);
void CopyQuestName(u8 *dst, u8 questId);
void ResetQuestMenuData(void);

#endif // GUARD_QUESTS_H


