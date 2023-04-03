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

}
Player::Player() {
}
int Player::stacksize() {
    return 0;
}
int Player::cardesTaken() {
    return 0;
}
