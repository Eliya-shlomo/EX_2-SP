//
// Created by eliya on 29/03/2023.
//

#include "card.hpp"
using namespace std;
using namespace ariel;
using std::string;

card::card(int number,string shape){
   this->number=number;
   this->shape=shape;
}

int card:: get_value() {
    return this->number;
}
string card::to_string() {
    string to_return= std::to_string(this->number)+","+ this->shape;
    return to_return;
}
