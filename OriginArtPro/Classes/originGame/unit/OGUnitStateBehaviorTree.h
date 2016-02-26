#ifndef __ORIGIN_GAME_STATE_BEHAVIOR_TREE_H_
#define __ORIGIN_GAME_STATE_BEHAVIOR_TREE_H_

#include "OriginGameMacros.h"
#include "OGUnitState.h"
#include "OBehaviorTree.h"

NS_OG_BEGIN

//=========================Condition===============================
/***********当前状态等于*********/
class UnitCurrentStateEqualCondition : public origin::ConditionBehaviorTreeNode
{
public:
	static const std::string TYPE;

	UnitCurrentStateEqualCondition(const std::string& currentState);
	~UnitCurrentStateEqualCondition();

	bool execute(cocos2d::EventCustom * event) const override;
};

/*********当前状态生命周期比较*******/
class UnitCurrentStateLifeTimeEqualCondition : public origin::ConditionBehaviorTreeNode
{
public:
	static const std::string TYPE;
	enum class EqualSign
	{
		LESS = -1,
		EQUAL = 0,
		GREATER = 1,
	};
	UnitCurrentStateLifeTimeEqualCondition(const EqualSign&equalSign);
	~UnitCurrentStateLifeTimeEqualCondition();

	bool execute(cocos2d::EventCustom * event) const override;
};

//=========================Action==================================
class UnitAttackAction : public origin::ActionBehaviorTreeNode
{
public:
	static const std::string TYPE;

	UnitAttackAction(const std::string&actionType = TYPE);
	~UnitAttackAction();

	bool execute(cocos2d::EventCustom * event) const override;
};

class UnitBeAttackAction : public origin::ActionBehaviorTreeNode
{
public:
	static const std::string TYPE;

	UnitBeAttackAction(const std::string&actionType = TYPE);
	~UnitBeAttackAction();

	bool execute(cocos2d::EventCustom * event) const override;
};

class UnitRunAction : public origin::ActionBehaviorTreeNode
{
public:
	static const std::string TYPE;

	UnitRunAction(const std::string&actionType = TYPE);
	~UnitRunAction();

	bool execute(cocos2d::EventCustom * event) const override;
};

class UnitDeadAction : public origin::ActionBehaviorTreeNode
{
public:
	static const std::string TYPE;

	UnitDeadAction(const std::string&actionType = TYPE);
	~UnitDeadAction();

	bool execute(cocos2d::EventCustom * event) const override;
};

class UnitIdleAction : public origin::ActionBehaviorTreeNode
{
public:
	static const std::string TYPE;

	UnitIdleAction(const std::string&actionType = TYPE);
	~UnitIdleAction();

	bool execute(cocos2d::EventCustom * event) const override;
};


NS_OG_END
#endif//__ORIGIN_GAME_STATE_BEHAVIOR_TREE_H_