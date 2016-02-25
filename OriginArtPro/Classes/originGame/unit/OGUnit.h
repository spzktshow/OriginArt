#ifndef __ORIGIN_GAME_UNIT_H_
#define __ORIGIN_GAME_UNIT_H_

#include "cocos2d.h"
#include "OGUnitDefiniation.h"
#include "OGUnitState.h"

NS_OG_BEGIN

class Unit : public cocos2d::Ref
{
public:
	Unit(const UnitDefiniation * unitDefiniation);
	~Unit();

	CC_SYNTHESIZE(unsigned int, _uid, UID);
};

NS_OG_END

#endif /**__ORIGIN_GAME_UNIT_H_**/