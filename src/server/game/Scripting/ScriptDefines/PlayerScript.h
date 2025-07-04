/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SCRIPT_OBJECT_PLAYER_SCRIPT_H_
#define SCRIPT_OBJECT_PLAYER_SCRIPT_H_

#include "ScriptObject.h"
#include "SharedDefines.h"
#include <vector>

// TODO to remove
#include "AchievementMgr.h"
#include "KillRewarder.h"

enum PlayerHook
{
    PLAYERHOOK_ON_PLAYER_JUST_DIED,
    PLAYERHOOK_ON_CALCULATE_TALENTS_POINTS,
    PLAYERHOOK_ON_PLAYER_RELEASED_GHOST,
    PLAYERHOOK_ON_SEND_INITIAL_PACKETS_BEFORE_ADD_TO_MAP,
    PLAYERHOOK_ON_BATTLEGROUND_DESERTION,
    PLAYERHOOK_ON_PLAYER_COMPLETE_QUEST,
    PLAYERHOOK_ON_PVP_KILL,
    PLAYERHOOK_ON_PLAYER_PVP_FLAG_CHANGE,
    PLAYERHOOK_ON_CREATURE_KILL,
    PLAYERHOOK_ON_CREATURE_KILLED_BY_PET,
    PLAYERHOOK_ON_PLAYER_KILLED_BY_CREATURE,
    PLAYERHOOK_ON_LEVEL_CHANGED,
    PLAYERHOOK_ON_FREE_TALENT_POINTS_CHANGED,
    PLAYERHOOK_ON_TALENTS_RESET,
    PLAYERHOOK_ON_AFTER_SPEC_SLOT_CHANGED,
    PLAYERHOOK_ON_BEFORE_UPDATE,
    PLAYERHOOK_ON_UPDATE,
    PLAYERHOOK_ON_MONEY_CHANGED,
    PLAYERHOOK_ON_BEFORE_LOOT_MONEY,
    PLAYERHOOK_ON_GIVE_EXP,
    PLAYERHOOK_ON_REPUTATION_CHANGE,
    PLAYERHOOK_ON_REPUTATION_RANK_CHANGE,
    PLAYERHOOK_ON_LEARN_SPELL,
    PLAYERHOOK_ON_FORGOT_SPELL,
    PLAYERHOOK_ON_DUEL_REQUEST,
    PLAYERHOOK_ON_DUEL_START,
    PLAYERHOOK_ON_DUEL_END,
    PLAYERHOOK_ON_CHAT,
    PLAYERHOOK_ON_BEFORE_SEND_CHAT_MESSAGE,
    PLAYERHOOK_ON_CHAT_WITH_RECEIVER,
    PLAYERHOOK_ON_CHAT_WITH_GROUP,
    PLAYERHOOK_ON_CHAT_WITH_GUILD,
    PLAYERHOOK_ON_CHAT_WITH_CHANNEL,
    PLAYERHOOK_ON_EMOTE,
    PLAYERHOOK_ON_TEXT_EMOTE,
    PLAYERHOOK_ON_SPELL_CAST,
    PLAYERHOOK_ON_LOAD_FROM_DB,
    PLAYERHOOK_ON_LOGIN,
    PLAYERHOOK_ON_BEFORE_LOGOUT,
    PLAYERHOOK_ON_LOGOUT,
    PLAYERHOOK_ON_CREATE,
    PLAYERHOOK_ON_DELETE,
    PLAYERHOOK_ON_FAILED_DELETE,
    PLAYERHOOK_ON_SAVE,
    PLAYERHOOK_ON_BIND_TO_INSTANCE,
    PLAYERHOOK_ON_UPDATE_ZONE,
    PLAYERHOOK_ON_UPDATE_AREA,
    PLAYERHOOK_ON_MAP_CHANGED,
    PLAYERHOOK_ON_BEFORE_TELEPORT,
    PLAYERHOOK_ON_UPDATE_FACTION,
    PLAYERHOOK_ON_ADD_TO_BATTLEGROUND,
    PLAYERHOOK_ON_QUEUE_RANDOM_DUNGEON,
    PLAYERHOOK_ON_REMOVE_FROM_BATTLEGROUND,
    PLAYERHOOK_ON_ACHI_COMPLETE,
    PLAYERHOOK_ON_BEFORE_ACHI_COMPLETE,
    PLAYERHOOK_ON_CRITERIA_PROGRESS,
    PLAYERHOOK_ON_BEFORE_CRITERIA_PROGRESS,
    PLAYERHOOK_ON_ACHI_SAVE,
    PLAYERHOOK_ON_CRITERIA_SAVE,
    PLAYERHOOK_ON_GOSSIP_SELECT,
    PLAYERHOOK_ON_GOSSIP_SELECT_CODE,
    PLAYERHOOK_ON_BEING_CHARMED,
    PLAYERHOOK_ON_AFTER_SET_VISIBLE_ITEM_SLOT,
    PLAYERHOOK_ON_AFTER_MOVE_ITEM_FROM_INVENTORY,
    PLAYERHOOK_ON_EQUIP,
    PLAYERHOOK_ON_PLAYER_JOIN_BG,
    PLAYERHOOK_ON_PLAYER_JOIN_ARENA,
    PLAYERHOOK_GET_CUSTOM_GET_ARENA_TEAM_ID,
    PLAYERHOOK_GET_CUSTOM_ARENA_PERSONAL_RATING,
    PLAYERHOOK_ON_GET_MAX_PERSONAL_ARENA_RATING_REQUIREMENT,
    PLAYERHOOK_ON_LOOT_ITEM,
    PLAYERHOOK_ON_BEFORE_FILL_QUEST_LOOT_ITEM,
    PLAYERHOOK_ON_STORE_NEW_ITEM,
    PLAYERHOOK_ON_CREATE_ITEM,
    PLAYERHOOK_ON_QUEST_REWARD_ITEM,
    PLAYERHOOK_CAN_PLACE_AUCTION_BID,
    PLAYERHOOK_ON_GROUP_ROLL_REWARD_ITEM,
    PLAYERHOOK_ON_BEFORE_OPEN_ITEM,
    PLAYERHOOK_ON_BEFORE_QUEST_COMPLETE,
    PLAYERHOOK_ON_QUEST_COMPUTE_EXP,
    PLAYERHOOK_ON_BEFORE_DURABILITY_REPAIR,
    PLAYERHOOK_ON_BEFORE_BUY_ITEM_FROM_VENDOR,
    PLAYERHOOK_ON_BEFORE_STORE_OR_EQUIP_NEW_ITEM,
    PLAYERHOOK_ON_AFTER_STORE_OR_EQUIP_NEW_ITEM,
    PLAYERHOOK_ON_AFTER_UPDATE_MAX_POWER,
    PLAYERHOOK_ON_AFTER_UPDATE_MAX_HEALTH,
    PLAYERHOOK_ON_BEFORE_UPDATE_ATTACK_POWER_AND_DAMAGE,
    PLAYERHOOK_ON_AFTER_UPDATE_ATTACK_POWER_AND_DAMAGE,
    PLAYERHOOK_ON_BEFORE_INIT_TALENT_FOR_LEVEL,
    PLAYERHOOK_ON_FIRST_LOGIN,
    PLAYERHOOK_ON_SET_MAX_LEVEL,
    PLAYERHOOK_CAN_JOIN_IN_BATTLEGROUND_QUEUE,
    PLAYERHOOK_SHOULD_BE_REWARDED_WITH_MONEY_INSTEAD_OF_EXP,
    PLAYERHOOK_ON_BEFORE_TEMP_SUMMON_INIT_STATS,
    PLAYERHOOK_ON_BEFORE_GUARDIAN_INIT_STATS_FOR_LEVEL,
    PLAYERHOOK_ON_AFTER_GUARDIAN_INIT_STATS_FOR_LEVEL,
    PLAYERHOOK_ON_BEFORE_LOAD_PET_FROM_DB,
    PLAYERHOOK_CAN_JOIN_IN_ARENA_QUEUE,
    PLAYERHOOK_CAN_BATTLEFIELD_PORT,
    PLAYERHOOK_CAN_GROUP_INVITE,
    PLAYERHOOK_CAN_GROUP_ACCEPT,
    PLAYERHOOK_CAN_SELL_ITEM,
    PLAYERHOOK_CAN_SEND_MAIL,
    PLAYERHOOK_PETITION_BUY,
    PLAYERHOOK_PETITION_SHOW_LIST,
    PLAYERHOOK_ON_REWARD_KILL_REWARDER,
    PLAYERHOOK_CAN_GIVE_MAIL_REWARD_AT_GIVE_LEVEL,
    PLAYERHOOK_ON_DELETE_FROM_DB,
    PLAYERHOOK_CAN_REPOP_AT_GRAVEYARD,
    PLAYERHOOK_ON_PLAYER_IS_CLASS,
    PLAYERHOOK_ON_GET_MAX_SKILL_VALUE,
    PLAYERHOOK_ON_PLAYER_HAS_ACTIVE_POWER_TYPE,
    PLAYERHOOK_ON_UPDATE_GATHERING_SKILL,
    PLAYERHOOK_ON_UPDATE_CRAFTING_SKILL,
    PLAYERHOOK_ON_UPDATE_FISHING_SKILL,
    PLAYERHOOK_CAN_AREA_EXPLORE_AND_OUTDOOR,
    PLAYERHOOK_ON_VICTIM_REWARD_BEFORE,
    PLAYERHOOK_ON_VICTIM_REWARD_AFTER,
    PLAYERHOOK_ON_CUSTOM_SCALING_STAT_VALUE_BEFORE,
    PLAYERHOOK_ON_CUSTOM_SCALING_STAT_VALUE,
    PLAYERHOOK_ON_APPLY_ITEM_MODS_BEFORE,
    PLAYERHOOK_ON_APPLY_ENCHANTMENT_ITEM_MODS_BEFORE,
    PLAYERHOOK_ON_APPLY_WEAPON_DAMAGE,
    PLAYERHOOK_CAN_ARMOR_DAMAGE_MODIFIER,
    PLAYERHOOK_ON_GET_FERAL_AP_BONUS,
    PLAYERHOOK_CAN_APPLY_WEAPON_DEPENDENT_AURA_DAMAGE_MOD,
    PLAYERHOOK_CAN_APPLY_EQUIP_SPELL,
    PLAYERHOOK_CAN_APPLY_EQUIP_SPELLS_ITEM_SET,
    PLAYERHOOK_CAN_CAST_ITEM_COMBAT_SPELL,
    PLAYERHOOK_CAN_CAST_ITEM_USE_SPELL,
    PLAYERHOOK_ON_APPLY_AMMO_BONUSES,
    PLAYERHOOK_CAN_EQUIP_ITEM,
    PLAYERHOOK_CAN_UNEQUIP_ITEM,
    PLAYERHOOK_CAN_USE_ITEM,
    PLAYERHOOK_CAN_SAVE_EQUIP_NEW_ITEM,
    PLAYERHOOK_CAN_APPLY_ENCHANTMENT,
    PLAYERHOOK_PASSED_QUEST_KILLED_MONSTER_CREDIT,
    PLAYERHOOK_CHECK_ITEM_IN_SLOT_AT_LOAD_INVENTORY,
    PLAYERHOOK_NOT_AVOID_SATISFY,
    PLAYERHOOK_NOT_VISIBLE_GLOBALLY_FOR,
    PLAYERHOOK_ON_GET_ARENA_PERSONAL_RATING,
    PLAYERHOOK_ON_GET_ARENA_TEAM_ID,
    PLAYERHOOK_ON_IS_FFA_PVP,
    PLAYERHOOK_ON_FFA_PVP_STATE_UPDATE,
    PLAYERHOOK_ON_IS_PVP,
    PLAYERHOOK_ON_GET_MAX_SKILL_VALUE_FOR_LEVEL,
    PLAYERHOOK_NOT_SET_ARENA_TEAM_INFO_FIELD,
    PLAYERHOOK_CAN_JOIN_LFG,
    PLAYERHOOK_CAN_ENTER_MAP,
    PLAYERHOOK_CAN_INIT_TRADE,
    PLAYERHOOK_CAN_SET_TRADE_ITEM,
    PLAYERHOOK_ON_SET_SERVER_SIDE_VISIBILITY,
    PLAYERHOOK_ON_SET_SERVER_SIDE_VISIBILITY_DETECT,
    PLAYERHOOK_ON_PLAYER_RESURRECT,
    PLAYERHOOK_ON_BEFORE_CHOOSE_GRAVEYARD,
    PLAYERHOOK_CAN_PLAYER_USE_CHAT,
    PLAYERHOOK_CAN_PLAYER_USE_PRIVATE_CHAT,
    PLAYERHOOK_CAN_PLAYER_USE_GROUP_CHAT,
    PLAYERHOOK_CAN_PLAYER_USE_GUILD_CHAT,
    PLAYERHOOK_CAN_PLAYER_USE_CHANNEL_CHAT,
    PLAYERHOOK_ON_PLAYER_LEARN_TALENTS,
    PLAYERHOOK_ON_PLAYER_ENTER_COMBAT,
    PLAYERHOOK_ON_PLAYER_LEAVE_COMBAT,
    PLAYERHOOK_ON_QUEST_ABANDON,
    PLAYERHOOK_ON_GET_QUEST_RATE,
    PLAYERHOOK_ON_CAN_PLAYER_FLY_IN_ZONE,
    PLAYERHOOK_ANTICHEAT_SET_CAN_FLY_BY_SERVER,
    PLAYERHOOK_ANTICHEAT_SET_UNDER_ACK_MOUNT,
    PLAYERHOOK_ANTICHEAT_SET_ROOT_ACK_UPD,
    PLAYERHOOK_ANTICHEAT_SET_JUMPING_BY_OPCODE,
    PLAYERHOOK_ANTICHEAT_UPDATE_MOVEMENT_INFO,
    PLAYERHOOK_ANTICHEAT_HANDLE_DOUBLE_JUMP,
    PLAYERHOOK_ANTICHEAT_CHECK_MOVEMENT_INFO,
    PLAYERHOOK_CAN_SEND_ERROR_ALREADY_LOOTED,
    PLAYERHOOK_ON_AFTER_CREATURE_LOOT,
    PLAYERHOOK_ON_AFTER_CREATURE_LOOT_MONEY,
    PLAYERHOOK_ON_CAN_UPDATE_SKILL,
    PLAYERHOOK_ON_BEFORE_UPDATE_SKILL,
    PLAYERHOOK_ON_UPDATE_SKILL,
    PLAYERHOOK_CAN_RESURRECT,
    PLAYERHOOK_ON_CAN_GIVE_LEVEL,
    PLAYERHOOK_ON_SEND_LIST_INVENTORY,
    PLAYERHOOK_ON_AFTER_MOVE_ITEM_TO_INVENTORY,
    PLAYERHOOK_ON_REMOVE_ITEM,
    PLAYERHOOK_ON_UNEQUIP,
    PLAYERHOOK_END
};

