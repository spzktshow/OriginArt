#include "OGUnitStateDefiniation.h"

USING_NS_OG;

/***************UnitStateDefiniation********************/
UnitStateDefiniation::UnitStateDefiniation(const std::string& type, const origin::ExclusionDefiniation * exclusionDefiniation) : StateFactorDefiniation(type, exclusionDefiniation)
{

}

UnitStateDefiniation::~UnitStateDefiniation()
{

}

/********************UnitStatesDefiniation********************/
UnitStatesDefiniation::UnitStatesDefiniation()
{

}

UnitStatesDefiniation::~UnitStatesDefiniation()
{

}

/******************UnitStateData******************/
const std::string UnitStateData::EVENT_ATTACK = "attackEvent";
const std::string UnitStateData::EVENT_BEATTACK = "beAttackEvent";
const std::string UnitStateData::EVENT_RUN = "runEvent";
const std::string UnitStateData::EVENT_DEAD = "deadEvent";
const std::string UnitStateData::EVENT_IDLE = "idleEvent";

const std::string UnitStateData::EVENT_ATTACK_COMPLETE = "attackCompleteEvent";
const std::string UnitStateData::EVENT_BEATTACK_COMPLETE = "beAttackCompleteEvent";
const std::string UnitStateData::EVENT_DEAD_COMPLETE = "deadCompleteEvent";

const std::string UnitStateData::STATE_ATTACK1 = "atk1";
const std::string UnitStateData::STATE_ATTACK2 = "atk2";
const std::string UnitStateData::STATE_SKILL = "skill";
const std::string UnitStateData::STATE_DEAD = "dead";
const std::string UnitStateData::STATE_WALK = "walk";
const std::string UnitStateData::STATE_IDLE = "idle";
const std::string UnitStateData::STATE_HURT = "hurt";

UnitStateData::UnitStateData()
{

}

UnitStateData::~UnitStateData()
{

}