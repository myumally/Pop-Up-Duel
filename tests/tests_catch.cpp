#include <cstring>

#include "../include/all_includes.hpp"

TEST_CASE("Constructeur Card 1") {
    Card c(1, "monster", "attack", Grey, Red, {Green, Blue}, Nothing, 1);

    CHECK( 1 == c.getId());
    CHECK("monster" == c.getMonsterName());
    CHECK("attack" == c.getAttackName());
    CHECK(Grey == c.getColour());
    CHECK(Sword == c.getRedZone());
    CHECK(Shield == c.getGreenZone());
    CHECK(Shield == c.getBlueZone());
    CHECK(Blank == c.getYellowZone());
    CHECK(true == c.hasSwordAttack());
    CHECK(Nothing == c.getEffect());
    CHECK(1 == c.getStrength());
}

TEST_CASE("Constructeur Card 2") {
    Card c(1, "monster", "attack", Red, Grey, {Green, Yellow}, Nothing, 1);

    CHECK(Red == c.getColour());
    CHECK(false == c.hasSwordAttack());
    CHECK(Nothing == c.getEffect());
}

TEST_CASE("Constructeur Player") {
    Player p1("player1");
    Player p2("player2");

    CHECK( 0 == p1.getId());
    CHECK( 1 == p2.getId());
    CHECK("player1" == p1.getName());
    CHECK(20 == p1.getLP());
}

TEST_CASE("LP Management 1") {
    Player p1("player1");

    CHECK(20 == p1.getLP());

    p1.loseLP(10);

    CHECK(10 == p1.getLP());

    p1.recoverLP(5);

    CHECK(15 == p1.getLP());
}

TEST_CASE("LP Management 2") {
    Player p1("player1");

    CHECK(20 == p1.getLP());

    p1.loseLP(50);

    CHECK(0 == p1.getLP());

    p1.recoverLP(50);

    CHECK(20 == p1.getLP());
}
