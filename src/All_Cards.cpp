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


std::array<int, 33> RedShield = { 8, 9, 10, 13, 25, 26, 50, 51, 52, 53, 54, 59, 60, 61, 62, 65, 66, 67, 68, 70, 72, 75, 76, 82, 91, 92, 95, 96, 101, 106, 112, 114, 116 };

std::array<int, 35> GreenShield = { 1, 3, 4, 5, 7, 8, 9, 13, 15, 16, 17, 18, 19, 20, 21, 23, 24, 25, 26, 27, 28, 30, 34, 39, 40, 57, 58, 59, 65, 66, 67, 98, 108, 109, 117 };

std::array<int, 37> BlueShield = { 20, 25, 26, 27, 28, 29, 30, 32, 34, 39, 40, 41, 44, 47, 52, 57, 58, 62, 67, 73, 74, 75, 76, 78, 79, 80, 81, 82, 83, 85, 86, 87, 88, 89, 92, 108, 118 };

std::array<int, 30> YellowShield = { 3, 6, 8, 17, 18, 25, 26, 27, 28, 29, 30, 32, 34, 38, 45, 46, 73, 75, 76, 77, 80, 81, 82, 88, 92, 97, 102, 109, 111, 116 };

int c = 0; // crystal ability

std::array<int, 122> Strength = { 
  3, 3, 0, 2, 0, 7,
  2, 0, 0, 0, 6, 8,
  1, 3, 3, 4, 2, 3,
  0, 2, 3, 3, 3, 3,

  0, 0, 3, 2, 3, 0,
  3, 3, 3, 0, 5, 6,
  3, 2, 0, 0, 0, 0,
  4, 3, 5, 7, 0, 0,

  3, 3, 3, 0, 8, 0,
  2, 2, 0, 0, 0, 0,
  2, 0, 3, 2, 2, 2,
  2, 3, 3, 0, 0, 0,

  2, 4, c, c, 0, 2,
  0, 4, 0, 1, 6, 9,
  3, 3, 4, 3, 0, 0,
  4, 5, 5, 0, 3, 4,

  c, c, 0, 3, 7, 0, 
  5, 5, 5, 0, 0, 3,
  3, 5, 0, 0, 0,
  2, 5, 1, 2, 6,

  0, 0, 0, 0
};

std::array<int, 6> BurnEffect = { 6, 7, 8, 16, 118, 119 };

std::array<int, 5> PoisonEffect = { 28, 33, 36, 109, 120 };

std::array<int, 4> FreezeEffect = { 49, 65, 108, 121 };

std::array<int, 4> NumbEffect = { 81, 86, 105, 122 };

std::array<int, 4> SilenceEffect = { 14, 37, 61, 73 };

std::array<int, 3> ProtectEffect = { 20, 30, 85 };

std::array<int, 2> RefreshEffect = { 38, 63 };

std::array<int, 3> HasteEffect = { 31, 74, 101 };

std::array<int, 3> SlowEffect = { 29, 92, 110 };


