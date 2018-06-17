//
// Created by Etai Ohana on 6/17/2018.
//

#ifndef HW5_WET2_WIZARD_H
#define HW5_WET2_WIZARD_H

#include "Player.h"


class Wizard  : public Player{
    int range;
public:
//Constructor
    Wizard(string const &name, Weapon const &weapon, int range);
//Destructor
    ~Wizard() override = default;
//Copy Constructor:
    Wizard(const Wizard &wizard) = default;

//Assignment Operator:
    Wizard &operator=(const Wizard &wizard)= default;

//Methods:
    bool checkIfCanAttack(Player &enemy) override ;







};


#endif //HW5_WET2_WIZARD_H
