#include "../include/all_includes.hpp"

std::array<std::string, 21> MonsterNames = {
  "Ifrit", 
  "Bomb", 
  "Lamia", 
  "Phoenix", 
  "Adamantoise", 
  "Cactuar", 
  "Unicorn", 
  "Titan", 
  "Shiva", 
  "Leviathan", 
  "Mist Dragon", 
  "Bismarck", 
  "Carbuncle", 
  "Ramuh", 
  "Cait Sith", 
  "Iron Giant", 
  "Odin", 
  "Bahamut", 
  "Tonberry", 
  "Goblin", 
  "Typhon"
};


std::array<std::string, 122> AttackNames = {
  "Fireblast",
  "Fireblast+",
  "Flame Ward",
  "Scorched Earth",
  "Forest Fire",
  "Hellfire",

  "Fiery Tango",
  "Delta Guard",
  "Self-Destruct",
  "Self-Destruct+",
  "Explode",
  "Explode+",

  "Tail",
  "Song",
  "Maiden's Kiss",
  "Maiden's Kiss+",
  "Entice",
  "Entice+",

  "Fire Strike",
  "Blazing Barrier",
  "Undying Spirit",
  "Undying Spirit+",
  "Flames of Rebirth",
  "Flames of Rebirth+",

  "Turtle Power",
  "Turtle Power+",
  "Miraculous Shell",
  "Miraculous Shell+",
  "Slowspell",
  "Mighty Guard",

  "Spinning Needle",
  "Ambush",
  "Poison Barb",
  "Photosynthesis",
  "Cactuar 1000 Needles",
  "Cactuar 1000 Needles+",

  "Rush",
  "Healing Kick",
  "Fountain Head",
  "Fountain Head+",
  "Gale Strike",
  "Gale Strike+",

  "Gaia's Wrath",
  "Boulder Toss",
  "Earthen Fist",
  "Earthen Fist+",
  "Fissure",
  "Fissure+",

  "Chilling Whisper",
  "Extinguish",
  "Extinguish+",
  "Snow Veil",
  "Diamond Dust",
  "Heavenly Strike",

  "Tail Whip",
  "Thunder Storm",
  "Geyser",
  "Geyser+",
  "Tidal Wave",
  "Tidal Wave+",

  "Mist Breath",
  "Billowing Mist",
  "Aqua Breath",
  "Aqua Breath+",
  "Ice Bind",
  "Ice Bind+",

  "No Mercy",
  "Engulf",
  "Engulf+",
  "Breach Blast",
  "Breach Blast+",
  "Maelstrom",

  "Shining Star",
  "Quickstomp",
  "Ruby Light",
  "Ruby Light+",
  "Holy Guard",
  "Blessed Song",

  "Shock",
  "Thundercloud",
  "EM Field",
  "EM Field+",
  "Judgment Bolt",
  "Judgment Bolt+",

  "Megaphone",
  "Battle Trumpet",
  "Battle Trumpet+",
  "Cat Rain",
  "Marvelous Cheer",
  "Marvelous Cheer+",

  "Fist",
  "Tackle",
  "Beam",
  "Beam+",
  "Overhead Smash",
  "Overhead Smash+",

  "Zantetsuken",
  "Zantetsuken+",
  "Gungnir",
  "Gungnir+",
  "Sleipnir",
  "Dark Blade",

  "Air Strike",
  "Mega Flare",
  "Mega Flare+",
  "Tera Flare",
  "Tera Flare+",
  "Impulse",

  "Poison Cloud",
  "Shadowbind",
  "Knife",
  "Karma",
  "Karma+",

  "Slap",
  "Slap+",
  "Rage",
  "Shout",
  "Meteor",

  "Fireball",
  "Chow Time",
  "Snort",
  "Body Splash"
};


