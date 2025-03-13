#include "../include/InGameInterface.hpp"

void InGameInterface::init_anim(sf::RenderWindow& window){

  Behind.setSize(sf::Vector2f(window.getSize().x, CardSpriteHeight + 40));
  Behind.setFillColor(sf::Color(200, 200, 180));
  Behind.setPosition(0, (window.getSize().y - CardSpriteHeight)/2 - 20);

  sprites[PlayerOneSelectedCard - 1].setScale(2.0f, 2.0f);
  sprites[PlayerTwoSelectedCard - 1].setScale(2.0f, 2.0f);

  CardSpriteWidth = sprites[PlayerOneSelectedCard - 1].getTexture()->getSize().x * sprites[PlayerOneSelectedCard - 1].getScale().x;
  CardSpriteHeight = sprites[PlayerOneSelectedCard - 1].getTexture()->getSize().y * sprites[PlayerOneSelectedCard - 1].getScale().y;

  sprites[PlayerOneSelectedCard - 1].setPosition((window.getSize().x - 3 * CardSpriteWidth)/2 - 30.f, (window.getSize().y - CardSpriteHeight)/2);
  sprites[PlayerTwoSelectedCard - 1].setPosition((window.getSize().x - 3 * CardSpriteWidth)/2 - 30.f + 2 * (CardSpriteWidth + 30.f), (window.getSize().y - CardSpriteHeight)/2);
}


void InGameInterface::draw_cards(sf::RenderWindow& window){
  sprites[PlayerOneSelectedCard - 1].setPosition((window.getSize().x - 3 * CardSpriteWidth)/2 - 30.f, (window.getSize().y - CardSpriteHeight)/2);
  window.draw(sprites[PlayerOneSelectedCard - 1]);

  sprites[PlayerTwoSelectedCard - 1].setPosition((window.getSize().x - 3 * CardSpriteWidth)/2 - 30.f + 2 * (CardSpriteWidth + 30.f), (window.getSize().y - CardSpriteHeight)/2);
  window.draw(sprites[PlayerTwoSelectedCard - 1]);
}


void InGameInterface::sword_vs_sword(sf::RenderWindow& window){
  init_anim(window);

  sprites[PlayerOneSelectedCard - 1].setPosition((window.getSize().x - 3 * CardSpriteWidth)/2 - 30.f, (window.getSize().y - CardSpriteHeight)/2);

  sword.setPosition(sprites[PlayerOneSelectedCard - 1].getPosition().x + CardSpriteWidth + sword2.getTexture()->getSize().x / 2.0f, sprites[PlayerOneSelectedCard - 1].getPosition().y + CardSpriteHeight / 2.0f);
  sword.setOrigin(sword.getTexture()->getSize().x / 2, sword.getTexture()->getSize().y / 2);

  sprites[PlayerTwoSelectedCard - 1].setPosition((window.getSize().x - 3 * CardSpriteWidth)/2 - 30.f + 2 * (CardSpriteWidth + 30.f), (window.getSize().y - CardSpriteHeight)/2);
  window.draw(sprites[PlayerTwoSelectedCard - 1]);

  sword2.setPosition(sprites[PlayerTwoSelectedCard - 1].getPosition().x - sword2.getTexture()->getSize().x / 2.0f, sprites[PlayerTwoSelectedCard - 1].getPosition().y + CardSpriteHeight / 2.0f);
  sword2.setOrigin(sword2.getTexture()->getSize().x / 2, sword2.getTexture()->getSize().y / 2);

  float swordSpeed = 500.0f;
  float rotationSpeed = 500.0f;

  bool RunAnimation = true;

  bool impact = false;

  float impactTimer = 0.0f;

  std::vector<Particle> particles;

  sf::Clock clock;
  sf::Clock timer;
  sf::Event event;

  while (window.isOpen() && RunAnimation) {

    while (window.pollEvent(event))
    {
      // check the type of the event...
      switch (event.type)
      {
        // window closed
        case sf::Event::Closed:
          window.close();
          break; 

        default:
          break;
      }
    }

    // update
    float deltaTime = clock.restart().asSeconds();

    if (!impact) {

      sword.move(swordSpeed * deltaTime, 0);
      sword.rotate(rotationSpeed * deltaTime);

      sword2.move(-swordSpeed * deltaTime, 0);
      sword2.rotate(-rotationSpeed * deltaTime);

      if (sword.getGlobalBounds().intersects(sword2.getGlobalBounds())) {
        impact = true;
        timer.restart();

        for (int i = 0; i < 10; i++) {
          Particle p;
          p.shape.setRadius(3);
          p.shape.setFillColor(sf::Color::Yellow);
          p.shape.setPosition((sword2.getPosition().x + sword.getPosition().x)/2, (sword2.getPosition().y + sword.getPosition().y)/2 - 20);
          float angle = (std::rand() % 360) * 3.14159f / 180.f;
          float speed = 150.0f + std::rand() % 100;
          p.velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
          p.lifetime = 0.5f;
          particles.push_back(p);
        }
      }
    } 
    else if (timer.getElapsedTime().asSeconds() >= 1) {
      RunAnimation = false;
    }
    else {
      impactTimer += deltaTime;

      float reboundSpeed = -500.0f * std::exp(-5 * impactTimer);
      sword.move(reboundSpeed * deltaTime, 0);
      sword.rotate(std::sin(impactTimer * 15) * 15 * deltaTime);

      sword2.move(-reboundSpeed * deltaTime, 0);
      sword2.rotate(-std::sin(impactTimer * 15) * 15 * deltaTime);
    }

    for (auto it = particles.begin(); it != particles.end();) {
      it->shape.move(it->velocity * deltaTime);
      it->lifetime -= deltaTime;
      if (it->lifetime <= 0) {
        it = particles.erase(it);
      } else {
        ++it;
      }
    } 

    // render
    window.clear();
    window.draw(Behind);
    draw_cards(window);

    window.draw(sword);
    window.draw(sword2);

    for (const auto& p : particles) {
      window.draw(p.shape);
    }

    window.display();
  }
}


