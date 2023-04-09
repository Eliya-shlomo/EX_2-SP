
// Created by eliya on 29/03/2023.
//

#include "game.hpp"
#include "card.hpp"
#include "player.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
using namespace ariel;


Game::Game(Player &player1, Player &player2):
    player_1(player1),player_2(player2)
{
    this->pacage=full_pacage();
    for(size_t i=0;i<52;i++){
        if(i%2==0){
            player1.add_to_package(pacage[i]);
        }
        else{
            player2.add_to_package(pacage[i]);
        }
    }
    this->cards1_won="";
    this->cards2_won="";
    this->drew=0;
    this->rounds=0;
    if(&player_1==&player2){
        player_same=true;
    } else{
        player_same=false;
    }


}

void Game::playTurn() {
    if(this->player_1.stacksize()==0||this->player_2.stacksize()==0){
        throw std::invalid_argument("empty package");
    }
    if(player_same== true){
        throw std::invalid_argument("A player cannot play against himself");
    }
    string bonus="";
    int condition=1;
    int cards_to_win=0;
    while(condition){
        this->rounds+=1;
        card card_1=this->player_1.showing_card_package();
        card card_2=this->player_2.showing_card_package();
        cards_to_win+=2;
        condition=0;
        if((card_1.get_value()==card_2.get_value())&&player_1.stacksize()==0){
            this->drew+=1;
            player_1.count_cards(cards_to_win/2);
            player_2.count_cards(cards_to_win/2);
            this->victory=""+player_1.get_name()+"played "+to_string(card_1.get_value())+" of "+card_1.to_string()+" "+player_2.get_name()+" played "+to_string(card_2.get_value())+" of"+player_2.get_name()+"."
            +" drew,end of cards."+"\n";
            total_viictory+=victory;
            cards1_won+=card_1.to_string();
            cards2_won+=card_2.to_string();
            break;
        }
        else if((card_1.get_value()==card_2.get_value())&&player_1.stacksize()>0) {
            this->drew+=1;
            condition = 1;
            cards_to_win+=2;
            card bonus_1 =player_1.showing_card_package();
            card bonus_2=player_2.showing_card_package();
            bonus=""+player_1.get_name()+"played "+to_string(bonus_1.get_value())+" of "+bonus_1.to_string()+" "+player_2.get_name()+" played "+to_string(bonus_2.get_value())+" of"+player_2.get_name()+"."+"\n"
                          +" flipped cards.";
            this->total_viictory+=bonus;
        }
        else if((card_1.get_value()==1&&card_2.get_value()!=2)||card_1.get_value()>card_2.get_value()){
            condition=0;
            player_1.count_cards(cards_to_win);
            this->victory=""+bonus+player_1.get_name()+"played "+to_string(card_1.get_value())+" of "+card_1.to_string()+" "+player_2.get_name()+" played "+to_string(card_2.get_value())+" of"+player_2.get_name()+"."+player_1.get_name()+" wins"+"\n";
            this->total_viictory+=victory;
        }
        else{
            condition=0;
            player_2.count_cards(cards_to_win);
            this->victory=""+bonus+player_2.get_name()+"played "+to_string(card_2.get_value())+" of "+card_2.to_string()+" "+player_1.get_name()+" played "+to_string(card_1.get_value())+" of"+player_1.get_name()+"."+player_2.get_name()+" wins"+"\n";
            this->total_viictory+=victory;
        }

    }



}

void Game::printLastTurn() {
    std::cout << victory <<endl;
}

void  Game::playAll() {
    while(this->player_1.stacksize()>0){
        this->playTurn();
    }
}

void Game::printWiner() {
    if(player_1.stacksize()>0){
        std::cout <<  "the game is still being played" <<endl;
    }
    else{
        if(player_1.cardesTaken()>player_2.cardesTaken()){
            std::cout <<  player_1.get_name() <<endl;
        }
        if(cardtaken_2>cardtaken_1){
            std::cout <<  player_2.get_name() <<endl;
        }
        if(cardtaken_1==cardtaken_2){
            std::cout << "its a drew "<<endl;
        }
    }
}

void Game::printLog() {
    std::cout << total_viictory <<endl;
}

void Game::printStats() {
    std::cout<<""+player_1.get_name()+ " win rate: "+to_string(player_1.cardesTaken()/26*100)+"\n"+cards1_won+"\n"+
    player_2.get_name()+" win rate: "+  to_string(player_2.cardesTaken()/26*100)+"\n"+cards2_won+"\n"+"drew rate: "+ to_string(drew/26*100)<<endl;
}

vector<card> Game::full_pacage() {
    vector<card>pacage;
    for(int i=1;i<53;i++){
        if(i>0&&i<=13){
            pacage.push_back(card(i,"diamond"));
        };
        if(i>13&&i<=26){
            pacage.push_back(card(i-13,"hurt"));
        }
        if(i>26&&i<=39){
            pacage.push_back(card(i-26,"clover"));
        }
        if(i>39&&i<=52){
            pacage.push_back(card(i-39,"leaf"));
        }
    }
    random_shuffle(pacage.begin(), pacage.end());
    return pacage;
}

//cardtaken_1+=2;
//this->victory=""+player_1.get_name()+"played "+to_string(card_player1.get_value())+" of "+card_player1.to_string()+" "+player_2.get_name()+" played "+to_string(card_player2.get_value())+" of"+player_2.get_name()+"."
//              +player_1.get_name()+" wins";
//total_viictory+=victory;
//cards1_won+=card_player1.to_string()+" "+card_player2.to_string();




