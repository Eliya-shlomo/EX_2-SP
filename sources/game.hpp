//
// Created by eliya on 29/03/2023.
//

#ifndef PROJECT1_PARTA_SEMESTERB_GAME_HPP
#define PROJECT1_PARTA_SEMESTERB_GAME_HPP

#include "player.hpp"

namespace ariel {
    class Game {
        Player player_1;
        Player player_2;
    

    public:
        Game(Player player1, Player player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();


    };
};

#endif //PROJECT1_PARTA_SEMESTERB_GAME_HPP
