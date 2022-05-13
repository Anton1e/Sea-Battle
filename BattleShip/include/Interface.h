#pragma once
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include "Board.h"

class Interface {
public:
    // Con/Des
    Interface() = default;
    ~Interface() = default;

    // printint texts
    int printPickSkill(int x);

    void printBoard(Board* board);

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
    void ssleep(int x);

    char suggestSkill(Board* board, int x);
    std::pair<int, int> printUsingDestroyRow();
    std::pair<int, int> printUsingDestroySquare();
    std::pair<int, int> printSkillMenu(int x);
};
