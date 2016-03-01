#ifndef __ORIGIN_GAME_UNIT_H_
#define __ORIGIN_GAME_UNIT_H_

#include "cocos2d.h"
#include "OGUnitDefiniation.h"
#include "OGUnitState.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "OGUnitStateBehaviorTree.h"

NS_OG_BEGIN

class Unit : public cocos2d::Ref
{
public:
	Unit(const UnitDefiniation * unitDefiniation);
	Unit(const UnitDefiniation * unitDefiniation, unsigned int uid);
	~Unit();

	CC_SYNTHESIZE(unsigned int, _uid, UID);

	/*******单位定义********/
	CC_SYNTHESIZE_READONLY(const UnitDefiniation *, _unitDefiniation, UnitDefiniation);

	/********实体*******/
	CC_SYNTHESIZE_RETAIN(cocos2d::Node *, _entry, Entry);
	/*********动作********/
	CC_SYNTHESIZE_RETAIN(cocostudio::timeline::ActionTimeline *, _action, Action);

	/***init unit***/
	virtual bool init();

	static Unit * create(const UnitDefiniation * unitDefiniation)
	{
		Unit * unit = new Unit(unitDefiniation);
		if (unit && unit->init())
		{
			unit->autorelease();
			return unit;
		}
		CC_SAFE_DELETE(unit);
		return nullptr;
	}

	//============action=================//
public:
	void refreshAction(const std::string& actionName, bool loop);
	void updateAction();
protected:
	std::string _actionName;
	bool _actionLoop;
	bool _actionDirty;
	//===================================//

	//============behavior===============//
	CC_SYNTHESIZE(const origin::ActionBehaviorTreeNode *, _rootBehaviorNode, RootBehaviorNode);
	CC_SYNTHESIZE_RETAIN(origin::StateStack *, _behaviorContext, BehaviorContext);
	CC_SYNTHESIZE(bool, _behaviorDirty, BehaviorDirty);
	CC_SYNTHESIZE_RETAIN(origin::StateStack *, _moveBehaviorContext, MoveBehaviorContext);
	CC_SYNTHESIZE(bool, _moveBehaviorDirty, MoveBehaviorDirty);
public:
	bool executeBehavior(const std::string&eventName, UnitStateData&data);
	void refreshBehavior();
	//===================================//
};

NS_OG_END

#endif /**__ORIGIN_GAME_UNIT_H_**/