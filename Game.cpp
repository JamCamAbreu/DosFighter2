/********************************************************************************
 * Author: James Cameron Abreu
 * Date: 11/03/2016
 * Description: The Game class has many features. It prompts the user for game 
 *  settings, begins the game, runs each turn, calculates combat results, and 
 *  determines game winning conditions.
 * *****************************************************************************/

#include "Game.hpp"

// get functions: ------------------------------------------------
Creature* Game::getCreatureLeft() {return CreatureLeft;}
Creature* Game::getCreatureRight() {return CreatureRight;}
int Game::getBattleTurn() {return battleTurn;}
Team* Game::getTeamLeft() {return teamLeft;}
Team* Game::getTeamRight() {return teamRight;}
Team* Game::getTeamLeftDefeated() {return teamLeftDefeated;}
Team* Game::getTeamRightDefeated() {return teamRightDefeated;}

// set functions: ------------------------------------------------
void Game::assignCreatureLeft(Creature* newCreature) {CreatureLeft = newCreature;}
void Game::assignCreatureRight(Creature* newCreature) {CreatureRight = newCreature;}
void Game::setBattleTurn(int newBattleTurn) {battleTurn = newBattleTurn;}
void Game::setTeamLeft(Team* newTeam) {teamLeft = newTeam;}
void Game::setTeamRight(Team* newTeam) {teamRight = newTeam;}
void Game::setTeamLeftDefeated(Team* newTeam) {teamLeftDefeated = newTeam;}
void Game::setTeamRightDefeated(Team* newTeam) {teamRightDefeated = newTeam;}

// increment functions: -------------------------------------------
void Game::incrementBattleTurn() {battleTurn++;}


/************************
** Name: displayStats
** Parameters: none
** Description: This function is a simple print function used by a few other functions.
*************************/
void Game::displayStats() {
  std::cout << std::endl;
  std::cout << "*****************************************************************" << std::endl;
  std::cout << "*                     Select your fighter!                      *" << std::endl;
  std::cout << "*---------------------------------------------------------------*" << std::endl;
  std::cout << "*-#--Name----------Attack--Defense--Armor---Strength--Special---*" << std::endl;
  std::cout << "* 1. Vampire       1d12    1d6      1       18        Charm     *" << std::endl;
  std::cout << "* 2. Barbarian     2d6     2d6      0       12        (none)    *" << std::endl;
  std::cout << "* 3. BlueMen       2d10    3d6      3(-mob) 12        Mob       *" << std::endl;
  std::cout << "* 4. Medusa        2d6     1d6      3       8         Glare     *" << std::endl;
  std::cout << "* 5. Harry Potter  2d6     2d6      0       10        Hogwarts  *" << std::endl;
  std::cout << "*****************************************************************" << std::endl;
}


