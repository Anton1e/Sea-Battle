#include "Skill.h"

// Con/Des
Skill::Skill(int points) {
    points_to_activate_ = points;
}

// accessor
int Skill::getPoints() {
    return points_to_activate_;
}
