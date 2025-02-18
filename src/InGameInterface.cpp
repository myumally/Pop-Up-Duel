#include "../include/InGameInterface.hpp"

void PriorityManagement(Player* p1, Player* p2){
  if(p1->isAffectedBySelfEffect() == Haste && p2->isAffectedBySelfEffect() != Haste){
    p1->setPriority(true);
    p2->setPriority(false);
  }
  else if(p1->isAffectedByOpponentEffect() == Slow && p2->isAffectedByOpponentEffect() != Slow){
    p2->setPriority(true);
    p1->setPriority(false);
  } 
}

int StrengthManagement(Effect selfEf, Effect opponentEf, Card* c2, int AttackPower2){
  int NewAttackPower2 = AttackPower2;
  switch (opponentEf) {
    case Burn:
      if(c2->getColour() == Red) NewAttackPower2 = NewAttackPower2 * 2;
      break;

    case Poison:
      if(c2->getColour() == Green) NewAttackPower2 = NewAttackPower2 * 2;
      break;

    case Freeze:
      if(c2->getColour() == Blue) NewAttackPower2 = NewAttackPower2 * 2;
      break;

    case Numb:
      if(c2->getColour() == Yellow) NewAttackPower2 = NewAttackPower2 * 2;
      break; 

    case Silence:
      // to-do annuler crystal ability
      break;

    default:
      break;
  }

  if(selfEf == Protect){
    NewAttackPower2 = NewAttackPower2 / 2;
  }

  return NewAttackPower2;
}

void AffectNewEffect(Player* p1, Card* c1, Player* p2){
  if(std::find(Player::OpponentEffect.begin(), Player::OpponentEffect.end(), c1->getEffect()) != Player::OpponentEffect.end()){
    p2->setAffectedBy(c1->getEffect());
  }
  else if (std::find(Player::SelfEffect.begin(), Player::SelfEffect.end(), c1->getEffect()) != Player::SelfEffect.end()){
    p1->setAffectedBy(c1->getEffect());
  }
}

void AttackPhase(Player* p1, Card* c1, Player* p2, Card* c2, int AttackPower1, int AttackPower2){
  Colour FocusZone;
  if(c1->hasSwordAttack()){
    FocusZone = c1->getSwordZone();
    switch (c2->getZones()[FocusZone - 1]) {
      case Blank:
        AffectNewEffect(p1, c1, p2);
        if(p2->isAffectedBySelfEffect() == Refresh) p2->loseLP(c1->getStrength()); 
        else p2->loseLP(AttackPower1); 
        break;

      case Sword:
        AffectNewEffect(p1, c1, p2);
        if(p2->isAffectedBySelfEffect() == Refresh) p2->loseLP(c1->getStrength()/2);
        else p2->loseLP(AttackPower1/2); 
        break;

      case Shield:
        if(!c2->hasSwordAttack()){
          AffectNewEffect(p2, c2, p1);
          if(p1->isAffectedBySelfEffect() == Refresh) p1->loseLP(c2->getStrength());
          else p1->loseLP(AttackPower2);
        }
        break;

      default:

        break;
    }
  }

  if(c1->getColour() != Grey){
    p1->addCP(c1->getColour());
  }
}

void CombatPhase(Player* p1, Card* c1, Player* p2, Card* c2){

  Effect OldSelfEffect1 = p1->isAffectedBySelfEffect();
  Effect OldOpponentEffect1 = p1->isAffectedByOpponentEffect();

  Effect OldSelfEffect2 = p2->isAffectedBySelfEffect();
  Effect OldOpponentEffect2 = p2->isAffectedByOpponentEffect();

  int AttackPower1 = c1->getStrength();
  int AttackPower2 = c2->getStrength();

  AttackPower1 = StrengthManagement(OldSelfEffect2, OldOpponentEffect2, c1, AttackPower1);
  AttackPower2 = StrengthManagement(OldSelfEffect1, OldOpponentEffect1, c2, AttackPower2);

  PriorityManagement(p1, p2);

  p1->setAffectedBy(Nothing);
  p2->setAffectedBy(Nothing);

  if(p1->hasPriority()){
    AttackPhase(p1, c1, p2, c2, AttackPower1, AttackPower2);
    AttackPhase(p2, c2, p1, c1, AttackPower2, AttackPower1);
  }
  else {
    AttackPhase(p2, c2, p1, c1, AttackPower2, AttackPower1);
    AttackPhase(p1, c1, p2, c2, AttackPower1, AttackPower2);
  }

  p1->setPriority(false);
  p2->setPriority(false);
}

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

