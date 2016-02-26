#include "OGUnitState.h"
#include "OGUnit.h"
USING_NS_OG;

/***************UnitState**************/
UnitState::UnitState(const UnitStateDefiniation *unitStateDefiniation) 
	:StateFactor(unitStateDefiniation)
{

}

UnitState::~UnitState()
{

}

void UnitState::startExecute()
{
	StateFactor::startExecute();
}

void UnitState::stopExecute()
{
	StateFactor::stopExecute();
}

void UnitState::pauseExecute()
{
	StateFactor::pauseExecute();
}

void UnitState::resumeExecute()
{
	StateFactor::resumeExecute();
}

/*****************UnitAttackState******************/
UnitAttackState::UnitAttackState(const UnitStateDefiniation * unitStateDefiniation) :UnitState(unitStateDefiniation)
{

}

UnitAttackState::~UnitAttackState()
{

}

void UnitAttackState::lifeTimeComplete(float dt)
{

}