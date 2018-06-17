//
// Created by idanc on 17/06/2018.
//
#include "mtm_exceptions.h"
#include "Warrior.h"
#define RIDER_STEP 5
//Constructor
Warrior::Warrior(string const &name, Weapon const &weapon, bool rider):
    Player(name,weapon),
    rider(rider) {
    if (weapon.getTarget()==LEVEL) {
        throw mtm::IllegalWeapon();
    }
}
void Warrior::makeStep() {
    if(rider){
        player_location+=RIDER_STEP;
    } else{
        player_location++;
    }
}