class PlayerScript : public ScriptObject
{
protected:
    PlayerScript(const char* name, std::vector<uint16> enabledHooks = std::vector<uint16>());

public:
    // Called when a player dies
    virtual void OnPlayerJustDied(Player* /*player*/) { }

    // Called player talent points are calculated
    virtual void OnPlayerCalculateTalentsPoints(Player const* /*player*/, uint32& /*talentPointsForLevel*/) { }

    // Called when clicking the release button
    virtual void OnPlayerReleasedGhost(Player* /*player*/) { }

    // Called on Send Initial Packets Before Add To Map
    virtual void OnPlayerSendInitialPacketsBeforeAddToMap(Player* /*player*/, WorldPacket& /*data*/) {}

    // Called when a player does a desertion action (see BattlegroundDesertionType)
    virtual void OnPlayerBattlegroundDesertion(Player* /*player*/, BattlegroundDesertionType const /*desertionType*/) { }

    // Called when a player completes a quest
    virtual void OnPlayerCompleteQuest(Player* /*player*/, Quest const* /*quest_id*/) { }

    // Called when a player kills another player
    virtual void OnPlayerPVPKill(Player* /*killer*/, Player* /*killed*/) { }

    // Called when a player toggles pvp
    virtual void OnPlayerPVPFlagChange(Player* /*player*/, bool /*state*/) { }

