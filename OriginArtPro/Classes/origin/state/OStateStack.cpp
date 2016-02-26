#include "OStateStack.h"

USING_NS_O;
/**************StateStack***************/
StateStack::StateStack(const DynamicStateDefiniation * dynamicStateDefiniation) :DynamicState(dynamicStateDefiniation){}

StateStack::~StateStack(){}

void StateStack::pushBack(DynamicState * state)
{
	if (!isStart()) return;
	//栈已经运行的情况下需要对栈顶状态进行排斥(+1)
	if (isRunning()) topExclusion();
	_stack.push(state);
	//栈停止状态下栈顶进行排斥(+1)
	if (!isRunning()) topExclusion();
}

void StateStack::popBack()
{
	if (!isStart()) return;
	if (_stack.size() > 0)
	{
		//栈停止的情况下解除栈顶排斥(-1)
		if (!isRunning()) topUnExclusion();
		_stack.pop();
	}
	//栈运行情况下栈顶接触排斥(-1)
	if (isRunning()) topUnExclusion();
}

const Stack<DynamicState *> StateStack::getStack() const
{
	return _stack;
}

void StateStack::startExecute()
{

}

void StateStack::stopExecute()
{
	while (_stack.size() > 0)
	{
		popBack();
	}
}

void StateStack::pauseExecute()
{
	topExclusion();
}

void StateStack::resumeExecute()
{
	topUnExclusion();
}

void StateStack::topExclusion()
{
	if (_stack.size() > 0)
	{
		DynamicState * state = _stack.top();
		state->exclusion();
	}
}

void StateStack::topUnExclusion()
{
	if (_stack.size() > 0)
	{
		DynamicState * state = _stack.top();
		state->unexclusion();
	}
}
