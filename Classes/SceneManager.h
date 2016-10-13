//
// Created by 咸光金 on 2016/10/13.
//

#ifndef HELLOWORLD_SCENEMANAGER_H
#define HELLOWORLD_SCENEMANAGER_H

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;


class SceneManager {
public:
    Scene *loadScene;
    Scene *openScene;
    Scene *clockScene;

    void createLoadScene();

    void goOpenScene();

    void goClockScene();

};

#endif //HELLOWORLD_SCENEMANAGER_H
