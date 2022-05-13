#pragma once
#include <vector>
#include <string>
#include "Board.h"
#include "Ship.h"
#include "Submarine.h"
#include "Destroyer.h"
#include "Battleship.h"
#include "Carrier.h"
#include "Skill.h"

class Player {
public:
    // Con/Des
    Player();
    ~Player();

    // set ships
    void setShips(std::string, std::string, char type);
    
    // fire a cell
    void fire(std::pair<int, int> coors);

    // check if lost
    bool isGameover();

    // accessor 
    Board* getBoard();
    int getPoints();
    int getSkillIndicator();
    int getSkillPoints();

    // set the skill
    void setSkillIndicator(int x); 

    // use the chosen skill
    void useSkill(int row, int column);

    // check whether a ship could be placed;
    bool checkIfValid(std::string first_pos, std::string second_pos, int expected_length);

private:
    // check which ship was hit
    void checkWhatWasHit(int x_coor, int y_coor);

    // deleters
    void clearSubmarines();
    void clearDestroyers();
    void clearBattleships();
    void clearCarriers();

    // number of boats
    static const int total_number_of_ships_ = 10;
    static const int number_of_submarines_ = 4;
    static const int number_of_destroyers_ = 3;
    static const int number_of_battleships_ = 2;
    static const int number_of_carriers_ = 1;

    // set of boats for the player
    std::vector<Submarine*>  submarines_;
    std::vector<Destroyer*> destroyers_;
    std::vector<Battleship*> battleships_;
    std::vector<Carrier*> carriers_;

    // player has a game board)
    Board* board_;

    // player's parameters
    int number_of_dead_ships_;
    int points_;

    // skill 
    int skill_indicator_;
    std::vector<Skill*> skills_;
};
