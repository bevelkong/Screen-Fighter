#ifndef SOLDIER_H
#define SOLDIER_H
#include "Character.h"
#include "archer.h"
#include <iostream>
#include <string>

class Soldier : public Character{
    private:
        string currWeapon;
        int weaponCost;
        int weaponAtk;
        int stamina;
    public:
        Soldier(string , string , int ,int );
        void equipWeapon(string);
        void rest();
        void weapons();
        void changeWeapon(string);
   //     void attack(Soldier player1, Soldier &player2);
     //   void attack(Soldier player1, Archer &player2);
        int getAttack();
        int getHealth();
        void attack();
        string getType();
};

#endif