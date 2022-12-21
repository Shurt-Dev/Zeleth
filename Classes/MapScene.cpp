/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "MapScene.h"

USING_NS_CC;

Scene* MapScene::createScene()
{
    return MapScene::create();
}

// on "init" you need to initialize your instance
bool MapScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    //create a tile map
    _tileMap = TMXTiledMap::create("testtiled/map.tmx");
    this->addChild(_tileMap);

	TMXObjectGroup* objectGroup = _tileMap->getObjectGroup("Objects"); // objectGroupNamed() deprecated

	if (objectGroup == NULL) {
		// CCLog("tile map has no objects in object layer"); // not working
		return false;
	}

	ValueMap spawnPoint = objectGroup->getObject("SpawnPoint");
	int x = spawnPoint.at("x").asInt();
	int y = spawnPoint.at("y").asInt();

	_player = new Sprite();
	_player->initWithFile("Player.png");
	_player->setPosition(cocos2d::Vec2(x, y));

	this->addChild(_player);
	this->setViewPointCenter(_player->getPosition());

    auto eventListener = EventListenerTouchOneByOne::create();
    eventListener->onTouchBegan = CC_CALLBACK_2(MapScene::onTouchBegan, this);
    eventListener->onTouchEnded = CC_CALLBACK_2(MapScene::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, _player);

    return true;
}

void MapScene::setViewPointCenter(Vec2 position) {
	Size winSize = Director::getInstance()->getWinSize();

	int x = MAX(position.x, winSize.width / 2);
	int y = MAX(position.y, winSize.height / 2);
	x = MIN(x, (_tileMap->getMapSize().width * this->_tileMap->getTileSize().width) - winSize.width / 2);
	y = MIN(y, (_tileMap->getMapSize().height * _tileMap->getTileSize().height) - winSize.height / 2);

	Vec2 actualPosition =Vec2(x, y);
	Vec2 centerOfView = Vec2(winSize.width / 2, winSize.height / 2);
	Vec2 viewPoint = centerOfView;
	viewPoint.subtract(actualPosition);

	this->setPosition(viewPoint);
}

void MapScene::registerWithTouchDispatcher() {
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [](Touch* touch, Event* event) {
		// Traitement de l'événement de toucher
		return true; // Consomme l'événement de toucher
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

bool MapScene::onTouchBegan(Touch* touch, Event* event)
{
	return true;
}

void MapScene::setPlayerPosition(Point position) {
	_player->setPosition(position);
}

void MapScene::onTouchEnded(Touch* touch, Event* event)
{
    Point touchLocation = touch->getLocationInView();
    touchLocation = Director::getInstance()->convertToGL(touchLocation);
    touchLocation = this->convertToNodeSpace(touchLocation);

    Point playerPos = _player->getPosition();
    Point diff = touchLocation - playerPos;

    if (abs(diff.x) > abs(diff.y)) {
        if (diff.x > 0) {
            playerPos.x += _tileMap->getTileSize().width;
        }
        else {
            playerPos.x -= _tileMap->getTileSize().width;
        }
    }
    else {
        if (diff.y > 0) {
            playerPos.y += _tileMap->getTileSize().height;
        }
        else {
            playerPos.y -= _tileMap->getTileSize().height;
        }
    }

    // safety check on the bounds of the map
    if (playerPos.x <= (_tileMap->getMapSize().width * _tileMap->getTileSize().width) &&
        playerPos.y <= (_tileMap->getMapSize().height * _tileMap->getTileSize().height) &&
        playerPos.y >= 0 &&
        playerPos.x >= 0)
    {
        this->setPlayerPosition(playerPos);
    }

    this->setViewPointCenter(_player->getPosition());
}