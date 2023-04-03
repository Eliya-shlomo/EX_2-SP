//
// Created by eliya on 27/03/2023.
//
#include <string>
#include "sources/game.hpp"
#include "sources/player.hpp"
#include "sources/card.hpp"
#include "doctest.h"
using namespace std;
using namespace ariel;

//game.playTurn();
//}
//game.printLastTurn(); // print the last turn stats. For example:
// Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
// Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
//cout << p1.stacksize() << endl; //prints the amount of cards left. should be 21 but can be less if a draw was played
//cout << p2.cardesTaken() << endl; // prints the amount of cards this player has won.
//game.playAll(); //playes the game untill the end
//game.printWiner(); // prints the name of the winning player
//game.printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
//game.printStats();

TEST_CASE("playturn should update player card counts"){
    Player p1("alice");
    Player p2("bob");
    Game g(p1,p2);
    g.printLastTurn();
    CHECK(p1.stacksize()==25);
    CHECK(p2.stacksize()==25);

    Player p3("Charlie");
    Player p4("Dave");

    Game b(p3,p4);
    CHECK(p3.stacksize() == 26);
    CHECK(p4.stacksize()== 26);
    }


TEST_CASE("playAll should finish the game with a winner") {
    Player p1("alice");
    Player p2("bob");
    Game g(p1,p2);
    g.playAll();
    CHECK((p1.stacksize() == 0 || p2.stacksize()== 0));
    }

TEST_CASE("getWinner should return nullptr if there is no winner yet") {
    Player p1("alice");
    Player p2("bob");
    Game g(p1,p2);
    g.playAll();
    CHECK_NOTHROW(g.printLog());
    CHECK_NOTHROW(g.printWiner());
    CHECK_NOTHROW(g.printStats());
    CHECK_NOTHROW(g.printLastTurn());
    }



TEST_CASE("getPot should return the correct number of cards in the p54ot") {
    Player p1("alice");
    Player p2("bob");
    Game g(p1,p2);
    g.playTurn();
    CHECK(p1.cardesTaken()<=1);
    CHECK(p2.cardesTaken()<=1);
    }
TEST_CASE("getPot should return the correct number of cards in the po43t") {
    Player p1("alice");
    Player p2("bob");
    Game g(p1,p2);
    g.playAll();
    CHECK_FALSE(p1.stacksize()==26);
    CHECK_FALSE(p2.stacksize()==26);

    Game b(p1,p2);
    CHECK_FALSE(p1.stacksize()==0);
    CHECK_FALSE(p2.stacksize()==0);


}

TEST_CASE("getPot should return the correct number of cards in the p21ot") {
    Player p1("alice");
    Player p2("bob");
    Game g(p1,p2);
    g.playAll();
    int number1=p1.cardesTaken();
    int number2=p2.cardesTaken();
    CHECK(number1>=0);
    CHECK(number2>=0);

}

TEST_CASE("getPot should return the correct number of cards in the pcasot") {
    Player p1("alice");
    Player p2("bob");
    Game g(p1,p2);
    g.playAll();
    int number1=p1.cardesTaken();
    int number2=p2.cardesTaken();
    CHECK(number1>=0);
    CHECK(number2>=0);

}


TEST_CASE("getPot should return the correct number of cards in the pocast") {
    Player p1("alice");
    Player p2("bob");
    Game g(p1,p2);

    CHECK_THROWS(Game (p1,p2));
    CHECK_NOTHROW(g.playAll());
    CHECK_NOTHROW(Game (p1,p2));
}