    // Called when a player kills a creature
    virtual void OnPlayerCreatureKill(Player* /*killer*/, Creature* /*killed*/) { }

    // Called when a player's pet kills a creature
    virtual void OnPlayerCreatureKilledByPet(Player* /*PetOwner*/, Creature* /*killed*/) { }

    // Called when a player is killed by a creature
    virtual void OnPlayerKilledByCreature(Creature* /*killer*/, Player* /*killed*/) { }

    // Called when a player's level changes (right after the level is applied)
    virtual void OnPlayerLevelChanged(Player* /*player*/, uint8 /*oldlevel*/) { }

    // Called when a player's free talent points change (right before the change is applied)
    virtual void OnPlayerFreeTalentPointsChanged(Player* /*player*/, uint32 /*points*/) { }

    // Called when a player's talent points are reset (right before the reset is done)
    virtual void OnPlayerTalentsReset(Player* /*player*/, bool /*noCost*/) { }

    // Called after a player switches specs using the dual spec system
    virtual void OnPlayerAfterSpecSlotChanged(Player* /*player*/, uint8 /*newSlot*/) { }

    // Called for player::update
    virtual void OnPlayerBeforeUpdate(Player* /*player*/, uint32 /*p_time*/) { }
    virtual void OnPlayerUpdate(Player* /*player*/, uint32 /*p_time*/) { }

    // Called when a player's money is modified (before the modification is done)
    virtual void OnPlayerMoneyChanged(Player* /*player*/, int32& /*amount*/) { }

    // Called before looted money is added to a player
    virtual void OnPlayerBeforeLootMoney(Player* /*player*/, Loot* /*loot*/) {}

    // Called when a player gains XP (before anything is given)
    virtual void OnPlayerGiveXP(Player* /*player*/, uint32& /*amount*/, Unit* /*victim*/, uint8 /*xpSource*/) { }

    // Called when a player's reputation changes (before it is actually changed)
    virtual bool OnPlayerReputationChange(Player* /*player*/, uint32 /*factionID*/, int32& /*standing*/, bool /*incremental*/) { return true; }

    // Called when a player's reputation rank changes (before it is actually changed)
    virtual void OnPlayerReputationRankChange(Player* /*player*/, uint32 /*factionID*/, ReputationRank /*newRank*/, ReputationRank /*olRank*/, bool /*increased*/) { }

    // Called when a player learned new spell
    virtual void OnPlayerLearnSpell(Player* /*player*/, uint32 /*spellID*/) {}

    // Called when a player forgot spell
    virtual void OnPlayerForgotSpell(Player* /*player*/, uint32 /*spellID*/) {}

    // Called when a duel is requested
    virtual void OnPlayerDuelRequest(Player* /*target*/, Player* /*challenger*/) { }

    // Called when a duel starts (after 3s countdown)
    virtual void OnPlayerDuelStart(Player* /*player1*/, Player* /*player2*/) { }

    // Called when a duel ends
    virtual void OnPlayerDuelEnd(Player* /*winner*/, Player* /*loser*/, DuelCompleteType /*type*/) { }

