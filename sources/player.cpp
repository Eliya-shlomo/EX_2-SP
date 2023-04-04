//
// Created by eliya on 29/03/2023.
//

#include "player.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace ariel;

Player::Player(string name)  {
    this->name=name;
    this->package=package;
}
Player::Player() {
}
int Player::stacksize() {
    return package.size();
}
int Player::cardesTaken() {
    return 0;
}

vector<card> Player:: get_package(){
    return this->package;
}
string Player:: get_name(){
    return this->name;
}

