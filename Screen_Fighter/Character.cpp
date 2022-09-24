#include "Character.h"
#include <iostream>
#include <string>

Character::Character(string _name, string _race, int _level, int _health){
    name = _name;
    race = _race;
    level = _level;
    health = _health;
}

Character::Character(){
    name = "IDK";
    race = "IDK";
    level = 1;
    health = 100;
}
void Character::setHealth(int _health){
    health = _health;
}
int Character::getHealth() const{
    return health;
}
void Character::attack() const{
}
void Character::rest() const{
}
int Character::getAttack() const{
    return 10;
}
void Character::setName(string _name){
    name = _name;
}
string Character::getName(){
    return name;
}
void Character::setRace(string _race){
    race = _race;
}
string Character::getRace(){
    return race;
}
void Character::setLevel(int _level){
    level = _level;
}
int Character::getLevel(){
    return level;
}


void Character::PrintInfo(){
    cout << "Name: " << name << endl;
    cout << "Race: " << race << endl;
    cout << "Level: " << level << endl;
    cout << "Health: " << health << endl;
}

