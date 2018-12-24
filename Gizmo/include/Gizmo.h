/***************************************************************************//* 
* @file  
* @brief header file containing Gizmo class
* ******************************************************************************/
#pragma once
#ifndef __GIZMO_H
#define __GIZMO_H

#include <vector>
#include <cctype>

#include "Actor.h"

#include "constants.h"
#include "coordinate.h"
#include "graph.h"
#include "bfsPaths.h"


class Gizmo : public Actor
{
    private:
        vector <vector <bool>> spotFilled;

    public:
        virtual direction move(MapData map, PositionData status);
        virtual direction attack(MapData map, PositionData status);
        virtual attributes setAttribute(int pointsAvailable, attributes baseStats);
        virtual int spendAP(MapData map, PositionData status);

        Gizmo();
        ~Gizmo();
};

#endif
