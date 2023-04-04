//
// Created by eliya on 29/03/2023.
//

#ifndef PROJECT1_PARTA_SEMESTERB_GAME_HPP
#define PROJECT1_PARTA_SEMESTERB_GAME_HPP
#include <iostream>
#include "vector"
#include "player.hpp"

namespace ariel {
    class Game {
        Player player_1;
        Player player_2;
    private:
        vector<card>pacage;
        string victory;
        string total_viictory;
        int cardtaken_1;
        int cardtaken_2;
        string cards1_won;
        string cards2_won;
        int drew=0;
    

    public:
        Game(Player player1, Player player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();


    private:

        vector<card> full_pacage();

        void split(vector<card> package_p1, vector<card> package_p2, vector<card>& package );


    };
};

#endif //PROJECT1_PARTA_SEMESTERB_GAME_HPP
