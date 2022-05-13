#pragma once
#include <string>
#include <stdlib.h>
#include "Board.h"

class Interface {
public:
    // Con/Des
    Interface() = default;
    ~Interface() = default;

    // printint texts
    std::string printSetSubmarine(Board* board, int x);
    std::pair<std::string, std::string> printSetDestroyer(Board* board, int x);
    std::pair<std::string, std::string> printSetBattleship(Board* board, int x);
    std::pair<std::string, std::string> printSetCarrier(Board* board, int x);

    std::pair<std::string, std::string> printNotValidPosition(bool is_only);

    void printWhenMissHit();
    void printWhenHit();

    std::pair<int, int> getCoorForAttack(Board* board);

    void printGameover(int x);

    void printSettingBoats(int x);
    void startAttackPhase(int x);

    void clear();
};
