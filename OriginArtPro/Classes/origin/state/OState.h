#ifndef __ORIGIN_STATE_H_
#define __ORIGIN_STATE_H_

#include "cocos2d.h"
#include "OExclusion.h"

NS_O_BEGIN

class StateDefinitaion
{
public:
	StateDefinitaion(const std::string& stateType);
	virtual ~StateDefinitaion();

	void setStateType(const std::string& stateType);

	const std::string& getStateType() const;

protected:
	std::string _stateType;
};

class State : public cocos2d::Ref
{
public:
	State(const StateDefinitaion * stateDefiniation);
	virtual ~State();

	virtual bool init();

	virtual void start();
	virtual void stop();

	void pause();
	void resume();

	bool isStart() const;
	bool isRunning() const;

	const StateDefinitaion * getStateDefiniation() const;

	cocos2d::EventDispatcher * getEventDispatcher() const;
	cocos2d::Scheduler * getScheduler() const;
protected:
	virtual void startExecute() = 0;
	virtual void stopExecute() = 0;

	virtual void pauseExecute() = 0;
	virtual void resumeExecute() = 0;

	const StateDefinitaion * _stateDefiniation;

	/****标记状态是否已经开始****/
	bool _start;
	/****标记状态是否在运行***/
	bool _running;

	cocos2d::EventDispatcher * _eventDispatcher;
	cocos2d::Scheduler * _scheduler;
};

class DynamicState : public State, public ExclusionProtocol
{
public:
	DynamicState(const StateDefinitaion * stateDefiniation, const ExclusionDefiniation * exclusionDefiniation);
	virtual ~DynamicState();

	int exclusion() override;
	int unexclusion() override;
	void resetExclusion() override;

	void start(unsigned int exclusionCount);
	void start() override;
	virtual void refresh();

	const Exclusion * getExclusion() const;
protected:
	Exclusion * _exclucsion;
};

NS_O_END

#endif