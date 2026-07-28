extends Node2D

const BLOCK_SIZE = 40
var player_pos = Vector2(400, 260)
var player_speed = 300

func _process(delta):
	# Управление
	if Input.is_action_pressed("ui_left") and player_pos.x > 0:
		player_pos.x -= player_speed * delta
	if Input.is_action_pressed("ui_right") and player_pos.x < 800 - BLOCK_SIZE:
		player_pos.x += player_speed * delta
	queue_redraw()

func _draw():
	# Небо
	draw_rect(Rect2(0, 0, 800, 600), Color.HTML("87ceeb"))
	# Генерация блоков мира
	for row in range(15):
		for col in range(20):
			var rect = Rect2(col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE)
			if row == 7:
				draw_rect(rect, Color.DARK_GREEN)
			elif row > 7 and row < 11:
				draw_rect(rect, Color.SADDLE_BROWN)
			elif row >= 11:
				draw_rect(rect, Color.DIM_GRAY)
	# Игрок
	draw_rect(Rect2(player_pos.x, player_pos.y, BLOCK_SIZE, BLOCK_SIZE), Color.RED)
