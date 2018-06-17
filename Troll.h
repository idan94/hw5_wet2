//
// Created by idanc on 17/06/2018.
//

#ifndef HW5_WET2_TROLL_H
#define HW5_WET2_TROLL_H

#include "Player.h"
class Troll : public Player {
    int max_life;
public:
//Constructor
    Troll(string const &name, Weapon const &weapon, int maxLife);

//Destructor
    ~Troll() override = default;

//Copy Constructor:
    Troll(const Troll &warrior) = default;

//Assignment Operator:
    Troll &operator=(const Troll &warrior)= default;

//Methods:
    void makeStep() override;
    void addLife() override ;
};


#endif //HW5_WET2_TROLL_H
