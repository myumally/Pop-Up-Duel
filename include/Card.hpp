#ifndef card__hpp
#define card__hpp

#include <string>
#include <list>
#include <array>
#include <iostream>
#include "enum.hpp"

#include "Special.hpp"

// To-Do : gérer les spéciaux
// To-Do : Crystal Ability

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
  std::array<ZoneType, 4> Zones;

  Effect effect = Nothing;
  int strength;

  ISpecial* special;

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

  std::array<ZoneType, 4> getZones() const;

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

  ISpecial* getSpecial() const;
  void setSpecial(ISpecial*  newSpecial);

  void toStream(std::ostream& os = std::cout) const;

};

#endif
