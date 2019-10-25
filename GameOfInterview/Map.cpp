//
//  Map.cpp
//  GameOfInterview
//
//  Created by lipengyao on 2019/10/24.
//  Copyright © 2019 lipengyao. All rights reserved.
//
#include <ctime>
#include <random>
#include "Common.h"
#include "Map.h"
// Define the enumtype of chess
enum class ChessStatus:char
{
    COVER = 'C', BOMB = 'B', FLAG = 'F', EMPTY = 'E'
};

    
namespace GeneForGame{
    bool isGameWin(vector<vector<char>> &gameCover, vector<vector<char>> &gameData)
    {
        for(int i=0; i<gameCover.size(); i++)
        {
            for(int j=0; j<gameCover[0].size(); j++)
            {
                if(gameCover[i][j] == (char)ChessStatus::COVER && gameData[i][j]!=(char)ChessStatus::BOMB)return false;
            }
        }
        
        return true;
    }
    void _putBombsInGame(vector<vector<char>> &gameMap, int bombNum)
    {
        // put bombs on the map
        std::random_device rd;
        std::default_random_engine e(rd());
        std::uniform_int_distribution<> uRow(0,gameMap.size()-1);
        std::uniform_int_distribution<> uCol(0,gameMap[0].size()-1);
        
        int numOfBombs = bombNum;
        while(numOfBombs>0)
        {
            bool suc = false;
            while(suc == false)
            {
                int randomRow = uRow(e);
                int randomCol = uCol(e);
                
                if(gameMap[randomRow][randomCol] == (char)ChessStatus::BOMB) continue;
                gameMap[randomRow][randomCol] = (char)ChessStatus::BOMB;
                suc = true;
            }
            numOfBombs--;
        }
    }
    void _generateNumbersInGame(vector<vector<char>> &gameMap)
    {
        for(int i=0; i<gameMap.size(); i++)
        {
            for(int j=0; j<gameMap[0].size(); j++)
            {
                if(gameMap[i][j] == (char)ChessStatus::BOMB) continue;
                
                int sumOfBombs = 0;
                //top
                int top = i-1;
                for(int col= j-1; col<=j+1; col++)
                {
                    if(top>=0&&col>=0&&col<gameMap[0].size())
                    {
                        if(gameMap[top][col] == (char)ChessStatus::BOMB) sumOfBombs++;
                    }
                }
                
                //down
                top = i+1;
                for(int col= j-1; col<=j+1; col++)
                {
                    if(top<gameMap.size()&&col>=0&&col<gameMap[0].size())
                    {
                        if(gameMap[top][col] == (char)ChessStatus::BOMB) sumOfBombs++;
                    }
                }
                
                //left middle
                int leftMiddle = j-1;
                if(leftMiddle>=0)
                {
                    if(gameMap[i][leftMiddle] == (char)ChessStatus::BOMB) sumOfBombs++;
                }
                
                //right middle
                int rightMiddle = j+1;
                if(rightMiddle<gameMap[0].size())
                {
                    if(gameMap[i][rightMiddle] == (char)ChessStatus::BOMB) sumOfBombs++;
                }
                
                
                char strSum = '0' + sumOfBombs;
                gameMap[i][j] = strSum;
            }
        }
    }
}




    GameMap::GameMap():isContinue(true)
    {
    };
    
    //IMapBase
    bool GameMap::create(int row, int col, int bombNum)
    {
        if(bombNum>(row*col))
        {
            cout<<"the num of bombs is overflow!"<<endl; return false;
        }
        
        if(row <=0 || col<=0)
        {
            cout<<"row or col is incorrect!"<<endl; return false;
        }
        
        for(int i = 0; i < row; i++)
        {
            vector<char> row;
            for(int j = 0; j < col; j++)
            {
                row.push_back((char)ChessStatus::EMPTY);
            }
            GameMap::mapData_.push_back(row);
        }
        
        
        GeneForGame::_putBombsInGame(mapData_, bombNum);
        
        GeneForGame::_generateNumbersInGame(mapData_);
        
        //create cover for the map
        for(int i=0; i<row; i++)
        {
            vector<char> row;
            for(int j=0; j<col; j++)
            {
                row.push_back((char)ChessStatus::COVER);
            }
            mapDataCover_.push_back(row);
        }
        
        return true;
    }
    
    bool GameMap::isEnd()
    {
        return !isContinue;
    }
    
    void GameMap::showView()
    {
        cout<<"*";
        for(int i=0; i<GameMap::mapDataCover_[0].size(); i++)
        {
            cout<<"** "<<i;
        }
        cout<<endl;
        for(int i=0; i<GameMap::mapDataCover_.size(); i++)
        {
            cout<<i<<"*| ";
            for(int j=0; j< GameMap::mapDataCover_[0].size(); j++)
            {
                cout<<GameMap::mapDataCover_[i][j]<<" | ";
            }
            cout<<endl;
        }
    }
    
    //IMapOperater
    void GameMap::openBox(int row, int col)
    {
        if(row<0||col<0||row>=mapDataCover_.size()||col>=mapDataCover_[0].size())
        {
            cout<<"your inputs are invalid!!!!"<<endl;
            return;
        }
        if(mapDataCover_[row][col] != (char)ChessStatus::COVER&&mapDataCover_[row][col] != (char)ChessStatus::FLAG)
        {
            cout<<"the box is already opened"<<endl;
            return;
        }
        if(mapData_[row][col] == (char)ChessStatus::BOMB)
        {
            cout<<"you lose!"<<endl;
            isContinue = false;
            return;
        }
        mapDataCover_[row][col] = mapData_[row][col];
        if(GeneForGame::isGameWin(mapDataCover_, mapData_))
        {
            cout<<"YOU WIN THE GAME!"<<endl;
            isContinue = false;
            return;
        }
    }
    void GameMap::putFlag(int row, int col)
    {
        if(mapDataCover_[row][col] != (char)ChessStatus::COVER)
        {
            cout<<"the box is already opened or flaged!"<<endl;
            return;
        }
        mapDataCover_[row][col] = (char)ChessStatus::FLAG;
    }
    
    GameMap::~GameMap()
    {
        
    }
