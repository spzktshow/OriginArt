#include "OGUnitState.h"
#include "OGUnit.h"
USING_NS_OG;

/***************UnitState**************/
UnitState::UnitState(const UnitStateDefiniation *unitStateDefiniation, Unit * unit) 
	:StateFactor(unitStateDefiniation)
	, _unit(unit)
{

}

UnitState::~UnitState()
{
	_unit = nullptr;
}

void UnitState::startExecute()
{
	StateFactor::startExecute();
}

void UnitState::stopExecute()
{
	StateFactor::stopExecute();
}

void UnitState::pauseExecute()
{
	StateFactor::pauseExecute();
	if (getScheduler())
	{
		getScheduler()->pauseTarget(this);
	}
	if (getEventDispatcher())
	{
		getEventDispatcher()->setEnabled(false);
	}
}

void UnitState::resumeExecute()
{
	if (getEventDispatcher())
	{
		getEventDispatcher()->setEnabled(true);
	}
	if (getScheduler())
	{
		getScheduler()->resumeTarget(this);
	}
	StateFactor::resumeExecute();
}

void UnitState::lifeTimeUpdate(float dt)
{
	StateFactor::lifeTimeUpdate(dt);
	CCLOG("type=%s time=%f", _stateDefiniation->getStateType().c_str(), _timeData);
}

/*****************UnitAttackState******************/
UnitAttackState::UnitAttackState(const UnitStateDefiniation * unitStateDefiniation, Unit * unit)
	:UnitState(unitStateDefiniation, unit)
{

}

UnitAttackState::~UnitAttackState()
{

}

void UnitAttackState::lifeTimeComplete(float dt)
{
	if (_unit)
	{
		UnitStateData data;
		data.unit = _unit;
		_unit->executeBehavior(UnitStateData::EVENT_ATTACK_COMPLETE, data);
	}
}

/************************UnitBeAttackState**********************/
UnitBeAttackState::UnitBeAttackState(const UnitStateDefiniation * unitStateDefiniation, Unit * unit)
	:UnitState(unitStateDefiniation, unit)
{

}

UnitBeAttackState::~UnitBeAttackState()
{

}

void UnitBeAttackState::lifeTimeComplete(float dt)
{
	if (_unit)
	{
		UnitStateData data;
		data.unit = _unit;
		_unit->executeBehavior(UnitStateData::EVENT_BEATTACK_COMPLETE, data);
	}
}

/*****************UnitRunState***************/
UnitRunState::UnitRunState(const UnitStateDefiniation * unitStateDefiniation, Unit * unit)
	:UnitState(unitStateDefiniation, unit)
{

}

UnitRunState::~UnitRunState()
{

}

/********************UnitIdleState***************/
UnitIdleState::UnitIdleState(const UnitStateDefiniation * unitStateDefiniation, Unit * unit)
	:UnitState(unitStateDefiniation, unit)
{

}

UnitIdleState::~UnitIdleState()
{

}
/**********************UnitDeadState******************/
UnitDeadState::UnitDeadState(const UnitStateDefiniation * unitStateDefiniation, Unit * unit)
	:UnitState(unitStateDefiniation, unit)
{

}

UnitDeadState::~UnitDeadState()
{

}

void UnitDeadState::lifeTimeComplete(float dt)
{
	if (_unit)
	{
		UnitStateData data;
		data.unit = _unit;
		_unit->executeBehavior(UnitStateData::EVENT_DEAD_COMPLETE, data);
	}
}

