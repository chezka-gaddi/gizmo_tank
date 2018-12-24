/***************************************************************************//* 
* @file  
* @brief header file containing Coordinate object
* ******************************************************************************/
#pragma once
#ifndef __COORDINATE_H
#define __COORDINATE_H

#include <iostream>  

using namespace std; 

struct Coordinate
{
    int x, y;

    Coordinate(int tileNumber)
    {
        int width = 0;
        x = tileNumber % width;
        y = (tileNumber - x) / width;
    }

    Coordinate(int paramX, int paramY)
    {
        x = paramX;
        y = paramY;
    };

    bool operator==(const Coordinate& a) const
    {
        return (x == a.x && y == a.y);
    }

    friend ostream& operator << (ostream& os, const Coordinate& rhs)
    {
        os << rhs.x << "," << rhs.y;
        return os;
    }
};

#endif