void InGameInterface::sword_vs_shield(sf::RenderWindow& window){
  init_anim(window);

  sword.setPosition(sprites[PlayerOneSelectedCard - 1].getPosition().x + CardSpriteWidth + sword2.getTexture()->getSize().x / 2.0f, sprites[PlayerOneSelectedCard - 1].getPosition().y + CardSpriteHeight / 2.0f);
  sword.setOrigin(sword.getTexture()->getSize().x / 2, sword.getTexture()->getSize().y / 2); 

  float swordSpeed = 500.0f;
  float rotationSpeed = 500.0f;

  bool RunAnimation = true;

  bool impact = false;

  float impactTimer = 0.0f;

  std::vector<Particle> particles;

  sf::Clock clock;
  sf::Clock timer;
  sf::Event event;


  shield.setPosition(sprites[PlayerTwoSelectedCard - 1].getPosition().x - shield.getTexture()->getSize().x / 2.0f, sprites[PlayerTwoSelectedCard - 1].getPosition().y + CardSpriteHeight / 2.0f - 37.5);

  sf::Vector2f shieldOriginalPos = shield.getPosition();

  while (window.isOpen() && RunAnimation) {

    while (window.pollEvent(event))
    {
      // check the type of the event...
      switch (event.type)
      {
        // window closed
        case sf::Event::Closed:
          window.close();
          break; 

        default:
          break;
      }
    }

    // update
    float deltaTime = clock.restart().asSeconds();

    if (!impact) {
      sword.move(swordSpeed * deltaTime, 0);
      sword.rotate(rotationSpeed * deltaTime);

      if (sword.getGlobalBounds().intersects(shield.getGlobalBounds())) {
        impact = true;
        timer.restart();

        for (int i = 0; i < 10; i++) {
          Particle p;
          p.shape.setRadius(3);
          p.shape.setFillColor(sf::Color::Yellow);
          p.shape.setPosition(shield.getPosition().x + 20, shield.getPosition().y + 20);
          float angle = (std::rand() % 360) * 3.14159f / 180.f;
          float speed = 150.0f + std::rand() % 100;
          p.velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
          p.lifetime = 0.5f;
          particles.push_back(p);
        }
      }
    } 
    else if (timer.getElapsedTime().asSeconds() >= 1) {
      RunAnimation = false;
    }
    else {
      impactTimer += deltaTime;

      float reboundSpeed = -500.0f * std::exp(-5 * impactTimer);
      sword.move(reboundSpeed * deltaTime, 0);
      sword.rotate(std::sin(impactTimer * 15) * 15 * deltaTime);

      shield.setPosition(shieldOriginalPos.x + std::sin(impactTimer * 50) * 5, shieldOriginalPos.y);
    }

    for (auto it = particles.begin(); it != particles.end();) {
      it->shape.move(it->velocity * deltaTime);
      it->lifetime -= deltaTime;
      if (it->lifetime <= 0) {
        it = particles.erase(it);
      } else {
        ++it;
      }
    }

    // render
    window.clear();
    window.draw(Behind);
    draw_cards(window);

    window.draw(sword);
    window.draw(shield);

    for (const auto& p : particles) {
      window.draw(p.shape);
    }
    window.display();
  }

}


