# Snake Game in C++

## Overview

This is a simple Snake game implemented in C++ using the Windows Console API. The game features a moving snake that grows as it eats food while avoiding collisions with walls and itself.

## Features

- Classic Snake gameplay
- Real-time keyboard input for movement
- Food spawning at random positions
- Growing snake on food consumption
- Collision detection with walls and self
- Score tracking
- Console-based UI with simple graphics

## Controls

- **W / w** - Move Up
- **S / s** - Move Down
- **A / a** - Move Left
- **D / d** - Move Right
- **X / x** - Exit the game

## How to Play

1. Run the compiled executable.
2. Use the controls to navigate the snake.
3. Eat the `*` symbol to grow and increase your score.
4. Avoid colliding with the walls and yourself.
5. Press `X` to exit the game.
6. The game ends if you hit a wall or yourself, displaying your final score.

## Compilation and Execution

### Using g++ (MinGW on Windows):

```
g++ -o snake_game snake_game.cpp -std=c++11
snake_game.exe
```

### Using Visual Studio:

1. Open the project in Visual Studio.
2. Compile and run the project.

## Requirements

- Windows OS
- C++ Compiler (MinGW, MSVC, etc.)
- Console-based execution

## Notes

- This game uses `windows.h` for console manipulation, so it is Windows-specific.
- `conio.h` is used for non-blocking keyboard input.
- Uses `Sleep(100)` for controlling game speed.

##
