#include "OStateQueue.h"

USING_NS_O;

StateQueue::StateQueue(const DynamicStateDefiniation * dynamicStateDefiniation) :DynamicState(dynamicStateDefiniation){}

StateQueue::~StateQueue(){};

void StateQueue::push(DynamicState * state)
{
	if (!isStart()) return;
	_queue.push(state);
	if (_queue.size() > 1 || !isRunning()) backExclusion();
}

void StateQueue::pop()
{
	if (!isStart()) return;
	if (_queue.size() > 0)
	{
		if (!isRunning()) frontUnExclusion();
		_queue.pop();
	}
	if (isRunning()) frontUnExclusion();
}

const Queue<DynamicState *> StateQueue::getQueue() const
{
	return _queue;
}

void StateQueue::startExecute()
{

}

void StateQueue::stopExecute()
{
	while (_queue.size() > 0)
	{
		pop();
	}
}

void StateQueue::pauseExecute()
{
	frontExclusion();
}

void StateQueue::resumeExecute()
{
	frontUnExclusion();
}

void StateQueue::frontExclusion()
{
	if (_queue.size() > 0)
	{
		DynamicState * state = _queue.front();
		state->exclusion();
	}
}

void StateQueue::frontUnExclusion()
{
	if (_queue.size() > 0)
	{
		DynamicState * state = _queue.front();
		state->unexclusion();
	}
}

void StateQueue::backExclusion()
{
	if (_queue.size() > 0)
	{
		DynamicState * state = _queue.back();
		state->exclusion();
	}
}
