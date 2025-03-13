#ifndef in_game_interface__hpp
#define in_game_interface__hpp

#include "../include/all_includes.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <optional> 

struct Particle {
  sf::CircleShape shape;
  sf::Vector2f velocity;
  float lifetime;
};

void createCrystalShape(sf::ConvexShape& ColourCrystal, sf::Vector2f Up, sf::Vector2f Right, sf::Vector2f Down, sf::Vector2f Left);

std::string effectToString(Effect ef);


class InGameInterface {

  std::vector<sf::Sprite> sprites;
  sf::Sprite sword;
  sf::Sprite shield;
  sf::Sprite sword2;
  sf::RectangleShape Behind;
  Player* player1;
  Player* player2;
  int PlayerOneSelectedCard;
  int PlayerTwoSelectedCard;
  float CardSpriteWidth;
  float CardSpriteHeight;

  public:
    void setPlayers(Player* p1, Player* p2);
    Player* getPlayerOne();
    Player* getPlayerTwo();
    InGameInterface(const std::vector<sf::Sprite>& Sprites, sf::Sprite sw, sf::Sprite sh, sf::Sprite sw2, Player* p1, Player* p2);
    void run(sf::RenderWindow& window, const sf::Font& font, const std::array<Card*, 122>& AllCards, sf::TcpSocket &socket);

  private:
    // Combat
    void PriorityManagement(Player* p1, Player* p2);
    int StrengthManagement(Effect selfEf, Effect opponentEf, Card* c2, int AttackPower2);
    void AffectNewEffect(Player* p1, Card* c1, Player* p2);
    void DamagePhase(bool ca1, Player* p1, Card* c1, Player* p2, Card* c2, Effect OldSelfEffect2, Effect OldOpponentEffect2, int a);
    
    void AttackPhase(sf::RenderWindow& window, Player* p1, Card* c1, Player* p2, Card* c2, Effect OldSelfEffect1, Effect OldOpponentEffect1, Effect OldSelfEffect2, Effect OldOpponentEffect2);
    void CombatPhase(sf::RenderWindow& window, Player* p1, Card* c1, Player* p2, Card* c2);

    // Animations
    void init_anim(sf::RenderWindow& window);
    void draw_cards(sf::RenderWindow& window);
    void sword_vs_sword(sf::RenderWindow& window);
    void sword_vs_shield(sf::RenderWindow& window);
    void sword_vs_blank(sf::RenderWindow& window);
    void shield_vs_sword(sf::RenderWindow& window);
    void blank_vs_sword(sf::RenderWindow& window);
    void shield_vs_shield(sf::RenderWindow& window); 
    void AttackAnimation (sf::RenderWindow& window, ZoneType type, Player* p1);
};

#endif
