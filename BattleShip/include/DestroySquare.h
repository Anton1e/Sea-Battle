#pragma once
#include "Player.h"
#include "Skill.h"

class DestroySquare: public Skill {
public:
    // Con/Des
    DestroySquare();
    ~DestroySquare() = default;

    // what the skill does
    void activate(Player& player, int row, int column);
};
