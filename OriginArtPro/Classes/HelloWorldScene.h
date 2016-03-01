#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "OGUnit.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	void onEnter() override;

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	originGame::Unit * _unit;

	cocos2d::EventListenerKeyboard * _keyBoardListener;
	void onPressed(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
	void onReleased(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
};

#endif // __HELLOWORLD_SCENE_H__
