#include "archer.h"
#include <iostream>
#include <string>
#include "Soldier.h"

Archer::Archer(string _name, string _race, int _level, int _health): Character(_name, _race, _level, _health){
}

string Archer::getType(){
    return "Archer";
}

void Archer::arrows(){
    cout <<"ARROW : ATTACK POWER"<<endl;
    cout << "Bronze arrow : 10" << endl;
    cout << "Silver arrow : 10" << endl;
    cout << "Steel arrow : 10" << endl;
    cout << "Gold arrow : 10" << endl;
    cout << "Diamond arrow : 10" << endl;
}

void Archer::changeArrows(string newArrow){
    if (newArrow == "Bronze") {arrowDamage=10;arrowCost=5;}
    else if (newArrow == "Silver") {arrowDamage=15;arrowCost=8;} 
    else if (newArrow == "Steel") {arrowDamage=20;arrowCost=11;}
    else if (newArrow == "Gold") {arrowDamage=25;arrowCost=14;}
    else if (newArrow == "Diamond") {arrowDamage=30;arrowCost=17;}
}

void Archer::rest(){
    energy += 10;
}

/*
void Archer::attack(Archer player1, Archer &player2){
    int _attack = player1.getAttack();
    int _health = player2.getHealth();
    _health -= _attack;
    player2.setHealth(_health);
}
void Archer::attack(Archer player1, Soldier &player2){
    int _attack = player1.getAttack();
    int _health = player2.getHealth();
    _health -= _attack;
    player2.setHealth(_health);
}
*/

int Archer::getAttack(){
    return arrowDamage;
}

int Archer::getHealth(){
    return health;
}

void Archer::attack(){
}