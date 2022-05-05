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
    interface_.printSettingBoats(1);
    player1->setShips();
    interface_.clear();

    interface_.printSettingBoats(2);
    player2->setShips();
    interface_.clear();

    while (!player1->isGameover() || !player2->isGameover()) {
        interface_.startAttackPhase(1);
        player2->fire();
        interface_.clear();

        if (player2->isGameover()) {
            interface_.printGameover(1);
            return;
        }

        interface_.startAttackPhase(2);
        player1->fire();
        interface_.clear();

        if (player1->isGameover()) {
            interface_.printGameover(2);
            return;
        }
    }
}
