CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

project(BattleShip)

include_directories(include)

add_executable(BattleShip ./src/main.cpp
                          ./ships/Ship.cpp
                          ./ships/Submarine.cpp
                          ./ships/Destroyer.cpp
                          ./ships/Battleship.cpp
                          ./ships/Carrier.cpp
                          ./skills/Skill.cpp
                          ./skills/DestroyRow.cpp
                          ./skills/DestroySquare.cpp
                          ./map/Board.cpp
                          ./map/Cell.cpp
                          ./player/Player.cpp
                          ./game/Game.cpp
                          ./interface/Interface.cpp)
