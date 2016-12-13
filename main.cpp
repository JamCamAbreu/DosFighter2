/************************************************************
 * Author: James Cameron Abreu
 * Date: 10/27/2016
 * Description: The main function serves as the top layer to 
 *  this multi-file program. For more information, read the 
 *  program overview and instructions located in the switch 
 *  case number 2 below.
 * *********************************************************/

#include <iostream>
#include <string>

#include "menuSelect.hpp"
#include "Game.hpp"

int main() {

  std::cout << std::endl;
  std::cout << "                         -----------------   " << std::endl;
  std::cout << "                          |     Dos     |    " << std::endl;
  std::cout << "  Welcome to...           |   Fighter   |    " << std::endl;
  std::cout << "                 _       .|_____2.0_____|.     " << std::endl;
  std::cout << "     ___        //       *-^-^-^-^-^-^-^-*     " << std::endl;
  std::cout << "    /   \\      //               |,|           " << std::endl;
  std::cout << "   :   ==\\  <\\//                | |            " << std::endl;
  std::cout << "    \\____/_-'_}>                | |           " << std::endl;
  std::cout << "    / '-`\\ .//`'                |'|           " << std::endl;
  std::cout << "   :__<_  :/\"          by       | |          " << std::endl;
  std::cout << "   /    \\ |               James Cam           " << std::endl;
  std::cout << "--{      }[-----------------Abreu |----------" << std::endl;
  std::cout << " '\"\\ \\/ /|    .',               | |            " << std::endl;
  std::cout << "    `\\/'\\`.   ,|                | |  .',       " << std::endl;
  std::cout << "    !___]_]         ,.          | |   |.   " << std::endl;
  std::cout << "                          '\"    [_]          " << std::endl;

  std::string mainMenu[7];
  mainMenu[1] = "Begin Tournament";
  mainMenu[2] = "Single Battle (assignment 3)";
  mainMenu[3] = "Test Simulator (assignment 3)";
  mainMenu[4] = "Overview and Instructions";
  mainMenu[5] = "About Author";
  mainMenu[6] = "Exit Program";

  int choice;
  do {

    choice = menuSelect(mainMenu, 6);

    switch (choice) {

      case 1: {

        Game* newGame = new Game;

        // flush input buffer:
        std::string flush;
        std::getline(std::cin, flush);

		    // RUN TOURNAMENT HERE!
        newGame->setTournamentSettings();
        newGame->beginTournament();

        // Game finished:
        delete newGame;
        break;
      }
	  
	  // SINGLE BATTLE--------------------------
      case 2: {

        Game* newGame = new Game;

        // flush input buffer:
        std::string flush;
        std::getline(std::cin, flush);

        newGame->singleCombat();

        // Game finished:
        delete newGame;
        break;
      }

      case 3: {
        Game* newGame = new Game;
        newGame->testDriver();
        delete newGame;
        break; }
		
      case 4:
        {
        std::cout << std::endl;
        std::cout << "Game Overview: " << std::endl;
        std::cout << "DosFighter is a cute command-line style 2D fighter simulator that pits ";
        std::cout << "a unique set of characters against each other. Characters have 4 primary ";
        std::cout << "stats that are different for each character type: Attack, Defense, Armor, ";
        std::cout << "and Strength. Attack and Defense are rolls of dice, armor is used to reduce ";
        std::cout << "the effectiveness of attacks, and Strength is how much health a character has";
        std::cout << "before they lose the battle. There are a few special moves unique to each ";
        std::cout << "character. The game is over when one character's strength is reduced to 0.";
        std::cout << std::endl;

        std::cout << std::endl;
        std::cout << "How to Play:" << std::endl;
        std::cout << "After choosing \"New Game\" from the main menu, you will be prompted to select ";
        std::cout << "what kind of character each person will play (there are two players in each game.) ";
        std::cout << "Once you have selected the character types, the game will begin and the characters ";
        std::cout << "will attack each other until one's strength has been reduced to 0.";
        std::cout << std::endl;
        break;
        }
		
      case 5:
        {
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "About Author:" << std::endl;
        std::cout << "James 'Cam' Abreu is currently a computer science major at Oregon State University.";
        std::cout << "He enjoys his programming assignments, but also fancies game programming at a higher ";
        std::cout << "level using programs such as GameMaker or whatever else he can find. He also previously ";
        std::cout << "earned a bachelor's degree in music education and spent a few years in the Seattle area ";
        std::cout << "as a public band teacher" << std::endl;
        std::cout << std::endl;
        break;
        }

      case 6: 
        break;

      default:
        break;
    } // end switch

  } while (choice != 6);


  std::cout << std::endl;
  std::cout << "Thank you for using James Cam Abreu's 'DosFighter 2.0'!" << std::endl;
  std::cout << std::endl;

  return 0;
}


