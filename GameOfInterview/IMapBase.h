//
//  IMapBase.h
//  GameOfInterview
//
//  Created by lipengyao on 2019/10/23.
//  Copyright © 2019 lipengyao. All rights reserved.
//

#ifndef IMapBase_h
#define IMapBase_h


#endif /* IMapBase_h */

#include "Common.h"


interface IMapBase
{
public:
    virtual bool create(int row, int col, int bombNum) = 0;
    virtual bool isEnd() = 0;
    virtual void showView() =0;
};
