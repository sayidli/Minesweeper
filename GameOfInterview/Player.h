//
//  Player.h
//  GameOfInterview
//
//  Created by lipengyao on 2019/10/23.
//  Copyright © 2019 lipengyao. All rights reserved.
//

#ifndef Player_h
#define Player_h





#include "Common.h"
#include "IPlayerBase.h"

class GamePlayer: public IPlayer
{
public:
    GamePlayer();
    
    bool virtual init(IMapOperater* pMapOperater);
    void virtual waitInputAndPlay();
    void virtual showWin();
    void virtual showLose();
    ~GamePlayer();
    
private:
    
    IMapOperater* m_pMapOperator;
    

};


#endif /* Player_h */
