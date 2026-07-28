#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

inline void drawHelpMenu(sf::RenderWindow& window) {
    // Создаем полупрозрачную подложку
    sf::RectangleShape overlay(sf::Vector2f(320.0f, 160.0f));
    overlay.setFillColor(sf::Color(0, 0, 0, 200)); // Черный с прозрачностью
    overlay.setPosition(10.0f, 10.0f);

    // Загрузка шрифта (убедись, что файл arial.ttf есть в папке проекта)
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        // Если шрифта нет, просто рисуем подложку без текста, чтобы игра не вылетала
        window.draw(overlay);
        return;
    }

    std::vector<std::string> lines = {
        "Управление в игре:",
        " СТРЕЛКА ВЛЕВО  - Идти влево",
        " СТРЕЛКА ВПРАВО - Идти вправо",
        " Удерживайте [ H ] - Справка"
    };

    window.draw(overlay);

    // Отрисовка строк текста
    float yOffset = 20.0f;
    for (const auto& line : lines) {
        sf::Text text;
        text.setFont(font);
        text.setString(line);
        text.setCharacterSize(16);
        text.setFillColor(sf::Color::White);
        text.setPosition(25.0f, yOffset);
        window.draw(text);
        yOffset += 30.0f;
    }
}
