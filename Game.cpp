#include <iostream>
#include "Game.h"

void Game::startGame(){
    player1 = 1;
    player2 = 1;
    Dice *d = new Dice;
    int playerRoll = 0;
    int selection;
    int playerTurn = 0;
    do
    {
       //Always reset selection to 0
        selection = 0;
        playerTurn +=1;
        playerRoll = d->roll();
        if ((player1+playerRoll)%4 == 0){ //Snakes
            std::cout << "You are in " << playerRoll+player1 << " position, and you landed on snakes... Go back 3 places..." << std::endl;
            player1+=playerRoll-3; 
        } else if ((player1 + playerRoll)%6==0){ //Ladders
            std::cout << "You are in " << playerRoll+player1 << " position, and you landed on ladders! Go forward 3 places!" << std::endl;
            player1+=playerRoll+3; 
        } else {
            std::cout << "You are in " << playerRoll+player1 << " position, and you landed on nothing. Stay in current position." << std::endl;
            player1+=playerRoll; 
        }
        if (player1 >= 50){
            break;
        }
    
        //Player turn end and continue input
        std::cout << "Turn ended, you are currently in " << player1 << " position." << std::endl;
        std::cout << "Enter 1 to continue or 2 to end game." << std::endl;
        while (selection != 1 || 2){
            std::cin >> selection;
            if (selection == 1){
                break;
            } else {
                std::cout << "Invalid option." << std::endl;
            }
        }

        if (selection == 1) {
            //Selection assigned to 0 again
            selection = 0;
            playerTurn +=1;
            playerRoll = d->roll();
            if ((player2+playerRoll)%4 == 0){ //Snakes
                std::cout << "Computer is in " << playerRoll+player2 << " position, and landed on snakes! Going back 3 places!" << std::endl;
                player2+=playerRoll-3; 
            } else if ((player2 + playerRoll)%6==0){ //Ladders
                std::cout << "Computer is in " << playerRoll+player2 << " position, and landed on ladders...  Forward 3 places..." << std::endl;
                player2+=playerRoll+3; 
            } else {
                std::cout << "Computer is in " << playerRoll+player2 << " position, and landed on nothing. Stayed in current position." << std::endl;
                player2+=playerRoll; 
            }
            if (player2 >= 50){
                break;
            }
        }
        //Computer turn end and continue input
        std::cout << "Computer has ended his turn and is currently on " << player2 << " position." << std::endl;
        std::cout << "Enter 1 to continue or 2 to end game." << std::endl;
        std::cin >> selection;

        //Win conditions
        if (player1 >= 50){
            std::cout << "You WON!" << std::endl;
        } else if (player2 >= 50){
            std::cout << "Computer WON!" << std::endl;
        } else {
            std::cout << "GAME OVER." << std::endl;
        }

        } while (selection != 'X');
    
}
