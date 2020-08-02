#include <iostream>
#include "Dice.h"
#include "Game.h"

void display(){
    std::cout << "SNAKES & LADDERS GAME \nENTER '1' TO PLAY OR '0' TO QUIT" << std::endl;    
}
int selection(){
    int select;
    std::cin >> select;
    return select;
}

int main(){
    display();
    char select = selection();
    do {
        switch (select)
        {
        case 1:
            std::cout << "Game started successfully." << std::endl;
            break;
        case 0:
            std::cout << "Game exited successfully." << std::endl;
            break;
        default:
            std::cout << "Invalid input." << std::endl;
            break;
        }
    } while (select != 0);
    
    //Game g;
    //g.startGame();
    return 0;
}