#pragma once

class Skill {
public:
    // Con/Des
    Skill() = default;
    Skill(int points);
    ~Skill() = default;

    // accessor
    int getPoints();

protected:
    // skill conditions
    int points_to_activate_;
};
