Snake Game (C++ Console Version)

A simple Snake Game implemented in C++ using Windows API for console manipulation. The game features smooth rendering with minimal flickering, user-controlled snake movement, and a dynamically growing snake upon eating food.

Features

🐍 Smooth snake movement with no flickering

🍎 Random food generation avoiding collisions with the snake

⌨ Keyboard controls for movement

🏆 Score tracking

❌ Game over on self-collision or wall collision


Requirements

Windows OS (Uses windows.h)

C++ compiler (G++ or Clang with Windows support)


Installation & Compilation

1. Clone this repository or copy the source code:

git clone https://github.com/your-repo/snake-game.git
cd snake-game


2. Compile the code using G++:

g++ snake_game.cpp -o snake.exe


3. Run the executable:

./snake.exe



Controls

How to Play

Move the snake using WASD keys

Eat food (*) to increase score and grow the snake

Avoid colliding with walls or your own tail

Press X to quit the game


Code Structure

The game is encapsulated in the SnakeGame class for better maintainability:

Setup() – Initializes game variables and settings

Draw() – Renders the game board efficiently

Input() – Reads player input without blocking

Logic() – Handles movement, collision detection, and food mechanics

Run() – Main game loop


Upcoming Features (TODO)

🔄 Enable Wrap-Around Mode (Snake can pass through walls)

🎨 Customizable Game Speed & Themes

🎵 Sound Effects on Food & Game Over


License

This project is open-source and available under the MIT License.


---
