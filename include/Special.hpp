#ifndef special__hpp
#define special__hpp

#include "enum.hpp"
#include <array>
#include <list>

class Card;
class Player;

class ISpecial {
  protected: 
    Card* card;
  public:
    Card* getCard() const;
    virtual int operator()(Player* p1, Player* p2, Card* OpponentCard) const = 0;
    virtual ~ISpecial() = default;
};


class Rebound : public ISpecial{
  private:
    int nbLP;
    int a;
    int b;

  public:
    Rebound(int NbLP, int A, int B, Card* Card);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};


class Color_Boost : public ISpecial{
  private:
    Colour col;
    int a;
    int b;
  public:
    Color_Boost(Colour Col, int A, int B, Card* Card);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};


class Zone_Boost : public ISpecial{
  private:
    int a;
    ZoneType zone;
  public:
    Zone_Boost(int A, ZoneType Zone, Card* Card);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};


class CP_Boost : public ISpecial{
  private:
    int nbCP;
    Colour CPColour;
    PlayerType CPOwner;
  public:
    CP_Boost(int NbCP, Colour Col, PlayerType Ow, Card* Card);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};


class CP_Crush : public ISpecial{
  private:
    int nbCP;
    Colour CPColour;
    SpecialColour SC;
  public:
    CP_Crush( int NbCP, Colour Col, SpecialColour sc, Card* Card);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};


class CP_Drain : public ISpecial{
  private:
    int nbCP;
    Colour CPColour;
  public:
    CP_Drain(int NbCP, Colour Col, Card* Card);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};


class Recover : public ISpecial{
  private:
    int a;
    int b;
    Colour CPColour;
    PlayerType CPOwner;
  public:
    Recover(int A, int B, Colour Col, PlayerType Ow, Card* Card);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};

class NothingSpecial : public ISpecial{
  public:
    NothingSpecial(Card* Card);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};

class CrystalAbility: public ISpecial{
  private:
    std::array<int, 4> CPs;
    ISpecial* Special;
  public:
    CrystalAbility(std::array<int, 4> cps, ISpecial* spec);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};

class CP_Strike : public ISpecial{
  private:
    int a;
    std::list<Colour> CPColours;
    PlayerType CPOwner;
  public:
    CP_Strike(int A, std::list<Colour> Cols, PlayerType ow, Card* Card);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};

class Life_Strike : public ISpecial{
  private:
    int a;
  public:
    Life_Strike(int A, Card* Card);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};

class Risky_Move : public ISpecial{
  private:
    int a1;
    int a2;
    Colour CPColour1;
    Colour CPColour2;
  public:
    Risky_Move(int A1, int A2, Colour Col1, Colour Col2, Card* Card);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};

class Reflect : public ISpecial{
  private:
    int a;
  public:
    Reflect(int A, Card* Card);
    int operator()(Player* p1, Player* p2, Card* OpponentCard) const;
};

#endif
