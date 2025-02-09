# DS-Lab-Project1-Snake-Game
# Snake Game in C++

## Overview
This is a simple **Snake Game** implemented in C++ using the **console** for rendering. The game utilizes **Windows API functions** to enhance console manipulation, preventing screen flickering for a smooth gameplay experience.

## Features
- **Classic Snake Mechanics**: Move the snake to eat food and grow.
- **Smooth Console Rendering**: Uses `GotoXY` and `HideCursor` functions to minimize flickering.
- **Dynamic Speed**: Snake speed increases as you level up.
- **Collision Handling**: Ends game if the snake collides with itself or the wall.
- **Score & Level System**: Earn points and level up after every 50 points.

## Controls
- `W` - Move Up
- `S` - Move Down
- `A` - Move Left
- `D` - Move Right
- `X` - Exit Game

## How It Works
1. The snake starts in the middle of the screen.
2. Move the snake to eat food (`*`), which increases the score and length.
3. Avoid colliding with walls or yourself.
4. The game speeds up as you level up.
5. The game ends when the snake crashes.

## Dependencies
- **Windows OS** (Due to use of `<windows.h>`, `_kbhit()`, `_getch()`)
- **C++ Compiler** (MinGW/GCC recommended for Windows users)

## Compilation & Execution
1. Open terminal/cmd in the directory containing `Lab2.cpp`.
2. Compile using:
   ```sh
   g++ Lab2.cpp -o snake_game.exe
   ```
3. Run the executable:
   ```sh
   snake_game.exe
   ```

## Notes
- Uses `Sleep()` to control game speed.
- Random food placement ensures it does not overlap with the snake.
- Uses vector `snake` to store body positions dynamically.

## Author
- **Your Name** (Modify this as needed)

Enjoy the game! 🐍🎮

