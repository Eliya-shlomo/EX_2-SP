//
// Created by eliya on 29/03/2023.
//

#ifndef PROJECT1_PARTA_SEMESTERB_PLAYER_HPP
#define PROJECT1_PARTA_SEMESTERB_PLAYER_HPP

#include <system_error>
#include <iostream>
#include <string>
#include "vector"
#include "card.hpp"
using namespace std;
using namespace std;

namespace ariel {
    class Player {
        string name;
    private:
        vector<card> package;
        int card_won;

    public:
        Player(string name);
        Player();

        int stacksize();

        int cardesTaken();

        vector<card> get_package();

        void add_to_package(card card);

        void pop_from_package();

        card showing_card_package();

        string get_name();
        void count_cards(int cards_won);

    };
}

#endif //PROJECT1_PARTA_SEMESTERB_PLAYER_HPP
