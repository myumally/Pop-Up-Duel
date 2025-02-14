#include "../include/InGameInterface.hpp"

void InGameInterface::setPlayers(Player* p1, Player* p2){
  player1 = p1;
  player2 = p2;
}

Player* InGameInterface::getPlayerOne(){
  return player1;
}

Player* InGameInterface::getPlayerTwo(){
  return player2;
}

InGameInterface::InGameInterface(std::vector<sf::Sprite> Sprites, Player* p1, Player* p2){
  sprites = Sprites;
  player1 = p1;
  player2 = p2;
}

void InGameInterface::run(sf::RenderWindow& window, const std::array<Card*, 122>& AllCards){

  window.setTitle("Pop-Up Duel !");

  bool RUN = true;

  std::list<Card*> deck1 = player1->getDeck();
  std::list<Card*> deck2 = player2->getDeck();

  std::vector<int> PlayerOneHand;
  std::vector<int> PlayerTwoHand;

  int PlayerOneSelectedCard;
  int PlayerTwoSelectedCard;

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

    
    // render

    window.clear();

    window.display();
  }

}
