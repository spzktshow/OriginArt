#ifndef __ORIGIN_UNIT_STATE_DEFINIATION_H_
#define __ORIGIN_UNIT_STATE_DEFINIATION_H_

#include "OriginGameMacros.h"
#include "origin.h"
#include "cocostudio/DictionaryHelper.h"
#include "OGState.h"

NS_OG_BEGIN

class UnitStateDefiniation : public StateFactorDefiniation
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

class Unit;
class UnitStateData
{
public:
	static const std::string EVENT_ATTACK;
	static const std::string EVENT_BEATTACK;
	static const std::string EVENT_RUN;
	static const std::string EVENT_DEAD;
	static const std::string EVENT_IDLE;

	static const std::string EVENT_ATTACK_COMPLETE;
	static const std::string EVENT_BEATTACK_COMPLETE;
	static const std::string EVENT_DEAD_COMPLETE;

	static const std::string STATE_ATTACK1;
	static const std::string STATE_ATTACK2;
	static const std::string STATE_SKILL;
	static const std::string STATE_DEAD;
	static const std::string STATE_WALK;
	static const std::string STATE_IDLE;
	static const std::string STATE_HURT;

	UnitStateData();
	~UnitStateData();

	Unit * unit;
};

NS_OG_END;

#endif // !__ORIGIN_UNIT_STATE_DEFINIATION_H_
