#include "../include/Player.hpp"

int Player::compteur = 0;

Player::Player(std::string name){
  id = compteur;
  compteur += 1;
  Name = name;
}

Player::Player(Player& p){
  id = compteur;
  compteur += 1;
  Name = p.Name;
}

Player::~Player(){
}


// Getters and Setters

int Player::getId() const {
  return id;
}

std::string Player::getName() const {
  return Name;
}
void Player::setName(const std::string& name) {
  Name = name;
} 

std::list<Card*> Player::getDeck() const {
  return deck;
}

int Player::getLP() const {
  return LP;
}
void Player::setLP(int lp) {
  LP = lp;
}

std::list<Colour*> Player::getCP() const {
  return CP;
}

// LP Management

void Player::recoverLP(int n){
  LP += n;
  if(LP > MAX_LP){
    LP = MAX_LP;
  }
}
void Player::loseLP(int n){
  LP -= n;
  if(LP < 0){
    LP = 0;
  }
}

// Deck Management

void Player::addCard(Card* card) {
  bool b = true;
  std::list<Card*>::iterator it;

  for(it = deck.begin(); it != deck.end(); it++){
    if((*it)->getId() == card->getId()){
      b = false;
    }
  }

  if((deck.size() < DECK_SIZE) && b){
    deck.push_back(card);
  }
}

void Player::removeCard(Card* card) {
  if(!(deck.empty())){
    deck.remove(card);
  }
}

void Player::removeCard(int id) {
  if(!(deck.empty())){
    std::list<Card*>::iterator it;
    for(it = deck.begin(); it != deck.end(); it++){
      if((*it)->getId() == id){
        removeCard(*it);
        break;
      }
    }
  }
}

bool Player::isDeckComplete() const {
  return(deck.size() == DECK_SIZE);
}