InGameInterface::InGameInterface(const std::vector<sf::Sprite>& Sprites, Player* p1, Player* p2){
  sprites = Sprites;
  player1 = p1;
  player2 = p2;
}

void createCrystalShape(sf::ConvexShape& ColourCrystal, sf::Vector2f Up, sf::Vector2f Right, sf::Vector2f Down, sf::Vector2f Left){
  ColourCrystal.setPointCount(4);
  ColourCrystal.setPoint(0, Up);
  ColourCrystal.setPoint(1, Right);
  ColourCrystal.setPoint(2, Down);
  ColourCrystal.setPoint(3, Left);
}


std::string effectToString(Effect ef) {
  switch (ef) {
    case Burn:
      return "Burn";
    case Freeze:    
      return "Freeze";
    case Numb:    
      return "Numb";
    case Poison:    
      return "Poison";
    case Silence:    
      return "Silence";
    case Protect:    
      return "Protect";
    case Refresh:    
      return "Refresh";
    case Haste:    
      return "Haste";
    case Slow:    
      return "Slow";
    default: 
      return " ";
  }
}


void InGameInterface::run(sf::RenderWindow& window, const sf::Font& font, const std::array<Card*, 122>& AllCards, sf::TcpSocket& socket){

  window.setTitle("Pop-Up Duel !");

  bool RUN = true;
  bool RUN_SELECTION_PHASE = true;
  bool RUN_COMBAT_PHASE = false;
  bool RUN_END_PHASE = false;

  sf::Clock clock;
  const float timeLimit = 15.0f;

  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> getRandomInt(0,DECK_SIZE -1); // distribution in range [0, DECK_SIZE - 1]


  float CardSpriteWidth;
  float CardSpriteHeight;

  Colour col;

  sf::Text PlayerOneName({player1->getName() + " - " + std::to_string(player1->getLP()) + "LP"}, font, 50); 
  PlayerOneName.setFillColor(sf::Color(100, 100, 0));
  PlayerOneName.setPosition(50.f, 100.f);

  sf::Text PlayerTwoName({player2->getName() + " - " + std::to_string(player2->getLP()) + "LP"}, font, 50); 
  PlayerTwoName.setFillColor(sf::Color(100, 100, 0));
  PlayerTwoName.setPosition(window.getSize().x - (PlayerTwoName.getGlobalBounds().width + 50.f), 100.f);


  sf::Text Effect1(" ", font, 50);
  Effect1.setPosition(50.f, 250.f);
  sf::Text Effect2(" ", font, 50);
  Effect2.setPosition(window.getSize().x - (PlayerTwoName.getGlobalBounds().width + 50.f), 250.f);


  sf::Vector2f rectSize(60.f, 90.f);

  sf::RectangleShape BlueRect(rectSize);
  BlueRect.setFillColor(sf::Color::Blue);

  sf::RectangleShape YellowRect(rectSize);
  YellowRect.setFillColor(sf::Color::Yellow);

  sf::RectangleShape GreenRect(rectSize);
  GreenRect.setFillColor(sf::Color::Green);

  sf::RectangleShape RedRect(rectSize);
  RedRect.setFillColor(sf::Color::Red);

  sf::RectangleShape GreyRect(rectSize);
  GreyRect.setFillColor(sf::Color(100, 100, 100));


  sf::Vector2f Up(25.f, 0.f);
  sf::Vector2f Right(50.f, 25.f);
  sf::Vector2f Down(25.f, 50.f);
  sf::Vector2f Left(0.f, 25.f);

  sf::ConvexShape BlueCrystal;
  createCrystalShape(BlueCrystal, Up, Right, Down, Left);
  BlueCrystal.setFillColor(sf::Color::Blue);

  sf::ConvexShape YellowCrystal;
  createCrystalShape(YellowCrystal, Up, Right, Down, Left);
  YellowCrystal.setFillColor(sf::Color::Yellow);

  sf::ConvexShape GreenCrystal;
  createCrystalShape(GreenCrystal, Up, Right, Down, Left);
  GreenCrystal.setFillColor(sf::Color::Green);

  sf::ConvexShape RedCrystal;
  createCrystalShape(RedCrystal, Up, Right, Down, Left);
  RedCrystal.setFillColor(sf::Color::Red); 

  sf::Text QuitText("Quit", font, 50); 
  QuitText.setFillColor(sf::Color(100, 100, 0));
  QuitText.setPosition((window.getSize().x - QuitText.getGlobalBounds().width)/2, (window.getSize().y - QuitText.getGlobalBounds().height)/2);

  sf::RectangleShape Quit;
  Quit.setSize(sf::Vector2f(0.f, 0.f));
  Quit.setFillColor(sf::Color(255, 255, 155));
  Quit.setPosition((window.getSize().x - QuitText.getGlobalBounds().width)/2, (window.getSize().y - QuitText.getGlobalBounds().height)/2);

  sf::Text WinText("It's a Win !", font, 50);
  sf::Text LoseText("Is that Skill Issue ? You Lost ...", font, 50);
  WinText.setPosition((window.getSize().x - WinText.getGlobalBounds().width)/2, (window.getSize().y - WinText.getGlobalBounds().height - 40.f)/2 - QuitText.getGlobalBounds().height - 20.f);
  LoseText.setPosition((window.getSize().x - LoseText.getGlobalBounds().width)/2, (window.getSize().y - LoseText.getGlobalBounds().height - 40.f)/2 - QuitText.getGlobalBounds().height - 20.f);


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

  sendIds(socket, PlayerOneHand, 3);
  receiveIds(socket, PlayerTwoHand, 3);

/*
     for(int i = 0; i < 3; i++){
     Drawed_Id = vectDeck2[getRandomInt(rng)]->getId();
     while(std::find(PlayerTwoHand.begin(), PlayerTwoHand.end(), Drawed_Id) != PlayerTwoHand.end()){
     Drawed_Id = vectDeck2[getRandomInt(rng)]->getId();
     }
     PlayerTwoHand.push_back(Drawed_Id);
     }
*/


  int cardCount = 0;
  int crystalCount = 0;


  for (int id : PlayerOneHand){
    std::cout << "Carte piochée : " << id << std::endl;
  }

  for (int id : PlayerTwoHand){
    std::cout << "Carte piochée adversaire : " << id << std::endl;
  }


  // mouse's position and state
  int x = 0;
  int y = 0;
  int mouse_state = 0;

  // id of the card pointed by the mouse
  int id_mouse_card = 0;

  sf::Event event;

  while (window.isOpen() && RUN) {

    clock.restart();

    while(window.isOpen() && RUN_SELECTION_PHASE){

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

      if(!player2->hasPriority()){
        sendBool(socket, player1->hasPriority());
        receiveBool(socket, player2->hasPriority()); 
      }

      if (mouse_state == 1){
        for (int i : PlayerOneHand){
          if (sprites[i - 1].getGlobalBounds().contains(x, y)){
            id_mouse_card = i;
            PlayerOneSelectedCard = id_mouse_card;

            if(!player2->hasPriority()){
              player1->setPriority(true);
              sendBool(socket, player1->hasPriority());
              receiveBool(socket, player2->hasPriority());
            }

            sendId(socket, PlayerOneSelectedCard);
            receiveId(socket, PlayerTwoSelectedCard);

            // PlayerTwoSelectedCard = PlayerTwoHand[0];
            RUN_SELECTION_PHASE = false;
            RUN_COMBAT_PHASE = true;
          }
        }
      } 
      else if (clock.getElapsedTime().asSeconds() >= timeLimit){
        PlayerOneSelectedCard = PlayerOneHand[0];

        sendId(socket, PlayerOneSelectedCard);
        receiveId(socket, PlayerTwoSelectedCard);

        RUN_SELECTION_PHASE = false;
        RUN_COMBAT_PHASE = true;
      }


      // render

      window.clear();

      cardCount = 0;
      for (int id : PlayerOneHand ){ 

        sprites[id - 1].setScale(2.0f, 2.0f);
        CardSpriteWidth = sprites[id - 1].getTexture()->getSize().x * sprites[id - 1].getScale().x;
        CardSpriteHeight = sprites[id - 1].getTexture()->getSize().y * sprites[id - 1].getScale().y;

        sprites[id - 1].setPosition((window.getSize().x - 3 * CardSpriteWidth)/2 - 30.f + (cardCount%3) * (CardSpriteWidth + 30.f), (window.getSize().y - CardSpriteHeight)/2);
        ++cardCount;
        window.draw(sprites[id - 1]); 
      }

      for (int id : PlayerTwoHand ){ 
        col = AllCards[id - 1]->getColour();

        switch (col) {
          case Red:
            RedRect.setPosition(window.getSize().x - 300.f + (cardCount%3) * (80.f), window.getSize().y - 150.f);
            window.draw(RedRect);
            break;

          case Green:
            GreenRect.setPosition(window.getSize().x - 300.f + (cardCount%3) * (80.f), window.getSize().y - 150.f);
            window.draw(GreenRect);
            break;

          case Blue:
            BlueRect.setPosition(window.getSize().x - 300.f + (cardCount%3) * (80.f), window.getSize().y - 150.f);
            window.draw(BlueRect);
            break;

          case Yellow:
            YellowRect.setPosition(window.getSize().x - 300.f + (cardCount%3) * (80.f), window.getSize().y - 150.f);
            window.draw(YellowRect);
            break;

          case Grey:
            GreyRect.setPosition(window.getSize().x - 300.f + (cardCount%3) * (80.f), window.getSize().y - 150.f);
            window.draw(GreyRect);
            break;

          default:

            break;
        }

        ++cardCount;   
      }

      crystalCount = 0;

      for(Colour crystal : player1->getCP()){
        switch (crystal) {
          case Red:
            RedCrystal.setPosition(50.f + (crystalCount%10) * (50.f), 180.f);
            window.draw(RedCrystal);
            break;

          case Green:
            GreenCrystal.setPosition(50.f + (crystalCount%10) * (50.f), 180.f);
            window.draw(GreenCrystal);
            break;

          case Blue:
            BlueCrystal.setPosition(50.f + (crystalCount%10) * (50.f), 180.f);
            window.draw(BlueCrystal);
            break;

          case Yellow:
            YellowCrystal.setPosition(50.f + (crystalCount%10) * (50.f), 180.f);
            window.draw(YellowCrystal);
            break;

          default:

            break;
        }
        ++crystalCount;
      }

      crystalCount = 0;

      for(Colour crystal : player2->getCP()){
        switch (crystal) {
          case Red:
            RedCrystal.setPosition(window.getSize().x - (PlayerTwoName.getGlobalBounds().width + 50.f) + (crystalCount%10) * (50.f), 180.f);
            window.draw(RedCrystal);
            break;

          case Green:
            GreenCrystal.setPosition(window.getSize().x - (PlayerTwoName.getGlobalBounds().width + 50.f) + (crystalCount%10) * (50.f), 180.f);
            window.draw(GreenCrystal);
            break;

          case Blue:
            BlueCrystal.setPosition(window.getSize().x - (PlayerTwoName.getGlobalBounds().width + 50.f) + (crystalCount%10) * (50.f), 180.f);
            window.draw(BlueCrystal);
            break;

          case Yellow:
            YellowCrystal.setPosition(window.getSize().x - (PlayerTwoName.getGlobalBounds().width + 50.f) + (crystalCount%10) * (50.f), 180.f);
            window.draw(YellowCrystal);
            break;

          default:

            break;
        }
        ++crystalCount;
      }

      window.draw(PlayerOneName);
      window.draw(PlayerTwoName);

      window.draw(Effect1);
      window.draw(Effect2);

      window.display();
    }

    while(window.isOpen() && RUN_COMBAT_PHASE){

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

      CombatPhase(player1, AllCards[PlayerOneSelectedCard - 1], player2, AllCards[PlayerTwoSelectedCard - 1]); 

      PlayerOneName.setString({player1->getName() + " - " + std::to_string(player1->getLP()) + "LP"});
      PlayerTwoName.setString({player2->getName() + " - " + std::to_string(player2->getLP()) + "LP"});

      Effect1.setString({effectToString(player1->isAffectedBySelfEffect()) + " " + effectToString(player1->isAffectedByOpponentEffect())});
      Effect2.setString({effectToString(player2->isAffectedBySelfEffect()) + " " + effectToString(player2->isAffectedByOpponentEffect())});

      Drawed_Id = vectDeck1[getRandomInt(rng)]->getId();
      while(std::find(PlayerOneHand.begin(), PlayerOneHand.end(), Drawed_Id) != PlayerOneHand.end()){
        Drawed_Id = vectDeck1[getRandomInt(rng)]->getId();;
      }
      PlayerOneHand.push_back(Drawed_Id);

      PlayerOneHand.erase(std::remove(PlayerOneHand.begin(), PlayerOneHand.end(), PlayerOneSelectedCard), PlayerOneHand.end());

      sendIds(socket, PlayerOneHand, 3);
      receiveIds(socket, PlayerTwoHand, 3);

/*
      Drawed_Id = vectDeck2[getRandomInt(rng)]->getId();
      while(std::find(PlayerTwoHand.begin(), PlayerTwoHand.end(), Drawed_Id) != PlayerTwoHand.end()){
        Drawed_Id = vectDeck2[getRandomInt(rng)]->getId();
      }
      PlayerTwoHand.push_back(Drawed_Id);
      
      PlayerTwoHand.erase(std::remove(PlayerTwoHand.begin(), PlayerTwoHand.end(), PlayerTwoSelectedCard), PlayerTwoHand.end()); 
*/ 

      RUN_COMBAT_PHASE = false;
      if((player1->getLP() != 0) && (player2->getLP() != 0)){
        RUN_SELECTION_PHASE = true;
      }
      else{
        RUN_END_PHASE = true;
      }

      // render

      window.clear(); 

      sprites[PlayerOneSelectedCard - 1].setScale(2.0f, 2.0f);
      sprites[PlayerTwoSelectedCard - 1].setScale(2.0f, 2.0f);

      CardSpriteWidth = sprites[PlayerOneSelectedCard - 1].getTexture()->getSize().x * sprites[PlayerOneSelectedCard - 1].getScale().x;
      CardSpriteHeight = sprites[PlayerOneSelectedCard - 1].getTexture()->getSize().y * sprites[PlayerOneSelectedCard - 1].getScale().y;

      sprites[PlayerOneSelectedCard - 1].setPosition((window.getSize().x - 3 * CardSpriteWidth)/2 - 30.f, (window.getSize().y - CardSpriteHeight)/2);

      window.draw(sprites[PlayerOneSelectedCard - 1]);

      sprites[PlayerTwoSelectedCard - 1].setPosition((window.getSize().x - 3 * CardSpriteWidth)/2 - 30.f + 2 * (CardSpriteWidth + 30.f), (window.getSize().y - CardSpriteHeight)/2);

      window.draw(sprites[PlayerTwoSelectedCard - 1]);

      window.draw(PlayerOneName);
      window.draw(PlayerTwoName);

      window.display();
      sf::sleep(sf::seconds(3));
    }

    while(window.isOpen() && RUN_END_PHASE){

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

    if (mouse_state == 1){
      if (Quit.getGlobalBounds().contains(x, y)){
        RUN = false;
        RUN_END_PHASE = false;
      }
    }

      // render

      window.clear();

      if (player1->getLP() == 0){
        window.draw(LoseText);
      }
      else {
        window.draw(WinText);
      }

      Quit.setSize(sf::Vector2f(QuitText.getGlobalBounds().width + 20.f, QuitText.getGlobalBounds().height + 20.f));
      window.draw(Quit);
      window.draw(QuitText);

      window.display();
    }
  }

}
