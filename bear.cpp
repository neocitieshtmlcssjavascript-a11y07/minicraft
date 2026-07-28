#include <SFML/Graphics.hpp>

class Bear {
public:
    sf::RectangleShape sprite;
    float x, y;
    float speed;
    int direction; // 1 = вправо, -1 = влево
    int walkTimer;

    Bear(float startX, float startY) {
        x = startX;
        y = startY;
        speed = 1.5f;
        direction = 1;
        walkTimer = 0;

        sprite.setSize(sf::Vector2f(60.0f, 40.0f)); // Медведь шире игрока
        sprite.setFillColor(sf::Color(101, 67, 33)); // Коричневый цвет кубика
        sprite.setPosition(x, y);
    }

    void update(float screenWidth) {
        // Простой ИИ: меняет направление каждые 100 кадров или у границ экрана
        x += speed * direction;
        walkTimer++;

        if (walkTimer > 100 || x <= 0 || x >= screenWidth - 60) {
            direction *= -1;
            walkTimer = 0;
        }

        sprite.setPosition(x, y);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }
};
