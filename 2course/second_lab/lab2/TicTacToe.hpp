#pragma once
#include "SparseVector.hpp"
#include <vector>
// -1 === 'X' 0 === ' ' 1 ==='O'

struct mymove
        {
            mymove() {};
            mymove(int score_): score(score_){}
            int x;
            int y;
            int score;
        };

class Board
{
    
private:
    myvector::SparseVector<int> data;
    size_t size;
public:
    Board(size_t size_);
    void Set(int i, int j, int value);
    int Get(int i, int j);
    void PrintBoard();
    int CheckVictory();
    mymove GetBestMove(int player, bool isAI);
};

Board::Board(size_t size_)  : size(size_) 
{
    data = myvector::SparseVector<int>("BTreeDictionary", "ArraySequence", 0);
    for (size_t i = 0; i < size_ * size_; ++i) {
            data.append(0);
        }   
}
void Board::Set(int i, int j, int value){
    data[this->size * i + j] = value;
}

int Board::Get(int i, int j){
    // cout<<i<<" SDES "<<j<<std::endl;
    return data[this->size * i + j];
}

void Board::PrintBoard(){
    for (size_t i = 0; i < size*size; i++)
    {
        if (i % size == 0)
        {
            std::cout<<'\n';
        }
        if (data[i] == -1)
        {
            std::cout<<"X ";
        }
        if (data[i] == 0)
        {
            std::cout<<"_ ";
        }
        if (data[i] == 1)
        {
            std::cout<<"O ";
        }
    }
    std::cout<<'\n';   
}
int Board::CheckVictory(){
    bool draw = true;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
            {
                if (Get(i,j) == 0)
                {
                   draw = false;
                }
                
            }
    }
    if (draw)
    {
        return 2;
    }
    
    int c;
    bool victory;
    for (size_t i = 0; i < size; i++)
    {
        c = Get(i,0);
        if (c != 0)
        {
            victory = true;
            for (size_t j = 0; j < size; j++)
            {
                if (Get(i,j) != c)
                {
                    victory = false;
                    break;
                }
            }
            if (victory)
            {
                return c;
            }
        }
    }
    
    for (size_t i = 0; i < size; i++)
    {
        c = Get(0,i);
        if (c != 0)
        {
            victory = true;
            for (size_t j = 0; j < size; j++)
            {
                if (Get(j,i) != c)
                {
                    victory = false;
                    break;
                }
            }
            if (victory)
            {
                return c;
            }
        }
    }

    c = Get(0,0);
    if (c != 0)
    {
        victory = true;
        for (size_t i = 0; i < size; i++)
        {
            if (Get(i,i) != c)
            {
                victory = false;
                break;
            }
        }
        if (victory)
        {
            return c;
        }
    }

    c = Get(size - 1,0);
    if (c != 0)
    {
        victory = true;
        for (size_t i = 0; i < size; i++)
        {
            if (Get(size - i - 1,i) != c)
            {
                victory = false;
                break;
            }
        }
        if (victory)
        {
            return c;
        }
    }
    return 0;
}



mymove Board::GetBestMove(int player, bool isAI){
    int rv = CheckVictory();
    int AIplayer;
    if (isAI)
    {
        AIplayer = player;
    }else
    {
        AIplayer = (-1)* player;
    }
    
    
    if (rv == AIplayer)
    {
        return move(10);
    }else if (rv == player)
    {
        return move (-10);
    } else if (rv == 2)
    {
        return move(0);
    }
    
    std::vector<mymove> vec;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (Get(i,j) == 0)
            {
               mymove mv;
               mv.x = i;
               mv.y = j;
               this->Set(i, j, player);
                if (isAI)
                {
                     mv.score = GetBestMove(player*(-1), false).score;
                }else
                {
                     mv.score = GetBestMove(player*(-1), true).score;
                }
                vec.push_back(mv);
               this->Set(i, j, 0);
            }
            
        }
    }
    int bestMove = 0;
    if (isAI)
    {
        int bestScore = -1000000;
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (vec[i].score > bestScore)
            {
                bestMove = i;
                bestScore = vec[i].score;
            }
            
        }
        
    }else
    {
        int bestScore = 1000000;
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (vec[i].score < bestScore)
            {
                bestMove = i;
                bestScore = vec[i].score;
            }
        }
    }
    
    return vec[bestMove];
}