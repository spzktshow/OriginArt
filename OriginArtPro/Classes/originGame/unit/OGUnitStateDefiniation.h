#ifndef __ORIGIN_UNIT_STATE_DEFINIATION_H_
#define __ORIGIN_UNIT_STATE_DEFINIATION_H_

#include "OriginGameMacros.h"
#include "origin.h"
#include "cocostudio/DictionaryHelper.h"
#include "OGState.h"

NS_OG_BEGIN

class UnitStateDefiniation : public StateComponentDefiniation
{
public:
	UnitStateDefiniation(const std::string& type, const origin::ExclusionDefiniation * exclusionDefiniation);
	~UnitStateDefiniation();

	//view
	/***¶¯×÷Ãû³Æ**/
	CC_SYNTHESIZE_PASS_BY_REF(std::string, _actionName, ActionName);
};

class UnitStatesDefiniation
{
public:
	UnitStatesDefiniation();
	~UnitStatesDefiniation();

	const std::map<std::string, UnitStateDefiniation*>& getStates() const
	{
		return _states;
	}

	void setStates(const std::map<std::string, UnitStateDefiniation*>states)
	{
		_states = states;
	}
protected:
	std::map<std::string, UnitStateDefiniation *> _states;
};

NS_OG_END;

#endif // !__ORIGIN_UNIT_STATE_DEFINIATION_H_
