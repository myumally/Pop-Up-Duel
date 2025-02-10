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