std::array<int, 36> NoSwords = {3, 8, 9, 10, 13, 17, 18, 20, 25, 26, 27, 28, 30, 32, 34, 39, 40, 52, 57, 58, 65, 66, 67, 73, 75, 76, 77, 80, 81, 82, 88, 92, 101, 108, 109, 116 };

std::array<int, 4> RedSword = { 97, 102, 104, 118 };

std::array<int, 6> GreenSword = { 100, 103, 111, 113, 114, 115 };

std::array<int, 4> BlueSword = { 98, 110, 112, 117 };

std::array<int, 5> YellowSword = { 56, 99, 105, 106, 107 };


std::array<int, 34> RedShield = { 8, 9, 10, 13, 25, 26, 50, 51, 52, 53, 54, 58, 59, 60, 61, 62, 65, 66, 67, 68, 70, 72, 75, 76, 82, 91, 92, 95, 96, 101, 106, 112, 114, 116 };

std::array<int, 34> GreenShield = { 1, 3, 4, 5, 7, 8, 9, 13, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 26, 27, 28, 30, 34, 39, 40, 57, 59, 65, 66, 67, 98, 108, 109, 117 };

std::array<int, 37> BlueShield = { 20, 25, 26, 27, 28, 29, 30, 32, 34, 39, 40, 41, 44, 47, 52, 57, 58, 62, 67, 73, 74, 75, 76, 78, 79, 80, 81, 82, 83, 85, 86, 87, 88, 89, 92, 108, 118 };

std::array<int, 30> YellowShield = { 3, 6, 8, 17, 18, 25, 26, 27, 28, 29, 30, 32, 34, 38, 45, 46, 73, 75, 76, 77, 80, 81, 82, 88, 92, 97, 102, 109, 111, 116 };


std::array<Card*, 122> Cards_Creation(){

  std::array<Card*, 122> ALL_CARDS;

  for(int i = 0; i < 122; i++){
    ALL_CARDS[i] = new Card (i+1, "monster", AttackNames[i], Grey, Grey, {}, Nothing, 1); 
  }


  for(int i = 0; i < 108; i++){
    ALL_CARDS[i]->setMonsterName(MonsterNames[i/6]);
    ALL_CARDS[i]->setColour(static_cast<Colour>((1 + i/24)%5));
  }

  for(int i = 0; i < 10; i++){
    ALL_CARDS[108 + i]->setMonsterName(MonsterNames[18 + i/5]);
    ALL_CARDS[108 + i]->setColour(Grey);
  }

  for(int i = 0; i < 4; i++){
    ALL_CARDS[118 + i]->setMonsterName(MonsterNames[20]);
    ALL_CARDS[118 + i]->setColour(static_cast<Colour>(1 + i));
  }

  for (int i = 0; i < 122; ++i) {        
    if (isInArray(i+1, RedSword)) {
      ALL_CARDS[i]->setSwordZone(Red);
    } 
    else if (isInArray(i+1, GreenSword)) {
      ALL_CARDS[i]->setSwordZone(Green);
    } 
    else if (isInArray(i+1, BlueSword)) {
      ALL_CARDS[i]->setSwordZone(Blue);
    } 
    else if (isInArray(i+1, YellowSword)) {
      ALL_CARDS[i]->setSwordZone(Yellow);
    } 
    else if (!(isInArray(i+1, NoSwords))) {
      ALL_CARDS[i]->setSwordZone(ALL_CARDS[i]->getColour());
    } 
  }

  for (int i = 0; i < 122; ++i) {        
    if (isInArray(i+1, RedShield)) {
      ALL_CARDS[i]->setRedZone(Shield);
    } 
    if (isInArray(i+1, GreenShield)) {
      ALL_CARDS[i]->setGreenZone(Shield);
    } 
    if (isInArray(i+1, BlueShield)) {
      ALL_CARDS[i]->setBlueZone(Shield);
    } 
    if (isInArray(i+1, YellowShield)) {
      ALL_CARDS[i]->setYellowZone(Shield);
    } 
  }

  return ALL_CARDS;

}
