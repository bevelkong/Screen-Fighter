#include "Character.cpp"
#include "Soldier.cpp"
#include "archer.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ifstream inputFile;
    inputFile.open("load.txt");
    string _name,_race;
    int _level, _health,count=0,archerOrSoldier;
    Character characters[10];
    while (!inputFile.eof()){
        inputFile >> _name >> _race >> _level >> _health >> archerOrSoldier;
        Character oldSave(_name,_race,_level,_health);
        characters[count]=oldSave;
        ++count;
    }
    for (int i=0;i<count;++i){
        if (characters[i].name == "Ryan"){
            cout << "found" << endl;
        }
    }

}