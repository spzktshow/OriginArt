#include "OGUnit.h"

USING_NS_OG;

Unit::Unit(const UnitDefiniation * unitDefiniation)
	:_unitDefiniation(unitDefiniation)
	, _entry(nullptr)
	, _action(nullptr)
	, _rootBehaviorNode(nullptr)
	, _moveBehaviorContext(nullptr)
	, _behaviorContext(nullptr)
	, _behaviorDirty(false)
	, _moveBehaviorDirty(false)
{

}

Unit::Unit(const UnitDefiniation * unitDefiniation, unsigned int uid)
	:_unitDefiniation(unitDefiniation)
	, _uid(uid)
	, _entry(nullptr)
	, _action(nullptr)
	, _actionDirty(false)
	, _actionLoop(false)
	, _rootBehaviorNode(nullptr)
	, _moveBehaviorContext(nullptr)
	, _behaviorContext(nullptr)
	, _behaviorDirty(false)
	, _moveBehaviorDirty(false)
{

}

Unit::~Unit()
{
	_unitDefiniation = nullptr;

	if (!_entry) CC_SAFE_RELEASE_NULL(_entry);
	if (!_action) CC_SAFE_RELEASE_NULL(_action);
}

bool Unit::init()
{
	if (_unitDefiniation)
	{
		std::string csb = _unitDefiniation->getName();
		cocos2d::Node * node = cocos2d::CSLoader::createNode(csb);
		cocostudio::timeline::ActionTimeline * action = cocos2d::CSLoader::createTimeline(csb);

		if (node) setEntry(node);
		if (action) setAction(action);

		if (node && action)
		{
			node->runAction(action);
		}
	}
	return true;
}

//================action============//
void Unit::refreshAction(const std::string& actionName, bool loop)
{
	/****这部分将来重构到ecs里***/
	if (_actionName == actionName) return;
	_actionName = actionName;
	_actionLoop = loop;
	_actionDirty = true;

	updateAction();
}

void Unit::updateAction()
{
	if (_actionDirty)
	{
		_actionDirty = false;

		if (_action)
		{
			_action->play(_actionName, _actionLoop);
		}
	}
}

//==================behavior===============//
bool Unit::executeBehavior(const std::string&eventName, UnitStateData&data)
{
	/***
	if (_rootBehaviorNode)
	{
		cocos2d::EventCustom event(eventName);
		event.setUserData(&data);
		_rootBehaviorNode->execute(&event);
	}
	***/
	UnitBehavior behavior;
	behavior.execute(eventName, data);
	return false;
}

void Unit::refreshBehavior()
{
	if (getBehaviorDirty() || getMoveBehaviorDirty())
	{
		UnitBehavior behavior;
		behavior.refresh(dynamic_cast<UnitState *>(getBehaviorContext()->getPopBack()), getBehaviorDirty(), dynamic_cast<UnitState *>(getMoveBehaviorContext()->getPopBack()), getMoveBehaviorDirty(), this);
	}
}