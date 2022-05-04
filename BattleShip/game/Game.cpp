#include "Game.h"

// Con/Des
Game::Game() {
    player1 = new Player();
    player2 = new Player();
}

Game::~Game() {
    delete player1;
    delete player2;
}

// main funciton for running the game
void Game::run() {
    printInstructions();

    printSettingBoats(player1, 1);
    printSettingBoats(player2, 2);

    while (!player1->isGameover() || !player2->isGameover()) {
        startAttackPhase(player2, 1);

        if (player2->isGameover()) {
            std::cout << "Player 1 wins!!!!\n";
            return;
        }

        startAttackPhase(player1, 2);

        if (player1->isGameover()) {
            std::cout << "Player 2 wins!!!!\n";
            return;
        }
    }
}

// printing texts
void Game::printInstructions() {
    std::cout << "For instructions check the README.md\n";
    std::cout << "Press c to continue with the game)\n";

    std::string indicator;
    while (indicator != "c") {
        std::cin >> indicator;
    }

    system("clear");
}

void Game::printSettingBoats(Player* player, int player_number) {
    std::cout << "Player" << player_number << ": " << "your turn to set the ships\n\n";
    player->setShips();

    system("clear");
}

void Game::startAttackPhase(Player* player, int player_number) {
    std::cout << "Player" << player_number << ": " << "your turn to attack\n";  
    player->fire();

    system("clear");
}
