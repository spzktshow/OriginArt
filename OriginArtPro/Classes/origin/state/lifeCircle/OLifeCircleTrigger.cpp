#include "OLifeCircleTrigger.h"

/************LifeCircleTrigger************/
LifeCircleTriggerDefiniation::LifeCircleTriggerDefiniation(const std::string&type)
{

}

LifeCircleTriggerDefiniation::~LifeCircleTriggerDefiniation()
{

}

const std::string& LifeCircleTriggerDefiniation::getType() const
{
	return _type;
}


/****************LifeCircleTimeTrigger***************/
const std::string LifeCircleTimeTriggerDefiniation::TYPE = "lifeCircleTimeTriggerDefiniation";

LifeCircleTimeTriggerDefiniation::LifeCircleTimeTriggerDefiniation(float time, unsigned int count, const std::string&type /* = TYPE */)
	:LifeCircleTriggerDefiniation(type), _time(time), _count(count)
{

}

LifeCircleTimeTriggerDefiniation::~LifeCircleTimeTriggerDefiniation()
{

}

float LifeCircleTimeTriggerDefiniation::getTime() const
{
	return _time;
}

unsigned int LifeCircleTimeTriggerDefiniation::getCount() const
{
	return _count;
}

/********************LifeCircleEventTrigger*******************/
const std::string LifeCircleEventTriggerDefiniation::TYPE = "lifeCircleEventTriggerDefiniation";

LifeCircleEventTriggerDefiniation::LifeCircleEventTriggerDefiniation(const std::string& eventName, const std::string& eventType, const std::string&type /* = TYPE */)
	:LifeCircleTriggerDefiniation(type), _eventName(eventName), _eventType(eventType)
{

}

LifeCircleEventTriggerDefiniation::~LifeCircleEventTriggerDefiniation()
{

}

const std::string& LifeCircleEventTriggerDefiniation::getEventName() const
{
	return _eventName;
}

const std::string& LifeCircleEventTriggerDefiniation::getEventType() const
{
	return _eventType;
}