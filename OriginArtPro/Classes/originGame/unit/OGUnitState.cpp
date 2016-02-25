#include "OGUnitState.h"
#include "OGUnit.h"
USING_NS_OG;

/***************UnitState**************/
UnitState::UnitState(const UnitStateDefiniation *unitStateDefiniation) 
	:StateComponent(unitStateDefiniation)
{

}

UnitState::~UnitState()
{

}

void UnitState::startExecute()
{
	StateComponent::startExecute();
}

void UnitState::stopExecute()
{
	StateComponent::stopExecute();
}

void UnitState::pauseExecute()
{
	StateComponent::pauseExecute();
}

void UnitState::resumeExecute()
{
	StateComponent::resumeExecute();
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