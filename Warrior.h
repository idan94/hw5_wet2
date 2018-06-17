//
// Created by idanc on 17/06/2018.
//

#ifndef HW5_WET2_WARRIOR_H
#define HW5_WET2_WARRIOR_H

#include "Player.h"

class Warrior : public Player {
    bool rider;
public:
//Constructor
    Warrior(string const &name, Weapon const &weapon, bool rider);

//Destructor
    ~Warrior() override = default;

//Copy Constructor:
    Warrior(const Warrior &warrior) = default;

//Assignment Operator:
    Warrior &operator=(const Warrior &warrior)= default;

//Methods:
    void makeStep() override;
};


#endif //HW5_WET2_WARRIOR_H
