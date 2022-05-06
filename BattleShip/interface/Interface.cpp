#include "Interface.h"

// printing texts
std::string Interface::printSetSubmarine(Board* board, int x) {
    std::string start_position;

    board->printBoard();
    std::cout << x + 1 << '\\' << 4  << ' ';
    std::cout << "Please set your submarines(size 1 ships)\n";
    std::cin >> start_position;

    return start_position;
}

std::pair<std::string, std::string> Interface::printSetDestroyer(Board* board, int x) {
    std::string start_position, end_position;

    board->printBoard();
    std::cout << x + 1 << '\\' << 3 << ' ';
    std::cout << "Please set your destroyers(size 2 ships)\n";
    std::cin >> start_position >> end_position;

    return std::make_pair(start_position, end_position);
}

std::pair<std::string, std::string> Interface::printSetBattleship(Board* board, int x) {
    std::string start_position, end_position;

    board->printBoard();
    std::cout << x + 1 << '\\' << 2 << ' ';
    std::cout << "Please set your battleships(size 3 ships)\n";
    std::cin >> start_position >> end_position;

    return std::make_pair(start_position, end_position);
}

std::pair<std::string, std::string> Interface::printSetCarrier(Board* board, int x) {
    std::string start_position, end_position;

    board->printBoard();
    std::cout << x + 1 << '\\' << 1 << ' ';
    std::cout << "Please set your carriers(size 4 ships)\n";
    std::cin >> start_position >> end_position;

    return std::make_pair(start_position, end_position);
}

std::pair<std::string, std::string> Interface::printNotValidPosition(bool is_only) {
    std::string start_position, end_position;

    std::cout << "Positions are not valid, please try again\n";
    std::cin >> start_position;

    if (!is_only) {
        std::cin >> end_position;
    }

    return std::make_pair(start_position, end_position);
}

void Interface::printWhenMissHit() {
    std::cout << "Too bad( You missed\n";
}

std::pair<int, int> Interface::getCoorForAttack(Board* board) {
    board->printBoard();
    std::cout << "Which cell would you like to attack?\n";
    std::string pos;
    std::cin >> pos;

    int x_coor =  pos[0] - 'A', y_coor = pos[1] - '0';
    
    return std::make_pair(x_coor, y_coor);
}

void Interface::printWhenHit() {
    std::cout << "You hit an oppenent's boat!!!\n";
    std::cout << "It's your turn again!\n";
}

void Interface::printGameover(int x) {
    std::cout << "Player" << x << " wins!!!\n";
}

void Interface::printSettingBoats(int x) {
    std::cout << "Player" << x << ": it's your turn to set the ships\n";
}

void Interface::startAttackPhase(int x) {
    std::cout << "Player" << x << ": it's your turn to attack\n";
}

void Interface::clear() {
    system("clear");
}