void InGameInterface::shield_vs_sword(sf::RenderWindow& window){
  init_anim(window);

  sword2.setPosition(sprites[PlayerTwoSelectedCard - 1].getPosition().x - sword2.getTexture()->getSize().x / 2.0f, sprites[PlayerTwoSelectedCard - 1].getPosition().y + CardSpriteHeight / 2.0f);
  sword2.setOrigin(sword2.getTexture()->getSize().x / 2, sword2.getTexture()->getSize().y / 2); 

  float swordSpeed = 500.0f;
  float rotationSpeed = 500.0f;

  bool RunAnimation = true;

  bool impact = false;

  float impactTimer = 0.0f;

  std::vector<Particle> particles;

  sf::Clock clock;
  sf::Clock timer;
  sf::Event event;

  shield.setPosition(sprites[PlayerOneSelectedCard - 1].getPosition().x + CardSpriteWidth, sprites[PlayerOneSelectedCard - 1].getPosition().y + CardSpriteHeight / 2.0f - 37.5);

  sf::Vector2f shieldOriginalPos = shield.getPosition();

  while (window.isOpen() && RunAnimation) {

    while (window.pollEvent(event))
    {
      // check the type of the event...
      switch (event.type)
      {
        // window closed
        case sf::Event::Closed:
          window.close();
          break; 

        default:
          break;
      }
    }

    // update
    float deltaTime = clock.restart().asSeconds();

    if (!impact) {
      sword2.move(-swordSpeed * deltaTime, 0);
      sword2.rotate(-rotationSpeed * deltaTime);

      if (sword2.getGlobalBounds().intersects(shield.getGlobalBounds())) {
        impact = true;
        timer.restart();

        for (int i = 0; i < 10; i++) {
          Particle p;
          p.shape.setRadius(3);
          p.shape.setFillColor(sf::Color::Yellow);
          p.shape.setPosition(shield.getPosition().x + 20, shield.getPosition().y + 20);
          float angle = (std::rand() % 360) * 3.14159f / 180.f;
          float speed = 150.0f + std::rand() % 100;
          p.velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
          p.lifetime = 0.5f;
          particles.push_back(p);
        }
      }
    } 
    else if (timer.getElapsedTime().asSeconds() >= 1) {
      RunAnimation = false;
    }
    else {
      impactTimer += deltaTime;

      float reboundSpeed = -500.0f * std::exp(-5 * impactTimer);
      sword2.move(-reboundSpeed * deltaTime, 0);
      sword2.rotate(-std::sin(impactTimer * 15) * 15 * deltaTime);

      shield.setPosition(shieldOriginalPos.x + std::sin(impactTimer * 50) * 5, shieldOriginalPos.y);
    }

    for (auto it = particles.begin(); it != particles.end();) {
      it->shape.move(it->velocity * deltaTime);
      it->lifetime -= deltaTime;
      if (it->lifetime <= 0) {
        it = particles.erase(it);
      } else {
        ++it;
      }
    }

    // render
    window.clear();
    window.draw(Behind);
    draw_cards(window);

    window.draw(sword2);
    window.draw(shield);

    for (const auto& p : particles) {
      window.draw(p.shape);
    }
    window.display();
  }

}


