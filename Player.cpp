//
// Created by idanc on 31/05/2018.
//

#include "Player.h"

static void changeNegativeToZero(int &num) {
    if (num < 0) {
        num = 0;
    }
}

//Constractor
Player::Player(string const &name, const Weapon &weapon) :
        name(name),
        level(1),
        life(1),
        strength(1),
        weapon(weapon),
        player_location(0) {}

Player::Player() :
        name(),
        level(1),
        life(1),
        strength(1),
        weapon(),
        player_location(0) {}


/*
//Destructor:
Player::~Player(){
    delete []name;
}
//Copy Constructor:
Player::Player(const Player& player):
    name(new char[strlen(player.name)+1]),
    level(player.level),
    life(player.life),
    strength(player.strength),
    weapon(player.weapon),
    player_location(player.player_location)
    {
        strcpy(name,player.name);
    }
//Assignment Operator:
Player& Player::operator=(const Player& player) {
    if (this == &player) {
        return (*this);
    }
    delete []name;
    name = new char[strlen(player.name) + 1];
    strcpy(name,player.name);
    level=player.level;
    life=player.life;
    strength=player.strength;
    weapon=player.weapon;
    player_location=player.player_location;
    return *this;
}
 */
void Player::nextLevel() {
    level++;
}

bool Player::isPlayer(string const &playerName) const {
    return (playerName == name);
}

void Player::makeStep() {
    player_location++;
}

void Player::addLife() {
    life++;
}

void Player::addStrength(int strengthToAdd) {
    strength += strengthToAdd;
}

string const &Player::getName() {
    return name;
}


int Player::getLocation() {
    return player_location;
}

bool Player::isAlive() const {
    return (level > 0 && life > 0 && strength > 0);
}

bool Player::weaponIsWeak(int weaponMinStrength) const {
    return (weapon.getValue() < weaponMinStrength);
}

bool Player::fight(Player &player) {
    /*if (player.player_location != player_location
        || player.weapon == weapon)
        return false;*/
    int who_attacks = 0;
    //0- no one can attack. 1- this attack player.   2- player attack this
    if (this->checkIfCanAttack(player) && !player.checkIfCanAttack(*this)) {
        //if this can attack player, and player can't attack this
        who_attacks = 1;
    }
    if (player.checkIfCanAttack(*this) && !this->checkIfCanAttack(player)) {
        //if player can attack this, and this can't attack player
        who_attacks = 2;
    }
    if (this->checkIfCanAttack(player) && player.checkIfCanAttack(*this)) {
        //if both players can attack, we will check value
        if (player.weapon > weapon) {
            who_attacks = 2;
        }
        if (weapon > player.weapon) {
            who_attacks = 1;
        }
    }
    if (who_attacks == 0) return false;
    if (who_attacks == 2) {
        switch (player.weapon.getTarget()) {
            case (LEVEL): {
                level -= player.weapon.getHitStrength();
                break;
            }
            case (STRENGTH): {
                strength -= player.weapon.getHitStrength();
                break;
            }
            case (LIFE): {
                life -= player.weapon.getHitStrength();
                break;
            }
        }
    } else {
        switch (weapon.getTarget()) {
            case (LEVEL): {
                player.level -= weapon.getHitStrength();
                break;
            }
            case (STRENGTH): {
                player.strength -= weapon.getHitStrength();
                break;
            }
            case (LIFE): {
                player.life -= weapon.getHitStrength();
                break;
            }
        }
    }
    changeNegativeToZero(level);
    changeNegativeToZero(strength);
    changeNegativeToZero(life);
    return true;
}

bool Player::checkIfCanAttack(Player &enemy) {
    return (player_location == enemy.player_location);
}

//Comparesion operators:
bool Player::operator>(Player player) {
    return this->name > player.name;
}

bool Player::operator<(Player player) {
    return this->name < player.name;
}

bool operator==(Player player_a, Player player_b) {
    return player_a.name == player_b.name;
}

//Print Operator:
std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "{player name: " << player.name << ", weapon: " << player.weapon
       << "},";
    return os;
}
