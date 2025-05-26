#pragma once

#include <stdexcept>
#include <vector>

#include "world_state.h"

enum struct Actions : std::uint32_t
{ 
    MoveToWeapon,
    PickUpWeapon,
    MoveToEnemy,
    KillEnemy,
    HealSelf,
    
    Count,
    None,
};

struct ActionsAndCost
{
    Actions action;
    int cost;
};

#define CreateActions(ActionName, Cost)\
constexpr ActionsAndCost ActionName = \
{\
    Actions::ActionName,\
    Cost,\
};\

CreateActions(MoveToWeapon, 2);
CreateActions(PickUpWeapon, 1);
CreateActions(MoveToEnemy, 2);
CreateActions(KillEnemy, 4);
CreateActions(HealSelf, 2);


inline WordlState ApplieActionToWorld(Actions _action, const WordlState& _wordlState)
{
    WordlState result = _wordlState;
    result.set(static_cast<uint8_t>(_action), false);
    
    switch (_action)
    {
    case Actions::MoveToWeapon:
        return result.set(static_cast<uint8_t>(WorldStateStatus::IsNearWeapon));
    case Actions::PickUpWeapon:
        return result.set(static_cast<uint8_t>(WorldStateStatus::HasWeapon));
    case Actions::MoveToEnemy:
        return result.set(static_cast<uint8_t>(WorldStateStatus::IsNearEnnemy));
    case Actions::KillEnemy:
            return result.set(static_cast<uint8_t>(WorldStateStatus::EnemyDead));
    case Actions::HealSelf:
        return result.set(static_cast<uint8_t>(WorldStateStatus::IsHurt), false);
    case Actions::Count:
    default:
            throw std::invalid_argument("Invalid ActionSet");
    }
    return {};
}

inline bool IsActionAvailable(Actions _action, const WordlState& _worldState )
{
    switch (_action)
    {
    case Actions::MoveToWeapon:
        return !TestWorldState(_worldState, WorldStateStatus::HasWeapon) && !TestWorldState(_worldState, WorldStateStatus::IsHurt)
        && !TestWorldState(_worldState, WorldStateStatus::IsNearWeapon);
    case Actions::PickUpWeapon:
        return TestWorldState(_worldState, WorldStateStatus::IsNearWeapon) && !TestWorldState(_worldState, WorldStateStatus::HasWeapon);
    case Actions::MoveToEnemy:
        return TestWorldState(_worldState, WorldStateStatus::HasWeapon) && !TestWorldState(_worldState, WorldStateStatus::IsNearEnnemy);
    case Actions::KillEnemy:
        return TestWorldState(_worldState, WorldStateStatus::HasWeapon) && TestWorldState(_worldState, WorldStateStatus::IsNearEnnemy)
        && !TestWorldState(_worldState, WorldStateStatus::IsHurt);
    case Actions::HealSelf:
        return TestWorldState(_worldState, WorldStateStatus::IsHurt);
        break;
    case Actions::Count:
    default: ;
        throw std::invalid_argument("Invalid ActionSet");
    }
}



inline std::vector<ActionsAndCost> CreateActionSubSet(const std::vector<ActionsAndCost>& _availableAction, Actions _action)
{
    switch (_action)
    {
    case Actions::MoveToWeapon:
        return
        {
            PickUpWeapon,
        };
        break;
    case Actions::PickUpWeapon:
        return
        {
            MoveToEnemy,
        };
    case Actions::MoveToEnemy:
        return
         {
             KillEnemy,
         };
    case Actions::KillEnemy:
        return
        {
            HealSelf,
        };
        break;
    case Actions::HealSelf:
        return
        {
            MoveToWeapon,
        };
        break;
    case Actions::Count:
    case Actions::None:
        break;
    default: ;
    }

    return {};
}