void InGameInterface::shield_vs_shield(sf::RenderWindow& window){
  init_anim(window);

  bool RunAnimation = true;

  sf::Clock timer;
  sf::Event event;

  while (window.isOpen() && RunAnimation) {

    while (window.pollEvent(event))
    {
      // check the type of the event...
      switch (event.type)
      {
        // window closed
        case sf::Event::Closed:
          window.close();
          break; 

        default:
          break;
      }
    }

    // update

    if (timer.getElapsedTime().asSeconds() >= 1) {
      RunAnimation = false;
    }

    // render
    window.clear();
    window.draw(Behind);

    sprites[PlayerOneSelectedCard - 1].setPosition((window.getSize().x - 3 * CardSpriteWidth)/2 - 30.f, (window.getSize().y - CardSpriteHeight)/2);
    window.draw(sprites[PlayerOneSelectedCard - 1]);

    shield.setPosition(sprites[PlayerOneSelectedCard - 1].getPosition().x + CardSpriteWidth, sprites[PlayerOneSelectedCard - 1].getPosition().y + CardSpriteHeight / 2.0f - 37.5);
    window.draw(shield);

    sprites[PlayerTwoSelectedCard - 1].setPosition((window.getSize().x - 3 * CardSpriteWidth)/2 - 30.f + 2 * (CardSpriteWidth + 30.f), (window.getSize().y - CardSpriteHeight)/2);
    window.draw(sprites[PlayerTwoSelectedCard - 1]);

    shield.setPosition(sprites[PlayerTwoSelectedCard - 1].getPosition().x - shield.getTexture()->getSize().x / 2.0f, sprites[PlayerTwoSelectedCard - 1].getPosition().y + CardSpriteHeight / 2.0f - 37.5);
    window.draw(shield);

    window.display();
  }

}


void InGameInterface::sword_vs_blank(sf::RenderWindow& window){
  init_anim(window);

  sword.setPosition(sprites[PlayerOneSelectedCard - 1].getPosition().x + CardSpriteWidth + sword2.getTexture()->getSize().x / 2.0f, sprites[PlayerOneSelectedCard - 1].getPosition().y + CardSpriteHeight / 2.0f);
  sword.setOrigin(sword.getTexture()->getSize().x / 2, sword.getTexture()->getSize().y / 2); 

  float swordSpeed = 500.0f;
  float rotationSpeed = 500.0f;

  bool RunAnimation = true;

  bool impact = false;

  float impactTimer = 0.0f;

  std::vector<Particle> particles;

  sf::Clock clock;
  sf::Clock timer;
  sf::Event event;


  shield.setPosition(sprites[PlayerTwoSelectedCard - 1].getPosition().x + shield.getTexture()->getSize().x, sprites[PlayerTwoSelectedCard - 1].getPosition().y + CardSpriteHeight / 2.0f - 37.5);

  sf::Vector2f shieldOriginalPos = shield.getPosition();

  while (window.isOpen() && RunAnimation) {

    while (window.pollEvent(event))
    {
      // check the type of the event...
      switch (event.type)
      {
        // window closed
        case sf::Event::Closed:
          window.close();
          break; 

        default:
          break;
      }
    }

    // update
    float deltaTime = clock.restart().asSeconds();

    if (!impact) {
      sword.move(swordSpeed * deltaTime, 0);
      sword.rotate(rotationSpeed * deltaTime);

      if (sword.getGlobalBounds().intersects(shield.getGlobalBounds())) {
        impact = true;
        timer.restart();

        for (int i = 0; i < 10; i++) {
          Particle p;
          p.shape.setRadius(3);
          p.shape.setFillColor(sf::Color::Yellow);
          p.shape.setPosition(shield.getPosition().x + 20, shield.getPosition().y + 20);
          float angle = (std::rand() % 360) * 3.14159f / 180.f;
          float speed = 150.0f + std::rand() % 100;
          p.velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
          p.lifetime = 0.5f;
          particles.push_back(p);
        }
      }
    } 
    else if (timer.getElapsedTime().asSeconds() >= 1) {
      RunAnimation = false;
    }
    else {
      impactTimer += deltaTime;

      float reboundSpeed = -500.0f * std::exp(-5 * impactTimer);
      sword.move(reboundSpeed * deltaTime, 0);
      sword.rotate(std::sin(impactTimer * 15) * 15 * deltaTime);

      shield.setPosition(shieldOriginalPos.x + std::sin(impactTimer * 50) * 5, shieldOriginalPos.y);
    }

    for (auto it = particles.begin(); it != particles.end();) {
      it->shape.move(it->velocity * deltaTime);
      it->lifetime -= deltaTime;
      if (it->lifetime <= 0) {
        it = particles.erase(it);
      } else {
        ++it;
      }
    }

    // render
    window.clear();
    window.draw(Behind);
    draw_cards(window);

    window.draw(sword);

    for (const auto& p : particles) {
      window.draw(p.shape);
    }
    window.display();
  }

}


