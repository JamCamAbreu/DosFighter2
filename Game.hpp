/********************************************************************************
 * Author: James Cameron Abreu
 * Date: 11/03/2016
 * Description: The Game class has many features. It prompts the user for game 
 *  settings, begins the game, runs each turn, calculates combat results, and 
 *  determines game winning conditions.
 * *****************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

// used for prompts:
#include <iostream>
#include <string>

#include "inputValidation.hpp"
#include "enumCreatureType.hpp"
#include "Creature.hpp"
#include "creatureTypes.hpp"
#include "Team.hpp"

const int ROUND_POINTS = 3;

class Game {

  private:
    Creature* CreatureLeft;
    Creature* CreatureRight;
    int battleTurn;
    Team* teamLeft;
    Team* teamRight;
    Team* teamLeftDefeated;
    Team* teamRightDefeated;

  public: 

    // get functions:
    Creature* getCreatureLeft();
    Creature* getCreatureRight();
    int getBattleTurn();
    Team* getTeamLeft();
    Team* getTeamRight();
    Team* getTeamLeftDefeated();
    Team* getTeamRightDefeated();


    // set functions:
    void assignCreatureLeft(Creature* newCreature);
    void assignCreatureRight(Creature* newCreature);
    void setBattleTurn(int newBattleTurn);
    void setTeamLeft(Team* newTeam);
    void setTeamRight(Team* newTeam);
    void setTeamLeftDefeated(Team* newTeam);
    void setTeamRightDefeated(Team* newTeam);
    
    // increment functions:
    void incrementBattleTurn();

    // other functions:
    void displayStats();
    void promptGameSettings();
	void singleCombat();
    int beginTurn(int random, bool print);
    void resolveCombat(Creature* attacker, Creature* defender, int attackingPlayer, bool print);

    std::string printType(int type);
    Creature* allocateCreature(int type);
    
    // attack/defend and special moves functions:
    void hogwarts(Creature* defender, std::string defenderName, bool print);
    bool isCharmed(Creature* attacker, Creature* defender, std::string defenderName, std::string attackerName, int random, bool print);
    void useGlare(Creature* defender, std::string defenderName, bool print);
    void runMob(Creature* defender, std::string defenderName, bool print);

    int rollDefender(Creature* defender, std::string defenderName, bool print);
    int rollAttacker(Creature* attacker, std::string attackerName, int attackingPlayer, bool print);
    void defenderTakeDamage(int attackRoll, int defendRoll, Creature* defender, std::string attackerName, std::string defenderName, bool print);

    // Tournament functions:
    void setTournamentSettings();
    void beginTournament();
    int tournamentRound(Creature* team1Creature, Creature* team2Creature, int random);


    // constructor/destructor:
    Game();
    ~Game();

    // Test functions:
    void testDriver();
};

#endif
