#include "../include/catch.hpp"
#include <cstring>
#include "../include/Card.hpp"
#include "../src/Card.cpp"

TEST_CASE("Constructeur") {
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

