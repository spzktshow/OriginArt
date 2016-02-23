#ifndef __ORIGIN_UNIT_STATE_DEFINIATION_H_
#define __ORIGIN_UNIT_STATE_DEFINIATION_H_

#include "OriginGameMacros.h"
#include "origin.h"

NS_OG_BEGIN

class UnitStateDefiniation : public origin::StateDefinitaion
{
public:
	UnitStateDefiniation(const std::string& type);
	~UnitStateDefiniation();

	/**持续时间，这个时间是标准时间，表示正常速度下人物播放帧的时间，如果人物有加速状态则时间会变短***/
	CC_SYNTHESIZE(float, _time, Time);

	/***动作名称**/
	CC_SYNTHESIZE_PASS_BY_REF(std::string, _actionName, ActionName);
};

NS_OG_END;

#endif // !__ORIGIN_UNIT_STATE_DEFINIATION_H_
