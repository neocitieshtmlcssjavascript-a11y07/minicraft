#include <iostream>
#include <vector>
#include <windows.h>

const int WIDTH = 40;
const int HEIGHT = 15;

int main() {
    int playerX = WIDTH / 2;
    int playerY = 6;

    // Скрытие курсора консоли
    void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);

    while (true) {
        // Установка курсора в начало экрана (убирает мерцание)
        COORD coord = {0, 0};
        SetConsoleCursorPosition(handle, coord);

        // Управление
        if (GetAsyncKeyState(VK_LEFT) & 0x8000 && playerX > 0) playerX--;
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && playerX < WIDTH - 1) playerX++;
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) break;

        // Отрисовка кадра
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                if (x == playerX && y == playerY) std::cout << "P"; // Игрок
                else if (y < 7) std::cout << " ";                  // Небо
                else if (y == 7) std::cout << "w";                 // Трава
                else if (y > 7 && y < 11) std::cout << ".";        // Земля
                else std::cout << "#";                             // Камень
            }
            std::cout << "\n";
        }
        Sleep(30); // Ограничение FPS
    }
    return 0;
}
