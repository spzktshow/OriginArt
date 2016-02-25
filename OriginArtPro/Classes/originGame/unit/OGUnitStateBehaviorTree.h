#ifndef __ORIGIN_GAME_STATE_BEHAVIOR_TREE_H_
#define __ORIGIN_GAME_STATE_BEHAVIOR_TREE_H_

#include "OriginGameMacros.h"
#include "OGUnitState.h"
#include "OBehaviorTree.h"

NS_OG_BEGIN

//=========================Condition===============================
/***********当前状态等于*********/
class UnitCurrentStateEqualCondition : public ConditionBehaviorTreeNode
{
public:
	static const std::string TYPE;

	UnitCurrentStateEqualCondition(const std::string& currentState);
	~UnitCurrentStateEqualCondition();

	bool execute(cocos2d::EventCustom * event) override;
};

/*********当前状态生命周期比较*******/
class UnitCurrentStateLifeTimeEqualCondition : public ConditionBehaviorTreeNode
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

	bool execute(cocos2d::EventCustom * event) override;
};
//=========================Action==================================
NS_OG_END

#endif//__ORIGIN_GAME_STATE_BEHAVIOR_TREE_H_