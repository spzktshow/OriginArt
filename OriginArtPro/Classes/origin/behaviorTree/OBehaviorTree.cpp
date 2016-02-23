#include "OBehaviorTree.h"
#include "cocostudio/DictionaryHelper.h"

USING_NS_O;

/********BehaviorTreeNode*******/
BehaviorTreeNode::BehaviorTreeNode(const std::string&type) :_type(type)
{
}

BehaviorTreeNode::~BehaviorTreeNode()
{

}

bool BehaviorTreeNode::execute(cocos2d::EventCustom * event) const
{
}

/**************CompositeBehaviorTreeNode************/
const std::string CompositeBehaviorTreeNode::TYPE = "composite";
CompositeBehaviorTreeNode::CompositeBehaviorTreeNode(const std::string&compositeType)
	:BehaviorTreeNode(CompositeBehaviorTreeNode::TYPE)
	, _compositeType(compositeType)
{

}

CompositeBehaviorTreeNode::~CompositeBehaviorTreeNode()
{

}

bool CompositeBehaviorTreeNode::execute(cocos2d::EventCustom * event) const
{
#ifdef ORIGIN_BEHAVIOR_TREE_DEBUG
	CCLOG("behaviorTreeNode compositeType=%s  name=%s execute", _compositeType.c_str(), _name.c_str());
#endif
}
/*************DecoratorBehaviorTreeNode*************/
const std::string DecoratorBehaviorTreeNode::TYPE = "decorator";
DecoratorBehaviorTreeNode::DecoratorBehaviorTreeNode(const std::string&decoratorType)
	:BehaviorTreeNode(DecoratorBehaviorTreeNode::TYPE)
	, _decoratorType(decoratorType)
{

}

DecoratorBehaviorTreeNode::~DecoratorBehaviorTreeNode()
{

}

bool DecoratorBehaviorTreeNode::execute(cocos2d::EventCustom * event) const
{
#ifdef ORIGIN_BEHAVIOR_TREE_DEBUG
	CCLOG("behaviorTreeNode decoratorType=%s  name=%s execute", _decoratorType.c_str(), _name.c_str());
#endif
}

/***************ConditionBehaviorTreeNode**************/
const std::string ConditionBehaviorTreeNode::TYPE = "condition";
ConditionBehaviorTreeNode::ConditionBehaviorTreeNode(const std::string&conditionType) :BehaviorTreeNode(ConditionBehaviorTreeNode::TYPE), _conditionType(conditionType)
{

}

ConditionBehaviorTreeNode::~ConditionBehaviorTreeNode()
{

}

bool ConditionBehaviorTreeNode::execute(cocos2d::EventCustom * event) const
{
#ifdef ORIGIN_BEHAVIOR_TREE_DEBUG
	CCLOG("behaviorTreeNode conditionType=%s  name=%s execute", _conditionType.c_str(), _name.c_str());
#endif
}
/**************ActionBehaviorTreeNode***************/
const std::string ActionBehaviorTreeNode::TYPE = "action";
ActionBehaviorTreeNode::ActionBehaviorTreeNode(const std::string&actionType) :BehaviorTreeNode(ActionBehaviorTreeNode::TYPE), _actionType(actionType)
{

}

ActionBehaviorTreeNode::~ActionBehaviorTreeNode()
{

}

bool ActionBehaviorTreeNode::execute(cocos2d::EventCustom * event) const
{
#ifdef ORIGIN_BEHAVIOR_TREE_DEBUG
	CCLOG("behaviorTreeNode actionType=%s  name=%s execute", _actionType.c_str(), _name.c_str());
#endif
}

/***************SelectorBehaviorTreeNode***************/
const std::string SelectorBehaviorTreeNode::TYPE = "selector";
SelectorBehaviorTreeNode::SelectorBehaviorTreeNode(const std::string&compositeType) :CompositeBehaviorTreeNode(compositeType)
{

}

SelectorBehaviorTreeNode::~SelectorBehaviorTreeNode()
{

}

bool SelectorBehaviorTreeNode::execute(cocos2d::EventCustom * event) const
{
	CompositeBehaviorTreeNode::execute(event);

	for (const auto&node : _children)
	{
		if (node.execute(event))
			return true;
	}
	return false;
}

