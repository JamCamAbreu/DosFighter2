/********************************************************************************
 * Author: James Cameron Abreu
 * Date: 11/17/2016
 * Description: Because the creature classes are not overly complex, I will 
 *  combine them into one file:
 * *****************************************************************************/

#include "creatureTypes.hpp"

// Barbarian --------------------------------------------
// constructor:
Barbarian::Barbarian() {
  setType(2);
  setNumberAttackDie(2);
  setSizeAttackDie(6);
  setNumberDefenseDie(2);
  setSizeDefenseDie(6);
  setArmor(0);
  setStrengthFull(12);
  setStrengthCurrent(12);

  assignAttackDie(new Die(6));
  assignDefenseDie(new Die(6));
}
// destructor:
Barbarian::~Barbarian() {
  if (getAttackDie() != NULL)
    delete getAttackDie();
  if (getDefenseDie() != NULL)
    delete getDefenseDie();
}


// Vampire --------------------------------------------
// constructor:
Vampire::Vampire() {
  setType(1);
  setNumberAttackDie(1);
  setSizeAttackDie(12);
  setNumberDefenseDie(1);
  setSizeDefenseDie(6);
  setArmor(1);
  setStrengthFull(18);
  setStrengthCurrent(18);

  assignAttackDie(new Die(12));
  assignDefenseDie(new Die(6));
}
// destructor:
Vampire::~Vampire() {
  if (getAttackDie() != NULL)
    delete getAttackDie();
  if (getDefenseDie() != NULL)
    delete getDefenseDie();
}


// Medusa --------------------------------------------
// constructor:
Medusa::Medusa() {
  setType(4);
  setNumberAttackDie(2);
  setSizeAttackDie(6);
  setNumberDefenseDie(1);
  setSizeDefenseDie(6);
  setArmor(3);
  setStrengthFull(8);
  setStrengthCurrent(8);

  assignAttackDie(new Die(6));
  assignDefenseDie(new Die(6));
}
// destructor:
Medusa::~Medusa() {
  if (getAttackDie() != NULL)
    delete getAttackDie();
  if (getDefenseDie() != NULL)
    delete getDefenseDie();
}


// Bluemen --------------------------------------------
// constructor:
BlueMen::BlueMen() {
  setType(3);
  setNumberAttackDie(2);
  setSizeAttackDie(10);
  setNumberDefenseDie(3);
  setSizeDefenseDie(6);
  setArmor(3);
  setStrengthFull(12);
  setStrengthCurrent(12);

  assignAttackDie(new Die(10));
  assignDefenseDie(new Die(6));
}
// destructor:
BlueMen::~BlueMen() {
  if (getAttackDie() != NULL)
    delete getAttackDie();
  if (getDefenseDie() != NULL)
    delete getDefenseDie();
}


// HarryPotter --------------------------------------------
// constructor:
HarryPotter::HarryPotter() {
  setType(5);
  setNumberAttackDie(2);
  setSizeAttackDie(6);
  setNumberDefenseDie(2);
  setSizeDefenseDie(6);
  setArmor(0);
  setStrengthFull(10);
  setStrengthCurrent(10);

  assignAttackDie(new Die(6));
  assignDefenseDie(new Die(6));
}

// destructor:
HarryPotter::~HarryPotter() {
  if (getAttackDie() != NULL)
    delete getAttackDie();
  if (getDefenseDie() != NULL)
    delete getDefenseDie();
}

