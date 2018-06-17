//
// Created by Etai Ohana on 6/17/2018.
//

#include "Wizard.h"


//Constructor
Warrior::Warrior(string const &name, Weapon const &weapon, bool rider):
        Player(name,weapon),
        rider(rider) {
    if (weapon.getTarget()==LEVEL) {
        throw mtm::IllegalWeapon();
    }
}