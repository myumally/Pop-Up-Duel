#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>


class DeckCreationMenu {

  std::vector<sf::Sprite> sprites;
  float scrollOffset = 0.f;
  float scrollSpeed = 20.f;

  public:
    DeckCreationMenu(std::vector<sf::Sprite> Sprites);
    void run();
};


