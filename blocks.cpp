#include <SFML/Graphics.hpp>
#include <vector>

const int BLOCK_SIZE = 40;

// Функция для разрушения блока (ставит воздух)
void breakBlock(sf::RenderWindow& window, std::vector<std::vector<int>>& world) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        int col = mousePos.x / BLOCK_SIZE;
        int row = mousePos.y / BLOCK_SIZE;

        // Проверяем границы массива
        if (row >= 0 && row < world.size() && col >= 0 && col < world[0].size()) {
            world[row][col] = 0; // Превращаем в воздух
        }
    }
}

// Функция для установки блока (например, дерева/досок)
void placeBlock(sf::RenderWindow& window, std::vector<std::vector<int>>& world, int currentBlockType) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        int col = mousePos.x / BLOCK_SIZE;
        int row = mousePos.y / BLOCK_SIZE;

        if (row >= 0 && row < world.size() && col >= 0 && col < world[0].size()) {
            if (world[row][col] == 0) { // Ставим только на пустое место
                world[row][col] = currentBlockType;
            }
        }
    }
}
