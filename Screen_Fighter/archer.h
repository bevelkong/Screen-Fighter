#ifndef ARCHER_H
#define ARCHER_H
#include "Character.h"
#include "Soldier.h"
#include <iostream>
#include <string>

class Archer: public Character{
    private:
        int energy;
        string currentArrow;
        int arrowCost;
        int arrowDamage;
        int numArrows;
        //int Arrows[5] = [10,15,20,25,30];
    public:
        Archer();
        int getHealth();
        Archer(string , string , int ,int );
        void arrows();
        void changeArrows(string newArrow);
        void rest();
//        void attack(Archer player1, Soldier &player2);
//       void attack(Archer player1, Archer &player2);
        int getAttack();
        void attack();
        string getType();

};

#endif