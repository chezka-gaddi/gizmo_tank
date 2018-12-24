/***************************************************************************//* 
* @file  
* @brief header file containing constants
* ******************************************************************************/
#pragma once
#ifndef __CONSTANTS_H
#define __CONSTANTS_H

#include <cmath>

#include "direction.h"
#include "coordinate.h"

// Macros to translate tile number to coordinates and vice versa
#define tileNumber(x,y) ( (y * width) + x )
#define unpackTile(num) (Coordinate(((num)%width),(num-(num%width))/width))

// Map variables
const int ENEMYTANK = -100;
const int SHOT = -90;
const int ROCK = -80;
const int WATER = -70;
const int CRATER = -60;
const int OURTANK = 100;
const int TREE = 90;
const int BUSH = 80;
const int EMPTY = 1;
const int UNKNOWN = 6;

// spendAP options
const int Move = 1;
const int Attack = 2;
const int EndTurn = 3;

// directions
const direction North = direction::UP;
const direction East = direction::RIGHT;
const direction South = direction::DOWN;
const direction West = direction::LEFT;
const direction Northeast = direction::UPRIGHT;
const direction Southeast = direction::DOWNRIGHT;
const direction Southwest = direction::DOWNLEFT;
const direction Northwest = direction::UPLEFT;
const direction Stay = direction::STAY;

#endif
