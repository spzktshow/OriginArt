#ifndef __ORIGIN_BEHAVIOR_TREE_H_
#define __ORIGIN_BEHAVIOR_TREE_H_

#include "OriginMacros.h"
#include "cocos2d.h"
#include "OBehaviorTreeDebug.h"

NS_O_BEGIN

/***抽象的行为树节点***/
class BehaviorTreeNode
{
public:
	BehaviorTreeNode(const std::string&type);
	virtual ~BehaviorTreeNode();

	CC_SYNTHESIZE_READONLY_PASS_BY_REF(std::string, _type, Type);

	/***调试模式下打印名称****/
#ifdef ORIGIN_BEHAVIOR_TREE_DEBUG
	CC_SYNTHESIZE_READONLY_PASS_BY_REF(std::string, _name, Name);
#endif//ORIGIN_BEHAVIOR_TREE_DEBUG

	virtual bool execute(cocos2d::EventCustom * event) const;
};

/****组合节点*****/
class CompositeBehaviorTreeNode : public BehaviorTreeNode
{
public:
	static const std::string TYPE;
	CompositeBehaviorTreeNode(const std::string&compositeType);
	virtual ~CompositeBehaviorTreeNode();

	CC_SYNTHESIZE_PASS_BY_REF(std::vector<BehaviorTreeNode>, _children, Children);

	CC_SYNTHESIZE_READONLY_PASS_BY_REF(std::string, _compositeType, CompositeType);

	bool execute(cocos2d::EventCustom * event) const override;
};

/****包装节点*****/
class DecoratorBehaviorTreeNode : public BehaviorTreeNode
{
public:
	static const std::string TYPE;
	DecoratorBehaviorTreeNode(const std::string&decoratorType);
	virtual ~DecoratorBehaviorTreeNode();

	CC_SYNTHESIZE_PASS_BY_REF(BehaviorTreeNode, _child, Child);

	CC_SYNTHESIZE_READONLY_PASS_BY_REF(std::string, _decoratorType, DecoratorType);

	bool execute(cocos2d::EventCustom * event) const override;
};

/****条件节点*****/
class ConditionBehaviorTreeNode : public BehaviorTreeNode
{
public:
	static const std::string TYPE;
	ConditionBehaviorTreeNode(const std::string&conditionType);
	virtual ~ConditionBehaviorTreeNode();

	CC_SYNTHESIZE_READONLY_PASS_BY_REF(std::string, _conditionType, ConditionType);

	bool execute(cocos2d::EventCustom * event) const override;
};

/****行为节点*****/
class ActionBehaviorTreeNode : public BehaviorTreeNode
{
public:
	static const std::string TYPE;
	ActionBehaviorTreeNode(const std::string&actionType);
	virtual ~ActionBehaviorTreeNode();

	CC_SYNTHESIZE_READONLY_PASS_BY_REF(std::string, _actionType, ActionType);

	bool execute(cocos2d::EventCustom * event) const override;
};

/***********  * Selector Node
    当执行本类型Node时，它将从begin到end迭代执行自己的Child Node：
    如遇到一个Child Node执行后返回True，那停止迭代，
    本Node向自己的Parent Node也返回True；否则所有Child Node都返回False，
    那本Node向自己的Parent Node返回False。**************/
class SelectorBehaviorTreeNode : public CompositeBehaviorTreeNode
{
public:
	static const std::string TYPE;
	SelectorBehaviorTreeNode(const std::string&compositeType = TYPE);
	~SelectorBehaviorTreeNode();

	bool execute(cocos2d::EventCustom * event) const override;
};

/****
* Sequence Node
当执行本类型Node时，它将从begin到end迭代执行自己的Child Node：
如遇到一个Child Node执行后返回False，那停止迭代，
本Node向自己的Parent Node也返回False；否则所有Child Node都返回True，
那本Node向自己的Parent Node返回True。***/
class SequenceBehaviorTreeNode : public CompositeBehaviorTreeNode
{
public:
	static const std::string TYPE;
	SequenceBehaviorTreeNode(const std::string&compositeType = TYPE);
	~SequenceBehaviorTreeNode();

	bool execute(cocos2d::EventCustom * event) const override;
};

class TurnBehaviorTreeNode : public DecoratorBehaviorTreeNode
{
public:
	static const std::string TYPE;
	TurnBehaviorTreeNode(const std::string&decoratorType = TYPE);
	~TurnBehaviorTreeNode();

	bool execute(cocos2d::EventCustom * event) const override;
};

class EventConditionBehaviorTreeNode : public ConditionBehaviorTreeNode
{
public:
	static const std::string TYPE;
	EventConditionBehaviorTreeNode(const std::string&eventName, const std::string&conditionType = TYPE);
	~EventConditionBehaviorTreeNode();

	bool execute(cocos2d::EventCustom * event) const override;

	CC_SYNTHESIZE_READONLY_PASS_BY_REF(std::string, _eventName, EventName);
};

class BehaviorTreeParse
{
public:
	BehaviorTreeParse();
	virtual ~BehaviorTreeParse();

	static BehaviorTreeNode parse(const rapidjson::Value&);
};

class BehaviorTreeDefiniation
{
public:
	BehaviorTreeDefiniation();
	~BehaviorTreeDefiniation();

	CC_SYNTHESIZE(unsigned int, _id, ID);

	CC_SYNTHESIZE_PASS_BY_REF(BehaviorTreeNode, _root, Root);
};

class BehaviorTreesDefiniation
{
public:
	BehaviorTreesDefiniation();
	~BehaviorTreesDefiniation();

	CC_SYNTHESIZE_PASS_BY_REF(std::vector<BehaviorTreeDefiniation>, _trees, Trees);

	void parse(const std::string&data);
};

NS_O_END;

#endif