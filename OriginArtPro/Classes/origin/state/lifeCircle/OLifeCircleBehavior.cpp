#include "OLifeCircleBehavior.h"

/****************LifeCircleBehaviorDefiniation**************/
LifeCircleBehaviorDefiniation::LifeCircleBehaviorDefiniation(const std::string&type)
{

}

LifeCircleBehaviorDefiniation::~LifeCircleBehaviorDefiniation()
{

}

const std::string& LifeCircleBehaviorDefiniation::getType() const
{
	return _type;
}

/****************LifeCircleEventBehaviorDefiniation****************/
LifeCircleEventBehaviorDefiniation::LifeCircleEventBehaviorDefiniation(const std::string& eventName, const std::string& eventType, const std::string&type) 
	:LifeCircleBehaviorDefiniation(type), _eventName(eventName), _eventType(eventType)
{

}

LifeCircleEventBehaviorDefiniation::~LifeCircleEventBehaviorDefiniation()
{

}

const std::string& LifeCircleEventBehaviorDefiniation::getEventName() const
{
	return _eventName;
}

const std::string& LifeCircleEventBehaviorDefiniation::getEventType() const
{
	return _eventType;
}

/************************LifeCircleBehavior**********************/
LifeCircleBehavior::LifeCircleBehavior(const LifeCircleBehaviorDefiniation * behaviorDef) :_behaviorDef(nullptr)
{

}

LifeCircleBehavior::~LifeCircleBehavior()
{

}

const LifeCircleBehaviorDefiniation * LifeCircleBehavior::getBehaviorDef() const
{
	return _behaviorDef;
}