#include <SFML/Graphics.hpp>
#include <vector>
#include "godoblocks.hpp" // Структура ID блоков
#include "blocks.cpp"     // Функции мышки (breakBlock, placeBlock)
#include "bear.cpp"       // Моб Медведь

const int WIDTH = 800;
const int HEIGHT = 600;
const int ROWS = HEIGHT / BLOCK_SIZE;
const int COLS = WIDTH / BLOCK_SIZE;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Minecraft 2D: Blocks & Mobs");
    window.setFramerateLimit(60);

    // Инициализация карты мира
    std::vector<std::vector<int>> world(ROWS, std::vector<int>(COLS, 0));
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (row == ROWS / 2) world[row][col] = GRASS;
            else if (row > ROWS / 2 && row < ROWS / 2 + 3) world[row][col] = DIRT;
            else if (row >= ROWS / 2 + 3) world[row][col] = STONE;
        }
    }

    // Создание игрока
    sf::RectangleShape player(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    player.setFillColor(sf::Color::Red);
    float playerX = WIDTH / 2.0f;
    float playerY = (ROWS / 2 - 1) * BLOCK_SIZE;

    // Спавн медведя на поверхности земли
    Bear bear(100.0f, (ROWS / 2 - 1) * BLOCK_SIZE + 10); 

    sf::RectangleShape blockRender(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        // Движение игрока
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerX > 0) playerX -= 4.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerX < WIDTH - BLOCK_SIZE) playerX += 4.0f;
        player.setPosition(playerX, playerY);

        // Работа с блоками через мышь
        breakBlock(window, world);               // ЛКМ — ломать блок
        placeBlock(window, world, WOOD);         // ПКМ — ставить дерево (доски)

        // Обновление мобов
        bear.update(WIDTH);

        // Рендеринг кадра
        window.clear(sf::Color(135, 206, 235)); // Небо

        // Отрисовка сетки блоков
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                int type = world[row][col];
                if (type == AIR) continue;

                if (type == GRASS) blockRender.setFillColor(sf::Color(34, 139, 34));
                else if (type == DIRT) blockRender.setFillColor(sf::Color(139, 69, 19));
                else if (type == STONE) blockRender.setFillColor(sf::Color(128, 128, 128));
                else if (type == WOOD) blockRender.setFillColor(sf::Color(205, 133, 63)); // Цвет дерева

                blockRender.setPosition(col * BLOCK_SIZE, row * BLOCK_SIZE);
                window.draw(blockRender);
            }
        }

        // Рисуем персонажей
        window.draw(player);
        bear.draw(window);

        window.display();
    }
    return 0;
}
