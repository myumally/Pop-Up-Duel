#ifndef deck_creation_menu__hpp
#define deck_creation_menu__hpp

#include "../include/all_includes.hpp"
#include <SFML/Graphics.hpp>
#include <optional>


class DeckCreationMenu {

  std::vector<sf::Sprite> sprites;
  Player* player;
  float scrollOffset = 0.f;
  float scrollSpeed = 20.f;

  public:
    void setPlayer(Player* p);
    Player* getPlayer();
    DeckCreationMenu(std::vector<sf::Sprite> Sprites, Player* p);
    void run(sf::RenderWindow& window, const std::array<Card*, 122>& AllCards);
};

#endif
