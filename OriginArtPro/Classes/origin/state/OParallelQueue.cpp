#include "OParallelQueue.h"

USING_NS_O;

StateParallelQueue::StateParallelQueue(const DynamicStateDefiniation * dynamicStateDefiniation) :DynamicState(dynamicStateDefiniation)
{

}

StateParallelQueue::~StateParallelQueue()
{

}

void StateParallelQueue::push(DynamicState * state)
{
	if (!isStart()) return;
	_parallelQueue.push(state);
	if (!isRunning()) state->exclusion();
}

void StateParallelQueue::insert(DynamicState * state, size_t index)
{
	if (!isStart()) return;
	_parallelQueue.getContainer().insert(index, state);
	if (!isRunning()) state->exclusion();
}

void StateParallelQueue::eraseObject(DynamicState * state)
{
	if (!isStart()) return;
	if (_parallelQueue.getContainer().contains(state))
	{
		if (!isRunning()) state->unexclusion();
		_parallelQueue.getContainer().eraseObject(state);
	}
}

void StateParallelQueue::startExecute()
{

}

void StateParallelQueue::stopExecute()
{
	if (!isRunning())
	{
		for (auto&state : _parallelQueue.getContainer())
		{
			state->unexclusion();
		}
	}
	_parallelQueue.getContainer().clear();
}

void StateParallelQueue::pauseExecute()
{
	for (auto&state : _parallelQueue.getContainer())
	{
		state->exclusion();
	}
}

void StateParallelQueue::resumeExecute()
{
	for (auto&state : _parallelQueue.getContainer())
	{
		state->unexclusion();
	}
}