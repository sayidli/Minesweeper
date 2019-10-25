//
//  Map.h
//  GameOfInterview
//
//  Created by lipengyao on 2019/10/24.
//  Copyright © 2019 lipengyao. All rights reserved.
//

#ifndef Map_h
#define Map_h


#endif /* Map_h */

#include "IMapBase.h"
#include "IPlayerBase.h"


class GameMap:public IMapOperater, public IMapBase
{
public:
    GameMap();
    
    //IMapBase
    bool virtual create(int row, int col, int bombNum);
    bool virtual isEnd();
    void virtual showView();
    //IMapOperater
    void virtual openBox(int row, int col);
    void virtual putFlag(int row, int col);
    
    ~GameMap();
    
protected:
    vector<vector<char>> mapData_;
    vector<vector<char>> mapDataCover_;
    bool isContinue = true;
    
};