/*********************UnitBehavior******************/
bool UnitBehavior::execute(const std::string&eventName, UnitStateData&data)
{
	Unit * unit = data.unit;
	if (!unit) return false;
	origin::StateStack * stack = unit->getBehaviorContext();
	if (!stack) return false;
	if (eventName == UnitStateData::EVENT_ATTACK)
	{
		UnitState * unitState = dynamic_cast<UnitState *>(stack->getPopBack());
		if (unitState->getUnitStateDefiniation())
		{
			if (unitState->getStateDefiniation()->getStateType() == UnitStateData::STATE_IDLE)
			{
				const UnitStatesDefiniation * statesDef = unit->getUnitDefiniation()->getStatesDefiniation();
				UnitAttackState * state = UnitAttackState::create(dynamic_cast<UnitStateDefiniation *>(statesDef->getStates().at(UnitStateData::STATE_ATTACK2)), unit);
				if (state)
				{
					state->start();
					stack->pushBack(state);
					unit->setBehaviorDirty(true);
					unit->refreshBehavior();
					return true;
				}
			}
			else if (unitState->getStateDefiniation()->getStateType() == UnitStateData::STATE_ATTACK1)
			{

			}
			else if (unitState->getStateDefiniation()->getStateType() == UnitStateData::STATE_ATTACK2)
			{
				stack->popBack();
				const UnitStatesDefiniation * statesDef = unit->getUnitDefiniation()->getStatesDefiniation();
				UnitAttackState * state = UnitAttackState::create(dynamic_cast<UnitStateDefiniation *>(statesDef->getStates().at(UnitStateData::STATE_SKILL)), unit);
				if (state)
				{
					state->start();
					stack->pushBack(state);
					unit->setBehaviorDirty(true);
					unit->refreshBehavior();
					return true;
				}
			}
			else if (unitState->getStateDefiniation()->getStateType() == UnitStateData::STATE_SKILL)
			{
				stack->popBack();
				const UnitStatesDefiniation * statesDef = unit->getUnitDefiniation()->getStatesDefiniation();
				UnitAttackState * state = UnitAttackState::create(dynamic_cast<UnitStateDefiniation *>(statesDef->getStates().at(UnitStateData::STATE_ATTACK1)), unit);
				if (state)
				{
					state->start();
					stack->pushBack(state);
					unit->setBehaviorDirty(true);
					unit->refreshBehavior();
					return true;
				}
			}
		}
	}
	else if (eventName == UnitStateData::EVENT_BEATTACK)
	{

	}
	else if (eventName == UnitStateData::EVENT_IDLE)
	{
		const UnitStatesDefiniation * statesDef = unit->getUnitDefiniation()->getStatesDefiniation();
		UnitRunState * state = UnitRunState::create(dynamic_cast<UnitStateDefiniation *>(statesDef->getStates().at(UnitStateData::STATE_IDLE)), unit);
		if (state)
		{
			state->start();
			stack->pushBack(state);
			unit->setBehaviorDirty(true);
			unit->refreshBehavior();
			return true;
		}
	}
	else if (eventName == UnitStateData::EVENT_RUN)
	{

	}
	else if (eventName == UnitStateData::EVENT_DEAD)
	{

	}
	else if (eventName == UnitStateData::EVENT_ATTACK_COMPLETE)
	{
		UnitState * unitState = dynamic_cast<UnitState *>(stack->getPopBack());
		if (unitState->getUnitStateDefiniation())
		{
			if (unitState->getStateDefiniation()->getStateType() == UnitStateData::STATE_ATTACK1
				|| unitState->getStateDefiniation()->getStateType() == UnitStateData::STATE_ATTACK2
				|| unitState->getStateDefiniation()->getStateType() == UnitStateData::STATE_SKILL
				)
			{
				unit->getBehaviorContext()->popBack();
				unit->setBehaviorDirty(true);
				unit->refreshBehavior();
				return true;
			}
		}
	}
}

bool UnitBehavior::refresh(UnitState * behaviorState, bool behaviorDirty, UnitState * moveBehaviorState, bool moveBehaviorDirty, Unit * unit)
{
	if (!unit) return false;
	if (behaviorState != nullptr)
	{
		if (behaviorState->getStateDefiniation())
		{
			if (behaviorState->getStateDefiniation()->getStateType() == UnitStateData::STATE_IDLE)
			{
				if (moveBehaviorState && moveBehaviorState->getUnitStateDefiniation())
				{
					unit->refreshAction(moveBehaviorState->getUnitStateDefiniation()->getActionName(), true);
					return true;
				}
				else
				{
					unit->refreshAction(behaviorState->getUnitStateDefiniation()->getActionName(), true);
					return true;
				}
			}
			else
			{
				unit->refreshAction(behaviorState->getUnitStateDefiniation()->getActionName(), false);
				return true;
			}
		}
	}
	return false;
}