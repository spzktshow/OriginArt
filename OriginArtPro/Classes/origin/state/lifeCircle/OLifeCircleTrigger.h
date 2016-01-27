#ifndef __ORIGIN_LIFE_CIRCLE_TRIGGER_H_
#define __ORIGIN_LIFE_CIRCLE_TRIGGER_H_

#include "OriginMacros.h"
#include <string>

//time
//event

/****触发器最小单位***/
class LifeCircleTrigger
{
public:
	LifeCircleTrigger(const std::string&type);
	virtual ~LifeCircleTrigger();

	const std::string& getType() const;
protected:
	std::string _type;
};

class LifeCircleTimeTrigger : public LifeCircleTrigger
{
public:
	LifeCircleTimeTrigger(const std::string&type, float time, unsigned int count);
	virtual ~LifeCircleTimeTrigger();

	float getTime() const;
	unsigned int getCount() const;
protected:
	float _time;
	unsigned int _count;
};

class LifeCircleEventTrigger : public LifeCircleTrigger
{
public:
	LifeCircleEventTrigger(const std::string&type);
	virtual ~LifeCircleEventTrigger();

	const std::string& getEventName() const;
	/**事件的副类型**/
	const std::string& getEventType() const;
protected:
	std::string _eventName;
	std::string _eventType;
};

#endif // !__ORIGIN_LIFE_CIRCLE_TRIGGER_H_
