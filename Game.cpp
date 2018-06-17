//
// Created by idanc on 31/05/2018.
//

#include <iostream>
#include <algorithm>
#include "mtm_exceptions.h"
#include "Game.h"

using std::cerr;

//Constructor
Game::Game(int maxPlayers) :
        maxPlayers(maxPlayers),
        //players_array(new Player *[maxPlayers]),
        players_array(),
        num_of_players(0) {}


//Destructor:
Game::~Game() {
    for(Player* it : players_array){
        delete it;
    }
    /*
    for (int i = 0; i < maxPlayers; i++) {
        delete players_array[i];
    }*/
}

//Copy Constractor:
Game::Game(const Game &game) :
        maxPlayers(game.maxPlayers),
        players_array(),
        num_of_players(game.num_of_players) {
    for (int i = 0; i < game.maxPlayers; ++i) {
        if (game.players_array[i] != nullptr) {
            players_array[i] = new Player(*game.players_array[i]);
        }
    }
}

//Assignment Operator:
Game &Game::operator=(const Game &game) {
    if (this == &game) return *this;
    maxPlayers = game.maxPlayers;
    players_array = game.players_array;
    for (int i = 0; i < maxPlayers; ++i) {
        players_array[i] = nullptr;
    }
    num_of_players = game.num_of_players;
    for (int i = 0; i < game.maxPlayers; ++i) {
        if (game.players_array[i] != nullptr) {
            players_array[i] = new Player(*game.players_array[i]);
        }
    }
    return *this;
}

//Methods:
GameStatus Game::addPlayer(string const &playerName, string const &weaponName,
                           Target target, int hit_strength) {
    try {
        addWarrior(playerName, weaponName, target, hit_strength, false);
    }
    catch (mtm::NameAlreadyExists &a) {
        return NAME_ALREADY_EXISTS;
    }
    catch (mtm::GameFull &a) {
        return GAME_FULL;
    }
    catch (mtm::IllegalWeapon &a) {
        return ILLEGAL_WEAPON;
    }
    return SUCCESS;
}

void Game::addWarrior(string const &playerName, string const &weaponName,
                      Target target, int hitStrength, bool rider) {
    for(Player* it : players_array){
        if(it->isPlayer(playerName)){
            throw mtm::NameAlreadyExists();
        }
    }
    /*for (int i = 0; i < num_of_players; ++i) {
        if (players_array[i]->isPlayer(playerName)) {
            throw mtm::NameAlreadyExists();
        }
    }*/
    if (num_of_players >= maxPlayers) {
        throw mtm::GameFull();
    }
    Weapon new_weapon(weaponName, target, hitStrength);
    players_array.push_back(new Warrior(playerName, new_weapon, rider));
    num_of_players++;
}

void Game::addWizard(string const &playerName, string const &weaponName,
                     Target target,
                     int hitStrength, int range) {
    for (int i = 0; i < num_of_players; ++i) {
        if (players_array[i]->isPlayer(playerName)) {
            throw mtm::NameAlreadyExists();
        }
    }
    if (num_of_players >= maxPlayers) {
        throw mtm::GameFull();
    }
    Weapon new_weapon(weaponName, target, hitStrength);
    players_array.push_back(new Wizard(playerName, new_weapon, range));
    num_of_players++;
}

void Game::addTroll(string const &playerName, string const &weaponName,
                    Target target, int hitStrength, int maxLife) {
    for (int i = 0; i < num_of_players; ++i) {
        if (players_array[i]->isPlayer(playerName)) {
            throw mtm::NameAlreadyExists();
        }
    }
    if (num_of_players >= maxPlayers) {
        throw mtm::GameFull();
    }
    Weapon new_weapon(weaponName, target, hitStrength);
    players_array.push_back(new Troll(playerName, new_weapon, maxLife));
    num_of_players++;

}

GameStatus Game::nextLevel(string const &playerName) {
    for (int i = 0; i < num_of_players; ++i) {
        if (players_array[i]->isPlayer(playerName)) {
            players_array[i]->nextLevel();
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}

GameStatus Game::makeStep(string const &playerName) {
    for (int i = 0; i < num_of_players; ++i) {
        if (players_array[i]->isPlayer(playerName)) {
            players_array[i]->makeStep();
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}

GameStatus Game::addLife(string const &playerName) {
    for (int i = 0; i < num_of_players; ++i) {
        if (players_array[i]->isPlayer(playerName)) {
            players_array[i]->addLife();
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}

GameStatus Game::addStrength(string const &playerName, int strengthToAdd) {
    if (strengthToAdd < 0) {
        return INVALID_PARAM;
    }
    for (int i = 0; i < num_of_players; ++i) {
        if (players_array[i]->isPlayer(playerName)) {
            players_array[i]->addStrength(strengthToAdd);
            return SUCCESS;
        }
    }
    return NAME_DOES_NOT_EXIST;
}


bool Game::removeAllPlayersWithWeakWeapon(int weaponStrength) {
    bool players_removed = false;
    for (int i = 0; i < num_of_players; ++i) {
        if (players_array[i]->weaponIsWeak(weaponStrength)) {
            players_array.erase(players_array.begin() + i);
            num_of_players--;
            i--;
            players_removed = true;
        }
    }
    return players_removed;
}

GameStatus Game::fight(string const &playerName1, string const &playerName2) {
    Player *ptr_a = nullptr;
    Player *ptr_b = nullptr;
    int i_a = 0, i_b = 0;
    for ( i_a = 0; i_a < num_of_players; ++i_a) {
        if (players_array[i_a]->isPlayer(playerName1)) {
            ptr_a = players_array[i_a];
            break;
        }
    }
    for ( i_b = 0; i_b < num_of_players; ++i_b) {
        if (players_array[i_b]->isPlayer(playerName2)) {
            ptr_b = players_array[i_b];
            break;
        }
    }
    if (ptr_a == nullptr || ptr_b == nullptr)
        return NAME_DOES_NOT_EXIST;
    if (!(ptr_a->fight(*ptr_b))) return FIGHT_FAILED;
    if (!ptr_a->isAlive()) {
        players_array.erase(players_array.begin() + i_a);
        num_of_players--;
        return SUCCESS;
    }
    if (!ptr_b->isAlive()) {
        players_array.erase(players_array.begin() + i_b);
        num_of_players--;
    }
    return SUCCESS;
}

/*
void Game::swapPlayer(Player &player1, Player &player2) {
    Player temp = player1;
    player1 = player2;
    player2 = temp;
}

int Game::indexOfMin(Player **players, int num) {
    int i, i_min = 0;
    for (i = 1; i < num; ++i) {
        if (players[i]->getName() > players[i_min]->getName()) {
            i_min = i;
        }
    }
    return i_min;
}

void Game::maxSort(Player **players, int currPlayers) {
    for (int len = currPlayers; len > 1; len--) {
        int i_min = indexOfMin(players, len);
        swapPlayer(*players[len - 1], *players[i_min]);
    }
}*/

//Print Operator:
std::ostream &operator<<(std::ostream &os, const Game &game) {
    using std::endl;
    std::sort(*game.players_array.begin(), //TODO: need to check if work
              *game.players_array.begin() + game.num_of_players);
    for (int i = 0; i < game.num_of_players; ++i) {
        os << "player " << i << ": " << *game.players_array[i] << endl;
    }
    return os;
}
