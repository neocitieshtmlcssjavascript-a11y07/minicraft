#include <SFML/Graphics.hpp>
#include <vector>

// Константы размеров окна и блоков
const int WIDTH = 800;
const int HEIGHT = 600;
const int BLOCK_SIZE = 40;
const int COLS = WIDTH / BLOCK_SIZE;
const int ROWS = HEIGHT / BLOCK_SIZE;

int main() {
    // Создание окна игры
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Mini-Minecraft 2D (C++)");
    window.setFramerateLimit(60);

    // Определение цветов
    sf::Color skyColor(135, 206, 235);
    sf::Color grassColor(34, 139, 34);
    sf::Color dirtColor(139, 69, 19);
    sf::Color stoneColor(128, 128, 128);

    // Генерация мира (0-воздух, 1-трава, 2-земля, 3-камень)
    std::vector<std::vector<int>> world(ROWS, std::vector<int>(COLS, 0));
    
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (row < ROWS / 2) {
                world[row][col] = 0; // Воздух
            } else if (row == ROWS / 2) {
                world[row][col] = 1; // Трава
            } else if (row < ROWS / 2 + 3) {
                world[row][col] = 2; // Земля
            } else {
                world[row][col] = 3; // Камень
            }
        }
    }

    // Параметры игрока (красный квадрат)
    sf::RectangleShape player(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    player.setFillColor(sf::Color::Red);
    
    float playerX = WIDTH / 2.0f;
    float playerY = (ROWS / 2 - 1) * BLOCK_SIZE;
    float playerSpeed = 5.0f;

    // Шаблон для отрисовки блоков мира
    sf::RectangleShape block(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));

    // Игровой цикл
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Управление персонажем (Влево / Вправо)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerX > 0) {
            playerX -= playerSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerX < WIDTH - BLOCK_SIZE) {
            playerX += playerSpeed;
        }

        // Обновление позиции игрока
        player.setPosition(playerX, playerY);

        // Очистка экрана цветом неба
        window.clear(skyColor);

        // Отрисовка блоков мира
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                int blockType = world[row][col];
                if (blockType == 0) continue; // Воздух не рисуем

                if (blockType == 1) block.setFillColor(grassColor);
                else if (blockType == 2) block.setFillColor(dirtColor);
                else if (blockType == 3) block.setFillColor(stoneColor);

                block.setPosition(col * BLOCK_SIZE, row * BLOCK_SIZE);
                window.draw(block);
            }
        }

        // Отрисовка игрока
        window.draw(player);

        // Вывод кадра на экран
        window.display();
    }

    return 0;
}