    // The following methods are called when a player sends a chat message.
    virtual void OnPlayerChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/) { }

    virtual void OnPlayerBeforeSendChatMessage(Player* /*player*/, uint32& /*type*/, uint32& /*lang*/, std::string& /*msg*/) { }

    virtual void OnPlayerChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/, Player* /*receiver*/) { }

    virtual void OnPlayerChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/, Group* /*group*/) { }

    virtual void OnPlayerChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/, Guild* /*guild*/) { }

    virtual void OnPlayerChat(Player* /*player*/, uint32 /*type*/, uint32 /*lang*/, std::string& /*msg*/, Channel* /*channel*/) { }

    // Both of the below are called on emote opcodes.
    virtual void OnPlayerEmote(Player* /*player*/, uint32 /*emote*/) { }

    virtual void OnPlayerTextEmote(Player* /*player*/, uint32 /*textEmote*/, uint32 /*emoteNum*/, ObjectGuid /*guid*/) { }

    // Called in Spell::Cast.
    virtual void OnPlayerSpellCast(Player* /*player*/, Spell* /*spell*/, bool /*skipCheck*/) { }

    // Called during data loading
    virtual void OnPlayerLoadFromDB(Player* /*player*/) { };

    // Called when a player logs in.
    virtual void OnPlayerLogin(Player* /*player*/) { }

    // Called before the player is logged out
    virtual void OnPlayerBeforeLogout(Player* /*player*/) { }

    // Called when a player logs out.
    virtual void OnPlayerLogout(Player* /*player*/) { }

    // Called when a player is created.
    virtual void OnPlayerCreate(Player* /*player*/) { }

    // Called when a player is deleted.
    virtual void OnPlayerDelete(ObjectGuid /*guid*/, uint32 /*accountId*/) { }

    // Called when a player delete failed.
    virtual void OnPlayerFailedDelete(ObjectGuid /*guid*/, uint32 /*accountId*/) { }

    // Called when a player is about to be saved.
    virtual void OnPlayerSave(Player* /*player*/) { }

    // Called when a player is bound to an instance
    virtual void OnPlayerBindToInstance(Player* /*player*/, Difficulty /*difficulty*/, uint32 /*mapId*/, bool /*permanent*/) { }

    // Called when a player switches to a new zone
    virtual void OnPlayerUpdateZone(Player* /*player*/, uint32 /*newZone*/, uint32 /*newArea*/) { }

    // Called when a player switches to a new area (more accurate than UpdateZone)
    virtual void OnPlayerUpdateArea(Player* /*player*/, uint32 /*oldArea*/, uint32 /*newArea*/) { }

    // Called when a player changes to a new map (after moving to new map)
    virtual void OnPlayerMapChanged(Player* /*player*/) { }

    // Called before a player is being teleported to new coords
    [[nodiscard]] virtual bool OnPlayerBeforeTeleport(Player* /*player*/, uint32 /*mapid*/, float /*x*/, float /*y*/, float /*z*/, float /*orientation*/, uint32 /*options*/, Unit* /*target*/) { return true; }

    // Called when team/faction is set on player
    virtual void OnPlayerUpdateFaction(Player* /*player*/) { }

    // Called when a player is added to battleground
    virtual void OnPlayerAddToBattleground(Player* /*player*/, Battleground* /*bg*/) { }

    // Called when a player queues a Random Dungeon using the RDF (Random Dungeon Finder)
    virtual void OnPlayerQueueRandomDungeon(Player* /*player*/, uint32 & /*rDungeonId*/) { }

    // Called when a player is removed from battleground
    virtual void OnPlayerRemoveFromBattleground(Player* /*player*/, Battleground* /*bg*/) { }

    // Called when a player complete an achievement
    virtual void OnPlayerAchievementComplete(Player* /*player*/, AchievementEntry const* /*achievement*/) { }

    // Called before player complete an achievement, can be used to disable achievements in certain conditions
    virtual bool OnPlayerBeforeAchievementComplete(Player* /*player*/, AchievementEntry const* /*achievement*/) { return true; }

    // Called when a player complete an achievement criteria
    virtual void OnPlayerCriteriaProgress(Player* /*player*/, AchievementCriteriaEntry const* /*criteria*/) { }

    //  Called before player complete an achievement criteria, can be used to disable achievement criteria in certain conditions
    virtual bool OnPlayerBeforeCriteriaProgress(Player* /*player*/, AchievementCriteriaEntry const* /*criteria*/) { return true; }

    // Called when an Achievement is saved to DB
    virtual void OnPlayerAchievementSave(CharacterDatabaseTransaction /*trans*/, Player* /*player*/, uint16 /*achId*/, CompletedAchievementData /*achiData*/) { }

    // Called when an Criteria is saved to DB
    virtual void OnPlayerCriteriaSave(CharacterDatabaseTransaction /*trans*/, Player* /*player*/, uint16 /*achId*/, CriteriaProgress /*criteriaData*/) { }

    // Called when a player selects an option in a player gossip window
    virtual void OnPlayerGossipSelect(Player* /*player*/, uint32 /*menu_id*/, uint32 /*sender*/, uint32 /*action*/) { }

    // Called when a player selects an option in a player gossip window
    virtual void OnPlayerGossipSelectCode(Player* /*player*/, uint32 /*menu_id*/, uint32 /*sender*/, uint32 /*action*/, const char* /*code*/) { }

    // On player getting charmed
    virtual void OnPlayerBeingCharmed(Player* /*player*/, Unit* /*charmer*/, uint32 /*oldFactionId*/, uint32 /*newFactionId*/) { }

    // To change behaviour of set visible item slot
    virtual void OnPlayerAfterSetVisibleItemSlot(Player* /*player*/, uint8 /*slot*/, Item* /*item*/) { }

    // After an item has been moved from inventory
    virtual void OnPlayerAfterMoveItemFromInventory(Player* /*player*/, Item* /*it*/, uint8 /*bag*/, uint8 /*slot*/, bool /*update*/) { }

    // After an item has been equipped
    virtual void OnPlayerEquip(Player* /*player*/, Item* /*it*/, uint8 /*bag*/, uint8 /*slot*/, bool /*update*/) { }

    // After player enters queue for BG
    virtual void OnPlayerJoinBG(Player* /*player*/) { }

    // After player enters queue for Arena
    virtual void OnPlayerJoinArena(Player* /*player*/) { }

    //Called after the normal slots (0..2) for arena have been evaluated so that custom arena teams could modify it if nececasry
    virtual void OnPlayerGetMaxPersonalArenaRatingRequirement(Player const* /*player*/, uint32 /*minSlot*/, uint32& /*maxArenaRating*/) const {}

    //After looting item
    virtual void OnPlayerLootItem(Player* /*player*/, Item* /*item*/, uint32 /*count*/, ObjectGuid /*lootguid*/) { }

    //Before looting item
    virtual void OnPlayerBeforeFillQuestLootItem(Player* /*player*/, LootItem& /*item*/) { }

    //After looting item (includes master loot).
    virtual void OnPlayerStoreNewItem(Player* /*player*/, Item* /*item*/, uint32 /*count*/) { }

    //After creating item (eg profession item creation)
    virtual void OnPlayerCreateItem(Player* /*player*/, Item* /*item*/, uint32 /*count*/) { }

    // After receiving item as a quest reward
    virtual void OnPlayerQuestRewardItem(Player* /*player*/, Item* /*item*/, uint32 /*count*/) { }

    // When placing a bid or buying out an auction
    [[nodiscard]] virtual bool OnPlayerCanPlaceAuctionBid(Player* /*player*/, AuctionEntry* /*auction*/) { return true; }

    // After receiving item as a group roll reward
    virtual void OnPlayerGroupRollRewardItem(Player* /*player*/, Item* /*item*/, uint32 /*count*/, RollVote /*voteType*/, Roll* /*roll*/) { }

    //Before opening an item
    [[nodiscard]] virtual bool OnPlayerBeforeOpenItem(Player* /*player*/, Item* /*item*/) { return true; }

    // After completed a quest
    [[nodiscard]] virtual bool OnPlayerBeforeQuestComplete(Player* /*player*/, uint32 /*quest_id*/) { return true; }

    // Called after computing the XP reward value for a quest
    virtual void OnPlayerQuestComputeXP(Player* /*player*/, Quest const* /*quest*/, uint32& /*xpValue*/) { }

    // Before durability repair action, you can even modify the discount value
    virtual void OnPlayerBeforeDurabilityRepair(Player* /*player*/, ObjectGuid /*npcGUID*/, ObjectGuid /*itemGUID*/, float&/*discountMod*/, uint8 /*guildBank*/) { }

    //Before buying something from any vendor
    virtual void OnPlayerBeforeBuyItemFromVendor(Player* /*player*/, ObjectGuid /*vendorguid*/, uint32 /*vendorslot*/, uint32& /*item*/, uint8 /*count*/, uint8 /*bag*/, uint8 /*slot*/) { };

    //Before buying something from any vendor
    virtual void OnPlayerBeforeStoreOrEquipNewItem(Player* /*player*/, uint32 /*vendorslot*/, uint32& /*item*/, uint8 /*count*/, uint8 /*bag*/, uint8 /*slot*/, ItemTemplate const* /*pProto*/, Creature* /*pVendor*/, VendorItem const* /*crItem*/, bool /*bStore*/) { };

    //After buying something from any vendor
    virtual void OnPlayerAfterStoreOrEquipNewItem(Player* /*player*/, uint32 /*vendorslot*/, Item* /*item*/, uint8 /*count*/, uint8 /*bag*/, uint8 /*slot*/, ItemTemplate const* /*pProto*/, Creature* /*pVendor*/, VendorItem const* /*crItem*/, bool /*bStore*/) { };

    virtual void OnPlayerAfterUpdateMaxPower(Player* /*player*/, Powers& /*power*/, float& /*value*/) { }

    virtual void OnPlayerAfterUpdateMaxHealth(Player* /*player*/, float& /*value*/) { }

    virtual void OnPlayerBeforeUpdateAttackPowerAndDamage(Player* /*player*/, float& /*level*/, float& /*val2*/, bool /*ranged*/) { }
    virtual void OnPlayerAfterUpdateAttackPowerAndDamage(Player* /*player*/, float& /*level*/, float& /*base_attPower*/, float& /*attPowerMod*/, float& /*attPowerMultiplier*/, bool /*ranged*/) { }

    virtual void OnPlayerBeforeInitTalentForLevel(Player* /*player*/, uint8& /*level*/, uint32& /*talentPointsForLevel*/) { }

    virtual void OnPlayerFirstLogin(Player* /*player*/) { }

    virtual void OnPlayerSetMaxLevel(Player* /*player*/, uint32& /*maxPlayerLevel*/) { }

    [[nodiscard]] virtual bool OnPlayerCanJoinInBattlegroundQueue(Player* /*player*/, ObjectGuid /*BattlemasterGuid*/, BattlegroundTypeId /*BGTypeID*/, uint8 /*joinAsGroup*/, GroupJoinBattlegroundResult& /*err*/) { return true; }
    virtual bool OnPlayerShouldBeRewardedWithMoneyInsteadOfExp(Player* /*player*/) { return false; }

    // Called before the player's temporary summoned creature has initialized it's stats
    virtual void OnPlayerBeforeTempSummonInitStats(Player* /*player*/, TempSummon* /*tempSummon*/, uint32& /*duration*/) { }

    // Called before the player's guardian / pet has initialized it's stats for the player's level
    virtual void OnPlayerBeforeGuardianInitStatsForLevel(Player* /*player*/, Guardian* /*guardian*/, CreatureTemplate const* /*cinfo*/, PetType& /*petType*/) { }

    // Called after the player's guardian / pet has initialized it's stats for the player's level
    virtual void OnPlayerAfterGuardianInitStatsForLevel(Player* /*player*/, Guardian* /*guardian*/) { }

    // Called before loading a player's pet from the DB
    virtual void OnPlayerBeforeLoadPetFromDB(Player* /*player*/, uint32& /*petentry*/, uint32& /*petnumber*/, bool& /*current*/, bool& /*forceLoadFromDB*/) { }

    [[nodiscard]] virtual bool OnPlayerCanJoinInArenaQueue(Player* /*player*/, ObjectGuid /*BattlemasterGuid*/, uint8 /*arenaslot*/, BattlegroundTypeId /*BGTypeID*/, uint8 /*joinAsGroup*/, uint8 /*IsRated*/, GroupJoinBattlegroundResult& /*err*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanBattleFieldPort(Player* /*player*/, uint8 /*arenaType*/, BattlegroundTypeId /*BGTypeID*/, uint8 /*action*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanGroupInvite(Player* /*player*/, std::string& /*membername*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanGroupAccept(Player* /*player*/, Group* /*group*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanSellItem(Player* /*player*/, Item* /*item*/, Creature* /*creature*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanSendMail(Player* /*player*/, ObjectGuid /*receiverGuid*/, ObjectGuid /*mailbox*/, std::string& /*subject*/, std::string& /*body*/, uint32 /*money*/, uint32 /*COD*/, Item* /*item*/) { return true; }

    virtual void OnPlayerPetitionBuy(Player* /*player*/, Creature* /*creature*/, uint32& /*charterid*/, uint32& /*cost*/, uint32& /*type*/) { }

    virtual void OnPlayerPetitionShowList(Player* /*player*/, Creature* /*creature*/, uint32& /*CharterEntry*/, uint32& /*CharterDispayID*/, uint32& /*CharterCost*/) { }

    virtual void OnPlayerRewardKillRewarder(Player* /*player*/, KillRewarder* /*rewarder*/, bool /*isDungeon*/, float& /*rate*/) { }

    [[nodiscard]] virtual bool OnPlayerCanGiveMailRewardAtGiveLevel(Player* /*player*/, uint8 /*level*/) { return true; }

    virtual void OnPlayerDeleteFromDB(CharacterDatabaseTransaction /*trans*/, uint32 /*guid*/) { }

    [[nodiscard]] virtual bool OnPlayerCanRepopAtGraveyard(Player* /*player*/) { return true; }

    [[nodiscard]] virtual Optional<bool> OnPlayerIsClass(Player const* /*player*/, Classes /*playerClass*/, ClassContext /*context*/) { return std::nullopt; }

    virtual void OnPlayerGetMaxSkillValue(Player* /*player*/, uint32 /*skill*/, int32& /*result*/, bool /*IsPure*/) { }

    [[nodiscard]] virtual bool OnPlayerHasActivePowerType(Player const* /*player*/, Powers /*power*/) { return false; }

    /**
     * @brief This hook called before gathering skill gain is applied to the character.
     *
     * @param player Contains information about the Player sender
     * @param skill_id Contains information about the skill line
     * @param current Contains the current skill level for skill
     * @param gray Contains the gray skill level for current application
     * @param green Contains the green skill level for current application
     * @param yellow Contains the yellow skill level for current application
     * @param gain Contains the amount of points that should be added to the Player
     */
    virtual void OnPlayerUpdateGatheringSkill(Player* /*player*/, uint32 /*skill_id*/, uint32 /*current*/, uint32 /*gray*/, uint32 /*green*/, uint32 /*yellow*/, uint32& /*gain*/) { }

    /**
     * @brief This hook is called before crafting skill gain is applied to the character.
     *
     * @param player Contains information about the Player sender
     * @param skill Contains information about the skill line
     * @param current_level Contains the current skill level for skill
     * @param gain Contains the amount of points that should be added to the Player
     */
    virtual void OnPlayerUpdateCraftingSkill(Player* /*player*/, SkillLineAbilityEntry const* /*skill*/, uint32 /*current_level*/, uint32& /*gain*/) { }

    [[nodiscard]] virtual bool OnPlayerUpdateFishingSkill(Player* /*player*/, int32 /*skill*/, int32 /*zone_skill*/, int32 /*chance*/, int32 /*roll*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanAreaExploreAndOutdoor(Player* /*player*/) { return true; }

    virtual void OnPlayerVictimRewardBefore(Player* /*player*/, Player* /*victim*/, uint32& /*killer_title*/, uint32& /*victim_title*/) { }

    virtual void OnPlayerVictimRewardAfter(Player* /*player*/, Player* /*victim*/, uint32& /*killer_title*/, uint32& /*victim_rank*/, float& /*honor_f*/) { }

    virtual void OnPlayerCustomScalingStatValueBefore(Player* /*player*/, ItemTemplate const* /*proto*/, uint8 /*slot*/, bool /*apply*/, uint32& /*CustomScalingStatValue*/) { }

    virtual void OnPlayerCustomScalingStatValue(Player* /*player*/, ItemTemplate const* /*proto*/, uint32& /*statType*/, int32& /*val*/, uint8 /*itemProtoStatNumber*/, uint32 /*ScalingStatValue*/, ScalingStatValuesEntry const* /*ssv*/) { }

    virtual void OnPlayerApplyItemModsBefore(Player* /*player*/, uint8 /*slot*/, bool /*apply*/, uint8 /*itemProtoStatNumber*/, uint32 /*statType*/, int32& /*val*/) { }

    virtual void OnPlayerApplyEnchantmentItemModsBefore(Player* /*player*/, Item* /*item*/, EnchantmentSlot /*slot*/, bool /*apply*/, uint32 /*enchant_spell_id*/, uint32& /*enchant_amount*/) { }

    virtual void OnPlayerApplyWeaponDamage(Player* /*player*/, uint8 /*slot*/, ItemTemplate const* /*proto*/, float& /*minDamage*/, float& /*maxDamage*/, uint8 /*damageIndex*/) { }

    [[nodiscard]] virtual bool OnPlayerCanArmorDamageModifier(Player* /*player*/) { return true; }

    virtual void OnPlayerGetFeralApBonus(Player* /*player*/, int32& /*feral_bonus*/, int32 /*dpsMod*/, ItemTemplate const* /*proto*/, ScalingStatValuesEntry const* /*ssv*/) { }

    [[nodiscard]] virtual bool OnPlayerCanApplyWeaponDependentAuraDamageMod(Player* /*player*/, Item* /*item*/, WeaponAttackType /*attackType*/, AuraEffect const* /*aura*/, bool /*apply*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanApplyEquipSpell(Player* /*player*/, SpellInfo const* /*spellInfo*/, Item* /*item*/, bool /*apply*/, bool /*form_change*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanApplyEquipSpellsItemSet(Player* /*player*/, ItemSetEffect* /*eff*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanCastItemCombatSpell(Player* /*player*/, Unit* /*target*/, WeaponAttackType /*attType*/, uint32 /*procVictim*/, uint32 /*procEx*/, Item* /*item*/, ItemTemplate const* /*proto*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanCastItemUseSpell(Player* /*player*/, Item* /*item*/, SpellCastTargets const& /*targets*/, uint8 /*cast_count*/, uint32 /*glyphIndex*/) { return true; }

    virtual void OnPlayerApplyAmmoBonuses(Player* /*player*/, ItemTemplate const* /*proto*/, float& /*currentAmmoDPS*/) { }

    [[nodiscard]] virtual bool OnPlayerCanEquipItem(Player* /*player*/, uint8 /*slot*/, uint16& /*dest*/, Item* /*pItem*/, bool /*swap*/, bool /*not_loading*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanUnequipItem(Player* /*player*/, uint16 /*pos*/, bool /*swap*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanUseItem(Player* /*player*/, ItemTemplate const* /*proto*/, InventoryResult& /*result*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanSaveEquipNewItem(Player* /*player*/, Item* /*item*/, uint16 /*pos*/, bool /*update*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanApplyEnchantment(Player* /*player*/, Item* /*item*/, EnchantmentSlot /*slot*/, bool /*apply*/, bool /*apply_dur*/, bool /*ignore_condition*/) { return true; }

    virtual void OnPlayerGetQuestRate(Player* /*player*/, float& /*result*/) { }

    [[nodiscard]] virtual bool OnPlayerPassedQuestKilledMonsterCredit(Player* /*player*/, Quest const* /*qinfo*/, uint32 /*entry*/, uint32 /*real_entry*/, ObjectGuid /*guid*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCheckItemInSlotAtLoadInventory(Player* /*player*/, Item* /*item*/, uint8 /*slot*/, uint8& /*err*/, uint16& /*dest*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerNotAvoidSatisfy(Player* /*player*/, DungeonProgressionRequirements const* /*ar*/, uint32 /*target_map*/, bool /*report*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerNotVisibleGloballyFor(Player* /*player*/, Player const* /*u*/) { return true; } // Whats that?

    virtual void OnPlayerGetArenaPersonalRating(Player* /*player*/, uint8 /*slot*/, uint32& /*result*/) { }

    virtual void OnPlayerGetArenaTeamId(Player* /*player*/, uint8 /*slot*/, uint32& /*result*/) { }

    virtual void OnPlayerIsFFAPvP(Player* /*player*/, bool& /*result*/) { }

    //Fires whenever the UNIT_BYTE2_FLAG_FFA_PVP bit is Changed on the player
    virtual void OnPlayerFfaPvpStateUpdate(Player* /*player*/, bool /*result*/) { }

    virtual void OnPlayerIsPvP(Player* /*player*/, bool& /*result*/) { }

    virtual void OnPlayerGetMaxSkillValueForLevel(Player* /*player*/, uint16& /*result*/) { }

    [[nodiscard]] virtual bool OnPlayerNotSetArenaTeamInfoField(Player* /*player*/, uint8 /*slot*/, ArenaTeamInfoType /*type*/, uint32 /*value*/) { return true; } // Whats that?

    [[nodiscard]] virtual bool OnPlayerCanJoinLfg(Player* /*player*/, uint8 /*roles*/, std::set<uint32>& /*dungeons*/, const std::string& /*comment*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanEnterMap(Player* /*player*/, MapEntry const* /*entry*/, InstanceTemplate const* /*instance*/, MapDifficulty const* /*mapDiff*/, bool /*loginCheck*/) { return true; }

    [[nodiscard]] virtual bool OnPlayerCanInitTrade(Player* /*player*/, Player* /*target*/) { return true; }

    /**
     * @brief This hook called just before finishing the handling of the action of a player setting an item in a trade slot
     *
     * @param player Contains information about the trade initiator Player
     * @param tradedItem Contains information about the item set in the trade slot
     *
     * @return True if you want to continue setting the item in the trade slot, false if you want to cancel the trade
     */
    [[nodiscard]] virtual bool OnPlayerCanSetTradeItem(Player* /*player*/, Item* /*tradedItem*/, uint8 /*tradeSlot*/) { return true; }

    virtual void OnPlayerSetServerSideVisibility(Player* /*player*/, ServerSideVisibilityType& /*type*/, AccountTypes& /*sec*/) { }

    virtual void OnPlayerSetServerSideVisibilityDetect(Player* /*player*/, ServerSideVisibilityType& /*type*/, AccountTypes& /*sec*/) { }

    virtual void OnPlayerResurrect(Player* /*player*/, float /*restore_percent*/, bool /*applySickness*/) { }

    // Called before selecting the graveyard when releasing spirit
    virtual void OnPlayerBeforeChooseGraveyard(Player* /*player*/, TeamId /*teamId*/, bool /*nearCorpse*/, uint32& /*graveyardOverride*/) { }

    /**
     * @brief This hook called before player sending message in default chat
     *
     * @param player Contains information about the Player sender
     * @param type Contains information about the chat message type
     * @param language Contains information about the language type
     * @param msg Contains information about the message
     *
     * @return True if you want to continue sending the message, false if you want to disable sending the message
     */
    [[nodiscard]] virtual bool OnPlayerCanUseChat(Player* /*player*/, uint32 /*type*/, uint32 /*language*/, std::string& /*msg*/) { return true; }

    /**
     * @brief This hook called before player sending message to other player via private
     *
     * @param player Contains information about the Player sender
     * @param type Contains information about the chat message type
     * @param language Contains information about the language type
     * @param msg Contains information about the message
     * @param receiver Contains information about the Player receiver
     *
     * @return True if you want to continue sending the message, false if you want to disable sending the message
     */
    [[nodiscard]] virtual bool OnPlayerCanUseChat(Player* /*player*/, uint32 /*type*/, uint32 /*language*/, std::string& /*msg*/, Player* /*receiver*/) { return true; }

    /**
     * @brief This hook called before player sending message to group
     *
     * @param player Contains information about the Player sender
     * @param type Contains information about the chat message type
     * @param language Contains information about the language type
     * @param msg Contains information about the message
     * @param group Contains information about the Group
     *
     * @return True if you want to continue sending the message, false if you want to disable sending the message
     */
    [[nodiscard]] virtual bool OnPlayerCanUseChat(Player* /*player*/, uint32 /*type*/, uint32 /*language*/, std::string& /*msg*/, Group* /*group*/) { return true; }

    /**
     * @brief This hook called before player sending message to guild
     *
     * @param player Contains information about the Player sender
     * @param type Contains information about the chat message type
     * @param language Contains information about the language type
     * @param msg Contains information about the message
     * @param guild Contains information about the Guild
     *
     * @return True if you want to continue sending the message, false if you want to disable sending the message
     */
    [[nodiscard]] virtual bool OnPlayerCanUseChat(Player* /*player*/, uint32 /*type*/, uint32 /*language*/, std::string& /*msg*/, Guild* /*guild*/) { return true; }

    /**
     * @brief This hook called before player sending message to channel
     *
     * @param player Contains information about the Player sender
     * @param type Contains information about the chat message type
     * @param language Contains information about the language type
     * @param msg Contains information about the message
     * @param channel Contains information about the Channel
     *
     * @return True if you want to continue sending the message, false if you want to disable sending the message
     */
    [[nodiscard]] virtual bool OnPlayerCanUseChat(Player* /*player*/, uint32 /*type*/, uint32 /*language*/, std::string& /*msg*/, Channel* /*channel*/) { return true; }

    /**
     * @brief This hook called after player learning talents
     *
     * @param player Contains information about the Player
     * @param talentId Contains information about the talent id
     * @param talentRank Contains information about the talent rank
     * @param spellid Contains information about the spell id
     */
    virtual void OnPlayerLearnTalents(Player* /*player*/, uint32 /*talentId*/, uint32 /*talentRank*/, uint32 /*spellid*/) { }

    /**
     * @brief This hook called after player entering combat
     *
     * @param player Contains information about the Player
     * @param Unit Contains information about the Unit
     */
    virtual void OnPlayerEnterCombat(Player* /*player*/, Unit* /*enemy*/) { }

    /**
     * @brief This hook called after player leave combat
     *
     * @param player Contains information about the Player
     */
    virtual void OnPlayerLeaveCombat(Player* /*player*/) { }

    /**
     * @brief This hook called after player abandoning quest
     *
     * @param player Contains information about the Player
     * @param questId Contains information about the quest id
     */
    virtual void OnPlayerQuestAbandon(Player* /*player*/, uint32 /*questId*/) { }

    /**
     * @brief This hook called before other CanFlyChecks are applied
     *
     * @param player Contains information about the Player
     * @param mapId Contains information about the current map id
     * @param zoneId Contains information about the current zone
     * @param bySpell Contains information about the spell that invoked the check
     */
    [[nodiscard]] virtual bool OnPlayerCanFlyInZone(Player* /*player*/, uint32 /*mapId*/, uint32 /*zoneId*/, SpellInfo const* /*bySpell*/) { return true; }

    // Passive Anticheat System
    virtual void AnticheatSetCanFlybyServer(Player* /*player*/, bool /*apply*/) { }
    virtual void AnticheatSetUnderACKmount(Player* /*player*/) { }
    virtual void AnticheatSetRootACKUpd(Player* /*player*/) { }
    virtual void AnticheatSetJumpingbyOpcode(Player* /*player*/, bool /*jump*/) { }
    virtual void AnticheatUpdateMovementInfo(Player* /*player*/, MovementInfo const& /*movementInfo*/) { }
    [[nodiscard]] virtual bool AnticheatHandleDoubleJump(Player* /*player*/, Unit* /*mover*/) { return true; }
    [[nodiscard]] virtual bool AnticheatCheckMovementInfo(Player* /*player*/, MovementInfo const& /*movementInfo*/, Unit* /*mover*/, bool /*jump*/) { return true; }

    /**
     * @brief This hook is called, to avoid displaying the error message that the body has already been stripped
     *
     * @param player Contains information about the Player
     *
     * @return true Avoiding displaying the error message that the loot has already been taken.
     */
    virtual bool OnPlayerCanSendErrorAlreadyLooted(Player* /*player*/) { return true; }

    /**
     * @brief It is used when an item is taken from a creature.
     *
     * @param player Contains information about the Player
     *
    */
    virtual void OnPlayerAfterCreatureLoot(Player* /*player*/) { }

    /**
     * @brief After a creature's money is taken
     *
     * @param player Contains information about the Player
     */
    virtual void OnPlayerAfterCreatureLootMoney(Player* /*player*/) { }

    virtual bool OnPlayerCanUpdateSkill(Player* /*player*/, uint32 /*skillId*/) { return true; }
    virtual void OnPlayerBeforeUpdateSkill(Player* /*player*/, uint32 /*skillId*/, uint32& /*value*/, uint32 /*max*/, uint32 /*step*/) { }
    virtual void OnPlayerUpdateSkill(Player* /*player*/, uint32 /*skillId*/, uint32 /*value*/, uint32 /*max*/, uint32 /*step*/, uint32 /*newValue*/) { }

    /**
     * @brief This hook is called, to avoid player resurrect
     *
     * @param player Contains information about the Player
     *
     * @return true if player is authorized to resurect
     */
    virtual bool OnPlayerCanResurrect(Player* /*player*/) { return true; }

    /**
     * @brief This hook is called, to cancel the normal level up flow
     *
     * @param player Contains information about the Player
     * @param newLevel The new level the player is about to be given
     *
     * @return true if player is allowed to gain the new level
     */
    virtual bool OnPlayerCanGiveLevel(Player* /*player*/, uint8 /*newLevel*/) { return true; }

    /**
     * @brief This hook is called whenever a player interacts with a vendor, and is then shown the vendor list
     *
     * @param player Contains information about the Player
     * @param vendorGuid Guid of the vendor player is interacting with
     * @param vendorEntry Entry of the vendor player is interacting with
     */
    virtual void OnPlayerSendListInventory(Player* /*player*/, ObjectGuid /*vendorGuid*/, uint32& /*vendorEntry*/) {}

    /**
     * @brief This hook is called whenever a player moves an item to their inventory
     * 
     * @param player Contains information about the Player
     * @param it Contains information about the Item being moved
     * @param update Whether the item should be updated in the database
     */
    virtual void OnPlayerAfterMoveItemToInventory(Player* /*player*/, Item* /*it*/, bool /*update*/) { }

    /**
     * @brief This hook is called whenever a player removes an item from their inventory
     * 
     * @param player Contains information about the Player
     * @param item Contains information about the Item being removed
     * @param bag The bag index from which the item is being removed
     * @param slot The slot index from which the item is being removed
     * @param update Whether the item should be updated in the database
     * @param swap Whether the item is being swapped with another item
     */
    virtual void OnPlayerRemoveItem(Player* /*player*/, Item* /*item*/, uint8 /*bag*/, uint8 /*slot*/, bool /*update*/, bool /*swap*/) { }

    /**
     * @brief This hook is called whenever a player equips an item
     * 
     * @param player Contains information about the Player
     * @param item Contains information about the Item being equipped
     * @param bag The bag index where the item is being equipped
     * @param slot The slot index where the item is being equipped
     * @param update Whether the item should be updated in the database
     * @param swap Whether the item is being swapped with another item
     */
    virtual void OnPlayerUnequipItem(Player* /*player*/, Item* /*item*/, uint8 /*bag*/, uint8 /*slot*/, bool /*update*/, bool /*swap*/) { }

};

#endif
