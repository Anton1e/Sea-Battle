#include "DestroySquare.h"

// Con/Drs
DestroySquare::DestroySquare(): Skill(3) {}

// what the skill does
void DestroySquare::activate(Player& player, int row, int column) {
    for (int i = row - 1; i <= row + 1; ++i) {
        for (int j = column - 1; j <= column + 1; ++j) {
            if (i >= 0 && i <= 9 && j >= 0 && j <= 9) {
                player.fire({i, j});
            }
        }
    }
}
