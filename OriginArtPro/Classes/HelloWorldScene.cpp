#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "origin.h"

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

	cocos2d::FileUtils::getInstance()->addSearchPath("unit");

	cocos2d::Node * role = cocos2d::CSLoader::createNode("Tauren.csb");
	if (role)
	{
		addChild(role);
		role->setPosition(cocos2d::Director::getInstance()->getWinSize() * .5f);
		cocostudio::timeline::ActionTimeline * roleTimeLine = cocos2d::CSLoader::createTimeline("unit/Tauren.csb");
		role->runAction(roleTimeLine);
		roleTimeLine->gotoFrameAndPause(0);
	}
	

    return true;
}

void HelloWorld::onEnter()
{
	cocos2d::Layer::onEnter();
}