/********************SequenceBehaviorTreeNode*******************/
const std::string SequenceBehaviorTreeNode::TYPE = "sequence";
SequenceBehaviorTreeNode::SequenceBehaviorTreeNode(const std::string&compositeType = TYPE) :CompositeBehaviorTreeNode(compositeType)
{

}

SequenceBehaviorTreeNode::~SequenceBehaviorTreeNode()
{

}

bool SequenceBehaviorTreeNode::execute(cocos2d::EventCustom * event) const
{
	CompositeBehaviorTreeNode::execute(event);

	for (const auto&node : _children)
	{
		if (node.execute(event))
			return false;
	}
	return true;
}

/*******************TurnBehaviorTreeNode************************/
const std::string TurnBehaviorTreeNode::TYPE = "turn";
TurnBehaviorTreeNode::TurnBehaviorTreeNode(const std::string&decoratorType) :DecoratorBehaviorTreeNode(decoratorType)
{

}

TurnBehaviorTreeNode::~TurnBehaviorTreeNode()
{

}

bool TurnBehaviorTreeNode::execute(cocos2d::EventCustom * event) const
{
	DecoratorBehaviorTreeNode::execute(event);

	return !_child.execute(event);
}

/********************EventConditionBehaviorTreeNode*******************/
const std::string EventConditionBehaviorTreeNode::TYPE = "eventCondition";
EventConditionBehaviorTreeNode::EventConditionBehaviorTreeNode(const std::string&eventName, const std::string&conditionType) 
	:ConditionBehaviorTreeNode(conditionType)
	, _eventName(eventName)
{

}

EventConditionBehaviorTreeNode::~EventConditionBehaviorTreeNode()
{

}

bool EventConditionBehaviorTreeNode::execute(cocos2d::EventCustom * event) const
{
	ConditionBehaviorTreeNode::execute(event);

	if (event->getEventName() == _eventName)
	{
		return true;
	}
	return false;
}

/*****************BehaviorTreesDefiniation*****************/
#define ORIGIN_BEHAVIOR_TREE_TAG_TREES				"trees"
#define ORIGIN_BEHAVIOR_TREE_TAG_ROOT				"root"
#define ORIGIN_BEHAVIOR_TREE_TAG_ID					"id"
#define ORIGIN_BEHAVIOR_TREE_TAG_TYPE				"type"
#define ORIGIN_BEHAVIOR_TREE_TAG_COMPOSITE_TYPE		"compositeType"
#define ORIGIN_BEHAVIOR_TREE_TAG_CHILDREN			"children"
#define ORIGIN_BEHAVIOR_TREE_TAG_DECORATOR_TYPE		"decoratorType"
#define ORIGIN_BEHAIVOR_TREE_TAG_CHILD				"child"
#define ORIGIN_BEHAIVOR_TREE_TAG_CONDDITION_TYPE	"conditionType"
#define ORIGIN_BEHAVIOR_TREE_TAG_EVENT_NAME			"eventName"
#define ORIGIN_BEHAIVOR_TREE_TAG_ACTION_TYPE		"actionType"

BehaviorTreesDefiniation::BehaviorTreesDefiniation()
{

}

BehaviorTreesDefiniation::~BehaviorTreesDefiniation()
{

}

void BehaviorTreesDefiniation::parse(const std::string&data)
{
	//
	rapidjson::Document document;
	document.Parse(data.c_str());

	size_t n = cocostudio::DictionaryHelper::getInstance()->getArrayCount_json(document, ORIGIN_BEHAVIOR_TREE_TAG_TREES);
	for (int i = 0; i < n; i++)
	{
		const rapidjson::Value&treeValue = cocostudio::DictionaryHelper::getInstance()->getDictionaryFromArray_json(document, ORIGIN_BEHAVIOR_TREE_TAG_TREES, i);
		unsigned int id = cocostudio::DictionaryHelper::getInstance()->getIntValue_json(treeValue, ORIGIN_BEHAVIOR_TREE_TAG_ID);
		const rapidjson::Value&rootValue = cocostudio::DictionaryHelper::getInstance()->getSubDictionary_json(treeValue, ORIGIN_BEHAVIOR_TREE_TAG_ROOT);
		BehaviorTreeNode root = std::move(BehaviorTreeParse::parse(rootValue));
		BehaviorTreeDefiniation tree;
		tree.setID(id);
		tree.setRoot(root);
		_trees.push_back(tree);
	}
}