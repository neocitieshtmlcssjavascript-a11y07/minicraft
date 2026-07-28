@echo off
chcp 65001 > nul
title Мульти-языковой запуск Мини-Майнкрафт 2D

:menu
cls
echo ===================================================
echo       ВЫБЕРИТЕ ЯЗЫК ПРОГРАММИРОВАНИЯ ДЛЯ ИГРЫ
echo ===================================================
echo 1. Python (game.py + Pygame)
echo 2. C++ SFML (game.cpp + Графика)
echo 3. C++ Консоль (games.cpp + Текстовая графика)
echo 4. JavaScript (game.js + Открытие в браузере)
echo 5. Lua (game.lua + LÖVE 2D)
echo 6. Godot (game.gd + Скрипт движка)
echo 7. R (game.r + Grid графика)
echo 8. Выход
echo ===================================================
set /p choice="Введите цифру (1-8): "

if "%choice%"=="1" goto run_python
if "%choice%"=="2" goto run_cpp_sfml
if "%choice%"=="3" goto run_cpp_console
if "%choice%"=="4" goto run_js
if "%choice%"=="5" goto run_lua
if "%choice%"=="6" goto run_godot
if "%choice%"=="7" goto run_r
if "%choice%"=="8" goto exit
goto menu

:run_python
cls
echo [Python] Проверка Pygame...
pip install pygame --user
echo [Python] Запуск...
python game.py
if %errorlevel% neq 0 pause
goto menu

:run_cpp_sfml
cls
echo [C++ SFML] Компиляция...
where g++ >nul 2>nul
if %errorlevel% neq 0 (echo Компилятор g++ не найден в PATH! && pause && goto menu)
g++ game.cpp -o game.exe -lsfml-graphics -lsfml-window -lsfml-system
if %errorlevel% equ 0 (game.exe) else (pause)
goto menu

:run_cpp_console
cls
echo [C++ Консоль] Компиляция...
where g++ >nul 2>nul
if %errorlevel% neq 0 (echo Компилятор g++ не найден в PATH! && pause && goto menu)
g++ games.cpp -o games_console.exe
if %errorlevel% equ 0 (games_console.exe) else (pause)
goto menu

:run_js
cls
echo [JavaScript] Создание index.html для запуска...
(
echo ^<!DOCTYPE html^>
echo ^<html^>^<head^>^<title^>JS Minecraft^</title^>^</head^>^<body style="margin:0; background:#000;"^>
echo ^<canvas id="gameCanvas" width="800" height="600" style="display:block; margin:20px auto; border:2px solid white;"^>^</canvas^>
echo ^<script src="game.js"^>^</script^>
echo ^</body^>^</html^>
) > index.html
echo [JavaScript] Открытие игры в браузере по умолчанию...
start index.html
timeout /t 2 > nul
goto menu

:run_lua
cls
echo [Lua] Проверка движка LÖVE...
where love >nul 2>nul
if %errorlevel% neq 0 (
    echo Движок LÖVE 2D не установлен или не добавлен в переменные среды PATH!
    echo Скачайте его с love2d.org
    pause
    goto menu
)
echo [Lua] Запуск игры...
love .
goto menu

:run_godot
cls
echo [Godot] Для запуска .gd файла требуется открытый редактор Godot.
echo Убедитесь, что ваш файл game.gd привязан к сцене в проекте Godot.
where godot >nul 2>nul
if %errorlevel% equ 0 (
    echo Запуск проекта через установленный Godot...
    godot --path .
) else (
    echo Команда 'godot' не найдена в PATH. Запустите движок вручную.
    pause
)
goto menu

:run_r
cls
echo [R] Запуск скрипта через Rscript...
where Rscript >nul 2>nul
if %errorlevel% neq 0 (echo Rscript не найден в PATH! && pause && goto menu)
Rscript game.r
goto menu

:exit
echo Скрипт завершен. Удачи в кодинге!
timeout /t 2 > nul
exit

