#include "OState.h"

NS_O_BEGIN
/**********StateDefiniation**********/
StateDefiniation::StateDefiniation(const std::string& stateType) :_id(0)
{
	setStateType(stateType);
}

StateDefiniation::~StateDefiniation()
{
}

void StateDefiniation::setStateType(const std::string& stateType)
{
	if (_stateType == stateType) return;
	_stateType = stateType;
}

const std::string& StateDefiniation::getStateType() const
{
	return _stateType;
}

/***************state****************/
State::State(const StateDefiniation * stateDefiniation)
	:_start(false)
	, _running(false)
	, _eventDispatcher(nullptr)
	, _scheduler(nullptr)
	, _stateDefiniation(stateDefiniation)
{
	CCASSERT(stateDefiniation != nullptr, "stateDefiniation must != nullptr");
}

State::~State()
{
	stop();
	_stateDefiniation = nullptr;
}

bool State::init()
{
	return true;
}

void State::start()
{
	if (!_start)
	{
		_start = true;
		startExecute();
	}

	resume();
}

void State::stop()
{
	pause();

	if (_start)
	{
		stopExecute();
		_start = false;
	}
}

void State::pause()
{
	if (_start && _running)
	{
		_running = false;
		pauseExecute();
	}
}

void State::resume()
{
	if (_start && !_running)
	{
		_running = true;
		resumeExecute();
	}
}

bool State::isStart() const
{
	return _start;
}

bool State::isRunning() const
{
	return _running;
}

const StateDefiniation * State::getStateDefiniation() const
{
	return _stateDefiniation;
}

cocos2d::EventDispatcher * State::getEventDispatcher() const
{
	return _eventDispatcher;
}

cocos2d::Scheduler * State::getScheduler() const
{
	return _scheduler;
}

/******************DynamicStateDefiniation*****************/
DynamicStateDefiniation::DynamicStateDefiniation(const std::string&stateType, const ExclusionDefiniation*exclusionDefiniation)
	:StateDefiniation(stateType)
	, _exclusionDefiniation(exclusionDefiniation)
{

}

DynamicStateDefiniation::~DynamicStateDefiniation()
{
	_exclusionDefiniation = nullptr;
}

/*****************DynamicState****************/
DynamicState::DynamicState(const DynamicStateDefiniation * dynamicStateDefiniation) :State(dynamicStateDefiniation), _exclucsion(nullptr)
{
	_exclucsion = new Exclusion(dynamicStateDefiniation->getExclusionDef());
}

DynamicState::~DynamicState()
{
	CC_SAFE_DELETE(_exclucsion);
}

int DynamicState::exclusion()
{
	_exclucsion->exclusion();
	refresh();
	return _exclucsion->getExclusionCount();
}

int DynamicState::unexclusion()
{
	_exclucsion->unexclusion();
	refresh();
	return _exclucsion->getExclusionCount();
}

void DynamicState::resetExclusion()
{
	_exclucsion->resetExclusion();
	refresh();
}

void DynamicState::start(unsigned int exclusionCount)
{
	if (!_start)
	{
		_start = true;
		startExecute();
	}

	while (exclusionCount > 0)
	{
		exclusion();
		exclusionCount--;
	}

	refresh();
}

void DynamicState::start()
{
	if (!_start)
	{
		_start = true;
		startExecute();
	}

	refresh();
}

void DynamicState::refresh()
{
	if (_exclucsion->checkType() == ExclusionDefiniation::ExclusionType::PAUSE)
	{
		pause();
	}
	else
	{
		resume();
	}
}

const Exclusion * DynamicState::getExclusion() const
{
	return _exclucsion;
}

NS_O_END