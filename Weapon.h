//
// Created by idanc on 31/05/2018.
//

#ifndef HW4_MTM_WEAPON_H
#define HW4_MTM_WEAPON_H

#include <ostream>
#include <cstring>

using std::string;

enum Target {
    LEVEL,
    STRENGTH,
    LIFE
};

class Weapon {
    string name;
    Target target;
    int hitStrength;

public:
    //Constructor:
    Weapon(string const& name, Target target, int hit_strength);

    Weapon();

    //Destructor:
    ~Weapon() = default;

    //Copy Constructor:
    Weapon(const Weapon &weapon) = default;

    //Assignment Operator:
    Weapon &operator=(const Weapon &weapon)= default;
    //Getters:
    /**
     * get the target of the weapon
     * @return the target
     */
    Target getTarget() const;

    /**
     * get the hit strength of the weapon
     * @return the hit strength
     */
    int getHitStrength() const;

    /**
     * calculate the value of the weapon by formula
     * @return the value(int)
     */
    int getValue() const;

    //Comparison operators: compare by value(from getValue formula)
    friend bool operator==(Weapon weapon_a, Weapon weapon_b);

    friend bool operator!=(Weapon weapon_a, Weapon weapon_b);

    bool operator>(Weapon weapon);

    bool operator<(Weapon weapon);

    //Print Operator:
    friend std::ostream &operator<<(std::ostream &os, const Weapon &weapon);
};


#endif //HW4_MTM_WEAPON_H
