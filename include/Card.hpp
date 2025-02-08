#ifndef card__hpp
#define card__hpp

#include <string>
#include <list>

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

  Effect effect = Nothing;
  int strength;

  public :

  Card(int n, std::string monster, std::string attack, Colour c, Colour SwordZone, std::list<Colour> GuardZones, Effect e, int s);

  // Getters and Setters

  int getId() const;
  void setId(int newId);

  std::string getMonsterName() const;
  void setMonsterName(const std::string& newName);

  std::string getAttackName() const;
  void setAttackName(const std::string& newAttackName);

  Colour getColour() const;
  void setColour(Colour newColour);

  ZoneType getRedZone() const;
  void setRedZone(ZoneType newRedZone);

  ZoneType getGreenZone() const;
  void setGreenZone(ZoneType newGreenZone);

  ZoneType getBlueZone() const;
  void setBlueZone(ZoneType newBlueZone);

  ZoneType getYellowZone() const;
  void setYellowZone(ZoneType newYellowZone);

  bool hasSwordAttack() const;
  void setSwordAttack(bool newSword);

  Effect getEffect() const;
  void setEffect(Effect newEffect);

  int getStrength() const;
  void setStrength(int newStrength);

};

#endif
