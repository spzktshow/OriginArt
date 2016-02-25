#ifndef __ORIGIN_GAME_UNIT_STATE_H_
#define __ORIGIN_GAME_UNIT_STATE_H_

#include "OriginGameMacros.h"
#include "OGUnitStateDefiniation.h"
#include "OGState.h"

NS_OG_BEGIN

class Unit;
class UnitStateData
{
public:
	static const std::string EVENT_ATTACK;
	static const std::string EVENT_BEATTACK;
	static const std::string EVENT_RUN;
	static const std::string EVENT_DEAD;
	static const std::string EVENT_IDLE;

	UnitStateData();
	~UnitStateData();

	Unit * entity;
};

class UnitState : public StateComponent
{
public:
	UnitState(const UnitStateDefiniation *unitStateDefiniation);
	virtual ~UnitState();

	const UnitStateDefiniation * getUnitStateDefiniation() const
	{
		return dynamic_cast<const UnitStateDefiniation *>(getDynamicStateDefiniation());
	}

	void startExecute() override;
	void stopExecute() override;
	void pauseExecute() override;
	void resumeExecute() override;
};

class UnitAttackState : public UnitState
{
public:
	UnitAttackState(const UnitStateDefiniation * unitStateDefiniation);
	~UnitAttackState();

	static UnitAttackState * create(const UnitStateDefiniation * unitStateDefiniation)
	{
		UnitAttackState * state = new UnitAttackState(unitStateDefiniation);
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
	UnitBeAttackState(const UnitStateDefiniation * unitStateDefiniation);
	~UnitBeAttackState();

	static UnitBeAttackState * create(const UnitStateDefiniation * unitStateDefiniation)
	{
		UnitBeAttackState * state = new UnitBeAttackState(unitStateDefiniation);
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
	UnitRunState(const UnitStateDefiniation * unitStateDefiniation);
	~UnitRunState();

	static UnitRunState * create(const UnitStateDefiniation * unitStateDefiniation)
	{
		UnitRunState * state = new UnitRunState(unitStateDefiniation);
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

class UnitIdleState : public UnitState
{
public:
	UnitIdleState(const UnitStateDefiniation * unitStateDefiniation);
	~UnitIdleState();

	static UnitIdleState * create(const UnitStateDefiniation * unitStateDefiniation)
	{
		UnitIdleState * state = new UnitIdleState(unitStateDefiniation);
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

class UnitDeadState : public UnitState
{
public:
	UnitDeadState(const UnitStateDefiniation * unitStateDefiniation);
	~UnitDeadState();

	static UnitDeadState * create(const UnitStateDefiniation * unitStateDefiniation)
	{
		UnitDeadState * state = new UnitDeadState(unitStateDefiniation);
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

NS_OG_END;

#endif // !__ORIGIN_GAME_UNIT_STATE_H_
