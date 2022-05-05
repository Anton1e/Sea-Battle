CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

project(BattleShip)

add_compile_options(-g -fsanitize=address)
add_link_options(-g -fsanitize=address)

include_directories(include)

add_executable(BattleShip ./src/main.cpp
                          ./ships/Ship.cpp
                          ./ships/Submarine.cpp
                          ./ships/Destroyer.cpp
                          ./ships/Battleship.cpp
                          ./ships/Carrier.cpp
                          ./map/Board.cpp
                          ./map/Cell.cpp
                          ./player/Player.cpp
                          ./game/Game.cpp
                          ./interface/Interface.cpp)
