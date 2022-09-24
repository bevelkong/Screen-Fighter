#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
using namespace std;

class Character{
    public:
        Character();
        Character(string , string , int , int );
        void setHealth(int _health);
        void setName(string _name);
        string getName();
        void setLevel(int _level);
        int getLevel();
        void setRace(string _race);
        string getRace();
        void PrintInfo();
        virtual int getHealth() const;
        virtual void attack() const;
        virtual int getAttack() const;
        virtual void rest() const;
    protected:
        string name;
        string race;
        int level;
        int health;
        //attack
};

#endif

