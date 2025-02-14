#ifndef in_game_interface__hpp
#define in_game_interface__hpp

#include "../include/all_includes.hpp"
#include <SFML/Graphics.hpp>
#include <optional>


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
