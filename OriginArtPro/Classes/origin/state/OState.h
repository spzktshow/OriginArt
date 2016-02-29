#ifndef __ORIGIN_STATE_H_
#define __ORIGIN_STATE_H_

#include "cocos2d.h"
#include "OExclusion.h"

NS_O_BEGIN

class StateDefiniation
{
public:
	StateDefiniation(const std::string& stateType);
	virtual ~StateDefiniation();

	void setStateType(const std::string& stateType);

	const std::string& getStateType() const;
protected:
	std::string _stateType;
};

class State : public cocos2d::Ref
{
public:
	State(const StateDefiniation * stateDefiniation);
	virtual ~State();

	virtual bool init();

	virtual void start();
	virtual void stop();

	void pause();
	void resume();

	bool isStart() const;
	bool isRunning() const;

	const StateDefiniation * getStateDefiniation() const;

	cocos2d::EventDispatcher * getEventDispatcher() const;
	cocos2d::Scheduler * getScheduler() const;
protected:
	virtual void startExecute(){};
	virtual void stopExecute(){};

	virtual void pauseExecute(){};
	virtual void resumeExecute(){};

	const StateDefiniation * _stateDefiniation;

	/****标记状态是否已经开始****/
	bool _start;
	/****标记状态是否在运行***/
	bool _running;

	cocos2d::EventDispatcher * _eventDispatcher;
	cocos2d::Scheduler * _scheduler;
};

class DynamicStateDefiniation : public StateDefiniation
{
public:
	DynamicStateDefiniation(const std::string&stateType, const ExclusionDefiniation*exclusionDefiniation);
	virtual ~DynamicStateDefiniation();

	CC_SYNTHESIZE_READONLY(const ExclusionDefiniation *, _exclusionDefiniation, ExclusionDef);
};

class DynamicState : public State, public ExclusionProtocol
{
public:
	DynamicState(const DynamicStateDefiniation * dynamicStateDefiniation);
	virtual ~DynamicState();

	int exclusion() override;
	int unexclusion() override;
	void resetExclusion() override;

	void start(unsigned int exclusionCount);
	void start() override;
	virtual void refresh();

	const Exclusion * getExclusion() const;

	const DynamicStateDefiniation * getDynamicStateDefiniation() const
	{
		return dynamic_cast<const DynamicStateDefiniation *>(getStateDefiniation());
	}
protected:
	Exclusion * _exclucsion;
};

NS_O_END

#endif