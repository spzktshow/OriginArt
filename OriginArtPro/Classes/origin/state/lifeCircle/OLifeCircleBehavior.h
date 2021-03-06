#ifndef __ORIGIN_LIFE_CIRCLE_BEHAVIOR_H_
#define __ORIGIN_LIFE_CIRCLE_BEHAVIOR_H_

#include "OriginMacros.h"
#include <string>
#include "cocos2d.h"

class LifeCircleBehaviorDefiniation
{
public:
	LifeCircleBehaviorDefiniation(const std::string&type);
	virtual ~LifeCircleBehaviorDefiniation();

	const std::string& getType() const;
protected:
	std::string _type;
};

//event
class LifeCircleEventBehaviorDefiniation : public LifeCircleBehaviorDefiniation
{
public:
	static const std::string TYPE;

	LifeCircleEventBehaviorDefiniation(const std::string& eventName, const std::string& eventType, const std::string&type = TYPE);
	virtual ~LifeCircleEventBehaviorDefiniation();

	const std::string& getEventName() const;
	const std::string& getEventType() const;
protected:
	std::string _eventName;
	std::string _eventType;
};

class LifeCircleBehavior : public cocos2d::Ref
{
public:
	LifeCircleBehavior(const LifeCircleBehaviorDefiniation * behaviorDef);
	virtual ~LifeCircleBehavior();

	const LifeCircleBehaviorDefiniation * getBehaviorDef() const;
protected:
	const LifeCircleBehaviorDefiniation * _behaviorDef;
};

#endif // !__ORIGIN_LIFE_CIRCLE_BEHAVIOR_H_
