//
// Created by eliya on 29/03/2023.
//

#include "game.hpp"
#include "card.hpp"
#include "player.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace ariel;


Game::Game(Player player1, Player player2){
    this->player_1=player1;
    this->player_2=player2;
    this->pacage=full_pacage();
    split(player1.get_package(),player2.get_package(),pacage);
    this->cardtaken_1=0;
    this->cardtaken_2=0;
    this->cards1_won;
    this->cards2_won;
    this->drew=0;

}

void Game::playTurn() {
    if(player_1.get_package().size()&&player_2.get_package().size()>0){
        card card_player1=player_1.get_package().back();
        card card_player2=player_2.get_package().back();
        player_1.get_package().pop_back();
        player_2.get_package().pop_back();

        if(card_player1.get_value()>card_player2.get_value()&&card_player2.get_value()==1||card_player1.get_value()==2&&card_player2.get_value()==1||card_player1.get_value()==1&&card_player2.get_value()!=1,2){
            cardtaken_1+=2;
            this->victory=""+player_1.get_name()+"played "+to_string(card_player1.get_value())+" of "+card_player1.to_string()+" "+player_2.get_name()+" played "+to_string(card_player2.get_value())+" of"+player_2.get_name()+"."
            +player_1.get_name()+" wins";
            total_viictory+=victory;
            cards1_won+=card_player1.to_string()+" "+card_player2.to_string();
        }
        if(card_player2.get_value()>card_player1.get_value()&&card_player1.get_value()==1||card_player2.get_value()==2&&card_player1.get_value()==1||card_player2.get_value()==1&&card_player1.get_value()!=1,2){
            cardtaken_2+=2;
            this->victory=""+player_2.get_name()+"played "+to_string(card_player2.get_value())+" of "+card_player2.to_string()+" "+player_1.get_name()+" played "+to_string(card_player1.get_value())+" of"+player_1.get_name()+"."
                    +player_2.get_name()+" wins";
            total_viictory+=victory;
            cards2_won+=card_player2.to_string()+" "+card_player1.to_string();
        }
        if(card_player1.get_value()==2&&card_player2.get_value()==1){
            cardtaken_1+=2;
            this->victory=""+player_1.get_name()+"played "+to_string(card_player1.get_value())+" of "+card_player1.to_string()+" "+player_2.get_name()+" played "+to_string(card_player2.get_value())+" of"+player_2.get_name()+"."
                          +player_1.get_name()+" wins";
            total_viictory+=victory;
            cards1_won+=card_player1.to_string()+" "+card_player2.to_string();
        }
        if(card_player2.get_value()==2&&card_player1.get_value()==1){
            cardtaken_2+=2;
            this->victory=""+player_2.get_name()+"played "+to_string(card_player2.get_value())+" of "+card_player2.to_string()+" "+player_1.get_name()+" played "+to_string(card_player1.get_value())+" of"+player_1.get_name()+"."
                          +player_2.get_name()+" wins";
            total_viictory+=victory;
            cards2_won+=card_player2.to_string()+" "+card_player1.to_string();
        }

        if(card_player1.get_value()==card_player2.get_value()){
            int bonus=0;
            string bonus_string;
            while(card_player1.get_value()==card_player2.get_value()) {
                drew++;
                total_viictory+=""+player_2.get_name()+"played "+to_string(card_player2.get_value())+" of "+card_player2.to_string()+" "+player_1.get_name()+" played "+to_string(card_player1.get_value())+" of"+player_1.get_name()+". its a drew";
                player_1.get_package().pop_back();
                player_2.get_package().pop_back();
                bonus = bonus + 2;
                bonus_string+=card_player2.to_string()+" "+card_player1.to_string();
                card card_player1 = player_1.get_package().back();
                card card_player2 = player_2.get_package().back();
                if(card_player1.get_value()>card_player2.get_value()&&card_player2.get_value()==1||card_player1.get_value()==2&&card_player2.get_value()==1||card_player1.get_value()==1&&card_player2.get_value()!=1,2){
                    cardtaken_1+=bonus+2;
                    this->victory=""+player_1.get_name()+"played "+to_string(card_player1.get_value())+" of "+card_player1.to_string()+" "+player_2.get_name()+" played "+to_string(card_player2.get_value())+" of"+player_2.get_name()+"."
                                  +player_1.get_name()+" wins";
                    total_viictory+=victory;
                    cards1_won+=card_player1.to_string()+" "+card_player2.to_string()+bonus_string;
                }
                if(card_player2.get_value()>card_player1.get_value()&&card_player1.get_value()==1||card_player2.get_value()==2&&card_player1.get_value()==1||card_player2.get_value()==1&&card_player1.get_value()!=1,2){
                    cardtaken_2+=bonus+2;
                    this->victory=""+player_2.get_name()+"played "+to_string(card_player2.get_value())+" of "+card_player2.to_string()+" "+player_1.get_name()+" played "+to_string(card_player1.get_value())+" of"+player_1.get_name()+"."
                                  +player_2.get_name()+" wins";
                    total_viictory+=victory;
                    cards2_won+=card_player2.to_string()+" "+card_player1.to_string()+bonus_string;
                }
                if(card_player1.get_value()==2&&card_player2.get_value()==1){
                    cardtaken_1+=bonus+2;
                    this->victory=""+player_1.get_name()+"played "+to_string(card_player1.get_value())+" of "+card_player1.to_string()+" "+player_2.get_name()+" played "+to_string(card_player2.get_value())+" of"+player_2.get_name()+"."
                                  +player_1.get_name()+" wins";
                    total_viictory+=victory;
                    cards1_won+=card_player1.to_string()+" "+card_player2.to_string()+bonus_string;
                }
                if(card_player2.get_value()==2&&card_player1.get_value()==1){
                    cardtaken_2+=bonus+2;
                    this->victory=""+player_2.get_name()+"played "+to_string(card_player2.get_value())+" of "+card_player2.to_string()+" "+player_1.get_name()+" played "+to_string(card_player1.get_value())+" of"+player_1.get_name()+"."
                                  +player_2.get_name()+" wins";
                    total_viictory+=victory;
                    cards2_won+=card_player2.to_string()+" "+card_player1.to_string()+bonus_string;
                }

            }
        }
        if(card_player1.get_value()==card_player2.get_value()&&player_1.stacksize()==1){
            card card_player1=player_1.get_package().back();
            card card_player2=player_2.get_package().back();
            player_1.get_package().pop_back();
            player_2.get_package().pop_back();
            cardtaken_1++;
            cardtaken_2++;
            cards1_won+=card_player1.to_string()+" "+card_player2.to_string();
            cards2_won+=card_player2.to_string()+" "+card_player1.to_string();
        }

    }
}

