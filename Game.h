//
// Created by idanc on 31/05/2018.
//

#ifndef HW4_MTM_GAME_H
#define HW4_MTM_GAME_H

#include <ostream>
#include <vector>
#include "Player.h"
#include "Weapon.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Troll.h"


enum GameStatus {
    INVALID_PARAM,
    NAME_ALREADY_EXISTS,
    GAME_FULL,
    NAME_DOES_NOT_EXIST,
    FIGHT_FAILED,
    SUCCESS,
    ILLEGAL_WEAPON
};

class Game {
    int maxPlayers;
    std::vector <Player* > players_array;
    //Player **players_array;
    int num_of_players;
public:
    //Constractor:
    explicit Game(int maxPlayers);

    //Destructor:
    ~Game();

    //Copy Constractor:
    Game(const Game &game);

    //Assignment Operator:
    Game &operator=(const Game &game);
    //Methods:
    /**
     * Add new player to the game.
     * @param playerName the player name
     * @param weaponName the weapon name
     * @param target the target of the weapon
     * @param hit_strength the hit strength of the weapon
     * @return SUCCESS- if the player added
     * NAME_ALREADY_EXISTS- if the name of the player is already exist
     * GAME_FULL- if the game is full
     */
    GameStatus
    addPlayer(string const &playerName, string const &weaponName, Target target,
              int hit_strength);

    void addWarrior(string const &playerName, string const &weaponName,
                    Target target, int hitStrength, bool rider);

    void
    addWizard(string const &playerName, string const &weaponName, Target target,
              int hitStrength, int range);

    void addTroll(string const &playerName, string const &weaponName,
                  Target target, int hitStrength, int maxLife);

    /**
     * get a player name, and upgrade him to the next level
     * @param playerName the player name
     * @return SUCCESS- if level upgraded
     * NAME_DOES_NOT_EXIST- if the player isn't exist
     */
    GameStatus nextLevel(string const &playerName);

    /**
     * get a player name, and move him one step
     * @param playerName the player name
     * @return SUCCESS- if player moved
     * NAME_DOES_NOT_EXIST- if the player isn't exist
     */
    GameStatus makeStep(string const &playerName);

    /**
     * get a player name, and add him one life
     * @param playerName the player name
     * @return SUCCESS- if life added
     * NAME_DOES_NOT_EXIST- if the player isn't exist
     */
    GameStatus addLife(string const &playerName);

    /**
     * get a player name, and upgrade his strength
     * @param playerName the player name
     * @param strengthToAdd how much strength to add
     * @return SUCCESS- strength added
     * NAME_DOES_NOT_EXIST- if the player isn't exist
     * INVALID_PARAM- if 'strengthToAdd' is negative
     */
    GameStatus addStrength(string const &playerName, int strengthToAdd);

    /**
     *gets a number, and remove all the players that have weapon that is
     * weaker then the number
     * @param weaponStrength the number we compare with
     * @return true- if players has been removed
     * false- if not
     */
    bool removeAllPlayersWithWeakWeapon(int weaponStrength);

    /**
     * gets 2 players, and make then fight, if one of them die- delete him
     * @param playerName1 the first player name
     * @param playerName2 the second player name
     * @return
     * NAME_DOES_NOT_EXIST- if the player isn't exist
     * FIGHT_FAILED- if fight failed
     * SUCCESS- if fight happened
     */
    GameStatus fight(string const &playerName1, string const &playerName2);

    //Print Operator:
    friend std::ostream &operator<<(std::ostream &os, const Game &game);

private:
    //swap between 2 players
    static void swapPlayer(Player &player1, Player &player2);

    //find the index of the min player(lexicography)
    static int indexOfMin(Player **players, int num);

    //sort a given array of pointers to players
    static void maxSort(Player **players, int currPlayers);


};


#endif //HW4_MTM_GAME_H
