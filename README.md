# Pop-Up-Duel

### Requirements

- git
- g++
- make (If you're on Windows you don't need it)
- SFML library

## How to install (Linux)

### Clone the repo then launch with :
```
git clone https://github.com/myumally/Pop-Up-Duel.git
cd  Pop-Up-Duel
make 
./pop <adress IP of your Opponent>
```
Note that if you do not know your opponent's IP you can just use ``` ./pop ``` then your IP will be printed in the terminal. Then your opponent can use ``` ./pop <your IP> ```

### If needed install the SFML library with :
```
sudo apt-get install libsfml-dev
```

## How to install (Windows)

### Clone the repo then launch with :
```
git clone https://github.com/myumally/Pop-Up-Duel.git
cd  Pop-Up-Duel
./build.bat
./pop <adress IP of your Opponent>
```
Note that if you do not know your opponent's IP you can just use ``` ./pop ``` then your IP will be printed in the terminal. Then your opponent can use ``` ./pop <your IP> ```

### If needed install the SFML library :
- First go on the official site to download *sfml-2.6.2* : https://www.sfml-dev.org/download/sfml/2.6.2/
- Download the version **GCC 13.1.0 MinGW (SEH) - 64-bit**
- Extract the file in **C:**
- Add the path using the powershell in admin mode : 
```
[System.Environment]::SetEnvironmentVariable("Path", $env:Path + ";C:\SFML-2.6.2\bin", [System.EnvironmentVariableTarget]::Machine)
```
- If you can't acced the powershell in admin mode, add the path only for the current session :
```
$env:PATH += ";C:\SFML-2.6.2\bin"
```

### If you do not have gcc/g++ :
- install MSYS2 using the powershell
```
winget install -e --id MSYS2.MSYS2
```
- open MSYS2 MINGW64 and install gcc using pacman : 
```
pacman -S mingw-w64-x86_64-gcc
```
- Add the path using the powershell in admin mode : 
```
[System.Environment]::SetEnvironmentVariable("Path", $env:Path + ";C:\msys64\mingw64\bin", [System.EnvironmentVariableTarget]::Machine)
```
- If you can't acced the powershell in admin mode, add the path only for the current session :
```
$env:PATH += ";C:\msys64\mingw64\bin"
```
- You can find other method on internet

### If you do not have git :
- install git using the powershell

```
winget install --id Git.Git -e --source winget
```

## To-Do List

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
- [x] Specials Class
    - [x] Specials
    - [x] Crystal Ability
    - [x] Tricky Attacks
- [x] Cards
  - [x] Images
  - [x] All cards available
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
    - [x] Tricky Attacks
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
- [x] Work on Windows
