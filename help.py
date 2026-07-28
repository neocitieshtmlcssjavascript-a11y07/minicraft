import pygame

# Инициализация шрифтов
pygame.font.init()
FONT = pygame.font.SysFont("Arial", 20)

def draw_help_menu(screen):
    """Отрисовывает полупрозрачное окно справки на экране."""
    # Создаем полупрозрачную подложку (ширина 300, высота 150)
    overlay = pygame.Surface((300, 150), pygame.SRCALPHA)
    overlay.fill((0, 0, 0, 200)) # Черный цвет с прозрачностью 200 из 255
    
    # Текст подсказок
    lines = [
        "Управление в игре:",
        " СТРЕЛКА ВЛЕВО — Идти влево",
        " СТРЕЛКА ВПРАВО — Идти вправо",
        " Удерживайте [ H ] — Справка",
    ]
    
    # Рендерим и накладываем строки текста
    y_offset = 15
    for line in lines:
        text_surface = FONT.render(line, True, (255, 255, 255)) # Белый текст
        overlay.blit(text_surface, (15, y_offset))
        y_offset += 30
        
    # Выводим окно в левый верхний угол экрана (с отступом 10 пикселей)
    screen.blit(overlay, (10, 10))
