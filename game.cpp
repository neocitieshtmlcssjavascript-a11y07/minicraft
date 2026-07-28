#include <SFML/Graphics.hpp>
#include <vector>
#include "help.hpp" // Подключаем наш аналог help.py

const int WIDTH = 800;
const int HEIGHT = 600;
const int BLOCK_SIZE = 40;
const int COLS = WIDTH / BLOCK_SIZE;
const int ROWS = HEIGHT / BLOCK_SIZE;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Мини-Майнкрафт 2D (game.cpp)");
    window.setFramerateLimit(60);

    sf::Color skyColor(135, 206, 235);
    sf::Color grassColor(34, 139, 34);
    sf::Color dirtColor(139, 69, 19);
    sf::Color stoneColor(128, 128, 128);

    // Генерация плоского мира
    std::vector<std::vector<int>> world(ROWS, std::vector<int>(COLS, 0));
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (row < ROWS / 2) world[row][col] = 0;
            else if (row == ROWS / 2) world[row][col] = 1;
            else if (row < ROWS / 2 + 3) world[row][col] = 2;
            else world[row][col] = 3;
        }
    }

    // Персонаж
    sf::RectangleShape player(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    player.setFillColor(sf::Color::Red);
    float playerX = WIDTH / 2.0f;
    float playerY = (ROWS / 2 - 1) * BLOCK_SIZE;
    float playerSpeed = 5.0f;

    sf::RectangleShape block(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Движение
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerX > 0) {
            playerX -= playerSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerX < WIDTH - BLOCK_SIZE) {
            playerX += playerSpeed;
        }
        player.setPosition(playerX, playerY);

        // Отрисовка
        window.clear(skyColor);

        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                int blockType = world[row][col];
                if (blockType == 0) continue;

                if (blockType == 1) block.setFillColor(grassColor);
                else if (blockType == 2) block.setFillColor(dirtColor);
                else if (blockType == 3) block.setFillColor(stoneColor);

                block.setPosition(col * BLOCK_SIZE, row * BLOCK_SIZE);
                window.draw(block);
            }
        }

        window.draw(player);

        // ЕСЛИ НАЖАТА КЛАВИША 'H' — вызываем функцию из help.hpp
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
            drawHelpMenu(window);
        }

        window.display();
    }

    return 0;
}
