#pragma once
#include <stdlib.h>
#include "Player.h"

class Game {
public:
    // Con/Des
    Game();
    ~Game();

    // main function for running the game
    void run();

    // printing texts
    void printInstructions();
    void printSettingBoats(Player* player, int player_number);
    void startAttackPhase(Player* player, int player_number);

private:
    // 2 players
    Player* player1;
    Player* player2;
};
