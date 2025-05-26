#include "Planer.h"

void Planer::InitGopContext(PlanerContext* goapContext)
{
    goapContext->nodeCount = 0;
    goapContext->nodes.resize(m_MaxNodeCount);
}

void Planer::ClearGopContext(PlanerContext* goapContext)
{
    goapContext->nodeCount = 0;
}
#pragma region Forward
void Planer::BuildGraphForward(PlanerContext* _currentContex,const Node* const _parent,
                             const std::vector<ActionsAndCost>& _availableAction, const WordlState& _worldGoal)
{
    for (auto& actionsAndCost : _availableAction)
    {
        const Actions action = actionsAndCost.action;

        bool isActionAvailable = IsActionAvailable(action, _parent->wordlState);

        if (!isActionAvailable)
            continue;

        // first tree nodes
        if (_parent->parent == nullptr)
        {
            m_Stopwatch.Start();
        }
            
        WordlState newWordlState = ApplieActionToWorld(action, _parent->wordlState);
        Node* newNode = &_currentContex->nodes[_currentContex->nodeCount++];
        *newNode = CreateChildNode(_parent, newWordlState, actionsAndCost);
        
        
        newNode->parent = _parent;
        std::vector<ActionsAndCost> actionSubSet = CreateActionSubSet(_availableAction, action);

        if (IsGoalAchieve(newWordlState, _worldGoal) || actionSubSet.empty())
        {
            _currentContex->leafNodes.emplace_back(newNode, m_Stopwatch.GetTimeElapsed());
        }
        else
        {
            BuildGraphForward(_currentContex, newNode, actionSubSet, _worldGoal);
        }
        
    }
}


#pragma endregion Forward

void Planer::BuildPlan(PlanerContext* goapContext,
    const std::vector<ActionsAndCost>& _availableAction,
    WordlState baseWorldState, WordlState goalWorldState)
{
    ClearGopContext(goapContext);

    switch (m_PlanerConstructionMethod)
    {
    case Planer::PlanerConstructionMethod::Forward:
        {
            Node* root = &goapContext->nodes[goapContext->nodeCount++];
            *root =
                {
                .wordlState = baseWorldState,
                .action = Actions::None,
                .totalCost = 0,
                .parent = nullptr,
                };

            m_Stopwatch.Start();
            BuildGraphForward(goapContext, root, _availableAction, goalWorldState);
        }
        break;
    case Planer::PlanerConstructionMethod::Backward:
        {
            /*
            std::vector<ActionsAndCost> actions = GetActionFromWorldState();
            Node* root = &goapContext->nodes[goapContext->nodeCount++];
            
            BuildGraphBackward(goapContext, baseWorldState, goalWorldState, actions);*/
        }
        
        break;
    default:
        break;
    }

}


Node Planer::CreateChildNode(const Node* _parent, const WordlState& _newWordlState, ActionsAndCost _action)
{
    return
    {
        .wordlState = _newWordlState,
        .action = _action.action,
        .totalCost = _parent->totalCost + _action.cost,
    };
}


void Planer::BuildGraphBackward(PlanerContext* _currentContext, const Node* _parent, const WordlState& _initialState,
    const WordlState& _goalState, const std::vector<ActionsAndCost>& _actionFromGoalState)
{
/*
    for (auto& action : _actionFromGoalState)
    {
        
        Node* newNode = &_currentContext->nodes[_currentContext->nodeCount++];
        newNode->parent = _parent;

        if (rewindWorldState == _initialState)
        {
            _currentContext->leafNodes.emplace_back(newNode, m_Stopwatch.GetTimeElapsed());
        }
        
    }*/
}