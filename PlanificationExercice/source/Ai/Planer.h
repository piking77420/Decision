#pragma once

#include "Actions.h"
#include "../Stopwatch.h"
#include "WorldState.h"

struct Node
{
    WordlState wordlState;
    Actions action;
    int totalCost;
    const Node* parent;
};

class Planer
{
public:

    enum struct PlanerConstructionMethod
    {
        Forward,
        Backward,
    };
    
    struct PlanerContext
    {
        std::vector<Node> nodes;
        std::vector<std::pair<Node*, float>> leafNodes;
        int nodeCount;
    };

    Planer(size_t maxNodeCount , PlanerConstructionMethod planerConstructionMethod) : 
        m_MaxNodeCount(maxNodeCount), m_PlanerConstructionMethod(planerConstructionMethod)
    {
        
    }

    void InitGopContext(PlanerContext* goapContext);
    
    void BuildPlan(PlanerContext* goapContext, 
        const std::vector<ActionsAndCost>& _availableAction,
            WordlState baseWorldState, WordlState goalWorldState);

    
private:

    size_t m_MaxNodeCount;

    PlanerConstructionMethod m_PlanerConstructionMethod;

    Stopwatch m_Stopwatch;

    void ClearGopContext(PlanerContext* goapContext);

    Node CreateChildNode(const Node* _parent, const WordlState& _newWordlState, ActionsAndCost _action);

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

    void BuildGraphForward(PlanerContext* _currentContex,
        const Node* const _parent,
        const std::vector<ActionsAndCost>& _availableAction,
        const WordlState& _worldGoal);

    void BuildGraphBackward(PlanerContext* _currentContex,
         const Node* _parent, const WordlState& _initialState, const WordlState& _goalState, const std::vector<ActionsAndCost>& _actionFromGoalState);
   
};

