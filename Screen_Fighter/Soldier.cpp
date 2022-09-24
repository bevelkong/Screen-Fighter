#include "Soldier.h"
#include <iostream>
#include <string>
#include "archer.h"

Soldier::Soldier(string _name, string _race, int _level, int _health): Character(_name, _race, _level, _health){
}

string Soldier::getType(){
    return "Soldier";
}
void Soldier::equipWeapon(string _weapon){
    currWeapon = _weapon;
}
void Soldier::rest(){
    stamina += 10;
}
void Soldier::weapons(){
    cout <<"WEAPON MATERIAL : ATTACK POWER"<<endl<<"PICK A WEAPON"<<endl;
    cout << "Bronze Sword : 10" << endl;
    cout << "Silver Sword : 10" << endl;
    cout << "Steel Sword : 10" << endl;
    cout << "Gold Sword : 10" << endl;
    cout << "Diamond Sword : 10" << endl;
}
void Soldier::changeWeapon(string _weapon){
    if (_weapon == "Bronze") {weaponAtk=10;weaponCost=5;}
    else if (_weapon == "Silver") {weaponAtk=15;weaponCost=8;} 
    else if (_weapon == "Steel") {weaponAtk=20;weaponCost=11;}
    else if (_weapon == "Gold") {weaponAtk=25;weaponCost=14;}
    else if (_weapon == "Diamond") {weaponAtk=30;weaponCost=17;}
}

/*
void Soldier::attack(Soldier player1, Soldier &player2){
    int _attack = player1.getAttack();
    int _health = player2.getHealth();
    _health -= _attack;
    player2.setHealth(_health);
}
void Soldier::attack(Soldier player1, Archer &player2){
    int _attack = player1.getAttack();
    int _health = player2.getHealth();
    _health -= _attack;
    player2.setHealth(_health);
}
*/

int Soldier::getAttack(){
    return weaponAtk;
}

int Soldier::getHealth(){
    return health;
}
void Soldier::attack(){
}