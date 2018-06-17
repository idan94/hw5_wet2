//
// Created by idanc on 31/05/2018.
//

#ifndef HW4_MTM_PLAYER_H
#define HW4_MTM_PLAYER_H

#include <ostream>
#include "Weapon.h"

class Player {
    string name;
    int level;
protected:    int life; //TODO: Moodle question
private:
    int strength;
    Weapon weapon;
protected:
    int player_location;
    // methods:
    /**
     *  calculate the distance between the player and another player(the enemy)
     * @param enemy - the player we check our player's distance from
     * @return - the distance (integer value).
     */
    static int findDistance(const Player& enemy);
public:

    //Constructors
    Player(string const& name, const Weapon &weapon);

    //Destructor:
      virtual ~Player() = default;

    //Copy Constructor:
    Player(const Player &player) = default;

    //Assignment Operator:
    Player &operator=(const Player &player)= default;
    //Methods:
    /**
     * upgrade the player to the next level( level++)
     */
    void nextLevel();

    /**
     * check if the player exist
     * @param playerName the player name
     * @return true if he is
     * false if not
     */
    bool isPlayer(string const& playerName) const;

    /**
     * make one step, (player_location++)
     */
    virtual void makeStep();

    /**
     * add one life to the player (life++)
     */
    virtual void addLife();

    /**
     * add number to player strength
     * @param strengthToAdd the num we want to add
     */
    void addStrength(int strengthToAdd);

    /**
     * check if player is alive
     * @return true if he is
     * false if not
     */
    bool isAlive() const;

    /**
     * give back the name of a player
     * @return the name(string)
     */
    string const& getName();

    /**
     * check if weapon is weaker then number given(check with getValue())
     * @param weaponMinStrength the number we compare with
     * @return bool if he is
     * false if not
     */
    bool weaponIsWeak(int weaponMinStrength) const;

    /**
     * fight player with other player.
     * update the life/strength/life of the loser player
     * @param player the player we want to fight with
     * @return true fight happand
     * false if not(because player location different or weapon value same)
     */
    bool fight(Player &player);

    //Comparison operators: by names(lexicography)
    bool operator<(Player player);

    bool operator>(Player player);

    friend bool operator==(Player player_a, Player player_b);

    //Print Operator:
    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    virtual bool checkIfCanAttack(Player &enemy);
    virtual bool checkIfCanAttack(int enemy_location);

};

#endif //HW4_MTM_PLAYER_H
