#include <iostream>
#include <cassert> // for assert
#include <cstdint> // for fixed width integers
#include <string_view>
#include <array>
#include <vector>
#include <algorithm> // for std::shuffle
#include "Random.h"  // for Random::mt


/*
Design:

board things:
- display game board
- randomize starting tiles
- swap tiles (Values)
- check if game is won

user:
- get input cmd for move 
- handle invalid input
- allow user to quit mid game

*/

class Board {
public:
    Board() {
        // randomize starting order (top left = empty)
        std::array<int, 15> vals { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
        std::random_shuffle(std::begin(vals), std::end(vals));
        board[0][0] = NULL;
        int v = 0;
        for (int i = 0; i < board_size; ++i) {
            for (int j = 0; j < board_size; ++j) {
                if (i != 0 && j != 0) {
                    board[i][j] = vals[v++];
                }
            }
        }
    }

    void swapTiles(char direc) {
        // switch(direc) {
        //     case 'w':
        //         // slide tile up
        //     case 'a':
        //         // slide tile left
        //     case 's':
        //         // slide tile down
        //     case 'd':
        //         // slide tile right
        // }

    }

    void printBoard() {
        for (int i = 0; i < board_size; ++i) {
            for (int j = 0; j < board_size; ++j) {
                if (!board[i][j]) {
                    std::cout << " ";
                } else {
                    std::cout << board[i][j] << " ";
                }
            }
            std::cout << '\n';
        }
    }

    bool checkWon() {
        int ct = 1;
        for (int i = 0; i < board_size; ++i) {
            for (int j = 0; j < board_size; ++j) {
                if (i != board_size-1  && j != board_size-1) {
                    if (board[i][j] != ct++) return false;
                }
            }
        }
        return true;
    }
private:
    // 4x4 of tiles (int)
    static constexpr int board_size = 4;
    std::array<std::array<int, board_size>, board_size> board {};
    std::pair<int, int> empty_tile { 0, 0 };
};

namespace UserInput {
    std::string_view getDirec(char c) {
        switch (c) {
            case 'w':
                return "up";
            case 'a':
                return "left";
            case 's':
                return "down";
            case 'd':
                return "right";
            default:
                return "invalid";
        }
    }

    char getUserInput() {
        // loop to get valid direction
        std::cout << "Enter a command: ";
        char in {};
        std::cin >> in;
        std::cout << "You entered direction: " << getDirec(in) << '\n';
    }

    bool checkInputValid() {

    }
}

// int main()
// {
//     // game loop (engine)
//     while (true) {
//         // char c = getUp
//     }

// 	return 0;
// }