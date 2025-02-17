#ifndef in_game_interface__hpp
#define in_game_interface__hpp

#include "../include/all_includes.hpp"
#include <SFML/Graphics.hpp>
#include <optional>


// Effects Management 

// void PriorityManagement(Player* p1, Player* p2);

int StrengthManagement(Effect selfEf, Effect opponentEf, Card* c2, int AttackPower2);

void AffectNewEffect(Player* p1, Card* c1, Player* p2);

void AttackPhase(Player* p1, Card* c1, Player* p2, Card* c2, int AttackPower1, int AttackPower2);

void CombatPhase(Player* p1, Card* c1, Player* p2, Card* c2);


void createCrystalShape(sf::ConvexShape& ColourCrystal, sf::Vector2f Up, sf::Vector2f Right, sf::Vector2f Down, sf::Vector2f Left);

std::string effectToString(Effect ef);


class InGameInterface {

  std::vector<sf::Sprite> sprites;
  Player* player1;
  Player* player2;

  public:
    void setPlayers(Player* p1, Player* p2);
    Player* getPlayerOne();
    Player* getPlayerTwo();
    InGameInterface(std::vector<sf::Sprite> Sprites, Player* p1, Player* p2);
    void run(sf::RenderWindow& window, const std::array<Card*, 122>& AllCards);
};

#endif
