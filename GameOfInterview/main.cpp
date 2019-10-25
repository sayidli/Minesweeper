//
//  main.cpp
//  GameOfInterview
//
//  Created by lipengyao on 2019/10/23.
//  Copyright © 2019 lipengyao. All rights reserved.
//

#include <iostream>
#include "Map.h"
#include "Player.h"


int main(int argc, const char * argv[]) {
    auto pGameM = make_shared<GameMap>();
    shared_ptr<IMapBase> pGameMap(pGameM) ;
    if(!pGameMap->create(3, 4, 7)) return 0;
    pGameMap->showView();
    
    shared_ptr<IPlayer> pGamePlayer(new GamePlayer()) ;
    pGamePlayer->init((IMapOperater*)pGameM.get());
    while(!pGameMap->isEnd())
    {
        pGamePlayer->waitInputAndPlay();
        pGameMap->showView();
    }
    
    return 0;
}
