#pragma once

class Ship {
public:
    // Con/Des
    Ship();
    Ship(int size);
    ~Ship();

    // interaction when hit
    void isHit();

    // accessor
    bool isDead();

protected:
    // ship's parameters
    int size_;
    int health_;
};