// Game Settings: -------------------------------------------------
/************************
** Name: printType
** Parameters: int type
** Description: This function returns the appropriate string name 
for the type of Creature.
*************************/
std::string Game::printType(int type) {
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


/************************
** Name: allocateCreature
** Parameters: int type
** Description: This function makes dynamically allocating the correct
type of Creature easier to implement. It returns a pointer to a dynamically 
allocated Creature of the appropriate type. 
*************************/
Creature* Game::allocateCreature(int type) {
  switch (type) {
    case 0: 
      std::cout << "ERROR: ALLOCATECREATURE: NULL(0)" << std::endl;
      return NULL;
      break; 

    case 1: {
      return new Vampire;
      break; }

    case 2:  {
      return new Barbarian;
      break; }

    case 3: {
      return new BlueMen;
      break; }

    case 4: {
      return new Medusa;
      break; }

    case 5: {
      return new HarryPotter;
      break; }

    default: {
      std::cout << "ERROR: ALLOCATECREATURE: DEFAULT" << std::endl;
      return NULL;
      break; }
  } // end switch
}


/************************
** Name: promptGameSettings
** Parameters: none
** Description: This function takes care of all of the game setup
and user interaction. It allows the user to choose from the different 
creature types for the simulation, and allocates the correct creatures 
that will be used later in combat. 
*************************/
void Game::promptGameSettings() {

  std::cout << "New Game Settings: " << std::endl;

  displayStats();

  std::cout << "Your Selection Player One: ";
  int choiceP1;
  std::cin >> choiceP1;
  inputValidation(choiceP1, 1, 5);

  std::cout << "Your Selection Player Two: ";
  int choiceP2;
  std::cin >> choiceP2;
  inputValidation(choiceP2, 1, 5);

  std::cout << std::endl;
  std::cout << "You chose: ";
  std::cout << printType(choiceP1) << ", ";
  std::cout << printType(choiceP2) << ". ";

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Beginning battle simulation!";
  std::cout << std::endl;

  // assign creatures:
  assignCreatureLeft(allocateCreature(choiceP1));
  assignCreatureRight(allocateCreature(choiceP2));
}



// Combat Logic-----------------------------------------------------
/************************
** Name: singleCombat
** Parameters: none
** Description: This function is the first function ran when the user 
  wants to begin a single combat simulation. They will choose which fighters
  will participate for each player, and then the combat will begin until a 
  winner emerges. 
*************************/
void Game::singleCombat() {
	
	promptGameSettings();
	
	int winner = beginTurn(1, true); // 1 for non-random
	std::cout << "Game over!" << std::endl;
	std::cout << std::endl;
	
	if (winner == 1) {
		std::cout << "Player one has won!";
	}
	else if (winner == 2) {
		std::cout << "Player two has won!";
		
	}
	else
		std::cout << "Error, no winner..." << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;
}


/************************
** Name: beginTurn
** Parameters: none
** Description: This function holds the logic to keep running the 
battle between the two previously chosen Creature types until one 
of them has become the winner (the other's strength is below 0.), 
and prints the winner to the screen. 
*************************/
int Game::beginTurn(int random, bool print) {
  bool gameOver = false;
  std::string pressToContinue; // flush input buffer:
  setBattleTurn(1);
  
  // press to continue:
  if (print) {
    std::getline(std::cin, pressToContinue);
  }

  while (!gameOver) {
	// print begin each round:
	if (print) {
		if ( (getCreatureLeft()->getStrengthCurrent() > 0) &&
			 (getCreatureRight()->getStrengthCurrent() > 0) ) {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Turn: ";
        std::cout << getBattleTurn();
        std::cout << std::endl;
        std::cout << "----------------------";
        std::cout << std::endl;
      }
    }

    // CreatureLeft attacks CreatureRight:
    if (!gameOver) {
      if (getCreatureLeft()->getStrengthCurrent() > 0)
        resolveCombat(getCreatureLeft(), getCreatureRight(), 1*random, print);
      else { // CreatureRight has won:
        return 2;
        gameOver = true;
      }
    }

    if (!gameOver) {
    // CreatureRight attacks CreatureLeft:
      if (getCreatureRight()->getStrengthCurrent() > 0)
        resolveCombat(getCreatureRight(), getCreatureLeft(), 2*random, print);
      else {
        return 1;
        gameOver = true;
      }
    }

    incrementBattleTurn();

	// Press to continue:
    if (print) {
      std::cout << "Press enter to continue...";
      std::getline(std::cin, pressToContinue);
    }
  } // end while (!gameOver)
}


/************************
** Name: resolveCombat
** Parameters: Creature* attacker, Creature* defender, int attackingPlayer
** Description: This function is the logic for each time an Creature 
attacks another player, and the defender defends against that attack. It 
was set up to take in an attacker and defender Creature, so that I could 
simply swap them in the beginTurn function to have the defender then become 
the attacker and vise versa. Special moves are checked and used if nessisary. 
Strength values for the defender is updated, and all combat information can 
be printed to the screen via the passed in bool "print". 
*************************/
void Game::resolveCombat(Creature* attacker, Creature* defender, int attackingPlayer, bool print) {

  std::string attackerName;
  std::string defenderName;
  if (attackingPlayer == 1) {
    attackerName = "Player 1 (" + printType(attacker->getType()) + ")";
    defenderName = "Player 2 (" + printType(defender->getType()) + ")";
  }
  if (attackingPlayer == 2) {
    attackerName = "Player 2 (" + printType(attacker->getType()) + ")";
    defenderName = "Player 1 (" + printType(defender->getType()) + ")";
  }

  if (print) {
	  std::cout << std::endl;
	  std::cout << printType(attacker->getType());
	  std::cout << "'s attack phase:" << std::endl;
  }

  if ( (attacker != NULL) && (defender != NULL) ) {
    // check to see if defender is a Vampire, if so run charmed function
    bool charmed = isCharmed(attacker, defender, defenderName, attackerName, attackingPlayer, print);

    // attacker was NOT charmed:
    if (!charmed) {

      // roll attacker:
      int attack = rollAttacker(attacker, attackerName, attackingPlayer, print);
      bool glare = false;
      if (attack == -1) {
         glare = true;
      }

      // Not a Medusa Glare:
      if (!glare) {
        // defender rolls its defense:
        int defense = rollDefender(defender, defenderName, print);

        // Combat is resolved, update strength on defending creature:
        defenderTakeDamage(attack, defense, defender, attackerName, defenderName, print);

      } // end if !MedusaGlare
      else 
        useGlare(defender, defenderName, print); // it WAS Medusa's Glare!

    } // end check if Charmed

      // check to see if defender is a BlueMen:
      // if so, update defense Die number if nessisary:
    runMob(defender, defenderName, print);
  } // end check NULL
}



/************************
** Name: ATTACK/DEFEND/ and SPECIAL ATTACK FUNCTIONS
** Description: These functions are the logic used when two creatures 
 attack each other. They all have an option to print out the 
 results, or simply run the functions without printing to the screen. 
*************************/
bool Game::isCharmed(Creature* attacker, Creature* defender, std::string defenderName, std::string attackerName, int random, bool print) {
	if (defender->getType() == 1) {
	  // run charm function:
	  int rollCharm = defender->rollDefense(random + 1);
	  if (rollCharm > (defender->getSizeDefenseDie()/2)) {
		  
		if (print) {  
			std::cout << defenderName << " has charmed " << attackerName << "!";
			std::cout << std::endl;
			std::cout << "No damage was dealt to " << defenderName;
			std::cout << " this turn!" << std::endl;
		}
		return true;
	  }
	  else
		return false;
	}
	else
		return false;
}

void Game::hogwarts(Creature* defender, std::string defenderName, bool print) {
	
  if ( (defender->getStrengthCurrent() <= 0) && 
	   (defender->getType() == 5) ) {
    if (defender->getUsedHogwarts() == false) {
      defender->setStrengthCurrent(20);
      defender->setUsedHogwarts(true);

      if (print) {
        std::cout << "          ";
        std::cout << defenderName << " used Hogwarts move!" << std::endl;
        std::cout << "          ";
        std::cout << defenderName << " now has " << defender->getStrengthCurrent();
        std::cout << " of " << defender->getStrengthFull() << " strength points!";
        std::cout << std::endl;
      }
    }

  }
}

void Game::useGlare(Creature* defender, std::string defenderName, bool print) {
	defender->setStrengthCurrent(0);
	// HarryPotter still loses:
	if (defender->getType() == 5) {
	  defender->setUsedHogwarts(true);
	}

	if (print) {
		std::cout << defenderName << " was turned to stone! ";
		std::cout << defenderName << " now has " << defender->getStrengthCurrent();
		std::cout << " of " << defender->getStrengthFull() << " strength points!";
		std::cout << std::endl;
	}	
}

void Game::runMob(Creature* defender, std::string defenderName, bool print) {
    if (defender->getType() == 3) {
      int howManyBefore = defender->getNumberDefenseDie();
      int currentStrength = defender->getStrengthCurrent();
      int howManyAfter;
      if (currentStrength > 8)
        howManyAfter = 3;
      else
        howManyAfter = 2;
      if (currentStrength <= 4)
        howManyAfter = 1;

      defender->setNumberDefenseDie(howManyAfter);
      if (howManyAfter < howManyBefore) {
		  if (print) {
			std::cout << "          ";
			std::cout << defenderName << " has decreased in size ";
			std::cout << "and lost defense!" << std::endl;
		  }
      }
    }	
}

int Game::rollDefender(Creature* defender, std::string defenderName, bool print) {
	int defenseRoll = defender->rollDefense(0);
	if (print) {
		std::cout << defenderName << ": rolls a " << defenseRoll;
		std::cout << " for the defense!" << std::endl;
	}
  return defenseRoll;
}

int Game::rollAttacker(Creature* attacker, std::string attackerName, int attackingPlayer, bool print){
	
  // attacker rolls its attack:
  int attack = attacker->rollAttack(attackingPlayer);
  
  if (print) {

    if (attack != -1) {
      std::cout << attackerName << ": rolls a " << attack;
      std::cout << " for the attack!" << std::endl;
    }
    // Medusa special move:
    else {
      std::cout << attackerName << ": rolls a perfect 12";
      std::cout << " for the attack!" << std::endl;
      std::cout << attackerName << "gazes at her opponent...";
      std::cout << std::endl;
    }
  } // end print

  return attack;
}

void Game::defenderTakeDamage(int attackRoll, int defendRoll, Creature* defender, std::string attackerName, std::string defenderName, bool print) {
	
	int strike = (attackRoll - (defendRoll + defender->getArmor()));
	if (strike < 0) {
	  strike = 0;
	  if (print) {
		  std::cout << "--Result--" << std::endl;
		  std::cout << "          ";
		  std::cout << defenderName << " evades the attack!" << std::endl;
		  std::cout << "          ";
		  std::cout << defenderName << " still has " << defender->getStrengthCurrent();
		  std::cout << " of " << defender->getStrengthFull() << " strength points!";
		  std::cout << std::endl;
	  }
	}
	else {
	  defender->setStrengthCurrent(defender->getStrengthCurrent() - strike);

	  if (print) {
		  std::cout << "--Result--" << std::endl;
		  std::cout << "          ";
		  std::cout << attackerName << " hits " << defenderName;
		  std::cout << " for " << strike << " points!" << std::endl;

		  std::cout << "          ";
		  std::cout << defenderName << " now has " << defender->getStrengthCurrent();
		  std::cout << " of " << defender->getStrengthFull() << " strength points!";
		  std::cout << std::endl;
	  }

	  // if defender was of type HarryPotter, check strength and 
	  // use Hogwarts if possible:
	  hogwarts(defender, defenderName, print);

	} // end strike > 0
}




// constructor/destructor -------------------------------------------
Game::Game() {

  assignCreatureLeft(NULL);
  assignCreatureRight(NULL);
  setBattleTurn(1);

  setTeamLeft(NULL);
  setTeamRight(NULL);
  setTeamLeftDefeated(NULL);
  setTeamRightDefeated(NULL);
}

// destructor:
Game::~Game() {
  if (getCreatureLeft() != NULL)
    delete getCreatureLeft();
  if (getCreatureRight() != NULL)
    delete getCreatureRight();
  if (getTeamLeft() != NULL)
    delete getTeamLeft();
  if (getTeamRight() != NULL)
    delete getTeamRight();
  if (getTeamLeftDefeated() != NULL)
    delete getTeamLeftDefeated();
  if (getTeamRightDefeated() != NULL)
    delete getTeamRightDefeated();
}



// Test functions: ----------------------------------------------------
/************************
** Name: testDriver
** Parameters: none
** Description: This function is the first function ran when the user 
wants to run the test driver. It explains how the test works, and begins 
the testing by running the simulations for each test type. In order to ensure 
that all creatures battle all other creature types, (including themselves), I've
used nested for loops to loop through all the types. 
*************************/
void Game::testDriver() {

  std::cout << std::endl;
  std::cout << "*********************** TEST SIMULATOR  ************************";
  std::cout << std::endl;
  std::cout << "A. Each Creature will fight all other types.                   |";
  std::cout << std::endl;
  std::cout << "B. The result of each test will be displayed.                  |";
  std::cout << std::endl;
  std::cout << "C. To save print space, only the results will be displayed.    |";
  std::cout << std::endl;
  std::cout << "---------------------------------------------------------------|";
  std::cout << std::endl;

  int round = 0;
  int winner;
  std::string nameLeft;
  std::string nameRight;
  
  for (int fighterLeft = 1; fighterLeft <= 5; fighterLeft++) {

    std::cout << "Group: " << printType(fighterLeft);
    std::cout << std::endl;

    for (int fighterRight = 1; fighterRight <= 5; fighterRight++) {

      // Fight Description:

      if (fighterLeft == fighterRight) {
        nameLeft = printType(fighterLeft) + " 1";
        nameRight = printType(fighterRight) + " 2";
      }
      else {
        nameLeft = printType(fighterLeft);
        nameRight = printType(fighterRight);
      }

      round++;
      std::cout << round << ". ";
      std::cout << nameLeft << " vs " << nameRight << " : ";

      // Begin fight!
	  
      assignCreatureLeft(allocateCreature(fighterLeft));
      assignCreatureRight(allocateCreature(fighterRight));
	  std::cout << "Beginning fight... ";
	  
      winner = beginTurn(round, false);

      if (winner == 1) {
        std::cout << nameLeft << " has won!" << std::endl;
      }
      else if (winner == 2) {
        std::cout << nameRight << " has won!" << std::endl;
      }

      // cleanup:
      delete getCreatureLeft();
      delete getCreatureRight();
    }

    std::cout << std::endl;
  } // outter forloop

}



// Tournament functions:------------------------------------------------
/************************
** Name: setTournamentSettings
** Parameters: none
** Description: This function is the first function that is called when the 
user selects "Tournament" from the main menu. The user first chooses how many 
fighters will be used on each team, and then each player will take turns 
choosing the fighters for their team. 
*************************/
void Game::setTournamentSettings() {
  std::cout << std::endl;
  std::cout << "|=========================================|" << std::endl;
  std::cout << "|           -~-`NEW TOURNAMENT'-~-        |" << std::endl;
  std::cout << "|=========================================|" << std::endl;
  std::cout << std::endl;

  // allocate Teams:
  setTeamLeft(new Team);
  setTeamRight(new Team);
  setTeamLeftDefeated(new Team);
  setTeamRightDefeated(new Team);

  std::cout << "How many creatures will fight on each team? " << std::endl;
  std::cout << "(You may choose any number between 2 to 12): ";
  int creaturesPerTeam;
  std::cin >> creaturesPerTeam;
  inputValidation(creaturesPerTeam, 2, 12);

  std::cout << creaturesPerTeam << " creatures will be chosen for each team.";
  std::cout << std::endl;

  for (int i = 0; i < creaturesPerTeam; i++) {
    std::cout << "Selecting creature #" << i+1 << " of " << creaturesPerTeam;
    std::cout << "..." << std::endl;

    displayStats();

    std::cout << "Your Selection Player One: ";
    int choiceP1;
    std::cin >> choiceP1;
    inputValidation(choiceP1, 1, 5);

    std::cout << "Your Selection Player Two: ";
    int choiceP2;
    std::cin >> choiceP2;
    inputValidation(choiceP2, 1, 5);

    // add creatures to Team:
    getTeamLeft()->pushNode(allocateCreature(choiceP1));
    getTeamRight()->pushNode(allocateCreature(choiceP2));
  }

  std::cout << "You have finished selecting creatures for each team.";
  std::cout << std::endl;
  std::cout << std::endl;
}


/************************
** Name: beginTournament
** Parameters: none
** Description: After the player has chosen the settings for the Tournament 
(in setTournamentSettings), this function is called and the player will choose 
whether or not to see the results of each round. The fighters battle each other 
using the same logic as the "single battle" and "test driver" options from the 
main menu. To save space, action between monsters are not displayed (which was 
a design choice but could easily be changed via a simple bool argument.)
*************************/
void Game::beginTournament() {
  std::cout << "Would you like to see the results of each round?";
  std::cout << std::endl;
  std::cout << "(Press 1 for yes, or 2 to see only tournament outcome): ";
  int yesNo;
  std::cin >> yesNo;
  inputValidation(yesNo, 1, 2);

  bool displayRounds = true;
  if (yesNo == 2)
    displayRounds = false;

  // Tournament code here:
  std::cout << "|-----------------------------------------------|" << std::endl;
  std::cout << "|                                               |" << std::endl;
  std::cout << "|        [A horn sounds in the distance...]     |" << std::endl;
  std::cout << "|   __                                          |" << std::endl;
  std::cout << "| _(  \\                     /  /                |" << std::endl;
  std::cout << "| \\   0.              _,'| ~ ~  /               |" << std::endl;
  std::cout << "| |    :@=====TTT===::_  | ~ ~  \\               |" << std::endl;
  std::cout << "|  \\   ,/ (_-/-p_)__)) `.|  \\  \\                |" << std::endl;
  std::cout << "| -`     '--/  /                                |" << std::endl;
  std::cout << "|             /                                 |" << std::endl;
  std::cout << "|         _,-'    \"Let the Tournament begin!\"   |" << std::endl;
  std::cout << "|        ;                                      |" << std::endl;
  std::cout << "|-----------------------------------------------|" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Here is the tournament lineup:" << std::endl;

  std::cout << "Team Player 1: ";
  getTeamLeft()->printNodes();
  std::cout << std::endl;

  std::cout << "Team Player 2: ";
  getTeamRight()->printNodes();
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "-------------------------------------" << std::endl;

  int roundWinner;
  int round = 1;

  // keep going until one team does not have any remaining creatures:
  while ( (getTeamLeft()->isEmpty() == false) && 
          (getTeamRight()->isEmpty() == false) ) {

    // pop from holding containers:
    Creature* team1Creature = getTeamLeft()->popNode();
    Creature* team2Creature = getTeamRight()->popNode();

    if ( (team1Creature == NULL) || (team2Creature == NULL) ) {
      std::cout << "ERROR: popped node returned NULL." << std::endl;
      std::cout << "Left isEmpty = " << getTeamLeft()->isEmpty();
      std::cout << std::endl;
      std::cout << "Right isEmpty = " << getTeamRight()->isEmpty();
      std::cout << std::endl;
    }

    // battle round:
    roundWinner = tournamentRound(team1Creature, team2Creature, round);

    // team 1 was victorious:----------------
    if (roundWinner == 1) {
      // store creature2 in defeated container:
      getTeamRightDefeated()->pushNode(team2Creature);
      // store creature1 back in team container:
      getTeamLeft()->pushNode(team1Creature);

      // add score team 1:
      getTeamLeft()->increasePoints(ROUND_POINTS);

      // display result:
      if (displayRounds) {
        std::string name = printType(team1Creature->getType());
        std::cout << "Round " << round << ": ";
        std::cout << "Team 1 (" << name << ") ";
        std::cout << "was victorious!" << std::endl;
      } 
    }

    // team 2 was victorious:----------------
    else if (roundWinner == 2) {
      // store creature1 in defeated container:
      getTeamLeftDefeated()->pushNode(team1Creature);
      // store creature1 back in team container:
      getTeamRight()->pushNode(team2Creature);

      // add score team 2:
      getTeamRight()->increasePoints(ROUND_POINTS);

      // display result:
      if (displayRounds) {
        std::string name = printType(team2Creature->getType());
        std::cout << "Round " << round << ": ";
        std::cout << "Team 2 (" << name << ") ";
        std::cout << "was victorious!" << std::endl;
      } 
    }
    else {
      std::cout << "ERROR: battle did not end successfully.";
      std::cout << std::endl;
    }

    round++;
  }
  std::cout << std::endl;
  std::cout << "|-----------------------------------|" << std::endl;
  std::cout << "|     <~-TOURNAMENT COMPLETE!-~>    |" << std::endl;
  std::cout << "|-----------------------------------|" << std::endl;
  std::cout << "  Results: " << "Player " << roundWinner;
  std::cout << " has won the tournament! Congratulations!";
  std::cout << std::endl; 
  std::cout << std::endl; 

  std::cout << "    Points Player 1: ";
  std::cout << getTeamLeft()->getPoints();
  std::cout << std::endl;

  std::cout << "    Remaining Fighters Player 1: ";
  getTeamLeft()->printNodes();
  std::cout << std::endl;

  std::cout << "    Defeated Fighters Player 1: ";
  getTeamLeftDefeated()->printNodes();
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "    Points Player 2: ";
  std::cout << getTeamRight()->getPoints();
  std::cout << std::endl;

  std::cout << "    Remaining Fighters Player 2: ";
  getTeamRight()->printNodes();
  std::cout << std::endl;

  std::cout << "    Defeated Fighters Player 2: ";
  getTeamRightDefeated()->printNodes();
  std::cout << std::endl;
  std::cout << "-------------------------------------" << std::endl;
  std::cout << std::endl;
}


/************************
** Name: tournamentRound
** Parameters: Creature* team1Creature, Creature* team2Creature, int random
** Description: This function is a slight variation of beginTurn. If I had more 
time, I would work out a few extra parameters to the beginTurn function and use 
it instead. The heal function is used, though not displayed. The winning creature 
is returned by the function, which is then handled by the beginTournament function. 
*************************/
int Game::tournamentRound(Creature* team1Creature, Creature* team2Creature, int random) {
  bool roundOver = false;
  setBattleTurn(1);
  int heal;
  
  while (!roundOver) {
    // team1 attacks team2:
    if (!roundOver) {
      if (team1Creature->getStrengthCurrent() > 0)
        resolveCombat(team1Creature, team2Creature, 1*random, false);
      else { // team2Creature has won:
        heal = team2Creature->healCreature(random);
        return 2;
        roundOver = true;
      }
    }

    if (!roundOver) {
    // team2 attacks team1:
      if (team2Creature->getStrengthCurrent() > 0)
        resolveCombat(team2Creature, team1Creature, 2*random, false);
      else {
        heal = team1Creature->healCreature(random);
        return 1;
        roundOver = true;
      }
    }
    incrementBattleTurn();
  } // end while (!roundOver)
}



