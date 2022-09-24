#include "Character.cpp"
#include "Soldier.cpp"
#include "archer.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    string inputName,name,race,userName,temp;
    int level,health,typeOfFighter;
    Character player1;
    Character player2;

//get save file of player1
    cout << "Player1 enter your name" <<endl;
    cin >> inputName;
    ifstream inputFile;
    inputFile.open("load.txt");
    while (inputFile >> name){
        userName = name;
        if (name == inputName){
            inputFile >> race >> level >> health >> typeOfFighter;
            if (typeOfFighter == 1){
                cout <<"Save Found" <<endl;
                Soldier player1(name, race, level, health);
               break;
            }
            else if (typeOfFighter == 2){
                cout <<"Save Found" <<endl;
                Archer player1(name, race, level ,health);
               break;
            }
        }
        else{
            cout <<"Starting new save"<<endl;
            cout << "Player1 enter your race" << endl;
            cin >> race;
            level = 1;
            health = 100;
            break;
        }
    }
    inputFile.close();
        
//initialize player1
    cout << "Player1: Soldier(1) or Archer(2)?" << endl;
    int choice1,choice2;
    cin >> choice1;
    if (choice1 == 1){
        Soldier player1(name, race, level, health);
        cout << "CHOOSE A WEAPON" << endl;
        player1.weapons();
        string weaponChoice;
        cin >> weaponChoice;
        player1.changeWeapon(weaponChoice);
    }
    else if (choice1 == 2){
        Archer player1(name,race, level, health);       
        cout << "CHOOSE AN ARROW" << endl;
        player1.arrows();
        string arrowChoice;
        cin >> arrowChoice;
        player1.changeArrows(arrowChoice);
    }else{
        cout<< "Invalid choice. Soldier(1) Archer(2)" << endl;
        cin >> choice1;
    }
    
    
//get save file of player2
    cout << "Player2 enter your name" <<endl;
    cin >> inputName;
    ifstream input;
    input.open("load.txt");
    while (input >> name){
        userName = name;
        if (name == inputName){
            inputFile >> race >> level >> health >> typeOfFighter;
            if (typeOfFighter == 1){
                Soldier player2(name, race, level, health);
                player2.weapons();
                cout << "CHOOSE A WEAPON" << endl;
                string weaponChoice;
                cin >> weaponChoice;
                player2.changeWeapon(weaponChoice);
                break;
            }
            else if (typeOfFighter == 2){
                Archer player2(name, race, level ,health);
                player2.arrows();
                cout << "CHOOSE AN ARROW" << endl;
                string arrowChoice;
                cin >> arrowChoice;
                player2.changeArrows(arrowChoice);
                break;
            }
        }
        else{
            cout << "Player2 enter your race" << endl;
            cin >> race;
            level = 1;
            health = 100;
            break;
        }
    }
    input.close();

//initialize player2
    cout << "Player2: Soldier(1) or Archer(2)?" << endl;
    cin >> choice2;
    if (choice2 == 1){
        Soldier player2(name, race, level, health);
        player2.weapons();
        string weaponChoice;
        cin >> weaponChoice;
        player2.changeWeapon(weaponChoice);
    }
    else if (choice2 == 2){
        Archer player2(name,race, level, health);
        cout << "CHOOSE AN ARROW" << endl;
        player2.arrows();
        string arrowChoice;
        cin >> arrowChoice;
        player2.changeArrows(arrowChoice);
    }else{
        cout <<"Invalid choice. Soldier(1) Archer(2)" << endl;
        cin >> choice2;
    }
    
    bool getOut = true;
    while (player1.getHealth() >= 0 || player2.getHealth()>= 0 || getOut == false){
        int move,offense,defense,net;
        int yesOrNo;

        cout <<"Player1 move: 1 for attack, 2 for rest"<<endl;
        cin >> move;
        if (move==1){
            player1.attack();
            offense = player1.getAttack();
            defense = player2.getHealth();
            net = defense-offense;
            player2.setHealth(net);
            break;
        }
        else if (move==2){
            player1.rest();
            break;
        }else{
            cout << "Invalid move. Attack(1) Rest(2)" << endl;
            cin >> move;
        }

        cout <<"Player2 move: 1 for attack, 2 for rest"<<endl;
        cin >> move;
        while (move <3){
        if (move==1){
            player2.attack();
            offense = player2.getAttack();
            defense = player1.getHealth();
            net = defense-offense;
            player1.setHealth(net);
            break;
        }
        else if (move==2){
            player2.rest();
            break;
        }else{
            cout << "Invalid move. Attack(1) Rest(2)" << endl;
            cin >> move;
        }
        }
        cout << "PLAYER 1: ";
        player1.PrintInfo();
        cout << endl << "PLAYER 2: ";
        player2.PrintInfo();

        cout <<"Continue? Yes(1) No(2)"<<endl;
        cin >> yesOrNo;
        if (yesOrNo == 2){
            ofstream outputFile;
            outputFile.open("save.txt");
            outputFile << player1.getName()<<" ";
            outputFile << player1.getRace()<<" ";
            outputFile << player1.getLevel()<<" ";
            outputFile << player1.getHealth()<<" ";
//            outputFile << choice1<<" ";

            //repeat for player2
            outputFile << player2.getName()<<" ";
            outputFile << player2.getRace()<<" ";
            outputFile << player2.getLevel()<<" ";
            outputFile << player2.getHealth()<<" ";
//            outputFile << choice2<<" ";
            break;
            getOut = true;
        }else{
            cout<<"Invalid choice. Continue? Yes(1) No(2)" <<endl;
            cin >> yesOrNo;
        }
    }



// Determine the winner
    if (player1.getHealth() < player2.getHealth()){
        cout << "Player 2 wins!"<<endl;
    }else if (player2.getHealth() < player1.getHealth()){
        cout <<"Player 1 wins!"<<endl;
    }else{
        cout << "It's a tie!" << endl;
    }



    return 0;
}