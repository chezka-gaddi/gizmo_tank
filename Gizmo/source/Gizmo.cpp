/***************************************************************************//**
 * @file
 * @brief Contains the Gizmo class.
 ******************************************************************************/
#include "Gizmo.h"


/***************************************************************************//**
 * @author Chezka Gaddi
 * 
 * @brief Constructor for Gizmo class, intializes objects and pointers.
 * 
 ******************************************************************************/

Gizmo::Gizmo() {
    name = "Gizmo";
}


/***************************************************************************//**
 * @author Chezka Gaddi
 * 
 * @brief  Destructor for Gizmo class delete dynamic memory.
 *
 ******************************************************************************/

Gizmo::~Gizmo() 
{
}


/***************************************************************************//**
 * @author Caelan Klein, Chezka Gaddi
 * 
 * @brief Assign attributes and return them.
 *
 * @param[in] pointsAvailable - assignable points
 * @param[in] baseStats - base attributes given
 * 
 * @return desired attributes
 ******************************************************************************/

attributes Gizmo::setAttribute(int pointsAvailable, attributes baseStats)
{ 
    attributes attrib;
    
    return attrib;
}


/***************************************************************************//**
 * @author Chezka Gaddi
 * 
 * @brief spendAP
 *
 * Update game state object, playstyle and call spendAP() on Strategy
 * pointer.
 *
 * @param[in] map - struct containing map information
 * @param[in] status - struct containing tank status information
 * 
 * @return action
 ******************************************************************************/

int Gizmo::spendAP(MapData map, PositionData status)
{
    return STAY;
}


/***************************************************************************//**
 * @author Caelan Klein
 * 
 * @brief Call move() on Strategy pointer 
 *
 * @param[in] map - struct containing map information
 * @param[in] status - struct containing tank status information
 * 
 * @return direction to move
 ******************************************************************************/

direction Gizmo::move(MapData map, PositionData status)
{
    return UP;
}


/***************************************************************************//**
 * @author Chezka Gaddi
 * 
 * @brief attack
 *
 * Call attack() on Strategy pointer 
 *
 * @param[in] map - struct containing map information
 * @param[in] status - struct containing tank status information
 * 
 * @return direction to attack
 ******************************************************************************/

direction Gizmo::attack(MapData map, PositionData status)
{
    return UP;
}




#ifdef DYNAMIC
extern "C" //required for runtime linking
{
    Actor * maker()
    {
        return new Gizmo;
    }
}
#endif
