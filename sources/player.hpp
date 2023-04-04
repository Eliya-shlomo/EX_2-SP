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

    public:
        Player(string name);
        Player();

        int stacksize();

        int cardesTaken();

        vector<card> get_package();

        string get_name();
    };
}

#endif //PROJECT1_PARTA_SEMESTERB_PLAYER_HPP
