#pragma once

#include <bitset>
#include <vector>


enum struct WorldStateStatus : std::uint32_t
{
    EnemyDead,
    HasWeapon,
    IsNearWeapon,
    IsNearEnnemy,
    IsHurt,

    Count,
};

using WordlState = std::bitset<static_cast<uint32_t>(WorldStateStatus::Count)>;

inline bool TestWorldState(const WordlState& _wstate, WorldStateStatus _stateStatus)
{
    return _wstate.test(static_cast<std::uint32_t>(_stateStatus));
}

inline void SetWorldState(WordlState& _wstate, WorldStateStatus _stateStatus, bool value = true)
{
    _wstate.set(static_cast<std::uint32_t>(_stateStatus), value);
}

/*
inline ActionsAndCost GetActionFromWorldState(const WordlState& _wstate)
{
    for (size_t i = 0; i < static_cast<size_t>(WorldStateStatus::Count); i++)
    {
        WorldStateStatus status = static_cast<WorldStateStatus>(i);
        if (_wstate.test(i))
            continue;
        
        switch (status)
        {
        case WorldStateStatus::EnemyDead:
            return KillEnemy;
        case WorldStateStatus::HasWeapon:
            return PickUpWeapon;
        case WorldStateStatus::IsNearWeapon:
            return MoveToWeapon;
        case WorldStateStatus::IsNearEnnemy:
            return MoveToEnemy;
        case WorldStateStatus::IsHurt:
            return HealSelf;
        case WorldStateStatus::Count:
        default: ;
            throw std::invalid_argument("Invalid world state");
        }
    }
    return {};
}*/
