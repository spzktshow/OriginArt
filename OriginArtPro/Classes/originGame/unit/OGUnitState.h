#ifndef __ORIGIN_GAME_UNIT_STATE_H_
#define __ORIGIN_GAME_UNIT_STATE_H_

#include "OriginGameMacros.h"
#include "OGUnitStateDefiniation.h"
#include "OGState.h"

NS_OG_BEGIN

class Unit;
class UnitState : public StateFactor
{
public:
	UnitState(const UnitStateDefiniation *unitStateDefiniation, Unit * unit);
	virtual ~UnitState();

	const UnitStateDefiniation * getUnitStateDefiniation() const
	{
		return dynamic_cast<const UnitStateDefiniation *>(getDynamicStateDefiniation());
	}

protected:
	Unit * _unit;

	void startExecute() override;
	void stopExecute() override;
	void pauseExecute() override;
	void resumeExecute() override;

	void lifeTimeUpdate(float dt) override;
};

class UnitAttackState : public UnitState
{
public:
	UnitAttackState(const UnitStateDefiniation * unitStateDefiniation, Unit * unit);
	~UnitAttackState();

	static UnitAttackState * create(const UnitStateDefiniation * unitStateDefiniation, Unit * unit)
	{
		UnitAttackState * state = new UnitAttackState(unitStateDefiniation, unit);
		if (state)
		{
			state->autorelease();
			return state;
		}
		CC_SAFE_DELETE(state);
		return nullptr;
	}

	void lifeTimeComplete(float dt) override;
};

class UnitBeAttackState : public  UnitState
{
public:
	UnitBeAttackState(const UnitStateDefiniation * unitStateDefiniation, Unit * unit);
	~UnitBeAttackState();

	static UnitBeAttackState * create(const UnitStateDefiniation * unitStateDefiniation, Unit * unit)
	{
		UnitBeAttackState * state = new UnitBeAttackState(unitStateDefiniation, unit);
		if (state)
		{
			state->autorelease();
			return state;
		}
		CC_SAFE_DELETE(state);
		return nullptr;
	}

	void lifeTimeComplete(float dt) override;
};

class UnitRunState : public UnitState
{
public:
	UnitRunState(const UnitStateDefiniation * unitStateDefiniation, Unit * unit);
	~UnitRunState();

	static UnitRunState * create(const UnitStateDefiniation * unitStateDefiniation, Unit * unit)
	{
		UnitRunState * state = new UnitRunState(unitStateDefiniation, unit);
		if (state)
		{
			state->autorelease();
			return state;
		}
		CC_SAFE_DELETE(state);
		return nullptr;
	}
};

class UnitIdleState : public UnitState
{
public:
	UnitIdleState(const UnitStateDefiniation * unitStateDefiniation, Unit * unit);
	~UnitIdleState();

	static UnitIdleState * create(const UnitStateDefiniation * unitStateDefiniation, Unit * unit)
	{
		UnitIdleState * state = new UnitIdleState(unitStateDefiniation, unit);
		if (state)
		{
			state->autorelease();
			return state;
		}
		CC_SAFE_DELETE(state);
		return nullptr;
	}
};

class UnitDeadState : public UnitState
{
public:
	UnitDeadState(const UnitStateDefiniation * unitStateDefiniation, Unit * unit);
	~UnitDeadState();

	static UnitDeadState * create(const UnitStateDefiniation * unitStateDefiniation, Unit * unit)
	{
		UnitDeadState * state = new UnitDeadState(unitStateDefiniation, unit);
		if (state)
		{
			state->autorelease();
			return state;
		}
		CC_SAFE_DELETE(state);
		return nullptr;
	}

	void lifeTimeComplete(float dt) override;
};

class UnitBehavior
{
public:
	UnitBehavior(){};
	~UnitBehavior(){};

	bool execute(const std::string&eventName, UnitStateData&data);

	bool refresh(UnitState * behaviorState, bool behaviorDirty, UnitState * moveBehaviorState, bool moveBehaviorDirty, Unit * unit);
};

NS_OG_END;

#endif // !__ORIGIN_GAME_UNIT_STATE_H_
