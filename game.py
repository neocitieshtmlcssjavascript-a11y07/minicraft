import pygame
import sys
import help  # Импортируем наш новый файл help.py

# Инициализация библиотеки
pygame.init()

# Настройки окна игры
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Мини-Майнкрафт 2D с подсказками")

# Цвета (RGB)
SKY_BLUE = (135, 206, 235)
GREEN = (34, 139, 34)
BROWN = (139, 69, 19)
GRAY = (128, 128, 128)
RED = (255, 0, 0)

# Размеры блоков и сетки
BLOCK_SIZE = 40
COLS = WIDTH // BLOCK_SIZE
ROWS = HEIGHT // BLOCK_SIZE

# Генерация плоского мира
world = []
for row in range(ROWS):
    world_row = []
    for col in range(COLS):
        if row < ROWS // 2:
            world_row.append(0)  
        elif row == ROWS // 2:
            world_row.append(1)  
        elif row < ROWS // 2 + 3:
            world_row.append(2)  
        else:
            world_row.append(3)  
    world.append(world_row)

# Параметры игрока
player_x = WIDTH // 2
player_y = (ROWS // 2 - 1) * BLOCK_SIZE
player_speed = 5

# Игровой цикл
clock = pygame.time.Clock()
running = True

while running:
    clock.tick(60)
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
            
    # Управление персонажем
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and player_x > 0:
        player_x -= player_speed
    if keys[pygame.K_RIGHT] and player_x < WIDTH - BLOCK_SIZE:
        player_x += player_speed

    # Очистка экрана и заливка небом
    screen.fill(SKY_BLUE)

    # Отрисовка блоков мира
    for row in range(ROWS):
        for col in range(COLS):
            block_type = world[row][col]
            x = col * BLOCK_SIZE
            y = row * BLOCK_SIZE
            
            if block_type == 1:
                pygame.draw.rect(screen, GREEN, (x, y, BLOCK_SIZE, BLOCK_SIZE))
            elif block_type == 2:
                pygame.draw.rect(screen, BROWN, (x, y, BLOCK_SIZE, BLOCK_SIZE))
            elif block_type == 3:
                pygame.draw.rect(screen, GRAY, (x, y, BLOCK_SIZE, BLOCK_SIZE))

    # Отрисовка игрока
    pygame.draw.rect(screen, RED, (player_x, player_y, BLOCK_SIZE, BLOCK_SIZE))

    # ЕСЛИ НАЖАТА КЛАВИША 'H' — вызываем функцию меню из help.py
    if keys[pygame.K_h]:
        help.draw_help_menu(screen)

    # Обновление экрана
    pygame.display.flip()

pygame.quit()
sys.exit()
