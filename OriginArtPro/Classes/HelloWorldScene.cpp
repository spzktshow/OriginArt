#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "origin.h"
#include "OGUnit.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	origin::ExclusionDefiniation * pauseDef = new origin::ExclusionDefiniation(origin::ExclusionDefiniation::ExclusionType::PAUSE);


	originGame::UnitPropertyDefiniation * propertyDef = new originGame::UnitPropertyDefiniation;
	propertyDef->setMoveSpeed(1.0f);
	propertyDef->setActionSpeed(1.0f);

	originGame::UnitStatesDefiniation * statesDef = new originGame::UnitStatesDefiniation;
	std::map<std::string, originGame::UnitStateDefiniation*>states;
	originGame::UnitStateDefiniation * atk1 = new originGame::UnitStateDefiniation(originGame::UnitStateData::STATE_ATTACK1, pauseDef);
	atk1->setActionName(originGame::UnitStateData::STATE_ATTACK1);
	atk1->setTime((float)(5 * 8) / (float)60);
	states.insert(std::make_pair(originGame::UnitStateData::STATE_ATTACK1, atk1));

	originGame::UnitStateDefiniation * atk2 = new originGame::UnitStateDefiniation(originGame::UnitStateData::STATE_ATTACK2, pauseDef);
	atk2->setActionName(originGame::UnitStateData::STATE_ATTACK2);
	atk2->setTime((float)(5 * 9) / (float)60);
	states.insert(std::make_pair(originGame::UnitStateData::STATE_ATTACK2, atk2));

	originGame::UnitStateDefiniation * skill = new originGame::UnitStateDefiniation(originGame::UnitStateData::STATE_SKILL, pauseDef);
	skill->setActionName(originGame::UnitStateData::STATE_SKILL);
	skill->setTime((float)(5 * 8) / (float)60);
	states.insert(std::make_pair(originGame::UnitStateData::STATE_SKILL, skill));

	originGame::UnitStateDefiniation * walk = new originGame::UnitStateDefiniation(originGame::UnitStateData::STATE_WALK, pauseDef);
	walk->setActionName(originGame::UnitStateData::STATE_WALK);
	walk->setTime(0.0f);
	states.insert(std::make_pair(originGame::UnitStateData::STATE_WALK, walk));

	originGame::UnitStateDefiniation * idle = new originGame::UnitStateDefiniation(originGame::UnitStateData::STATE_IDLE, pauseDef);
	idle->setActionName(originGame::UnitStateData::STATE_IDLE); 
	idle->setTime(0.0f);
	states.insert(std::make_pair(originGame::UnitStateData::STATE_IDLE, idle));

	originGame::UnitStateDefiniation * hurt = new originGame::UnitStateDefiniation(originGame::UnitStateData::STATE_HURT, pauseDef);
	hurt->setActionName(originGame::UnitStateData::STATE_HURT);
	hurt->setTime((float)(5 * 4) / (float)60);
	states.insert(std::make_pair(originGame::UnitStateData::STATE_HURT, hurt));
	statesDef->setStates(states);

	originGame::UnitDefiniation * unitDef = new originGame::UnitDefiniation;
	unitDef->setID(72003);
	unitDef->setName("unit72003/unit72003.csb");
	unitDef->setType("fighter");
	unitDef->setStatesDefiniation(statesDef);
	unitDef->setPropertyDefiniation(propertyDef);

	originGame::Unit * unit = originGame::Unit::create(unitDef);
	unit->retain();
	
	origin::DynamicStateDefiniation * behaviorDef = new origin::DynamicStateDefiniation("behaviorContext", pauseDef);
	origin::DynamicStateDefiniation * moveBehaviorDef = new origin::DynamicStateDefiniation("moveBehaviorContext", pauseDef);
	origin::StateStack * behaviorContext = origin::StateStack::create(behaviorDef);
	origin::StateStack * moveBehaviorContext = origin::StateStack::create(moveBehaviorDef);
	unit->setBehaviorContext(behaviorContext);
	behaviorContext->start();
	unit->setMoveBehaviorContext(moveBehaviorContext);
	moveBehaviorContext->start();
	if (unit->getEntry())
	{
		addChild(unit->getEntry());
		unit->getEntry()->setPosition(cocos2d::Director::getInstance()->getWinSize() * .5f);
	}

	originGame::UnitStateData data;
	data.unit = unit;
	unit->executeBehavior(originGame::UnitStateData::EVENT_IDLE, data);

	_unit = unit;

	_keyBoardListener = cocos2d::EventListenerKeyboard::create();
	_keyBoardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onPressed, this);
	_keyBoardListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onReleased, this);
	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(_keyBoardListener, 1);
    return true;
}

void HelloWorld::onEnter()
{
	cocos2d::Layer::onEnter();
}

void HelloWorld::onPressed(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event*)
{
	if (key == cocos2d::EventKeyboard::KeyCode::KEY_J)
	{
		if (_unit)
		{
			originGame::UnitStateData data;
			data.unit = _unit;
			_unit->executeBehavior(originGame::UnitStateData::EVENT_ATTACK, data);
		}
	}
}

void HelloWorld::onReleased(cocos2d::EventKeyboard::KeyCode key, cocos2d::Event*)
{

}