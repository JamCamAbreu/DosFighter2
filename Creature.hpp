/********************************************************************************
 * Author: James Cameron Abreu
 * Date: 11/03/2016
 * Description: Creature is an abstract base clas in which specific Creatures 
 *  are defined in derived classes.
 * *****************************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "Die.hpp"

class Creature {

  private:
    int type;
    int numberAttackDie;
    int sizeAttackDie;
    int numberDefenseDie;
    int sizeDefenseDie;
    int armor;
    int strengthFull;
    int strengthCurrent;
    Die* attackDie;
    Die* defenseDie;
    bool usedHogwarts;

  public: 
    // get functions:
    int getType();
    int getNumberAttackDie();
    int getSizeAttackDie();
    int getNumberDefenseDie();
    int getSizeDefenseDie();
    int getArmor();
    int getStrengthFull();
    int getStrengthCurrent();
    Die* getAttackDie();
    Die* getDefenseDie();
    bool getUsedHogwarts();

    // set functions:
    void setType(int newType);
    void setNumberAttackDie(int newNumber);
    void setSizeAttackDie(int newSize);
    void setNumberDefenseDie(int newNumber);
    void setSizeDefenseDie(int newSize);
    void setArmor(int newArmor);
    void setStrengthFull(int newStrengthFull);
    void setStrengthCurrent(int newStrengthCurrent);
    void assignAttackDie(Die* newDie);
    void assignDefenseDie(Die* newDie);
    void setUsedHogwarts(bool newFlag);

    // other functions:
    int rollAttack(int random);
    int rollDefense(int random);
    int healCreature(int random);

    // constructor/destructor:
    Creature();
    ~Creature();
};

#endif
