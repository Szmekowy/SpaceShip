# Space Battle

### General info

Space Battle is an arcade-style shooter inspired by the classic game Warblade. Players take control of a spaceship and battle against waves of enemy ships. The game features an upgrade system that allows players to enhance their weapons, increase their fire rate, and collect coins dropped by defeated enemies. The game progressively increases in difficulty, offering a thrilling challenge with each new level. It was developed using C++ with the SDL2 and SDL_mixer libraries.


#### Key Features:

* Dynamic Enemy Waves: Increasingly difficult enemy formations challenge the player.

* Upgradeable Weapons: Purchase enhanced projectiles and boost fire rate.

* Coin Collection System: Enemies have a chance to drop coins that can be used for upgrades.

* Progressive Difficulty: Each level becomes more challenging, testing the player’s skills.
  
* Immersive Sound Effects: Integrated audio using SDL_mixer to enhance gameplay.

### Technologies

The project is created with:

C++

SDL2

SDL_mixer

### Setup

To compile and run the game, follow these steps:

#### Linux (GCC)

1) Ensure you have SDL2 and SDL_mixer installed on your system.

    a) On Ubuntu/Debian: sudo apt-get install libsdl2-dev libsdl2-mixer-dev

    b)On macOS: brew install sdl2 sdl2_mixer

2) Clone the repository

3) Navigate to the project directory: cd SDLTEST/SDLTEST

 4) Compile the game:

    add every cpp to comand line for example :

    g++ -o space_battle main.cpp Game.cpp Info.cpp Enemy.cpp EnemyAttack.cpp ... -lSDL2 -lSDL2_mixer

6) Run the game: ./space_battle

#### Windows (Visual Studio)
0) source files are located in SDLTEST/SDLTEST

1) Install Visual Studio with C++ development tools.

2) Install SDL2 and SDL_mixer development libraries.

3) Open Visual Studio and create a new C++ project.

4) Add all source files (main.cpp, game.cpp, etc.) to the project.

5) Configure the project:

    a) Add SDL2 and SDL_mixer include directories.

    b) Link SDL2 and SDL_mixer libraries.

6) Build and run the project.

### How to play

* Use Arrow Keys to move the spaceship.

* Press CTRL to shoot.

* Destroy enemy ships to earn coins.

* Spend coins to upgrade weapons and increase fire rate.

* Survive waves of enemies and progress through levels.

### Conclusions

The game is currently complete, but future improvements could include:

* More enemy types with unique attack patterns.

* Additional power-ups and ship customizations.

* Expanded levels with varying environments and challenges.

### License

This project is licensed under the MIT License.

### Author & Contact

This project is maintained by Szymon Drywa.

For any suggestions, feedback, or inquiries, please reach out via:

Email: szmekdrywa@wp.pl

GitHub: https://github.com/Szmekowy
