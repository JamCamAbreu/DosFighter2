/********************************************************************************
 * Author: James Cameron Abreu
 * Date: 11/03/2016
 * Description:
 * *****************************************************************************/

#include "Creature.hpp"
#include "Die.hpp"

// get functions: --------------------------------------------
int Creature::getType() {return type;}
int Creature::getNumberAttackDie() {return numberAttackDie;}
int Creature::getSizeAttackDie() {return sizeAttackDie;}
int Creature::getNumberDefenseDie() {return numberDefenseDie;}
int Creature::getSizeDefenseDie() {return sizeDefenseDie;}
int Creature::getArmor() {return armor;}
int Creature::getStrengthFull() {return strengthFull;}
int Creature::getStrengthCurrent() {return strengthCurrent;}
Die* Creature::getAttackDie() {return attackDie;}
Die* Creature::getDefenseDie() {return defenseDie;}
bool Creature::getUsedHogwarts() {return usedHogwarts;}

// set functions: --------------------------------------------
void Creature::setType(int newType) {type = newType;}
void Creature::setNumberAttackDie(int newNumber) {numberAttackDie = newNumber;}
void Creature::setSizeAttackDie(int newSize) {sizeAttackDie = newSize;}
void Creature::setNumberDefenseDie(int newNumber) {numberDefenseDie = newNumber;}
void Creature::setSizeDefenseDie(int newSize) {sizeDefenseDie = newSize;}
void Creature::setArmor(int newArmor) {armor = newArmor;}
void Creature::setStrengthFull(int newStrengthFull) {strengthFull = newStrengthFull;}
void Creature::setStrengthCurrent(int newStrengthCurrent) {strengthCurrent = newStrengthCurrent;}
void Creature::assignAttackDie(Die* newDie) {attackDie = newDie;}
void Creature::assignDefenseDie(Die* newDie) {defenseDie = newDie;}
void Creature::setUsedHogwarts(bool newFlag) {usedHogwarts = newFlag;}

// other functions: -------------------------------------------
/************************
** Name: rollAttack
** Parameters: int random
** Description: This function uses the Die object that each creature 
has in order to get a random roll. The parameter random passes in a 
number that helps to deal with the fact that randomization is not only 
time-random. This is because I discovered I was getting the same values 
returned when using for loops (probably because the computer does it 
so quickly that the time(0) function was returning the same seed.) The 
random integer added to this ensures a different seed every time. 
*************************/
int Creature::rollAttack(int random) {
  if (getAttackDie() != NULL) {

    int totalAttack = 0; // accumulator
    // roll each die, add up total attack:
    for (int i = 0; i < getNumberAttackDie(); i++) {
      totalAttack += getAttackDie()->rollDie(i + random); // each roll is random
    }
    // if medusa, return -1 for special move:
    if ( (getType() == 4) && (totalAttack == 12) )
      return -1;
    else
      return totalAttack;
  } // end if NOT NULL

  else 
    return -9999; // error flag
}

/************************
** Name: rollDefense
** Parameters: int random
** Description: Similar to the rollAttack function above, but it uses 
the defense Die and correct number of defense Die's. 
*************************/
int Creature::rollDefense(int random) {
  if (getDefenseDie() != NULL) {

    int totalDefense = 0; // accumulator
    // roll each die, add up total attack:
    for (int i = 0; i < getNumberDefenseDie(); i++) {
      totalDefense += getDefenseDie()->rollDie(i + random); // each roll is random
    }
    return totalDefense;
  } // end if NOT NULL

  else 
    return -9999; // error flag
}



int Creature::healCreature(int random) {
  
  int healAmount;
  if (getDefenseDie() != NULL) {
    healAmount = getDefenseDie()->rollDie(random);
    setStrengthCurrent(healAmount);
    return healAmount;
  }
  else 
    return -999; // ERROR

}
    


// constructor/destructor: -----------------------------------
Creature::Creature() {
  setType(0);
  setNumberAttackDie(0);
  setSizeAttackDie(0);
  setNumberDefenseDie(0);
  setSizeDefenseDie(0);
  setArmor(0);
  setStrengthFull(0);
  setStrengthCurrent(0);
  assignAttackDie(NULL);
  assignDefenseDie(NULL);
  setUsedHogwarts(false);
}

Creature::~Creature() {
  if (getAttackDie() != NULL)
    delete getAttackDie();

  if (getDefenseDie() != NULL)
    delete getDefenseDie();
}

