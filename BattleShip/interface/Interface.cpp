#include "Interface.h"

// printing texts
int Interface::printPickSkill(int x) {
    std::cout << "Player" << x << ": It's your turn to pick a skill\n";

    std::cout << "Please pick one of the following skills\n";
    std::cout << "1) Destroy an entire row(costs 5 points)\n";
    std::cout << "2) Destroy all cells around a chosen one(costs 3 points)\n";
    std::cout << "Type in 1 or 2 in a relation to your desired skill\n";

    int indicator;
    std::cin >> indicator;

    return indicator;
}

void Interface::printBoard(Board* board) {
    std::cout << "  ";
    for (int i = 0; i < board->getWidth(); ++i) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    for (int i = 0; i < board->getHeight(); ++i) {
        std::cout << static_cast<char>('A' + i) << " ";
        for (int j = 0; j < board->getWidth(); ++j) {
            std::cout << board->getCell(i, j)->getType() << " ";
        }
        std::cout << '\n';
    }
}

std::string Interface::printSetSubmarine(Board* board, int x) {
    std::string start_position;

    printBoard(board);
    std::cout << x + 1 << '\\' << 4  << ' ';
    std::cout << "Please set your submarines(size 1 ships)\n";
    std::cin >> start_position;

    return start_position;
}

std::pair<std::string, std::string> Interface::printSetDestroyer(Board* board, int x) {
    std::string start_position, end_position;

    printBoard(board);
    std::cout << x + 1 << '\\' << 3 << ' ';
    std::cout << "Please set your destroyers(size 2 ships)\n";
    std::cin >> start_position >> end_position;

    return std::make_pair(start_position, end_position);
}

std::pair<std::string, std::string> Interface::printSetBattleship(Board* board, int x) {
    std::string start_position, end_position;

    printBoard(board);
    std::cout << x + 1 << '\\' << 2 << ' ';
    std::cout << "Please set your battleships(size 3 ships)\n";
    std::cin >> start_position >> end_position;

    return std::make_pair(start_position, end_position);
}

std::pair<std::string, std::string> Interface::printSetCarrier(Board* board, int x) {
    std::string start_position, end_position;

    printBoard(board);
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
    printBoard(board);
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

void Interface::ssleep(int x) {
    sleep(x);
}

char Interface::suggestSkill(Board* board, int x) {
    printBoard(board);

    std::cout << "Player" << x << ": Skill turn\n";
    std::cout << "You have enough points, would you like to use the skill?\n";
    std::cout << "Type Y to use the skill\n";
    std::cout << "Type N to continue with normal hit\n";

    char indicator;
    std::cin >> indicator;

    return indicator;
}

std::pair<int, int> Interface::printUsingDestroyRow() {
    std::cout << "Please pick a row you would like to destroy\n";
    
    char row;
    std::cin >> row;

    return {row - 'A', row - 'A'};
}

std::pair<int, int> Interface::printUsingDestroySquare() {
    std::cout << "Please pick a cell around which you would like to destroy\n";

    std::string pos;
    std::cin >> pos;

    return {pos[0] - 'A', pos[1] - '0'};
}

std::pair<int, int> Interface::printSkillMenu(int x) {
    return x == 0 ? printUsingDestroyRow() : printUsingDestroySquare();
}
