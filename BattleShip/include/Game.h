#pragma once
#include "Player.h"
#include "Interface.h"

class Game {
public:
    // Con/Des
    Game();
    ~Game();

    // main function for running the game
    void run();

private:
    // 2 players
    Player* player1;
    Player* player2;

    // interface
    Interface interface_;
};
