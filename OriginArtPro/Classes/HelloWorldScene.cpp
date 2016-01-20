#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

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
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);


	cocos2d::Sprite * sp = new cocos2d::Sprite;
	sp->setName("lxy");
	cocos2d::RefPtr<cocos2d::Sprite> sprite;
	sprite.weakAssign(sp);
	CCLOG("%d", sp->getReferenceCount());
	ps.push_back(sprite);
	CCLOG("%d", sp->getReferenceCount());
	addChild(sp);
	CCLOG("%d", sp->getReferenceCount());
    return true;
}

void HelloWorld::onEnter()
{
	cocos2d::Layer::onEnter();
	cocos2d::Sprite * sp = (cocos2d::Sprite *)getChildByName("lxy");
	if (sp)
	{
		CCLOG("%d", sp->getReferenceCount());
	}
}
