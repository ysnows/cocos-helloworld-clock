//
// Created by 咸光金 on 2016/10/13.
//

#include "ClockLayer.h"

bool ClockLayer::init() {
    if (!Layer::init()) {
        return false;
    }
    Size size = Director::getInstance()->getWinSize();

    /*create back menu*/

    MenuItemLabel *menuItemLabel = MenuItemLabel::create(Label::createWithSystemFont("back", "", 18), CC_CALLBACK_1(ClockLayer::onMenuClick, this));
    menuItemLabel->setPosition(size.width * 0.9, size.height * 0.8);

    Menu *menu = Menu::create(menuItemLabel, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);


    /*create the clock*/
    backgroud = Sprite::create("res/background.jpg");
    backgroud->setPosition(Vec2(size.width / 2, size.height / 2));
    backgroud->setScale(0.8);
    addChild(backgroud);

    hour = Sprite::create("res/shi.png");
    hour->setPosition(Vec2(size.width / 2, size.height / 2));
    hour->setScale(0.5);
    hour->setAnchorPoint(Vec2(0.5, 0));
    addChild(hour);

    minute = Sprite::create("res/fen.png");
    minute->setPosition(Vec2(size.width / 2, size.height / 2));
    minute->setScale(0.5);
    minute->setAnchorPoint(Vec2(0.5, 0));
    addChild(minute);

    second = Sprite::create("res/miao.png");
    second->setPosition(Vec2(size.width / 2, size.height / 2));
    second->setScale(0.5);
    second->setAnchorPoint(Vec2(0.5, 0));
    addChild(second);



    /*get local time info*/


    struct timeval nowTimeVal;
    gettimeofday(&nowTimeVal, NULL);

    struct tm *tm;
    time_t time_sec;
    time_sec = nowTimeVal.tv_sec;
    tm = localtime(&time_sec);

    CCLOG("%d:%d:%d", tm->tm_hour, tm->tm_min, tm->tm_sec);

    sRotation = tm->tm_sec * 6;
    mRotation = tm->tm_min * 6;

    if (tm->tm_hour > 12) {
        hRotation = (tm->tm_hour - 12) * 5 * 6 + (mRotation / 72) * 6;
    } else {
        hRotation = tm->tm_hour * 5 * 6 + (mRotation / 72) * 6;
    }

    hour->setRotation(hRotation);
    minute->setRotation(mRotation);
    second->setRotation(sRotation);

    schedule(CC_SCHEDULE_SELECTOR(ClockLayer::onTimeUpdate), 1.0);

    return true;

}

void ClockLayer::onMenuClick(Ref *sender) {
    tsm->goOpenScene();

}

void ClockLayer::onTimeUpdate(float t) {

    second->setRotation(second->getRotation() + 6);

    if (second->getRotation() == 360) {
        //change minute
        minute->setRotation(minute->getRotation() + 6);
        second->setRotation(0);
        if ((int) minute->getRotation() % 72 == 0) {
            hour->setRotation(hour->getRotation() + 6);

            if (minute->getRotation() == 360) {
                minute->setRotation(0);
            }
        }


    }
}
