
#include <array>
#include <vector>

#include "Actions.h"
#include <cassert>
#include <iostream>


struct Node
{
    WordlState wordlState;
    Actions action;
    int totalCost;
    const Node* parent;
};

std::array<Node, 2048> nodesAlloc;
int nodeCount = 0;

Node CreateChildNode(const Node* _parent, const WordlState& _newWordlState, ActionsAndCost _action)
{
    return
    {
        .wordlState = _newWordlState,
        .action = _action.action,
        .totalCost = _parent->totalCost + _action.cost,
    };
}

bool IsGoalAchieve(const WordlState& _worldState, const WordlState& _worldGoal)
{
    // THIS function should be optimise fix xor or other operator
    
    for (uint32_t i = 0; i < static_cast<uint32_t>(WorldStateStatus::Count); i++)
    {
        if (!_worldGoal.test(i))
            continue;

        if (!_worldState.test(i))
            return false;
        
    }

    return true;
}


void BuildGraphForward(const Node* const _parent, std::vector<Node>* leaves, std::vector<ActionsAndCost>& _availableAction,
    const WordlState& _worldGoal)
{
    for (auto& actionsAndCost : _availableAction)
    {
        const Actions action = actionsAndCost.action;

        if (!IsActionAvailable(action, _parent->wordlState))
            continue;
            
        WordlState newWordlState = ApplieActionToWorld(action, _parent->wordlState);
        Node* newNode = &nodesAlloc[nodeCount++];
        *newNode = CreateChildNode(_parent, newWordlState, actionsAndCost);
        
        
        newNode->parent = _parent;
        std::vector<ActionsAndCost> actionSubSet = CreateActionSubSet(_availableAction, action);

        if (IsGoalAchieve(newWordlState, _worldGoal) || actionSubSet.empty())
        {
            leaves->push_back(*newNode);
        }
        else
        {
            BuildGraphForward(newNode, leaves, actionSubSet, _worldGoal);
        }
        
    }
}


int main(int argc, char* argv[])
{
    // init worldState
    WordlState initialWorldState;
    initialWorldState.set(static_cast<size_t>(WorldStateStatus::IsHurt), true);

    
    std::vector<ActionsAndCost> availableActions =
        {
        HealSelf,
        };
    
    // set GOAl
    WordlState goal;
    goal.set(static_cast<size_t>(WorldStateStatus::EnemyDead), true);
    Node* root = &nodesAlloc[nodeCount++] ;
    *root = Node(initialWorldState, Actions::None,  0, nullptr);
    
    std::vector<Node> leaves = {};
    // reserve in order to keep push back ptr valid
    leaves.reserve(2048);
    
    BuildGraphForward(root , &leaves , availableActions, goal);

    int cost = std::numeric_limits<int>::max();
    int BestleaveIndex = -1;
    
    for (int i = 0; i < (int)leaves.size(); i++)
    {
        if  (leaves[i].totalCost < cost)
        {
            cost = leaves[i].totalCost;
            BestleaveIndex = i;
        }
    }
    assert(BestleaveIndex != -1);

    const Node* iterate = &leaves[BestleaveIndex];
    // root
    while (iterate->parent != nullptr)
    {
        switch (iterate->action)
        {
        case Actions::MoveToWeapon:
            std::cout << "MoveToWeapon" << std::endl;
            break;
        case Actions::PickUpWeapon:
            std::cout << "PickUpWeapon" << std::endl;
            break;
        case Actions::MoveToEnemy:
            std::cout << "MoveToEnemy" << std::endl;
            break;
        case Actions::KillEnemy:
            std::cout << "KillEnemy" << std::endl;
            break;
        case Actions::HealSelf:
            std::cout << "HealSelf" << std::endl;
            break;
        case Actions::Count:
        case Actions::None:
        default:
            throw std::invalid_argument("Invalid action provided");
        }
        iterate = iterate->parent;
    }
    
    
    return 0;
}
