#ifndef __ORIGIN_GAME_STATE_H_
#define __ORIGIN_GAME_STATE_H_

#include "OriginGameMacros.h"

NS_OG_BEGIN

class StateFactorDefiniation : public origin::DynamicStateDefiniation
{
public:
	static const float TIME_DATA_MAX;

	StateFactorDefiniation(const std::string& type, const origin::ExclusionDefiniation * exclusionDefiniation);
	virtual ~StateFactorDefiniation();

	/**����ʱ�䣬���ʱ���Ǳ�׼ʱ�䣬��ʾ�����ٶ������ﲥ��֡��ʱ�䣬��������м���״̬��ʱ�����,
	���ֵΪ<=0���ʾ���״̬Ϊѭ��״̬,time�ĵ�λΪ�룬��ȷ��С�����һλ
	***/
	CC_SYNTHESIZE(float, _time, Time);
};

class StateFactor : public origin::DynamicState
{
public:
	StateFactor(const StateFactorDefiniation * stateComponentDefiniation);
	virtual ~StateFactor();

	const StateFactorDefiniation * getStateComponentDefiniation() const;
protected:
	void startExecute() override;
	void stopExecute() override;
	void pauseExecute() override;
	void resumeExecute() override;

	virtual void lifeTimeComplete(float dt);
	virtual void lifeTimeUpdate(float dt);

	/*********��ǰ����ʱ��, ����״̬Ϊѭ��״̬ʱ��_timeData�����FLT_MAX********/
	CC_SYNTHESIZE_READONLY(float, _timeData, TimeData);
};

NS_OG_END

#endif//__ORIGIN_GAME_STATE_H_