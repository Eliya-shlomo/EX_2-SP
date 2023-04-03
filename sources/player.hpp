//
// Created by eliya on 29/03/2023.
//

#ifndef PROJECT1_PARTA_SEMESTERB_PLAYER_HPP
#define PROJECT1_PARTA_SEMESTERB_PLAYER_HPP

#include <system_error>
#include <string>
using namespace std;
#include "vector"
#include "card.hpp"


using namespace std;
namespace ariel {
    class Player {
        string name;

    public:
        Player(string name);
        Player();

        int stacksize();

        int cardesTaken();
    };
}

#endif //PROJECT1_PARTA_SEMESTERB_PLAYER_HPP
