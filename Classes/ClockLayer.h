//
// Created by 咸光金 on 2016/10/13.
//

#ifndef HELLOWORLD_CLOCKLAYER_H
#define HELLOWORLD_CLOCKLAYER_H

#include "cocos2d.h"
#include "SceneManager.h"
#include <iostream>

USING_NS_CC;

class ClockLayer : public Layer {
public:
    CREATE_FUNC(ClockLayer);

    virtual bool init();

    void onMenuClick(Ref *sender);

    void onTimeUpdate(float t);

public:
    SceneManager *tsm;
    Sprite *hour;
    Sprite *minute;
    Sprite *second;
    Sprite *backgroud;

    /*rotation of time*/
    int hRotation = 0;
    int mRotation = 0;
    int sRotation = 0;

};


#endif //HELLOWORLD_CLOCKLAYER_H
