#ifndef __ORIGIN_STATE_STACK_H_
#define __ORIGIN_STATE_STACK_H_

#include "OriginMacros.h"
#include "OState.h"
#include "OStack.h"

NS_O_BEGIN

class StateStack : public DynamicState
{
public:
	StateStack(const DynamicStateDefiniation * dynamicStateDefiniation);
	virtual ~StateStack();

	void pushBack(DynamicState * state);
	void popBack();

	const Stack<DynamicState *> getStack() const;

	bool hasPopBack();
	DynamicState * getPopBack();

	static StateStack * create(const DynamicStateDefiniation * dynamicStateDefiniation)
	{
		StateStack * stack = new StateStack(dynamicStateDefiniation);
		if (stack && stack->init())
		{
			stack->autorelease();
			return stack;
		}
		CC_SAFE_DELETE(stack);
		return nullptr;
	}
protected:
	void startExecute() override;
	void stopExecute() override;

	void pauseExecute() override;
	void resumeExecute() override;

	Stack<DynamicState *>  _stack;

	void topExclusion();
	void topUnExclusion();
};

NS_O_END;

#endif/**__ORIGIN_STATE_STACK_H_*/