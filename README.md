# Pop-Up-Duel

### Requirements

- git
- g++
- make
- SFML library

### How to install

Clone the repo then launch with :
```
git clone https://github.com/myumally/Pop-Up-Duel.git
cd  Pop-Up-Duel
make 
./pop <adress IP of your Opponent>
```

If needed install the SFML library with :
```
sudo apt-get install libsfml-dev
```

### To-Do List

- [x] Makefile
- [x] Card Class
  - [x] Constructor
  - [x] Getters and Setters
  - [x] ZoneTypes and Colours
  - [x] Specials Management
  - [x] Crystal Ability
- [x] Player Class
  - [x] Constructor
  - [x] Getters and Setters
  - [x] LP (Life Points) Management Methods
  - [x] Deck Management Methods
  - [x] CP (Crystal Points) Management Methods
  - [x] Stealing CP from another player (needed for some Specials)
- [ ] Specials Class
    - [x] Specials
    - [x] Crystal Ability
    - [ ] Tricky Attacks
- [ ] Cards
  - [x] Images
  - [ ] All cards available
    - [x] Ids
    - [x] Monster Names
    - [x] Attack Names
    - [x] Card Colours
    - [x] Sword Zones 
    - [x] Guard Zones
    - [x] Effects
    - [x] Strength
    - [x] Specials
    - [x] Crystal Ability
    - [ ] Tricky Attacks
- [ ] User Interface
  - [x] Choosing what to use for graphics -> **SFML**
  - [x] Deck Creation Menu
  - [ ] Home Menu
  - [ ] InGame Interface
    - [x] Each player draw 3 cards from their deck
    - [x] Active player cards in the center
    - [x] Opponent card's colours in the corner
    - [x] Player's names and LP
    - [x] Player's CP
    - [x] Player's Effects
    - [x] 15 seconds to choose a card
    - [ ] Combat Phase
        - [x] LP Management
        - [x] CP Management
        - [x] Hand Management
        - [x] Priority Management
        - [x] Effects Management
        - [x] Specials
        - [x] Crystal Ability
        - [ ] Little Animation
    - [x] End of the game
- [x] Network Play
    - [x] Local Network Play
