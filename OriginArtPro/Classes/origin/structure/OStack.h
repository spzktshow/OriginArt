#ifndef __OSTACK_H_
#define __OSTACK_H_

#include "OState.h"

NS_O_BEGIN

class StateStackProtocol
{
public:
	virtual DynamicState * back() const = 0;

	virtual void resumeBack() = 0;
	virtual void pauseBack() = 0;

	virtual void pushBack(DynamicState *) = 0;
	virtual void popFront() = 0;

	virtual void pushBackAuto(DynamicState *) = 0;
	virtual void popFrontAuto() = 0;
};

template<typename T>
class StateStack : public DynamicState, public StateStackProtocol
{
public:
	StateStack(const StateDefinitaion * stateDefiniation, const ExclusionDefiniation * exclusionDefiniation);
	virtual ~StateStack();

	DynamicState * back() const override;

	virtual void resumeBack() override;
	virtual void pauseBack() override;

	void pushBack(DynamicState *) override;
	void popFront() override;

	void pushBackAuto(DynamicState *) override;
	void popFrontAuto() override;
protected:
	void startExecute() override;
	void stopExecute() override;

	void pauseExecute() override;
	void resumeExecute() override;

	T _container;
};

NS_O_END
#endif// !__OSTACK_H_