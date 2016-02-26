#include "OGState.h"

USING_NS_OG;

const float StateFactorDefiniation::TIME_DATA_MAX = FLT_MAX;

/********************StateComponent**********************/
StateFactor::StateFactor(const StateFactorDefiniation * stateComponentDefiniation)
	:origin::DynamicState(stateComponentDefiniation)
	, _timeData(0.0f)
{

}

StateFactor::~StateFactor()
{

}

const StateFactorDefiniation * StateFactor::getStateComponentDefiniation() const
{
	return dynamic_cast<const StateFactorDefiniation *>(getDynamicStateDefiniation());
}

void StateFactor::startExecute()
{
	origin::DynamicState::startExecute();

	const StateFactorDefiniation * definiation = getStateComponentDefiniation();
	if (definiation && definiation->getTime() > 0 && getScheduler())
	{
		getScheduler()->schedule(schedule_selector(StateFactor::lifeTimeUpdate), this, 0.1, (int)(definiation->getTime() * 10.0f), 0.0f, !isRunning());
	}
	else
	{
		_timeData = StateFactorDefiniation::TIME_DATA_MAX;
	}
}

void StateFactor::stopExecute()
{
	const StateFactorDefiniation * definiation = getStateComponentDefiniation();
	if (definiation && definiation->getTime() > 0)
	{
		getScheduler()->unschedule(schedule_selector(StateFactor::lifeTimeUpdate), this);
	}
	origin::DynamicState::stopExecute();
}

void StateFactor::pauseExecute()
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

void StateFactor::resumeExecute()
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

void StateFactor::lifeTimeUpdate(float dt)
{
	_timeData += 0.1f;
	const StateFactorDefiniation * definiation = getStateComponentDefiniation();
	if (definiation)
	{
		if (_timeData >= definiation->getTime())
		{
			lifeTimeComplete(_timeData);
		}
	}
}

void StateFactor::lifeTimeComplete(float dt)
{

}