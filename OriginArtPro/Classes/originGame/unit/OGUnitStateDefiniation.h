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

	/**����ʱ�䣬���ʱ���Ǳ�׼ʱ�䣬��ʾ�����ٶ������ﲥ��֡��ʱ�䣬��������м���״̬��ʱ�����***/
	CC_SYNTHESIZE(float, _time, Time);

	/***��������**/
	CC_SYNTHESIZE_PASS_BY_REF(std::string, _actionName, ActionName);
};

NS_OG_END;

#endif // !__ORIGIN_UNIT_STATE_DEFINIATION_H_
