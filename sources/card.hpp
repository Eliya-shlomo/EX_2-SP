//
// Created by eliya on 29/03/2023.
//

#ifndef PROJECT1_PARTA_SEMESTERB_CARD_HPP
#define PROJECT1_PARTA_SEMESTERB_CARD_HPP
#include <string>
#include <iostream>
using std::string;

namespace ariel {
    class card {
    private:
        int number;
        string shape;



    public:
        card(int number,string shape);

        int get_value();
        string to_string();
    };
}

#endif //PROJECT1_PARTA_SEMESTERB_CARD_HPP
