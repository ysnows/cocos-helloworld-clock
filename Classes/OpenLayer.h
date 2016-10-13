//
// Created by 咸光金 on 2016/10/13.
//

#ifndef HELLOWORLD_OPENLAYER_H
#define HELLOWORLD_OPENLAYER_H

#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"

USING_NS_CC;

class OpenLayer : public Layer {
public:
    CREATE_FUNC(OpenLayer);

    virtual bool init();

    void onMenuClick(Ref *pSender);

public:
    SceneManager *tsm;
};


#endif //HELLOWORLD_OPENLAYER_H
