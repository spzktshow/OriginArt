#ifndef __ORIGIN_LIFE_CIRCLE_TRIGGER_H_
#define __ORIGIN_LIFE_CIRCLE_TRIGGER_H_

#include "OriginMacros.h"
#include <string>

/****触发器最小单位***/
class LifeCircleTriggerDefiniation
{
public:
	LifeCircleTriggerDefiniation(const std::string&type);
	virtual ~LifeCircleTriggerDefiniation();

	const std::string& getType() const;
protected:
	std::string _type;
};

//time
class LifeCircleTimeTriggerDefiniation : public LifeCircleTriggerDefiniation
{
public:
	static const std::string TYPE;

	LifeCircleTimeTriggerDefiniation(float time, unsigned int count, const std::string&type = TYPE);
	virtual ~LifeCircleTimeTriggerDefiniation();

	float getTime() const;
	unsigned int getCount() const;
protected:
	float _time;
	unsigned int _count;
};

//event
class LifeCircleEventTriggerDefiniation : public LifeCircleTriggerDefiniation
{
public:
	static const std::string TYPE;

	LifeCircleEventTriggerDefiniation(const std::string& eventName, const std::string& eventType, const std::string&type = TYPE);
	virtual ~LifeCircleEventTriggerDefiniation();

	const std::string& getEventName() const;
	/**事件的副类型**/
	const std::string& getEventType() const;
protected:
	std::string _eventName;
	std::string _eventType;
};

#endif // !__ORIGIN_LIFE_CIRCLE_TRIGGER_H_
