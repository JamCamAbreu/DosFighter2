/***************************************************************
 * Author: James Cameron Abreu
 * Date: 11/17/2016
 * Description: The team class holds the logic for storing Creature*'s 
    into a linked list. Creatures are pushed and popped from the 
	queue. Two Team objects are used for each player, for a total of 
	four Team objects: Each player has a current Team (in which creatures 
	are popped from the queue and used for battle), and a loser pile Team
	which is used to store creatures that were defeated. 
 *  ************************************************************/

#include "Team.hpp"

// get functions
CreatureNode* Team::getHead() {return head;}
CreatureNode* Team::getTail() {return tail;}
CreatureNode* Team::getIterator() {return iterator;}
int Team::getPoints() {return points;}

// set functions
void Team::setHead(CreatureNode* newNode) {head = newNode;}
void Team::setTail(CreatureNode* newNode) {tail = newNode;}
void Team::setIterator(CreatureNode* newNode) {iterator = newNode;}
void Team::setPoints(int newPoints) {points = newPoints;}
void Team::increasePoints(int newPoints) {points += newPoints;}
void Team::iteratorNext() {iterator = iterator->next;}
void Team::iteratorPrevious() {iterator = iterator->previous;}

// linked list actions:------------------------------------------------
/************************
** Name: isEmpty
** Parameters: none
** Description: This function is common in linked lists, and is used to 
check if the list is empty. 
*************************/
bool Team::isEmpty() {
  if (getHead()->next == getTail())
    return true;
  else 
    return false;
}


/************************
** Name: pushNode
** Parameters: Creature* newID
** Description: This push function pushes a new Creature* onto the queue. 
That value can later be popped. 
*************************/
void Team::pushNode(Creature* newID) {
  // allocate a new queue cell:
  CreatureNode* newCell = new CreatureNode;

  // Team is empty:
  if (isEmpty()) {
    newCell->next = getTail();
    newCell->previous = getHead();
    getTail()->previous = newCell;
  }
  // Team already has at least one Creature* node:
  else {
       // put the new cell in our Team:
    newCell->next = getHead()->next; // whatever top WAS pointing to
    newCell->previous = getHead();

    // update previous 2nd queue item:
    newCell->next->previous = newCell;
  }

  // assign the value to the the new cell:
  newCell->ID = newID;

  // update the head:
  getHead()->next = newCell;
}


/************************
** Name: displayStats
** Parameters: none
** Description: This function pops a Creature* off of the queue, which can 
then be stored in a temporary variable (which is how it is implemented in
the Tournament game. It's popped in order to battle another Creature, and then 
pushed back onto the queue, either the original Team queue, or the loser queue 
if it lost the battle.)
*************************/
Creature* Team::popNode() {
  // Team has at least one creature to pop:
  if (!isEmpty()) {
    // the CreatureNode* we will pop:
    CreatureNode* popCell = getTail()->previous; // last cell

    // redirect the tail to point to the cell 
    // BEFORE the one that we will pop:
    getTail()->previous = popCell->previous; // top is possible too

    // update the second to last cell's next to point to tail:
    CreatureNode* secondToLast = popCell->previous; // could be the head 
    secondToLast->next = getTail();

    // grab value for return before deleting:
    Creature* popID = popCell->ID;

    // delete the popped cell:
    delete popCell;

    // return value:
    return popID;
  }
  else // if empty return NULL:
    return NULL;
}


/************************
** Name: printNodes
** Parameters: none
** Description: This function uses the iterator to traverse through the 
linked list and access the Creature*'s type which is used to print out 
the correct string. A counter is used to fix grammatical mistakes 
such as printing out "and" even though there is only one object in the 
queue. 
*************************/
void Team::printNodes() {

  setIterator(getHead()->next);
  int counter = 1;

  while (getIterator() != getTail()) {

    // call appropriate print function:
    std::string name;
    name = getName(getIterator()->ID->getType());

    if (getIterator()->next == getTail()) {
      if (counter > 1)
        std::cout << "and " << name << ".";
      else 
        std::cout << name << ".";
    }
    else {
      std::cout << name << ", ";
    }

    // move to next CreatureNode* if exists:
    iteratorNext();
    counter++;
  }

  // none were printed
  if (counter == 1) {
    std::cout << "(none)";
  }
}


/************************
** Name: deleteNodes
** Parameters: none
** Description: This function uses the iterator to traverse through the 
linked list and carefully delete each node in the list and then deleting the 
head and tail nodes. This function is logically used by the class destructor. 
*************************/
void Team::deleteNodes() {
  setIterator(getHead()->next);
  while (getIterator() != getTail()) {

    // call appropriate delete code:
    // in order to NOT delete the cell we are currently on:
    CreatureNode* previousCell = getIterator()->previous;
    // move to next CreatureNode*:
    iteratorNext();

    // delete the previousCell:
    delete previousCell;
  } // end while loop

  // delete the last item, unless it's the head:
  if (getIterator()->previous != getHead()) {
    CreatureNode* previousCell = getIterator()->previous;
    delete previousCell;
  }

  // finally, delete the head and tail:
  delete getHead();
  delete getTail();

  setHead(NULL);
  setTail(NULL);
}



/************************
** Name: getName
** Parameters: int type
** Description: This function simply returns the appropriate string for the 
Creature type that's passed in. 
*************************/
std::string Team::getName(int type) {
  switch (type) {
    case 0: 
      return "ERROR: NULL";
      break; 

    case 1: {
      return "Vampire";
      break; }

    case 2:  {
      return "Barbarian";
      break; }

    case 3: {
      return "BlueMen";
      break; }

    case 4: {
      return "Medusa";
      break; }

    case 5: {
      return "Harry Potter";
      break; }

    default: {
      return "ERROR: DEFAULT VALUE";
      break; }
  } // end switch
}



// constructor:-----------------------------------------------------
Team::Team() {
  // Node setup:
  setHead(new CreatureNode);
  setTail(new CreatureNode);

  getHead()->next = getTail();
  getHead()->previous = NULL;
  getHead()->ID = NULL;

  getTail()->next = NULL;
  getTail()->previous = getHead();
  getTail()->ID = NULL;

  setPoints(0);
}


// destructor:
Team::~Team() {
  deleteNodes();
}
