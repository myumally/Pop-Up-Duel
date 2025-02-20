#include "../include/Special.hpp"
#include "../include/all_includes.hpp"

Rebound::Rebound(int NbLP, int A, int B, Card* Card){
  nbLP = NbLP;
  a = A;
  b = B;
  card = Card;
}

Color_Boost::Color_Boost(Colour Col, int A, int B, Card* Card){
  col = Col;
  a = A;
  b = B;
  card = Card;
}

Zone_Boost::Zone_Boost(int A, ZoneType Zone, Card* Card){
  a = A;
  zone = Zone;
  card = Card;
}

CP_Boost::CP_Boost(int NbCP, Colour Col, PlayerType Ow, Card* Card){
  nbCP = NbCP;
  CPColour = Col;
  CPOwner = Ow;
  card = Card;
}

CP_Crush::CP_Crush( int NbCP, std::list<Colour> Cols, Card* Card){
  nbCP = NbCP;
  CPColours = Cols;
  card = Card;
}

CP_Drain::CP_Drain(int NbCP, Colour Col, Card* Card){
  nbCP = NbCP;
  CPColour = Col;
  card = Card;
}

Risky_Move::Risky_Move(int A, Colour Col, Card* Card){
  a = A;
  CPColour = Col;
  card = Card;
}

Recover::Recover(int A, int B, Colour Col, PlayerType Ow, Card* Card){
  a = A;
  b = B;
  CPColour = Col;
  CPOwner = Ow;
  card = Card;
}

NothingSpecial::NothingSpecial(Card* Card){
  card = Card;
}

int Rebound::operator()(Player* p1, Player* p2, Card* OpponentCard) const{
  int LP = nbLP;
  if(nbLP == -1)
    LP = p2->getLP();
  int damage = card->getStrength();
  if(p1->getLP() <= LP)
    damage = a * damage + b;
  return damage;
}

int Color_Boost::operator()(Player* p1, Player* p2, Card* OpponentCard) const{
  int damage = card->getStrength();
  if(OpponentCard->getColour() == col)
    damage = a * damage + b;
  return damage;
}

int Zone_Boost::operator()(Player* p1, Player* p2, Card* OpponentCard) const{
  int damage = a * OpponentCard->getNumberOfZoneType(zone);
  return damage;
}

int CP_Boost::operator()(Player* p1, Player* p2, Card* OpponentCard) const{
  Colour col = CPColour;
  if (CPColour == Grey)
    col = OpponentCard->getColour();
  if (CPOwner == Opponent){
    for (int i = 0; i<nbCP; ++i)
      p2->addCP(CPColour);
  }
  else{
    for (int i = 0; i<nbCP; ++i)
      p1->addCP(CPColour);
  }
  return card->getStrength();
}

int CP_Crush::operator()(Player* p1, Player* p2, Card* OpponentCard) const{
  Colour col;
  for(Colour cp : CPColours){
    if(cp == Grey)
      col = p2->getMostAbundantCP();
    if(nbCP < MAX_CP){
      for(int i = 0; i<nbCP; ++i)
        p2->removeCP(col);
    }
    else 
      p2->removeAllSpecificCP(cp);
  }
  return card->getStrength();
}

int CP_Drain::operator()(Player* p1, Player* p2, Card* OpponentCard) const{
  Colour col = CPColour;
  if(CPColour == Grey)
    col = p2->getMostAbundantCP();
  for(int i = 0; i<nbCP; ++i){
    p2->removeCP(col);
    p1->addCP(col);
  }
  return card->getStrength();
}

int Risky_Move::operator()(Player* p1, Player* p2, Card* OpponentCard) const{
  int damage = card->getStrength();
  damage = a * p2->getNumberOfCP(CPColour);
  p1->loseLP(p1->getNumberOfCP(CPColour));
  return damage;
}

int Recover::operator()(Player* p1, Player* p2, Card* OpponentCard) const{
  if(CPOwner == Opponent)
    p1->recoverLP(a * p2->getNumberOfCP(CPColour) + b);
  else 
    p1->recoverLP(a * p1->getNumberOfCP(CPColour) + b);
  return card->getStrength();
}

int NothingSpecial::operator()(Player* p1, Player* p2, Card* OpponentCard) const{
  return card->getStrength();
}