void Game::printLastTurn() {
    std::cout << victory <<endl;
}

void  Game::playAll() {
    while(player_1.stacksize()>0){
        this->playTurn();
    }
}

void Game::printWiner() {
    if(player_1.stacksize()>0){
        std::cout <<  "the game is still being played" <<endl;
    }
    else{
        if(cardtaken_1>cardtaken_2){
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
    std::cout<<""+player_1.get_name()+ " win rate: "+to_string(cardtaken_1/26*100)+"\n"+cards1_won+"\n"+
    player_2.get_name()+" win rate: "+  to_string(cardtaken_2/26*100)+"\n"+cards2_won+"\n"+"drew rate: "+ to_string(drew/26*100)<<endl;
}

vector<card> Game::full_pacage() {
    vector<card>pacage;
    for(int i=0;i<52;i++){
        if(i>0&&i<=13){
            pacage.push_back(card(i,"diamond"));
        };
        if(i>0&&i<=26){
            pacage.push_back(card(i,"hurt"));
        }
        if(i>0&&i<=39){
            pacage.push_back(card(i,"clover"));
        }
        if(i>0&&i<=52){
            pacage.push_back(card(i,"leaf"));
        }
    }
    random_shuffle(pacage.begin(), pacage.end());

}

void Game::split(vector<card> package_p1, vector<card> package_p2, vector<card>& package ) {
    for(int i=0;i<52;i++){
        if(i%2==0){
            package_p1.push_back(pacage[i]);
        }
        else{
            package_p2.push_back(pacage[i]);
        }
    }
}




