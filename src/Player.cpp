#include "../include/Player.hpp"

int Player::compteur = 0;

Player::Player(const std::string& name){
  id = compteur;
  compteur += 1;
  Name = name;
}

Player::Player(const Player& p){
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

std::list<Colour> Player::getCP() const {
  return CP;
}

std::array<Effect, 3> Player::SelfEffect = {Protect, Refresh, Haste};

std::array<Effect, 7> Player::OpponentEffect = {Burn, Freeze, Numb, Poison, Silence, Slow};

Effect Player::isAffectedBySelfEffect() const{
  return AffectedBySelfEffect;
}

Effect Player::isAffectedByOpponentEffect() const{
  return AffectedByOpponentEffect;
}

void Player::setAffectedBy(Effect effect){
  if(std::find(SelfEffect.begin(), SelfEffect.end(), effect) != SelfEffect.end())
    AffectedBySelfEffect = effect;
  else if (std::find(OpponentEffect.begin(), OpponentEffect.end(), effect) != OpponentEffect.end())
    AffectedByOpponentEffect = effect;
  else{
    AffectedBySelfEffect = effect;
    AffectedByOpponentEffect = effect;
  }
}

bool Player::hasPriority() const{
  return Priority;
}
void Player::setPriority(bool b){
  Priority = b;
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

void Player::addCard(int id, std::array<Card*, 122> AllCards) {
  if(!(AllCards.empty())){
    std::array<Card*, 122>::iterator it;
    for(it = AllCards.begin(); it != AllCards.end(); it++){
      if((*it)->getId() == id){
        addCard(*it);
        break;
      }
    }
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

// CP Management

void Player::addCP(const Colour& colour){
  if(colour != Grey){
    if((CP.size() == MAX_CP)){
      CP.pop_front();
    }
    CP.push_back(colour);
  }
}

void Player::removeAllCP(){
  CP.clear();
}

void Player::removeCP(const Colour& colour){
  if(!(CP.empty())){
    std::list<Colour>::iterator it;
    for(it = CP.begin(); it != CP.end(); it++){
      if((*it) == colour){
        CP.erase(it);
        break;
      }
    }
  }
}

void Player::removeAllSpecificCP(const Colour& colour){
  CP.remove(colour);
}

void Player::setAllCP(const Colour& colour){
  int number_of_cp = CP.size();
  CP.clear();
  for(int i = 0; i < number_of_cp; i++){
    addCP(colour);
  }
}

int Player::getNumberOfCP(const Colour& colour) const{
  int n = 0; 
  for (Colour c : CP) {
    if (c == colour) {
      ++n;
    }
  }
  return n;
}

int Player::getNumberOfCP(const std::list<Colour>& colours) const {
  int n = 0;
  for (Colour c : CP) {
    if (std::find(colours.begin(), colours.end(), c) != colours.end()) {
      ++n;
    }
  }
  return n;
}

int Player::getNumberOfMostAbundantCP() const{
  std::array<int, 4> colours = {0};
  for(int i = 1; i < 5; i++){
    colours[i-1] = getNumberOfCP(static_cast<Colour>(i));
  }

  return *std::max_element(colours.begin(), colours.end());
}

