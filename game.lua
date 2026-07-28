local player = { x = 400, y = 240, speed = 300, size = 40 }
local blockSize = 40

function love.update(dt)
    if love.keyboard.isDown("left") and player.x > 0 then
        player.x = player.x - player.speed * dt
    end
    if love.keyboard.isDown("right") and player.x < 800 - player.size then
        player.x = player.x + player.speed * dt
    end
end

function love.draw()
    -- Небо
    love.graphics.clear(135/255, 206/255, 235/255)
    -- Мир
    for row = 0, 14 do
        for col = 0, 19 do
            local x, y = col * blockSize, row * blockSize
            if row == 7 then
                love.graphics.setColor(34/255, 139/255, 34/255)
                love.graphics.rectangle("fill", x, y, blockSize, blockSize)
            elseif row > 7 and row < 11 then
                love.graphics.setColor(139/255, 69/255, 19/255)
                love.graphics.rectangle("fill", x, y, blockSize, blockSize)
            elseif row >= 11 then
                love.graphics.setColor(128/255, 128/255, 128/255)
                love.graphics.rectangle("fill", x, y, blockSize, blockSize)
            end
        end
    end
    -- Игрок
    love.graphics.setColor(1, 0, 0)
    love.graphics.rectangle("fill", player.x, player.y, player.size, player.size)
end
