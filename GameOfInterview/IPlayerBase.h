//
//  IPlayerBase.h
//  GameOfInterview
//
//  Created by lipengyao on 2019/10/23.
//  Copyright © 2019 lipengyao. All rights reserved.
//

#ifndef IPlayerBase_h
#define IPlayerBase_h




#include "Common.h"

interface IMapOperater
{
public:
    virtual void openBox(int row, int col) = 0;
    virtual void putFlag(int row, int col) = 0;
};


interface IPlayer
{
public:
    virtual bool init(IMapOperater* pMapOperater) = 0;
    virtual void waitInputAndPlay() = 0;
    virtual void showWin() = 0;
    virtual void showLose() = 0;
};

#endif /* IPlayerBase_h */
