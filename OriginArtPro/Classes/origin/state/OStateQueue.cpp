#include "OStateQueue.h"

USING_NS_O;

StateQueue::StateQueue(const StateDefinitaion * stateDefiniation, const ExclusionDefiniation * exclusionDefiniation) :DynamicState(stateDefiniation, exclusionDefiniation){}

StateQueue::~StateQueue(){};

void StateQueue::push(DynamicState * state)
{

}

void StateQueue::pop()
{

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

}

void StateQueue::pauseExecute()
{

}

void StateQueue::resumeExecute()
{

}

