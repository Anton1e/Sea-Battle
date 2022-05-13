#pragma once
#include "Skill.h"
#include "Player.h"

class DestroyRow: public Skill {
public:
    // Con/Des
    DestroyRow();
    ~DestroyRow() = default;

    // what the skill does
    void activate(Player& player, int row);
};