void InGameInterface::blank_vs_sword(sf::RenderWindow& window){
  init_anim(window);

  sword2.setPosition(sprites[PlayerTwoSelectedCard - 1].getPosition().x - sword2.getTexture()->getSize().x / 2.0f, sprites[PlayerTwoSelectedCard - 1].getPosition().y + CardSpriteHeight / 2.0f);
  sword2.setOrigin(sword2.getTexture()->getSize().x / 2, sword2.getTexture()->getSize().y / 2); 

  float swordSpeed = 500.0f;
  float rotationSpeed = 500.0f;

  bool RunAnimation = true;

  bool impact = false;

  float impactTimer = 0.0f;

  std::vector<Particle> particles;

  sf::Clock clock;
  sf::Clock timer;
  sf::Event event;

  shield.setPosition(sprites[PlayerOneSelectedCard - 1].getPosition().x + CardSpriteWidth - shield.getTexture()->getSize().x, sprites[PlayerOneSelectedCard - 1].getPosition().y + CardSpriteHeight / 2.0f - 37.5);

  sf::Vector2f shieldOriginalPos = shield.getPosition();

  while (window.isOpen() && RunAnimation) {

    while (window.pollEvent(event))
    {
      // check the type of the event...
      switch (event.type)
      {
        // window closed
        case sf::Event::Closed:
          window.close();
          break; 

        default:
          break;
      }
    }

    // update
    float deltaTime = clock.restart().asSeconds();

    if (!impact) {
      sword2.move(-swordSpeed * deltaTime, 0);
      sword2.rotate(-rotationSpeed * deltaTime);

      if (sword2.getGlobalBounds().intersects(shield.getGlobalBounds())) {
        impact = true;
        timer.restart();

        for (int i = 0; i < 10; i++) {
          Particle p;
          p.shape.setRadius(3);
          p.shape.setFillColor(sf::Color::Yellow);
          p.shape.setPosition(shield.getPosition().x + 20, shield.getPosition().y + 20);
          float angle = (std::rand() % 360) * 3.14159f / 180.f;
          float speed = 150.0f + std::rand() % 100;
          p.velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
          p.lifetime = 0.5f;
          particles.push_back(p);
        }
      }
    } 
    else if (timer.getElapsedTime().asSeconds() >= 1) {
      RunAnimation = false;
    }
    else {
      impactTimer += deltaTime;

      float reboundSpeed = -500.0f * std::exp(-5 * impactTimer);
      sword2.move(-reboundSpeed * deltaTime, 0);
      sword2.rotate(-std::sin(impactTimer * 15) * 15 * deltaTime);

      shield.setPosition(shieldOriginalPos.x + std::sin(impactTimer * 50) * 5, shieldOriginalPos.y);
    }

    for (auto it = particles.begin(); it != particles.end();) {
      it->shape.move(it->velocity * deltaTime);
      it->lifetime -= deltaTime;
      if (it->lifetime <= 0) {
        it = particles.erase(it);
      } else {
        ++it;
      }
    }

    // render
    window.clear();
    window.draw(Behind);
    draw_cards(window);

    window.draw(sword2);

    for (const auto& p : particles) {
      window.draw(p.shape);
    }
    window.display();
  }

}



void InGameInterface::AttackAnimation (sf::RenderWindow& window, ZoneType type, Player* p1){
  if(p1 == player1){
    switch (type)
    {
      case Sword:
        sword_vs_sword(window);  
        break;

      case Shield:
        sword_vs_shield(window);
        break;

      case Blank:
        sword_vs_blank(window);
        break;

      default:
        break;
    }
  }
  else{
    switch (type)
    {
      case Sword:
        sword_vs_sword(window);
        break;

      case Shield:
        shield_vs_sword(window); 
        break;

      case Blank:
        blank_vs_sword(window);       
        break;

      default:
        break;
    }
  }
}
