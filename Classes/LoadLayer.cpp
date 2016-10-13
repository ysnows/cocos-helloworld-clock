//
// Created by 咸光金 on 2016/10/13.
//

#include "LoadLayer.h"

bool LoadLayer::init() {

    if (!Layer::init()) {
        return false;
    }

    Size size = Director::getInstance()->getVisibleSize();

    Label *label = Label::createWithTTF("loading...", "fonts/Marker Felt.ttf", 24);
    label->setPosition(size.width / 2, size.height / 2);
    this->addChild(label);

    scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce), 1.0);

    return true;
}

void LoadLayer::onScheduleOnce(float dt) {
    tsm->goOpenScene();

}



