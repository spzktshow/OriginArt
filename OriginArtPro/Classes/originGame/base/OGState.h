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

	/**持续时间，这个时间是标准时间，表示正常速度下人物播放帧的时间，如果人物有加速状态则时间会变短,
	如果值为<=0则表示这个状态为循环状态,time的单位为秒，精确到小数点后一位
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

	/*********当前运行时间, 当该状态为循环状态时，_timeData恒等于FLT_MAX********/
	CC_SYNTHESIZE_READONLY(float, _timeData, TimeData);
};

NS_OG_END

#endif//__ORIGIN_GAME_STATE_H_