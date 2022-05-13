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
    playerSetSkill(player2, 1);

    playerSetSkill(player1, 2);
    
    setBoats(player1, 1);

    setBoats(player2, 2);

    while (!player1->isGameover() || !player2->isGameover()) {
        playerAttackPhase(player2, 1);

        if (player2->isGameover()) {
            interface_.printGameover(1);
            return;
        }
        
        playerAttackPhase(player1, 2);

        if (player1->isGameover()) {
            interface_.printGameover(2);
            return;
        } 
    }
}

// have players pick their skills
void Game::playerSetSkill(Player* player, int x) {
    int indicator;

    indicator = interface_.printPickSkill(x);
    
    player->setSkillIndicator(indicator - 1);

    interface_.clear();
}

// logic for setting boats
void Game::setBoats(Player* player, int x) {
    interface_.printSettingBoats(x);
    
    std::string start_position, end_position;

    for (int i = 0; i < number_of_submarines_; ++i) {
        start_position = interface_.printSetSubmarine(player->getBoard(), i);

        while (!player->checkIfValid(start_position, start_position, 1)) {
            start_position = interface_.printNotValidPosition(true).first;
        }

        player->setShips(start_position, end_position, 'S');

        interface_.clear();
    }

    for (int i = 0; i < number_of_destroyers_; ++i) {
        std::pair<std::string, std::string> positions = interface_.printSetDestroyer(player->getBoard(), i);
        start_position = positions.first;
        end_position = positions.second;

        while (!player->checkIfValid(start_position, end_position, 2)) {
            positions = interface_.printNotValidPosition(false);
            start_position = positions.first;
            end_position = positions.second;
        }

        player->setShips(start_position, end_position, 'D');

        interface_.clear();
    }

    for (int i = 0; i < number_of_battleships_; ++i) {
        std::pair<std::string, std::string> positions = interface_.printSetBattleship(player->getBoard(), i);
        start_position = positions.first;
        end_position = positions.second;

        while (!player->checkIfValid(start_position, end_position, 3)) {
            positions = interface_.printNotValidPosition(false);
            start_position = positions.first;
            end_position = positions.second;
        }

        player->setShips(start_position, end_position, 'B');

        interface_.clear();
    }

    for (int i = 0; i < number_of_carriers_; ++i) {
        std::pair<std::string, std::string> positions = interface_.printSetCarrier(player->getBoard(), i);
        start_position = positions.first;
        end_position = positions.second;

        while (!player->checkIfValid(start_position, end_position, 4)) {
            positions = interface_.printNotValidPosition(false);
            start_position = positions.first;
            end_position = positions.second;
        }

        player->setShips(start_position, end_position, 'C');

        interface_.clear();
    }
    
    player->getBoard()->withoutShipTypes();
}

// logic for attack phase
void Game::playerAttackPhase(Player* player, int x) {
    if (player->getPoints() >= player->getSkillPoints()) {
        char flag = interface_.suggestSkill(player->getBoard(), x);
        interface_.clear();
        if (flag == 'Y') {
            playerUseSkill(player);
        }
        else {
            playerAttack(player, x);
        }
    }
    else {
        playerAttack(player, x);
    }
}

// logic for player attacking
void Game::playerAttack(Player* player, int x) {
    interface_.startAttackPhase(x);

    std::pair<int, int> coors = interface_.getCoorForAttack(player->getBoard());
    int x_coor = coors.first, y_coor = coors.second;
    
    while (player->getBoard()->getCell(x_coor, y_coor)->isBoat()) {
        interface_.printWhenHit();

        player->fire({x_coor, y_coor});

        interface_.clear();

        if (player->isGameover()) {
            return;
        }

        coors = interface_.getCoorForAttack(player->getBoard());
        x_coor = coors.first;
        y_coor = coors.second;
    }

    if (!player->getBoard()->getCell(x_coor, y_coor)->isBoat()) {
        interface_.printWhenMissHit();

        player->fire({x_coor, y_coor});

        interface_.ssleep(1);

        interface_.clear();
    }
}

// logic for using skill
void Game::playerUseSkill(Player* player) {
    interface_.printBoard(player->getBoard());
    std::pair<int, int> coor = interface_.printSkillMenu(player->getSkillIndicator());
    player->useSkill(coor.first, coor.second);
    interface_.printBoard(player->getBoard());
    interface_.ssleep(1);
    interface_.clear();
}
