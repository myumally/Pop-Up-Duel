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

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> getRandomInt(0,DECK_SIZE -1); // distribution in range [0, DECK_SIZE - 1]


  sf::Font font;
  if (!(font.loadFromFile("assets/fonts/Unique.ttf"))){
    std::cout << "error while getting font " << std::endl; 
  }

  sf::Text PlayerOneName(player1->getName(), font, 50); 
  PlayerOneName.setFillColor(sf::Color(100, 100, 0));
  PlayerOneName.setPosition(850.f, 500.f);

  sf::Text PlayerTwoName(player2->getName(), font, 50); 
  PlayerTwoName.setFillColor(sf::Color(100, 100, 0));
  PlayerTwoName.setPosition(850.f, 500.f);


  std::list<Card*> listDeck1 = player1->getDeck();
  std::list<Card*> listDeck2 = player2->getDeck();

  std::vector<Card*> vectDeck1(listDeck1.begin(), listDeck1.end());
  std::vector<Card*> vectDeck2(listDeck2.begin(), listDeck2.end());

  std::vector<int> PlayerOneHand;
  std::vector<int> PlayerTwoHand;

  int PlayerOneSelectedCard;
  int PlayerTwoSelectedCard;  

  int Drawed_Id; 

  for(int i = 0; i < 3; i++){
    Drawed_Id = vectDeck1[getRandomInt(rng)]->getId();
    while(std::find(PlayerOneHand.begin(), PlayerOneHand.end(), Drawed_Id) != PlayerOneHand.end()){
      Drawed_Id = vectDeck1[getRandomInt(rng)]->getId();;
    }
    PlayerOneHand.push_back(Drawed_Id);
  }

  for(int i = 0; i < 3; i++){
    Drawed_Id = vectDeck2[getRandomInt(rng)]->getId();
    while(std::find(PlayerTwoHand.begin(), PlayerTwoHand.end(), Drawed_Id) != PlayerTwoHand.end()){
      Drawed_Id = vectDeck2[getRandomInt(rng)]->getId();
    }
    PlayerTwoHand.push_back(Drawed_Id);
  }

  int cardCount = 0;


  for (Card* c : listDeck1){
    if (std::find(PlayerOneHand.begin(), PlayerOneHand.end(), c->getId()) != PlayerOneHand.end()){
      std::cout << "Carte piochée joueur 1 : " << c->getId() << std::endl;
    }
    ++cardCount;
  }
  cardCount = 0;

  for (Card* c : listDeck2){
    if (std::find(PlayerTwoHand.begin(), PlayerTwoHand.end(), c->getId()) != PlayerTwoHand.end()){
      std::cout << "Carte piochée joueur 2 : " << c->getId() << std::endl;
    }
    ++cardCount;
  }
  cardCount = 0;


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

    cardCount = 0;
    for (int id : PlayerOneHand ){ 
      sprites[id - 1].setScale(2.0f, 2.0f);
      sprites[id - 1].setPosition(600.f + (cardCount%3) * 300.f, ((cardCount/3) * 400.f) + 400.f);
      ++cardCount;
      window.draw(sprites[id - 1]); 
    }

    window.display();
  }

}
