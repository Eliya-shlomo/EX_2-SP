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
    this->package.clear();
    this->card_won=0;
}
Player::Player() {
}
int Player::stacksize() {
    return this->package.size();
}
int Player::cardesTaken() {
    return card_won;
}

vector<card> Player:: get_package(){
    return this->package;
}
string Player:: get_name(){
    return this->name;
}
void Player:: add_to_package(card card){
    this->package.push_back(card);
};
void Player:: pop_from_package(){
    this->package.pop_back();
};
card Player:: showing_card_package(){
    card card =this->package.back();
    this->package.pop_back();
    return  card;
};
void Player:: count_cards(int cards_won){
    this->card_won+=cards_won;
};





