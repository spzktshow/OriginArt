#ifndef __ORIGIN_GAME_DEFINIATION_H_
#define __ORIGIN_GAME_DEFINIATION_H_

#include "OriginGameMacros.h"
#include "OGUnitStateDefiniation.h"

NS_OG_BEGIN

class UnitPropertyDefiniation
{
public:
	UnitPropertyDefiniation();
	~UnitPropertyDefiniation();

	CC_SYNTHESIZE(float, _moveSpeed, MoveSpeed);
	CC_SYNTHESIZE(float, _actionSpeed, ActionSpeed);
};

class UnitDefiniation
{
public:
	UnitDefiniation();
	virtual ~UnitDefiniation();

	CC_SYNTHESIZE(unsigned int, _id, ID);

	CC_SYNTHESIZE_PASS_BY_REF(std::string, _type, Type);

	CC_SYNTHESIZE_PASS_BY_REF(std::string, _name, Name);

	CC_SYNTHESIZE(const UnitStatesDefiniation *, _statesDefiniation, StatesDefiniation);

	CC_SYNTHESIZE(const UnitPropertyDefiniation *, _propertyDefiniation, PropertyDefiniation);
};

NS_OG_END

#endif /**__ORIGIN_GAME_DEFINIATION_H_*/