//
// Created by 咸光金 on 2016/10/13.
//

#ifndef HELLOWORLD_LOADLAYER_H
#define HELLOWORLD_LOADLAYER_H

#include "cocos2d.h"
#include "SceneManager.h"
#include <iostream>

USING_NS_CC;

class LoadLayer : public Layer {
public:
    CREATE_FUNC(LoadLayer);

    virtual bool init();

    void onScheduleOnce(float dt);

public:
    SceneManager *tsm;
};


#endif //HELLOWORLD_LOADLAYER_H
