#ifndef deck_creation_menu__hpp
#define deck_creation_menu__hpp

#include "../include/all_includes.hpp"
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>


class DeckCreationMenu {

  std::vector<sf::Sprite> sprites;
  Player* player;
  float scrollOffset = 0.f;
  float scrollSpeed = 20.f;

  public:
    DeckCreationMenu(std::vector<sf::Sprite> Sprites, Player* p);
    void run(const std::array<Card*, 122>& AllCards);
};

#endif
