Game2d
======
Тестовый набросок 2d игры хз какого жанра

Зависимости:

1. SDL2-2.0.3
2. SDL2_image-2.0.0
3. SDL2_ttf-2.0.12



Генерация проекта для CodeBlocks под windows:

У нас есть директория пример D:\game (назовем ее корневой) в ней лежат папки: 

1. lib библеотеки SDL
2. res ресурсы игры
3. code исходный код
4. build сюда будет компилироваться

Открываем cmd
переходим в папку куда будем генерировать файлы проекта например корневая папка\project_cb
запускаем cmake:

cmake -G "CodeBlocks - MinGW Makefiles" -D BASE_DIR:STRING="корневая папка"  ../code

