#ifndef __ORIGIN_STATE_QUEUE_H_
#define __ORIGIN_STATE_QUEUE_H_

#include "OriginMacros.h"
#include "OState.h"
#include "OQueue.h"

NS_O_BEGIN

class StateQueue : public DynamicState
{
public:
	StateQueue(const StateDefinitaion * stateDefiniation, const ExclusionDefiniation * exclusionDefiniation) :DynamicState(stateDefiniation, exclusionDefiniation);
	virtual ~StateQueue();

	void push(DynamicState * state);
	void pop();

	const Queue<DynamicState *> getQueue() const;
protected:
	void startExecute() override;
	void stopExecute() override;

	void pauseExecute() override;
	void resumeExecute() override;

	Queue<DynamicState *> _queue;

	void frontExclusion();
	void frontUnExclusion();
	void backExclusion();
};

NS_O_END;

#endif/**__ORIGIN_STATE_QUEUE_H_*/