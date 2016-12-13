/***************************************************************
 * Author: James Cameron Abreu
 * Date: 11/17/2016
 * Description: 
 *  ************************************************************/

#ifndef TEAM_HPP
#define TEAM_HPP

#include <string>
#include <iostream>

#include "Creature.hpp"

// creature nodes used by teams:
struct CreatureNode {
  CreatureNode* next;
  CreatureNode* previous;
  Creature* ID;
};


class Team {

  private:
    CreatureNode* head;
    CreatureNode* tail;
    CreatureNode* iterator;
    int points;

  public:
    
    // get functions
    CreatureNode* getHead();
    CreatureNode* getTail();
    CreatureNode* getIterator();
    int getPoints();

    // set functions
    void setHead(CreatureNode* newNode);
    void setTail(CreatureNode* newNode);

    void setIterator(CreatureNode* newNode);
    void iteratorNext();
    void iteratorPrevious();

    void setPoints(int newPoints);
    void increasePoints(int newPoints);

    // linked list actions:
    bool isEmpty();
    void pushNode(Creature* newID);
    Creature* popNode();
    void printNodes();
    void deleteNodes();

    // game functions:
    std::string getName(int type);

    // constructor/destructors:
    Team();
    ~Team();
};

#endif
