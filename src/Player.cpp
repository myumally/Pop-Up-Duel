#include "../include/Player.hpp"

int Player::compteur = 0;

Player::Player(std::string name){
  id = compteur;
  compteur += 1;
  Name = name;
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

std::list<Card*> Player::getDeck() {
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