std::array<Card*, 122> Cards_Creation(){

  std::array<Card*, 122> ALL_CARDS;

  for(int i = 0; i < 122; i++){
    ALL_CARDS[i] = new Card (i+1, "monster", AttackNames[i], Grey, Grey, {}, Nothing, Strength[i]); 
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

  for (int i = 0; i < 122; ++i) {        
    if (isInArray(i+1, BurnEffect)) {
      ALL_CARDS[i]->setEffect(Burn);
    } 
    else if (isInArray(i+1, PoisonEffect)) {
      ALL_CARDS[i]->setEffect(Poison);
    } 
    else if (isInArray(i+1, FreezeEffect)) {
      ALL_CARDS[i]->setEffect(Freeze);
    } 
    else if (isInArray(i+1, NumbEffect)) {
      ALL_CARDS[i]->setEffect(Numb);
    } 
    else if (isInArray(i+1, SilenceEffect)) {
      ALL_CARDS[i]->setEffect(Silence);
    }
    else if (isInArray(i+1, ProtectEffect)) {
      ALL_CARDS[i]->setEffect(Protect);
    }
    else if (isInArray(i+1, RefreshEffect)) {
      ALL_CARDS[i]->setEffect(Refresh);
    }
    else if (isInArray(i+1, HasteEffect)) {
      ALL_CARDS[i]->setEffect(Haste);
    }
    else if (isInArray(i+1, SlowEffect)) {
      ALL_CARDS[i]->setEffect(Slow);
    }
  }

  // Rebound
  ALL_CARDS[1]->setSpecial(new Rebound(5, 2, 0, ALL_CARDS[1]));
  ALL_CARDS[94]->setSpecial(new Rebound(-1, 2, 0, ALL_CARDS[94]));
  ALL_CARDS[95]->setSpecial(new Rebound(5, 2, 0, ALL_CARDS[95]));
  ALL_CARDS[111]->setSpecial(new Rebound(7, 0, 7, ALL_CARDS[111]));
  ALL_CARDS[112]->setSpecial(new Rebound(3, 0, 10, ALL_CARDS[112]));

  // Color_Boost
  ALL_CARDS[2]->setSpecial(new Color_Boost(Green, 0, 3, ALL_CARDS[2]));
  ALL_CARDS[25]->setSpecial(new Color_Boost(Grey, 0, 4, ALL_CARDS[25]));
  ALL_CARDS[51]->setSpecial(new Color_Boost(Red, 0, 4, ALL_CARDS[51]));
  ALL_CARDS[79]->setSpecial(new Color_Boost(Blue, 2, 0, ALL_CARDS[79]));
  ALL_CARDS[86]->setSpecial(new Color_Boost(Grey, 2, 0, ALL_CARDS[86]));

  // Zone_Boost
  ALL_CARDS[18]->setSpecial(new Zone_Boost(2, Shield, ALL_CARDS[18]));
  ALL_CARDS[40]->setSpecial(new Zone_Boost(2, Blank, ALL_CARDS[40]));
  ALL_CARDS[41]->setSpecial(new Zone_Boost(4, Shield, ALL_CARDS[41])); 
  ALL_CARDS[98]->setSpecial(new Zone_Boost(3, Shield, ALL_CARDS[98]));

  // CP_Boost
  ALL_CARDS[22]->setSpecial(new CP_Boost(3, Grey, NotOpponent, ALL_CARDS[22]));
  ALL_CARDS[23]->setSpecial(new CP_Boost(MAX_CP, Red, NotOpponent, ALL_CARDS[23])); 
  ALL_CARDS[81]->setSpecial(new CP_Boost(MAX_CP, Yellow, NotOpponent, ALL_CARDS[81]));

  // CP_Crush
  ALL_CARDS[3]->setSpecial(new CP_Crush(3, Green, No, ALL_CARDS[3]));
  ALL_CARDS[12]->setSpecial(new CP_Crush(2, Grey, OppCard, ALL_CARDS[12]));
  ALL_CARDS[17]->setSpecial(new CP_Crush(5, Grey, OppCard, ALL_CARDS[17]));
  ALL_CARDS[31]->setSpecial(new CP_Crush(2, Blue, No, ALL_CARDS[31]));
  ALL_CARDS[43]->setSpecial(new CP_Crush(2, Green, No, ALL_CARDS[43]));
  ALL_CARDS[55]->setSpecial(new CP_Crush(2, Grey, OppCard, ALL_CARDS[55]));
  ALL_CARDS[66]->setSpecial(new CP_Crush(2, Green, No, ALL_CARDS[66]));
  ALL_CARDS[68]->setSpecial(new CP_Crush(MAX_CP, Grey, MostAbundant, ALL_CARDS[68]));
  ALL_CARDS[77]->setSpecial(new CP_Crush(MAX_CP, Grey, MostAbundant, ALL_CARDS[77]));
  ALL_CARDS[87]->setSpecial(new CP_Crush(MAX_CP, Grey, MostAbundant, ALL_CARDS[87]));
  ALL_CARDS[99]->setSpecial(new CP_Crush(MAX_CP, Grey, MostAbundant, ALL_CARDS[99]));

  // CP_Drain
  ALL_CARDS[16]->setSpecial(new CP_Drain(3, Red, ALL_CARDS[16]));
  ALL_CARDS[54]->setSpecial(new CP_Drain(3, Blue, ALL_CARDS[54]));
  ALL_CARDS[65]->setSpecial(new CP_Drain(2, Blue, ALL_CARDS[65]));
  ALL_CARDS[67]->setSpecial(new CP_Drain(3, Blue, ALL_CARDS[67]));

  // Risky_Move
  ALL_CARDS[8]->setSpecial(new Risky_Move(2, 1, Red, Red, ALL_CARDS[8]));
  ALL_CARDS[9]->setSpecial(new Risky_Move(3, 1, Red, Red, ALL_CARDS[9]));

  // Recover
  ALL_CARDS[20]->setSpecial(new Recover(2, 0, Red, NotOpponent, ALL_CARDS[20]));
  ALL_CARDS[21]->setSpecial(new Recover(3, 0, Red, NotOpponent, ALL_CARDS[21]));
  ALL_CARDS[33]->setSpecial(new Recover(2, 0, Yellow, Opponent, ALL_CARDS[33]));
  ALL_CARDS[61]->setSpecial(new Recover(2, 0, Blue, NotOpponent, ALL_CARDS[61])); 
  ALL_CARDS[76]->setSpecial(new Recover(0, 10, Grey, NotOpponent, ALL_CARDS[76]));

  // CP_Strike
  ALL_CARDS[80]->setSpecial(new CP_Strike(1, {Blue}, Opponent, ALL_CARDS[80]));
  for (int i = 0; i < 4; ++i)
    ALL_CARDS[118 + i]->setSpecial(new CP_Strike(2, {static_cast<Colour>(i + 1)}, NotOpponent, ALL_CARDS[118 + i]));

  // CrystalAbility
  ALL_CARDS[4]->setSpecial(new CrystalAbility( {1, 1, 0, 0}, new CP_Strike(3, {Green}, Opponent, ALL_CARDS[4]) ));
  ALL_CARDS[5]->setSpecial(new CrystalAbility( {2, 0, 0, 2}, new NothingSpecial(ALL_CARDS[5]) ));

  ALL_CARDS[10]->setSpecial(new CrystalAbility( {3, 0, 0, 0}, new CP_Crush(MAX_CP, Red, No, ALL_CARDS[10]) ));
  ALL_CARDS[11]->setSpecial(new CrystalAbility( {5, 0, 0, 0}, new CP_Crush(MAX_CP, Grey, All, ALL_CARDS[11]) ));

  ALL_CARDS[14]->setSpecial(new CrystalAbility( {1, 0, 1, 0}, new Recover(0, 4, Grey, NotOpponent, ALL_CARDS[14]) ));
  ALL_CARDS[15]->setSpecial(new CrystalAbility( {1, 0, 1, 0}, new NothingSpecial(ALL_CARDS[15]) ));
  

  ALL_CARDS[26]->setSpecial(new CrystalAbility( {0, 1, 0, 1}, new NothingSpecial(ALL_CARDS[26]) ));
  ALL_CARDS[27]->setSpecial(new CrystalAbility( {0, 1, 0, 1}, new NothingSpecial(ALL_CARDS[27]) ));
  ALL_CARDS[29]->setSpecial(new CrystalAbility( {0, 2, 0, 0}, new NothingSpecial(ALL_CARDS[29]) ));

  ALL_CARDS[33]->setSpecial(new CrystalAbility( {0, 2, 0, 1}, new NothingSpecial(ALL_CARDS[33]) ));
  ALL_CARDS[34]->setSpecial(new CrystalAbility( {0, 2, 0, 0}, new NothingSpecial(ALL_CARDS[34]) ));
  ALL_CARDS[35]->setSpecial(new CrystalAbility( {0, 3, 0, 0}, new NothingSpecial(ALL_CARDS[35]) ));

  ALL_CARDS[38]->setSpecial(new CrystalAbility( {0, 2, 0, 0}, new CP_Boost(MAX_CP, Green, NotOpponent, ALL_CARDS[38]) ));
  ALL_CARDS[39]->setSpecial(new CrystalAbility( {0, 3, 0, 0}, new CP_Boost(MAX_CP, Green, Opponent, ALL_CARDS[39]) ));

  ALL_CARDS[42]->setSpecial(new CrystalAbility( {0, 2, 0, 0}, new Color_Boost(Green, 2, 0, ALL_CARDS[42]) ));
  ALL_CARDS[44]->setSpecial(new CrystalAbility( {0, 1, 0, 0}, new NothingSpecial(ALL_CARDS[44]) ));
  ALL_CARDS[45]->setSpecial(new CrystalAbility( {0, 2, 0, 0}, new NothingSpecial(ALL_CARDS[45]) ));
  ALL_CARDS[46]->setSpecial(new CrystalAbility( {0, 2, 0, 1}, new CP_Strike(1, {Green, Yellow}, NotOpponent, ALL_CARDS[46]) ));
  ALL_CARDS[47]->setSpecial(new CrystalAbility( {0, 3, 0, 0}, new Zone_Boost(4, Blank, ALL_CARDS[47]) ));


  ALL_CARDS[49]->setSpecial(new CrystalAbility( {0, 0, 1, 0}, new CP_Crush(3, Red, No, ALL_CARDS[49]) ));
  ALL_CARDS[50]->setSpecial(new CrystalAbility( {0, 0, 2, 0}, new CP_Crush(MAX_CP, Red, No, ALL_CARDS[50]) ));
  ALL_CARDS[52]->setSpecial(new CrystalAbility( {0, 1, 2, 0}, new NothingSpecial(ALL_CARDS[52]) ));
  ALL_CARDS[53]->setSpecial(new CrystalAbility( {0, 0, 2, 1}, new CP_Strike(3, {Red}, Opponent, ALL_CARDS[53]) ));

  ALL_CARDS[56]->setSpecial(new CrystalAbility( {0, 0, 2, 0}, new CP_Boost(MAX_CP, Blue, NotOpponent, ALL_CARDS[56]) ));
  ALL_CARDS[57]->setSpecial(new CrystalAbility( {0, 0, 2, 0}, new CP_Boost(MAX_CP, Blue, Opponent, ALL_CARDS[57]) ));
  ALL_CARDS[58]->setSpecial(new CrystalAbility( {0, 1, 1, 0}, new CP_Strike(1, {Green, Blue}, Opponent, ALL_CARDS[58]) ));
  ALL_CARDS[59]->setSpecial(new CrystalAbility( {0, 1, 2, 0}, new CP_Strike(2, {Green, Blue}, Opponent, ALL_CARDS[59]) ));

  ALL_CARDS[62]->setSpecial(new CrystalAbility( {0, 0, 2, 0}, new NothingSpecial(ALL_CARDS[62]) ));
  ALL_CARDS[63]->setSpecial(new CrystalAbility( {0, 0, 3, 0}, new Recover(5, 0, Blue, NotOpponent, ALL_CARDS[63]) ));

  ALL_CARDS[69]->setSpecial(new CrystalAbility( {0, 0, 1, 0}, new Zone_Boost(3, Shield, ALL_CARDS[69]) ));
  ALL_CARDS[70]->setSpecial(new CrystalAbility( {0, 1, 1, 1}, new Zone_Boost(5, Shield, ALL_CARDS[70]) ));
  ALL_CARDS[71]->setSpecial(new CrystalAbility( {0, 0, 2, 0}, new CP_Strike(2, {Red}, Opponent, ALL_CARDS[71]) ));


  ALL_CARDS[74]->setSpecial(new CrystalAbility( {0, 0, 0, 2}, new Reflect(1, ALL_CARDS[74]) ));
  ALL_CARDS[75]->setSpecial(new CrystalAbility( {1, 1, 1, 3}, new Reflect(2, ALL_CARDS[75]) ));

  ALL_CARDS[78]->setSpecial(new CrystalAbility( {0, 0, 0, 2}, new CP_Strike(3, {Blue}, Opponent, ALL_CARDS[78]) ));
  ALL_CARDS[82]->setSpecial(new CrystalAbility( {0, 0, 0, 2}, new NothingSpecial(ALL_CARDS[82]) ));
  ALL_CARDS[83]->setSpecial(new CrystalAbility( {0, 0, 0, 3}, new NothingSpecial(ALL_CARDS[83]) ));

  ALL_CARDS[88]->setSpecial(new CrystalAbility( {1, 0, 1, 1}, new CP_Strike(1, {Red, Blue, Yellow}, Opponent, ALL_CARDS[88]) ));
  ALL_CARDS[89]->setSpecial(new CrystalAbility( {1, 1, 1, 1}, new CP_Strike(2, {Red, Green, Blue, Yellow}, Opponent, ALL_CARDS[89]) ));

  ALL_CARDS[90]->setSpecial(new CrystalAbility( {0, 0, 0, 1}, new NothingSpecial(ALL_CARDS[90]) ));
  ALL_CARDS[91]->setSpecial(new CrystalAbility( {0, 1, 0, 2}, new NothingSpecial(ALL_CARDS[91]) ));
  ALL_CARDS[92]->setSpecial(new CrystalAbility( {0, 0, 0, 2}, new Color_Boost(Grey, 2, 0, ALL_CARDS[92]) ));
  ALL_CARDS[93]->setSpecial(new CrystalAbility( {0, 0, 0, 3}, new CP_Strike(1, {Red, Green, Blue}, NotOpponent, ALL_CARDS[93]) ));


  ALL_CARDS[96]->setSpecial(new CrystalAbility( {1, 0, 0, 2}, new Risky_Move(3, 2, Red, Blue, ALL_CARDS[96]) ));
  ALL_CARDS[97]->setSpecial(new CrystalAbility( {0, 0, 1, 2}, new Risky_Move(3, 2, Blue, Green, ALL_CARDS[97]) ));
  ALL_CARDS[101]->setSpecial(new CrystalAbility( {1, 1, 0, 1}, new Life_Strike(2, ALL_CARDS[101]) ));

  ALL_CARDS[105]->setSpecial(new CrystalAbility( {1, 0, 0, 1}, new CP_Strike(2, {Red, Yellow}, Opponent, ALL_CARDS[105]) ));
  ALL_CARDS[106]->setSpecial(new CrystalAbility( {1, 0, 0, 2}, new CP_Strike(3, {Red, Yellow}, Opponent, ALL_CARDS[106]) ));

  ALL_CARDS[108]->setSpecial(new CrystalAbility( {0, 1, 0, 0}, new NothingSpecial(ALL_CARDS[108]) ));
  ALL_CARDS[109]->setSpecial(new CrystalAbility( {0, 0, 1, 0}, new NothingSpecial(ALL_CARDS[109]) ));
  ALL_CARDS[110]->setSpecial(new CrystalAbility( {1, 2, 0, 0}, new Life_Strike(2, ALL_CARDS[110]) ));
  
  ALL_CARDS[117]->setSpecial(new CrystalAbility( {3, 0, 0, 0}, new NothingSpecial(ALL_CARDS[117]) ));

  return ALL_CARDS;

}
