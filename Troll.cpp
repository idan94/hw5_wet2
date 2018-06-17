//
// Created by idanc on 17/06/2018.
//

#include "Troll.h"
#include "mtm_exceptions.h"


//Constructor
Troll::Troll(string const &name, Weapon const &weapon, int maxLife) :
        Player(name,weapon),
        max_life(maxLife) {
    if (maxLife <= 0) {
        throw mtm::InvalidParam();
    }
}
//Methods:

void Troll::makeStep(){
    player_location++;
    addLife();
}
void Troll::addLife() {
    if(life<max_life) {
        life++;
    }
}