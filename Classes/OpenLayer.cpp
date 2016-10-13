//
// Created by 咸光金 on 2016/10/13.
//

#include "OpenLayer.h"

bool OpenLayer::init() {

    if (!Layer::init()) {
        return false;
    }


    /*add the game name*/
    Size size = Director::getInstance()->getVisibleSize();
    Label *label = Label::createWithSystemFont("时钟程序", "", 40);
    label->setColor(Color3B(255, 0, 0));
    label->setPosition(size.width / 2, size.height * 3 / 4);
    this->addChild(label);


    /*add the menus*/
    MenuItemLabel *menuItemLabel = MenuItemLabel::create(Label::createWithSystemFont("开始", "", 20), CC_CALLBACK_1(OpenLayer::onMenuClick, this));
    menuItemLabel->setTag(101);
    menuItemLabel->setPosition(size.width / 2, size.height * 0.3);

    MenuItemLabel *menuItemLabelb = MenuItemLabel::create(Label::createWithSystemFont("结束", "", 20), CC_CALLBACK_1(OpenLayer::onMenuClick, this));
    menuItemLabelb->setTag(102);
    menuItemLabelb->setPosition(size.width / 2, size.height * 0.15);


    Menu *menu = Menu::create(menuItemLabel, menuItemLabelb, NULL);
    menu->setPosition(Point::ZERO);

    this->addChild(menu);

    return true;
}

void OpenLayer::onMenuClick(Ref *pSender) {
    switch (((MenuItem *) pSender)->getTag()) {
        case 101:
            tsm->goClockScene();
            break;
        case 102:
            Director::getInstance()->end();
            exit(0);
            break;
    }

}
