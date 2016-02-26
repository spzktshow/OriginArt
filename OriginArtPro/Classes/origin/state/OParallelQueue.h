#ifndef __ORIGIN_PARALLEL_QUEUE_H_
#define __ORIGIN_PARALLEL_QUEUE_H_

#include "OriginMacros.h"
#include "OState.h"
#include "OQueue.h"
#include "OList.h"

NS_O_BEGIN

class StateParallelQueue : public DynamicState
{
public:
	StateParallelQueue(const DynamicStateDefiniation * dynamicStateDefiniation);
	virtual ~StateParallelQueue();

	void push(DynamicState * state);
	void insert(DynamicState * state, size_t index);
	void eraseObject(DynamicState * state);
protected:
	void startExecute() override;
	void stopExecute() override;

	void pauseExecute() override;
	void resumeExecute() override;

	Queue<DynamicState *, origin::List<DynamicState *>> _parallelQueue;
};

NS_O_END;

#endif // !__ORIGIN_PARALLEL_QUEUE_H_
