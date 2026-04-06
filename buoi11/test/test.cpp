#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

const int W = 30, H = 20;

struct Point { int x, y; };

// ── Console helpers ──────────────────────────────────────────
void gotoxy(int x, int y) {
    COORD c = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void hideCursor() {
    CONSOLE_CURSOR_INFO ci = { 1, FALSE };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
}
void setColor(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// ── Game state ───────────────────────────────────────────────
vector<Point> snake;
Point food;
int dx = 1, dy = 0;
int ndx = 1, ndy = 0;
int score = 0, best = 0, level = 1;
bool running = true;

void spawnFood() {
    do {
        food = { rand() % W, rand() % H };
    } while ([&]() {
        for (auto& s : snake) if (s.x == food.x && s.y == food.y) return true;
        return false;
        }());
}

void drawBorder() {
    setColor(8); // dark gray
    gotoxy(0, 0);
    cout << char(201);
    for (int i = 0; i < W; i++) cout << char(205) << char(205);
    cout << char(187);
    for (int i = 0; i < H; i++) {
        gotoxy(0, i + 1); cout << char(186);
        gotoxy(W * 2 + 1, i + 1); cout << char(186);
    }
    gotoxy(0, H + 1); cout << char(200);
    for (int i = 0; i < W; i++) cout << char(205) << char(205);
    cout << char(188);
}

void drawHUD() {
    setColor(7);
    gotoxy(0, H + 2);
    cout << "  Score: ";
    setColor(10); cout << score;
    setColor(7); cout << "   Best: ";
    setColor(14); cout << best;
    setColor(7); cout << "   Level: ";
    setColor(11); cout << level;
    cout << "   [WASD / Arrow Keys]   [Q: Quit]   ";
}

void draw() {
    // Clear interior
    setColor(0);
    for (int y = 0; y < H; y++) {
        gotoxy(1, y + 1);
        for (int x = 0; x < W; x++) cout << "  ";
    }

    // Food
    setColor(12); // red
    gotoxy(food.x * 2 + 1, food.y + 1);
    cout << char(4) << ' '; // diamond

    // Snake body
    for (int i = (int)snake.size() - 1; i >= 0; i--) {
        auto& s = snake[i];
        if (i == 0) {
            setColor(10); // bright green head
            gotoxy(s.x * 2 + 1, s.y + 1);
            cout << char(2) << ' '; // head symbol
        }
        else {
            setColor(i % 2 == 0 ? 2 : 6); // green / dark yellow body
            gotoxy(s.x * 2 + 1, s.y + 1);
            cout << char(254) << ' '; // small square
        }
    }

    drawHUD();
    setColor(7);
}

bool collide(Point p) {
    if (p.x < 0 || p.x >= W || p.y < 0 || p.y >= H) return true;
    for (auto& s : snake) if (s.x == p.x && s.y == p.y) return true;
    return false;
}

void tick() {
    dx = ndx; dy = ndy;
    Point head = { snake[0].x + dx, snake[0].y + dy };

    if (collide(head)) { running = false; return; }

    snake.insert(snake.begin(), head);

    if (head.x == food.x && head.y == food.y) {
        score += 10 * level;
        if (score > best) best = score;
        if (score % (50 * level) == 0 && level < 10) level++;
        spawnFood();
    }
    else {
        snake.pop_back();
    }
}

void input() {
    if (!_kbhit()) return;
    int key = _getch();
    if (key == 224 || key == 0) key = _getch(); // special keys
    switch (key) {
    case 'w': case 'W': case 72: if (dy != 1) { ndx = 0; ndy = -1; } break;
    case 's': case 'S': case 80: if (dy != -1) { ndx = 0; ndy = 1; } break;
    case 'a': case 'A': case 75: if (dx != 1) { ndx = -1;ndy = 0; } break;
    case 'd': case 'D': case 77: if (dx != -1) { ndx = 1;ndy = 0; } break;
    case 'q': case 'Q': running = false; break;
    }
}

void gameOver() {
    gotoxy(W - 4, H / 2);
    setColor(12);
    cout << " GAME OVER! ";
    gotoxy(W - 6, H / 2 + 1);
    setColor(7);
    cout << " Score: " << score << " | Best: " << best;
    gotoxy(W - 5, H / 2 + 2);
    cout << " Nhan phim bat ky... ";
    while (_kbhit()) _getch();
    _getch();
}

int main() {
    srand((unsigned)time(0));
    hideCursor();
    system("cls");
    system("title SNAKE - C++");

    // Init snake
    snake = { {10,10},{9,10},{8,10} };
    spawnFood();
    drawBorder();

    int frameDelay = 150;

    while (running) {
        input();
        tick();
        if (!running) break;
        draw();

        // Speed up with level
        frameDelay = max(60, 150 - (level - 1) * 12);
        Sleep(frameDelay);
    }

    gameOver();
    setColor(7);
    gotoxy(0, H + 4);
    return 0;
} 
