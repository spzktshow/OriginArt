#include "OStateStack.h"

USING_NS_O;
/**************StateStack***************/
StateStack::StateStack(const DynamicStateDefiniation * dynamicStateDefiniation) :DynamicState(dynamicStateDefiniation){}

StateStack::~StateStack(){}

void StateStack::pushBack(DynamicState * state)
{
	if (!isStart()) return;
	//ջ�Ѿ����е��������Ҫ��ջ��״̬�����ų�(+1)
	if (isRunning()) topExclusion();
	_stack.push(state);
	//ջֹͣ״̬��ջ�������ų�(+1)
	if (!isRunning()) topExclusion();
}

void StateStack::popBack()
{
	if (!isStart()) return;
	if (_stack.size() > 0)
	{
		//ջֹͣ������½��ջ���ų�(-1)
		if (!isRunning()) topUnExclusion();
		_stack.pop();
	}
	//ջ���������ջ���Ӵ��ų�(-1)
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
