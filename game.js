const canvas = document.getElementById("gameCanvas");
const ctx = canvas.getContext("2d");

const BLOCK_SIZE = 40;
let playerX = 400;
let playerY = 240;
let keys = {};

window.addEventListener("keydown", (e) => keys[e.code] = true);
window.addEventListener("keyup", (e) => keys[e.code] = false);

function gameLoop() {
    // Логика управления
    if (keys["ArrowLeft"] && playerX > 0) playerX -= 5;
    if (keys["ArrowRight"] && playerX < canvas.width - BLOCK_SIZE) playerX += 5;

    // Очистка и небо
    ctx.fillStyle = "#87ceeb";
    ctx.fillRect(0, 0, canvas.width, canvas.height);

    // Отрисовка мира
    for (let row = 0; row < 15; row++) {
        for (let col = 0; col < 20; col++) {
            let x = col * BLOCK_SIZE;
            let y = row * BLOCK_SIZE;
            if (row === 7) {
                ctx.fillStyle = "#228B22";
                ctx.fillRect(x, y, BLOCK_SIZE, BLOCK_SIZE);
            } else if (row > 7 && row < 11) {
                ctx.fillStyle = "#8B4513";
                ctx.fillRect(x, y, BLOCK_SIZE, BLOCK_SIZE);
            } else if (row >= 11) {
                ctx.fillStyle = "#808080";
                ctx.fillRect(x, y, BLOCK_SIZE, BLOCK_SIZE);
            }
        }
    }

    // Отрисовка игрока
    ctx.fillStyle = "red";
    ctx.fillRect(playerX, playerY, BLOCK_SIZE, BLOCK_SIZE);

    requestAnimationFrame(gameLoop);
}
gameLoop();
