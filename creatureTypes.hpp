/********************************************************************************
 * Author: James Cameron Abreu
 * Date: 11/17/2016
 * Description: Because the creature classes are not overly complex, I will 
 *  combine them into one file:
 * *****************************************************************************/

#ifndef CREATURETYPES_HPP
#define CREATURETYPES_HPP

#include "Creature.hpp"

// Barbarian --------------------------------------------
class Barbarian : public Creature {
  public:
    // constructor/destructor:
    Barbarian();
    ~Barbarian();
};

// Vampire --------------------------------------------
class Vampire : public Creature {
  public:
    // constructor/destructor:
    Vampire();
    ~Vampire();
};

// Medusa --------------------------------------------
class Medusa : public Creature {
  public:
    // constructor/destructor:
    Medusa();
    ~Medusa();
};

// Bluemen --------------------------------------------
class BlueMen : public Creature {
  public:
    // constructor:
    BlueMen();
    ~BlueMen();
};

// HarryPotter --------------------------------------------
class HarryPotter : public Creature {
  public:
    // constructor/destructor:
    HarryPotter();
    ~HarryPotter();
};


#endif

