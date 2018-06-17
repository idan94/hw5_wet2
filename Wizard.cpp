//
// Created by Etai Ohana on 6/17/2018.
//

#include "Wizard.h"
#include "mtm_exceptions.h"


//Constructor
Wizard::Wizard(string const &name, Weapon const &weapon, int range):
        Player(name,weapon),
        range(range) {
    if (weapon.getTarget()==LIFE) {
        throw mtm::IllegalWeapon();
    }
}
bool Wizard::checkIfCanAttack(Player &enemy){
    if(player_location==enemy.getLocation()) return false;
    int distance=(player_location-enemy.getLocation());
    if(distance<0) {  //we want absolute distance
        distance= -(distance);
    }
    return distance<=range;
}