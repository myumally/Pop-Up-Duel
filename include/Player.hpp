#ifndef player__hpp
#define player__hpp

#include <string>
#include <list>
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
  std::list<Colour*> CP;

  public :

  Player(std::string name);

  // Getters and Setters

  int getId() const;

  std::string getName() const;
  void setName(const std::string& name);

  std::list<Card*> getDeck();

  int getLP() const;
  void setLP(int lp);

  std::list<Colour*> getCP() const; 

  void recoverLP(int n);
  void loseLP(int n); 

 };

#endif
