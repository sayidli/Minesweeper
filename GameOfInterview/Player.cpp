//
//  Player.cpp
//  GameOfInterview
//
//  Created by lipengyao on 2019/10/24.
//  Copyright © 2019 lipengyao. All rights reserved.
//

#include "Player.h"

GamePlayer::GamePlayer():m_pMapOperator(nullptr){}

bool GamePlayer::init(IMapOperater* pMapOperater)
{
    if(!pMapOperater)
    {
        cout<<"the pMapOperator is null"<<endl;
        return false;
    }
    //shared_ptr<IMapOperater> pTem(pMapOperater);
    m_pMapOperator = pMapOperater;
    return true;
}

void GamePlayer::waitInputAndPlay()
{
    cout<<"begin input col and row...."<<endl;
    int col = 0;
    int row = 0;
    cin>>row>>col;
    cout<<"row: "<<row<<",col: "<<col<<endl;
    
    m_pMapOperator->openBox(row, col);
    
}

void GamePlayer::showWin()
{
    
}

void GamePlayer::showLose()
{
    
}

GamePlayer::~GamePlayer()
{
}
