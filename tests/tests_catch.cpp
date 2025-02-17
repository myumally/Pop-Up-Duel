#include "../include/all_includes.hpp"
#include "catch.hpp"

#include "../src/Card.cpp"
#include "../src/Player.cpp"
#include "../src/All_Cards.cpp"

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
    CHECK(Red == c.getSwordZone());
    CHECK(std::array<ZoneType, 4>{Sword, Shield, Shield, Blank} == c.getZones());

    CHECK(Nothing == c.getEffect());
    CHECK(1 == c.getStrength());
}

TEST_CASE("Constructeur Card 2") {
    Card c(1, "monster", "attack", Red, Grey, {Green, Yellow}, Nothing, 1);

    CHECK(Red == c.getColour());
    CHECK(false == c.hasSwordAttack());
    CHECK(Nothing == c.getEffect());
    CHECK(0 == c.getNumberOfZoneType(Sword));
    CHECK(2 == c.getNumberOfZoneType(Shield));
    CHECK(2 == c.getNumberOfZoneType(Blank));
    CHECK(Grey == c.getSwordZone());
}

TEST_CASE("Constructeur Card 3") {
    Card c(1, "monster", "attack", Red, Red, {}, Nothing, 1);

    CHECK(Red == c.getColour());
    CHECK(c.hasSwordAttack());
    CHECK(Red == c.getSwordZone());
    CHECK(Nothing == c.getEffect());
    CHECK(1 == c.getNumberOfZoneType(Sword));
    CHECK(0 == c.getNumberOfZoneType(Shield));
    CHECK(3 == c.getNumberOfZoneType(Blank));
}

