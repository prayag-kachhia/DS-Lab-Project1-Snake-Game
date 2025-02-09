#include <iostream>
#include <conio.h>      // For _kbhit() and _getch()
#include <windows.h>    // For Sleep() and console functions
#include <vector>

using namespace std;

bool gameOver;
const int width = 30, height = 20;
int x, y, foodX, foodY, score, level;
vector<pair<int, int>> snake;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

// Function to move cursor without flickering
void GotoXY(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(console, coord);
}

// Function to hide the cursor
void HideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = false; 
    SetConsoleCursorInfo(console, &cursorInfo);
}

// Function to set up initial game state
void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2; 
    y = height / 2;
    foodX = rand() % width;
    foodY = rand() % height;
    score = 0;
    level = 1;
    snake.clear();
    snake.push_back({x, y});
    HideCursor(); // Hide cursor for smooth gameplay
}

// Function to draw the game board without flickering
void Draw() {
    GotoXY(0, 0);

    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#";

            if (i == y && j == x) cout << "O"; // Head
            else if (i == foodY && j == foodX) cout << "*"; // Food
            else {
                bool print = false;
                for (auto s : snake) {
                    if (s.first == j && s.second == i) {
                        cout << "o";
                        print = true;
                        break;
                    }
                }
                if (!print) cout << " ";
            }

            if (j == width - 1) cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << "\nScore: " << score << "   Level: " << level << endl;
}

// Function to take input for direction
void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': case 'A': if (dir != RIGHT) dir = LEFT; break;
            case 'd': case 'D': if (dir != LEFT) dir = RIGHT; break;
            case 'w': case 'W': if (dir != DOWN) dir = UP; break;
            case 's': case 'S': if (dir != UP) dir = DOWN; break;
            case 'x': gameOver = true; break;
        }
    }
}

// Function to update snake position
void Logic() {
    int prevX = snake[0].first, prevY = snake[0].second;
    int prev2X, prev2Y;
    snake[0] = {x, y};

    for (size_t i = 1; i < snake.size(); i++) {
        prev2X = snake[i].first;
        prev2Y = snake[i].second;
        snake[i] = {prevX, prevY};
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        default: break;
    }

    // Check for collisions
    if (x < 0 || x >= width || y < 0 || y >= height) gameOver = true;
    for (size_t i = 1; i < snake.size(); i++) {
        if (snake[i].first == x && snake[i].second == y) gameOver = true;
    }

    // Eat food
    if (x == foodX && y == foodY) {
        score += 10;
        snake.push_back({foodX, foodY});

        // Generate new food position ensuring it's not on the snake
        bool validFoodPosition;
        do {
            validFoodPosition = true;
            foodX = rand() % width;
            foodY = rand() % height;
            for (const auto& segment : snake) {
                if (segment.first == foodX && segment.second == foodY) {
                    validFoodPosition = false;
                    break;
                }
            }
        } while (!validFoodPosition);

        // Increase level every 50 points
        if (score % 50 == 0) {
            level++;
        }
    }
}

// Main function
int main() {
while (1) {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(120 - (level * 10)); // Speed increases with level
    }
    cout << "\nGame Over! Final Score: " << score << "  Level Reached: " << level << endl;
    Sleep(7000);

}
    return 0;
}