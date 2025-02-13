#include "../include/DeckCreationMenu.hpp"

DeckCreationMenu::DeckCreationMenu(std::vector<sf::Sprite> Sprites){
  sprites = Sprites;
}

void DeckCreationMenu::run() {

  bool RUN = true;

  // Get Screen Dimension
  sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
  unsigned int screenHeight = desktopMode.height;

  // Create Window
  sf::RenderWindow window(sf::VideoMode(screenHeight * 0.9 * 1.5, screenHeight * 0.9), "Deck Creation");

  sf::RectangleShape BehindCard;
  BehindCard.setSize(sf::Vector2f(950.f, 2000.f));
  BehindCard.setFillColor(sf::Color(200, 200, 180));
  BehindCard.setPosition(550.f, 0);

  // mouse's position and state
  int x = 0;
  int y = 0;
  int mouse_state = 0;

  // id of the card pointed by the mouse
  int id_mouse_card = 0;

  sf::Event event; 

  while (window.isOpen() && RUN) {

    mouse_state = 0;

    while (window.pollEvent(event))
    {
      // check the type of the event...
      switch (event.type)
      {
        // window closed
        case sf::Event::Closed:
          window.close();
          break;

        case sf::Event::MouseWheelScrolled:
          if (event.mouseWheelScroll.delta > 0) {
            scrollOffset += scrollSpeed;
          } else {
            scrollOffset -= scrollSpeed;
          }
          break;

        case sf::Event::MouseButtonPressed:
          x = event.mouseButton.x;
          y = event.mouseButton.y;
          mouse_state = 1;          
          break;

        case sf::Event::MouseMoved:
          x = event.mouseMove.x;
          y = event.mouseMove.y;          
          break;

        default:
          break;
      }
    }

    // update

    if (mouse_state == 1){
      for (int i = 0; i < 122; ++i){
        if (sprites[i].getGlobalBounds().contains(x, y)){
          id_mouse_card = i + 1;
          std::cout << "La souris est sur l'image " << id_mouse_card << std::endl;

        }
      }
    }

    // render

    window.clear();

    window.draw(BehindCard);

    for (int i = 0; i < 122; ++i){
      sprites[i].setPosition(600.f + (i%3) * 300.f, ((i/3) * 400.f) + scrollOffset);
      window.draw(sprites[i]); 
    }

    window.display();
  }
}
