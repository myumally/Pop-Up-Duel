#include "../include/DeckCreationMenu.hpp"

DeckCreationMenu::DeckCreationMenu(std::vector<sf::Sprite> Sprites, Player* p){
  sprites = Sprites;
  player = p;
}

void DeckCreationMenu::setPlayer(Player* p){
  player = p;
}

Player* DeckCreationMenu::getPlayer(){
  return player;
}


void DeckCreationMenu::run(sf::RenderWindow& window, const std::array<Card*, 122>& AllCards) {

  window.setTitle("Deck Creation");

  bool RUN = true;

  std::list<Card*> deck = player->getDeck();

  sf::RectangleShape BehindCard;
  BehindCard.setSize(sf::Vector2f(950.f, 2000.f));
  BehindCard.setFillColor(sf::Color(200, 200, 180));
  BehindCard.setPosition(550.f, 0);

  sf::RectangleShape Confirm;
  Confirm.setSize(sf::Vector2f(0.f, 0.f));
  Confirm.setFillColor(sf::Color(255, 255, 155));
  Confirm.setPosition(850.f, 500.f);

  sf::Font font;
  if (!(font.loadFromFile("assets/fonts/Unique.ttf"))){
    std::cout << "error while getting font " << std::endl; 
  }
  sf::Text ConfirmText("Confirm Deck", font, 50); 
  ConfirmText.setFillColor(sf::Color(100, 100, 0));
  ConfirmText.setPosition(850.f, 500.f);

  scrollOffset = 0.f;

  int cardCount = 0;

  std::vector<int> SelectedCards;

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

          if (std::find(SelectedCards.begin(), SelectedCards.end(), id_mouse_card) != SelectedCards.end()){
            player->removeCard(id_mouse_card);
            SelectedCards.erase(std::remove(SelectedCards.begin(), SelectedCards.end(), id_mouse_card), SelectedCards.end());
          } 

          else if(!player->isDeckComplete()) {
            player->addCard(id_mouse_card, AllCards); 
            SelectedCards.push_back(id_mouse_card);
          } 
        }
        else if (Confirm.getGlobalBounds().contains(x, y)){
          RUN = false;
        }
      }
      deck = player->getDeck();
    }

    // render

    window.clear();

    window.draw(BehindCard);

    for (int i = 0; i < 122; ++i){
      if (!(std::find(SelectedCards.begin(), SelectedCards.end(), (i + 1)) != SelectedCards.end())){
        sprites[i].setScale(2.0f, 2.0f);
        sprites[i].setPosition(600.f + (i%3) * 300.f, ((i/3) * 400.f) + scrollOffset);
      }
      window.draw(sprites[i]);
    }

    cardCount = 0;
    for (Card* c : deck){
      ++cardCount;
      sprites[c->getId() - 1].setScale(1.f, 1.f);
      sprites[c->getId() - 1].setPosition(55.f + ((cardCount - 1)%3) * 150.f, (((cardCount - 1)/3) * 200.f) );
      window.draw(sprites[c->getId() - 1]);
    }

    if(player->isDeckComplete() == true){
      Confirm.setSize(sf::Vector2f(400.f, 70.f));
      window.draw(Confirm); 
      window.draw(ConfirmText);
    }

    window.display();
  }
}
