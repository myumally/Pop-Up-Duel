#ifndef card__hpp
#define card__hpp

#include <string>
#include <list>
#include <iostream>

enum ZoneType {Blank, Sword, Shield};

enum Colour {Grey, Red, Green, Blue, Yellow};

enum Effect {Nothing, Burn, Freeze, Numb, Poison, Silence, Protect, Haste, Slow};

enum Special {
  Crystal_Ability,
  Rebound,
  Color_Boost,
  Zone_Boost,
  CP_Boost,
  CP_Crush,
  CP_Drain,
  Risky_Move,
  Recover,
  Refresh
};

// To-Do : gérer les spéciaux

class Card{

  int id;
  std::string MonsterName;
  std::string AttackName;
  Colour colour;

  ZoneType RedZone = Blank;
  ZoneType GreenZone = Blank;
  ZoneType BlueZone = Blank;
  ZoneType YellowZone = Blank;
  bool SwordAttack;
  Colour SwordZone;

  Effect effect = Nothing;
  int strength;

  public :

  Card(int n, std::string monster, std::string attack, Colour c, Colour swordZone, std::list<Colour> GuardZones, Effect e, int s);
  Card(Card& c);
  ~Card();

  // Getters and Setters

  int getId() const;
  void setId(int newId);

  std::string getMonsterName() const;
  void setMonsterName(const std::string& newName);

  std::string getAttackName() const;
  void setAttackName(const std::string& newAttackName);

  Colour getColour() const;
  void setColour(const Colour& newColour);

  void setSwordZone(const Colour& swordZone);
  Colour getSwordZone() const;

  ZoneType getRedZone() const;
  void setRedZone(const ZoneType& newRedZone);

  ZoneType getGreenZone() const;
  void setGreenZone(const ZoneType& newGreenZone);

  ZoneType getBlueZone() const;
  void setBlueZone(const ZoneType& newBlueZone);

  ZoneType getYellowZone() const;
  void setYellowZone(const ZoneType& newYellowZone);

  int getNumberOfZoneType(const ZoneType& type) const;

  bool hasSwordAttack() const;
  void setSwordAttack(bool newSword);

  Effect getEffect() const;
  void setEffect(const Effect& newEffect);

  int getStrength() const;
  void setStrength(int newStrength);

  void toStream(std::ostream& os = std::cout) const;

};

#endif
