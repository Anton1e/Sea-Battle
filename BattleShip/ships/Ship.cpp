#include "Ship.h"

// Con/Des
Ship::Ship() {}

Ship::Ship(int size) {
    size_ = size;
    health_ = size;
}

Ship::~Ship() {}

// interaction when hit
void Ship::isHit() {
    --health_;
}

// accessor
bool Ship::isDead() {
     return health_ == 0;
}
