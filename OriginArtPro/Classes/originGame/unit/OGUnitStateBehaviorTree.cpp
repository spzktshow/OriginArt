#include "OGUnitStateBehaviorTree.h"
#include "OGUnit.h"
USING_NS_OG

/********************UnitCurrentStateEqualCondition****************************/
const std::string UnitCurrentStateEqualCondition::TYPE = "unitCurrentStateEqualCondition";

UnitCurrentStateEqualCondition::UnitCurrentStateEqualCondition(const std::string& currentState)
:origin::ConditionBehaviorTreeNode(UnitCurrentStateEqualCondition::TYPE)
, _currentState(currentState)
{

}

UnitCurrentStateEqualCondition::~UnitCurrentStateEqualCondition()
{

}

bool UnitCurrentStateEqualCondition::execute(cocos2d::EventCustom * event) const
{
	const UnitStateData * data = (const UnitStateData *)event->getUserData();
	if (data)
	{
		if (data->unit)
		{
			origin::StateStack * behaviorContext = data->unit->getBehaviorContext();
			if (behaviorContext)
			{
				UnitState * unitState = dynamic_cast<UnitState *>(behaviorContext->getPopBack());
				if (unitState && unitState->getStateDefiniation() && unitState->getStateDefiniation()->getStateType() == _currentState)
				{
					return true;
				}
			}
		}
	}
	return false;
}

/**************************UnitCurrentStateLifeTimeEqualCondition*******************************/
const std::string UnitCurrentStateLifeTimeEqualCondition::TYPE = "unitCurrentStateLifeTimeEqualCondition";

UnitCurrentStateLifeTimeEqualCondition::UnitCurrentStateLifeTimeEqualCondition(const EqualSign&equalSign, float time)
	:origin::ConditionBehaviorTreeNode(UnitCurrentStateLifeTimeEqualCondition::TYPE)
	, _equalSign(equalSign)
	, _time(time)
{

}

UnitCurrentStateLifeTimeEqualCondition::~UnitCurrentStateLifeTimeEqualCondition()
{

}

bool UnitCurrentStateLifeTimeEqualCondition::execute(cocos2d::EventCustom * event) const
{
	const UnitStateData * data = (const UnitStateData *)event->getUserData();
	if (data)
	{
		if (data->unit)
		{
			origin::StateStack * behaviorContext = data->unit->getBehaviorContext();
			if (behaviorContext)
			{
				UnitState * unitState = dynamic_cast<UnitState *>(behaviorContext->getPopBack());
				if (_equalSign == EqualSign::LESS)
				{
					if (unitState->getTimeData() > _time)
					{
						return true;
					}
				}
				else if (_equalSign == EqualSign::EQUAL)
				{
					if (unitState->getTimeData() == _time)
					{
						return true;
					}
				}
				else if (_equalSign == EqualSign::GREATER)
				{
					if (unitState->getTimeData() < _time)
					{
						return true;
					}
				}
				else
				{
					return false;
				}
			}
		}
	}
	return false;
}