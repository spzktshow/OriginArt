#include "OGState.h"

USING_NS_OG;

const float StateComponentDefiniation::TIME_DATA_MAX = FLT_MAX;

/********************StateComponent**********************/
StateComponent::StateComponent(const StateComponentDefiniation * stateComponentDefiniation)
	:origin::DynamicState(stateComponentDefiniation)
	, _timeData(0.0f)
{

}

StateComponent::~StateComponent()
{

}

const StateComponentDefiniation * StateComponent::getStateComponentDefiniation() const
{
	return dynamic_cast<const StateComponentDefiniation *>(getDynamicStateDefiniation());
}

void StateComponent::startExecute()
{
	origin::DynamicState::startExecute();

	const StateComponentDefiniation * definiation = getStateComponentDefiniation();
	if (definiation && definiation->getTime() > 0 && getScheduler())
	{
		getScheduler()->schedule(schedule_selector(StateComponent::lifeTimeUpdate), this, 0.1, (int)(definiation->getTime() * 10.0f), 0.0f, !isRunning());
	}
	else
	{
		_timeData = StateComponentDefiniation::TIME_DATA_MAX;
	}
}

void StateComponent::stopExecute()
{
	const StateComponentDefiniation * definiation = getStateComponentDefiniation();
	if (definiation && definiation->getTime() > 0)
	{
		getScheduler()->unschedule(schedule_selector(StateComponent::lifeTimeUpdate), this);
	}
	origin::DynamicState::stopExecute();
}

void StateComponent::pauseExecute()
{
	if (getEventDispatcher())
	{
		getEventDispatcher()->setEnabled(false);
	}
	origin::DynamicState::pauseExecute();
	if (getScheduler())
	{
		getScheduler()->pauseTarget(this);
	}
}

void StateComponent::resumeExecute()
{
	if (getScheduler())
	{
		getScheduler()->resumeTarget(this);
	}
	origin::DynamicState::resumeExecute();
	if (getEventDispatcher())
	{
		getEventDispatcher()->setEnabled(true);
	}
}

void StateComponent::lifeTimeUpdate(float dt)
{
	_timeData += 0.1f;
	const StateComponentDefiniation * definiation = getStateComponentDefiniation();
	if (definiation)
	{
		if (_timeData >= definiation->getTime())
		{
			lifeTimeComplete(_timeData);
		}
	}
}

void StateComponent::lifeTimeComplete(float dt)
{

}