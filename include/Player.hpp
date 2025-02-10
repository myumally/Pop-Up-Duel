#ifndef player__hpp
#define player__hpp

#include <string>
#include <list>
#include <array>
#include <algorithm>
#include "../include/Card.hpp"

const int DECK_SIZE = 15;
const int MAX_LP = 20;
const int MAX_CP = 10;

class Player{

  static int compteur;

  int id;
  std::string Name;
  std::list<Card*> deck;

  int LP = MAX_LP;
  std::list<Colour> CP;

  Effect AffectedBy = Nothing;

  public :

  Player(const std::string& name);
  Player(const Player& p);
  ~Player();

  // Getters and Setters

  int getId() const;

  std::string getName() const;
  void setName(const std::string& name);

  std::list<Card*> getDeck() const;

  int getLP() const;
  void setLP(int lp);

  std::list<Colour> getCP() const;

  Effect isAffectedBy() const;
  void setAffectedBy(Effect effect);

  void recoverLP(int n);
  void loseLP(int n); 

  void addCard(Card* card);
  void removeCard(Card* card);
  void removeCard(int id);
  bool isDeckComplete() const;

  void addCP(const Colour colour);
  void removeCP(const Colour colour);
  void removeAllCP();
  void removeAllSpecificCP(const Colour c);
  void setAllCP(const Colour colour);
  int getNumberOfCP(const Colour& colour) const;
  int getNumberOfCP(const std::list<Colour>& colours) const;
  int getNumberOfMostAbundantCP() const;

 };

#endif
