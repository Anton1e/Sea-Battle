#pragma once
#include <string>
#include "Player.h"
#include "Interface.h"

class Game {
public:
    // Con/Des
    Game();
    ~Game();

    // main function for running the game
    void run();

    // have players pick their skills
    void playerSetSkill(Player* player, int x);

    // logic for setting boats
    void setBoats(Player* player, int x);

    // logic for attack phase
    void playerAttackPhase(Player* player, int x);

    // logic for player attacking
    void playerAttack(Player* player, int x);

    // logic fot player using skill
    void playerUseSkill(Player* player);

private:
    // number of boats
    static const int number_of_submarines_ = 4;
    static const int number_of_destroyers_ = 3;
    static const int number_of_battleships_ = 2;
    static const int number_of_carriers_ = 1;

    // 2 players
    Player* player1;
    Player* player2;

    // interface
    Interface interface_;
};
