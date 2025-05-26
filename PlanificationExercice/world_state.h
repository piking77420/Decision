#pragma once

#include <bitset>

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