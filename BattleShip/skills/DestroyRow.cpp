#include "DestroyRow.h"

// Con/Des
DestroyRow::DestroyRow(): Skill(5) {}

// what the skill does
void DestroyRow::activate(Player& player, int row) {
    for (int i = 0; i < player.getBoard()->getWidth(); ++i) {
        player.fire({row, i});
    }
}
