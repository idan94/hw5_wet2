//
// Created by idanc on 31/05/2018.
//
#include <cstring>
#include "Weapon.h"


//Constructors:
Weapon::Weapon(string const& name, Target target, int hit_strength) :
        name(name),
        target(target),
        hitStrength(hit_strength) {}
/*
Weapon::Weapon():
    name(nullptr),
    target(Target(0)),
    hitStrength(0){}

//Destructor:
Weapon::~Weapon(){
    delete []name;
}
//Copy Constructor:
Weapon::Weapon(const Weapon& weapon) :
    name(new char[strlen(weapon.name)+1]),
    target(weapon.target),
    hitStrength(weapon.hitStrength)
{
    strcpy(name,weapon.name);
}

//Assignment Operator:
Weapon& Weapon::operator=(const Weapon& weapon){
    if(this == &weapon) return *this;
    delete []name;
    name=new char[strlen(weapon.name)+1];
    strcpy(name,weapon.name);
    target=weapon.target;
    hitStrength=weapon.hitStrength;
    return *this;
}

*/
//Getters:
Target Weapon::getTarget() const {
    return target; //return this->target
}

int Weapon::getHitStrength() const {
    return hitStrength; //return this->hitStrength
}

int Weapon::getValue() const {
    int target = getTarget();
    int hit_strength = getHitStrength();
    return (target + 1) * hit_strength;
}

//Comparesion operators:
bool Weapon::operator>(Weapon weapon) {
    return (getValue() > weapon.getValue());
}

bool Weapon::operator<(Weapon weapon) {
    return (getValue() < weapon.getValue());
}

bool operator==(Weapon weapon_a, Weapon weapon_b) {
    return (weapon_a.getValue() == weapon_b.getValue());
}

bool operator!=(Weapon weapon_a, Weapon weapon_b) {
    return (weapon_a.getValue() != weapon_b.getValue());
}

//Print Operator:
std::ostream &operator<<(std::ostream &os, const Weapon &weapon) {
    os << "{weapon name: " << weapon.name << ", weapon value:"
       << weapon.getValue() << "}";
    return os;
}