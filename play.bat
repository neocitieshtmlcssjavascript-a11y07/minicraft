@echo off
chcp 65001 > nul
title Запуск Мини-Майнкрафт 2D

:menu
cls
echo ==========================================
echo       ЗАПУСК МИНИ-МАЙНКРАФТ 2D
echo ==========================================
echo 1. Запустить версию на Python (game.py)
echo 2. Скомпилировать и запустить на C++ (SFML)
echo 3. Выход
echo ==========================================
set /p choice="Выберите вариант (1-3): "

if "%choice%"=="1" goto run_python
if "%choice%"=="2" goto run_cpp
if "%choice%"=="3" goto exit
goto menu

:run_python
cls
echo [Python] Проверка и установка Pygame...
pip install pygame --user
echo.
echo [Python] Запуск игры...
python game.py
if %errorlevel% neq 0 (
    echo.
    echo [Ошибка] Не удалось запустить Python-скрипт. Проверьте, установлен ли Python.
    pause
)
goto menu

:run_cpp
cls
echo [C++] Попытка компиляции minecraft.cpp...
:: Проверяем наличие g++ в системе
where g++ >nul 2>nul
if %errorlevel% neq 0 (
    echo [Ошибка] Компилятор g++ не найден в PATH.
    echo Установите MinGW и добавьте его в переменные среды.
    pause
    goto menu
)

:: Компиляция (предполагается, что SFML настроен или файлы лежат рядом)
:: Если библиотека SFML лежит в отдельной папке, укажите пути: -I"путь" -L"путь"
g++ minecraft.cpp -o minecraft.exe -lsfml-graphics -lsfml-window -lsfml-system

if %errorlevel% equ 0 (
    echo [C++] Компиляция успешна! Запуск игры...
    minecraft.exe
) else (
    echo.
    echo [Ошибка] Не удалось скомпилировать код. 
    echo Убедитесь, что библиотека SFML установлена и доступна для компилятора.
    pause
)
goto menu

:exit
echo До встречи!
timeout /t 2 > nul
exit