TEST_CASE("Constructeur Player") {
    Player p1("player1");
    Player p2("player2");

    CHECK( 0 == p1.getId());
    CHECK( 1 == p2.getId());
    CHECK("player1" == p1.getName());
    CHECK(20 == p1.getLP());
    CHECK(Nothing == p1.isAffectedBySelfEffect());
    CHECK(Nothing == p1.isAffectedByOpponentEffect());
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

TEST_CASE("Deck Management 1") {
    Player p1("player1");

    CHECK(false == p1.isDeckComplete());

    for(int i = 0; i < DECK_SIZE + 5; i++){
      p1.addCard( new Card(i, "monster", "attack", Red, Grey, {Green, Yellow}, Nothing, 1));
    }

    CHECK(p1.isDeckComplete());
}

TEST_CASE("Deck Management 2") {
    Player p1("player1");

    for(int i = 0; i < DECK_SIZE + 5; i++){
      p1.addCard( new Card(4, "monster", "attack", Red, Grey, {Green, Yellow}, Nothing, 1));
    }

    CHECK(false == p1.isDeckComplete());
    CHECK(1 == p1.getDeck().size());

}

TEST_CASE("Deck Management 3") {
    Player p1("player1");

    for(int i = 0; i < DECK_SIZE; i++){
      p1.addCard( new Card(i, "monster", "attack", Red, Grey, {Green, Yellow}, Nothing, 1));
    }

    std::list<Card*> deck = p1.getDeck();
    
    std::list<Card*>::iterator it = deck.begin();
    for (int i = 0; i < 15; ++i, ++it) {
        CHECK(i == (*it)->getId());
    }
}

TEST_CASE("Deck Management 4") {
    Player p1("player1");

    for(int i = 0; i < DECK_SIZE; i++){
      p1.addCard( new Card(i, "monster", "attack", Red, Grey, {Green, Yellow}, Nothing, 1));
    }

    p1.removeCard(5);

    CHECK( 14 == p1.getDeck().size());
 
}

TEST_CASE("Deck Management 5") {
    Player p1("player1");

    for(int i = 0; i < DECK_SIZE; i++){
      p1.addCard( new Card(i, "monster", "attack", Red, Grey, {Green, Yellow}, Nothing, 1));
    }

    for(int i = 0; i < DECK_SIZE; i++){
      p1.removeCard(i);
    }

    CHECK( 0 == p1.getDeck().size());
 
}

TEST_CASE("CP Management 1") {
    Player p1("player1");

    for(int i = 0; i < MAX_CP + 5; i++){
      p1.addCP(Red);
    }

    CHECK( MAX_CP == p1.getCP().size());
}

TEST_CASE("CP Management 2") {
    Player p1("player1");

    for(int i = 0; i < MAX_CP; i++){
      p1.addCP(Grey);
    }

    p1.addCP(Red);

    CHECK( 1 == p1.getCP().size());
}

TEST_CASE("CP Management 3") {
    Player p1("player1");

    for(int i = 0; i < 3; i++){
      p1.addCP(Red);
      p1.addCP(Blue);
      p1.addCP(Green);
    }

    p1.removeAllSpecificCP(Blue);
    CHECK( 6 == p1.getCP().size());

    p1.removeCP(Blue);
    CHECK( 6 == p1.getCP().size());

    p1.removeCP(Red);
    CHECK( 5 == p1.getCP().size());

    p1.removeAllCP();
    CHECK( 0 == p1.getCP().size());
}

TEST_CASE("CP Management 4") {
    Player p1("player1");

    for(int i = 0; i < 3; i++){
      p1.addCP(Red);
      p1.addCP(Blue);
      p1.addCP(Green);
    }

    CHECK( 3 == p1.getNumberOfCP(Blue));

    p1.removeCP(Blue);
    CHECK( 2 ==  p1.getNumberOfCP(Blue));
    CHECK( 5 ==  p1.getNumberOfCP({Blue, Green}));
    CHECK( 3 == p1.getNumberOfMostAbundantCP());

    p1.setAllCP(Blue);
    CHECK( 8 ==  p1.getNumberOfCP(Blue));
    CHECK( 8 == p1.getNumberOfMostAbundantCP());

    p1.removeAllCP();
    CHECK( 0 == p1.getNumberOfMostAbundantCP());
}

TEST_CASE("All Cards 1") {
    std::array<Card*, 122> AllCards = Cards_Creation();


    CHECK( 1 == AllCards[0]->getId());
    CHECK("Ifrit" == AllCards[0]->getMonsterName());
    CHECK("Fireblast" == AllCards[0]->getAttackName());

    CHECK(Red == AllCards[0]->getColour());
    CHECK(Red == AllCards[0]->getSwordZone());
    CHECK(std::array<ZoneType, 4>{Sword, Shield, Blank, Blank} == AllCards[0]->getZones());

    CHECK(Sword == AllCards[0]->getRedZone());
    CHECK(Shield == AllCards[0]->getGreenZone());
    CHECK(Blank == AllCards[0]->getBlueZone());
    CHECK(Blank == AllCards[0]->getYellowZone());
    CHECK(true == AllCards[0]->hasSwordAttack());


    CHECK( 12 == AllCards[11]->getId());
    CHECK("Bomb" == AllCards[11]->getMonsterName());
    CHECK("Explode+" == AllCards[11]->getAttackName());

    CHECK(Red == AllCards[11]->getColour());
    CHECK(Red == AllCards[11]->getSwordZone());
    CHECK(std::array<ZoneType, 4>{Sword, Blank, Blank, Blank} == AllCards[11]->getZones());

    CHECK(Sword == AllCards[11]->getRedZone());
    CHECK(Blank == AllCards[11]->getGreenZone());
    CHECK(Blank == AllCards[11]->getBlueZone());
    CHECK(Blank == AllCards[11]->getYellowZone());
    CHECK(true == AllCards[11]->hasSwordAttack());


    CHECK( 56 == AllCards[55]->getId());
    CHECK("Leviathan" == AllCards[55]->getMonsterName());
    CHECK("Thunder Storm" == AllCards[55]->getAttackName());

    CHECK(Blue == AllCards[55]->getColour());
    CHECK(Yellow == AllCards[55]->getSwordZone());
    CHECK(std::array<ZoneType, 4>{Blank, Blank, Blank, Sword} == AllCards[55]->getZones());

    CHECK(Blank == AllCards[55]->getRedZone());
    CHECK(Blank == AllCards[55]->getGreenZone());
    CHECK(Blank == AllCards[55]->getBlueZone());
    CHECK(Sword == AllCards[55]->getYellowZone());
    CHECK(true == AllCards[55]->hasSwordAttack());


    CHECK( 109 == AllCards[108]->getId());
    CHECK("Tonberry" == AllCards[108]->getMonsterName());
    CHECK("Poison Cloud" == AllCards[108]->getAttackName());

    CHECK(Grey == AllCards[108]->getColour());
    CHECK(Grey == AllCards[108]->getSwordZone());
    CHECK(std::array<ZoneType, 4>{Blank, Shield, Blank, Shield} == AllCards[108]->getZones());

    CHECK(Blank == AllCards[108]->getRedZone());
    CHECK(Shield == AllCards[108]->getGreenZone());
    CHECK(Blank == AllCards[108]->getBlueZone());
    CHECK(Shield == AllCards[108]->getYellowZone());
    CHECK(false == AllCards[108]->hasSwordAttack());


    CHECK( 120 == AllCards[119]->getId());
    CHECK("Typhon" == AllCards[119]->getMonsterName());
    CHECK("Chow Time" == AllCards[119]->getAttackName());

    CHECK(Green == AllCards[119]->getColour());
    CHECK(Green == AllCards[119]->getSwordZone());
    CHECK(std::array<ZoneType, 4>{Blank, Sword, Blank, Blank} == AllCards[119]->getZones());

    CHECK(Blank == AllCards[119]->getRedZone());
    CHECK(Sword == AllCards[119]->getGreenZone());
    CHECK(Blank == AllCards[119]->getBlueZone());
    CHECK(Blank == AllCards[119]->getYellowZone());
    CHECK(true == AllCards[119]->hasSwordAttack());


    CHECK( 122 == AllCards[121]->getId());
    CHECK("Typhon" == AllCards[121]->getMonsterName());
    CHECK("Body Splash" == AllCards[121]->getAttackName());

    CHECK(Yellow == AllCards[121]->getColour());
    CHECK(Yellow == AllCards[121]->getSwordZone());
    CHECK(std::array<ZoneType, 4>{Blank, Blank, Blank, Sword} == AllCards[121]->getZones());

    CHECK(Blank == AllCards[121]->getRedZone());
    CHECK(Blank == AllCards[121]->getGreenZone());
    CHECK(Blank == AllCards[121]->getBlueZone());
    CHECK(Sword == AllCards[121]->getYellowZone());
    CHECK(true == AllCards[121]->hasSwordAttack());
}

TEST_CASE("Deck Management x AllCards") {
    std::array<Card*, 122> AllCards = Cards_Creation();
    Player p1("player1");

    for(int i = 0; i < DECK_SIZE; i++){
      p1.addCard( i+6, AllCards);
    }

    std::list<Card*> deck = p1.getDeck();
    
    std::list<Card*>::iterator it = deck.begin();
    for (int i = 0; i < 15; ++i, ++it) {
        CHECK(i+6 == (*it)->getId());
    }

    for(int i = 0; i < DECK_SIZE; i++){
      p1.removeCard(i+6);
    }

    CHECK( 0 == p1.getDeck().size());
}

TEST_CASE("All Cards 2") {
    std::array<Card*, 122> AllCards = Cards_Creation();
    CHECK(Nothing == AllCards[0]->getEffect());
    CHECK(Silence == AllCards[13]->getEffect());
    CHECK(Poison == AllCards[27]->getEffect());
    CHECK(Refresh == AllCards[62]->getEffect());
    CHECK(Numb == AllCards[80]->getEffect());
    CHECK(Haste == AllCards[100]->getEffect());
    CHECK(Slow == AllCards[109]->getEffect());
    CHECK(Protect == AllCards[29]->getEffect());
    CHECK(Freeze == AllCards[120]->getEffect());
    CHECK(Burn == AllCards[118]->getEffect());
}

