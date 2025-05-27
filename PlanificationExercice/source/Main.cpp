
#include <array>
#include <vector>

#include "Ai/Actions.h"
#include <cassert>
#include <iostream>


#include "AI/Planer.h"
#include "Core/App.h"


size_t GetBestNodeIndex(const std::vector<std::pair<Node*, float>>& leafNodes)
{
    size_t cost = std::numeric_limits<int>::max();
    size_t BestleaveIndex = std::numeric_limits<size_t>::max();
    
    for (size_t i = 0; i < leafNodes.size(); i++)
    {
        if  (leafNodes[i].first->totalCost < cost)
        {
            cost = leafNodes[i].first->totalCost;
            BestleaveIndex = i;
        }
    }
    assert(BestleaveIndex != std::numeric_limits<size_t>::max());

    return BestleaveIndex;
}


void IterateOverGrap(const Node* leaf)
{
    // root
    std::vector<const char*> actions;
    
    while (leaf->parent != nullptr)
    {
        switch (leaf->action)
        {
        case Actions::MoveToWeapon:
            actions.push_back( "MoveToWeapon");
            break;
        case Actions::PickUpWeapon:
            actions.push_back( "PickUpWeapon");
            break;
        case Actions::MoveToEnemy:
            actions.push_back( "MoveToEnemy");
            break;
        case Actions::KillEnemy:
            actions.push_back( "KillEnemy");
            break;
        case Actions::HealSelf:
            actions.push_back( "HealSelf");
            break;
        case Actions::Count:
        case Actions::None:
        default:
            throw std::invalid_argument("Invalid action provided");
        }
        leaf = leaf->parent;
    }

    for (size_t i = actions.size(); i-- > 0; )
    {
        std::cout << actions[i] << '\n';
    }
}


void TestGoap()
{
    constexpr size_t NodeAllocCount = 2048;
    Planer goap(NodeAllocCount, Planer::PlanerConstructionMethod::Forward);

    Planer::PlanerContext goapContext;
    goap.InitGopContext(&goapContext);
    
    // init worldState
    WordlState initialWorldState;
    initialWorldState.set(static_cast<size_t>(WorldStateStatus::IsHurt), true);
    
    std::vector<ActionsAndCost> availableActions =
        {
        MoveToWeapon,
        PickUpWeapon,
        MoveToEnemy,
        KillEnemy,
        HealSelf,
        };
    
    // set GOAl
    WordlState goal;
    goal.set(static_cast<size_t>(WorldStateStatus::EnemyDead), true);

    goap.BuildPlan(&goapContext, availableActions, initialWorldState, goal);

    for (auto& leafNode : goapContext.leafNodes)
    {
        std::cout << "Start Graph : " << '\n';
        std::cout << "Time for construction : " << leafNode.second << '\n';
        IterateOverGrap(leafNode.first);
        std::cout << "End Graph : " << '\n' << '\n';
    }
    
}

int main(int argc, char* argv[])
{
    TestGoap();
    return 0;
}
