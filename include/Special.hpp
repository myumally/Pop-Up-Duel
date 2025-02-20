#ifndef special__hpp
#define special__hpp

#include "enum.hpp"
#include <list>

class Card;
class Player;

class ISpecial {
  protected: 
    Card* card;
  public:
    virtual int operator()(Player* p1, Player* p2, Card* OpponentCard) const = 0;
    virtual ~ISpecial() = default;
};


class Rebound : public ISpecial{
  private:
    int nbLP;
    int a;
    int b;

  public:
    Rebound(int NbLP, int A, int B);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};


class Color_Boost : public ISpecial{
  private:
    Colour col;
    int a;
    int b;
  public:
    Color_Boost(Colour Col, int A, int B);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};


class Zone_Boost : public ISpecial{
  private:
    int a;
    ZoneType zone;
  public:
    Zone_Boost(int A, ZoneType Zone);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};


class CP_Boost : public ISpecial{
  private:
    int nbCP;
    Colour CPColour;
    PlayerType CPOwner;
  public:
    CP_Boost(int NbCP, Colour Col, PlayerType Ow);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};


class CP_Crush : public ISpecial{
  private:
    int nbCP;
    std::list<Colour> CPColours;
  public:
    CP_Crush( int NbCP, std::list<Colour> Cols);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};


class CP_Drain : public ISpecial{
  private:
    int nbCP;
    Colour CPColour;
  public:
    CP_Drain(int NbCP, Colour Col);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};


class Risky_Move : public ISpecial{
  private:
    int a;
    Colour CPColour;
  public:
    Risky_Move(int A, Colour Col);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};


class Recover : public ISpecial{
  private:
    int a;
    int b;
    Colour CPColour;
    PlayerType CPOwner;
  public:
    Recover(int A, int B, Colour Col, PlayerType Ow);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};

class NothingSpecial : public ISpecial{
  public:
    NothingSpecial();
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};

#endif
