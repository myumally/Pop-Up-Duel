#include "../include/Card.hpp"

Card::Card(int n, std::string monster, std::string attack, Colour c, Colour SwordZone, std::list<Colour> GuardZones, Effect e, int s){

  // Card

  id = n;
  MonsterName = monster;
  AttackName = attack;
  colour = c;

  // Zones 

  SwordAttack = true;

  switch (SwordZone) {
    case 1:
      RedZone = Sword; 
      break;
    case 2:
      GreenZone = Sword; 
      break;
    case 3:
      BlueZone = Sword; 
      break;
    case 4:
      YellowZone = Sword; 
      break;
    default:
      SwordAttack = false;
        break;
  }

  for(Colour col : GuardZones){
    switch (col) {
      case 1:
        RedZone = Shield; 
        break;
      case 2:
        GreenZone = Shield; 
        break;
      case 3:
        BlueZone = Shield; 
        break;
      case 4:
        YellowZone = Shield; 
        break;
      default:
        break;
    }
  }

  // Attack and Effects

  effect = e;
  strength = s;
}

Card::Card(Card& c){

  // Card

  id = c.getId();
  MonsterName = c.getMonsterName();
  AttackName = c.getMonsterName();
  colour = c.getColour();

  // Zones 

  SwordAttack = c.hasSwordAttack();
  RedZone = c.getRedZone(); 
  GreenZone = c.getGreenZone();
  BlueZone = c.getBlueZone();
  YellowZone = c.getYellowZone(); 

  // Attack and Effects

  effect = c.getEffect();
  strength = c.getEffect();
}

Card::~Card(){

}


// Getter and Setter

int Card::getId() const {
  return id;
}
void Card::setId(int newId) {
  id = newId;
}

std::string Card::getMonsterName() const {
  return MonsterName;
}
void Card::setMonsterName(const std::string& newName) {
  MonsterName = newName;
}

std::string Card::getAttackName() const {
  return AttackName;
}
void Card::setAttackName(const std::string& newAttackName) {
  AttackName = newAttackName;
}

Colour Card::getColour() const {
  return colour;
}
void Card::setColour(const Colour& newColour) {
  colour = newColour;
}

ZoneType Card::getRedZone() const {
  return RedZone;
}
void Card::setRedZone(const ZoneType& newRedZone) {
  RedZone = newRedZone;
}

ZoneType Card::getGreenZone() const {
  return GreenZone;
}
void Card::setGreenZone(const ZoneType& newGreenZone) {
  GreenZone = newGreenZone;
}

ZoneType Card::getBlueZone() const {
  return BlueZone;
}
void Card::setBlueZone(const ZoneType& newBlueZone) {
  BlueZone = newBlueZone;
}

ZoneType Card::getYellowZone() const {
  return YellowZone;
}
void Card::setYellowZone(const ZoneType& newYellowZone) {
  YellowZone = newYellowZone;
}

int Card::getNumberOfZoneType(const ZoneType& type) const{
  int n = 0;
  if(RedZone == type) ++n;
  if(GreenZone == type) ++n;
  if(BlueZone == type) ++n;
  if(YellowZone == type) ++n;
  return n;
}

bool Card::hasSwordAttack() const {
  return SwordAttack;
}
void Card::setSwordAttack(bool b) {
  SwordAttack = b;
}

Effect Card::getEffect() const {
  return effect;
}
void Card::setEffect(const Effect& newEffect) {
  effect = newEffect;
}

int Card::getStrength() const {
  return strength;
}
void Card::setStrength(int newStrength) {
  strength = newStrength;
}

void Card::toStream(std::ostream& os) const{
    os<<"Monster Name: " << MonsterName <<" Attack Name: " << AttackName <<" id: " << id <<" Colour: " << colour;
}
