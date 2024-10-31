# Console2048

<img src="https://github.com/OtryvnoyKalendar/console2048/blob/main/screenshots/screenshot%201.png" height="400" width="300" >

### Общее описание
Console2048 - это игра 2048 для консоли Linux. Это только прототип игры, которую я написал для практики языка C++.
Игра сделана на основе видео с ютуб канала Begin End и адаптирована под Linux. Вот *ссылки на видео*:  
[Язык С++ - Урок 26 - Пишем игру 2048.](https://www.youtube.com/watch?v=kxjj89Sf45M&pp=ygU30K_Qt9GL0Log0KErKyAtINCj0YDQvtC6IDI2IC0g0J_QuNGI0LXQvCDQuNCz0YDRgyAyMDQ4Lg%3D%3D)  
[Язык С++ - Урок 27 - Анимация для игры 2048](https://www.youtube.com/watch?v=P0H9VsKQz5o&pp=ygU30K_Qt9GL0Log0KErKyAtINCj0YDQvtC6IDI2IC0g0J_QuNGI0LXQvCDQuNCz0YDRgyAyMDQ4Lg%3D%3D)  

### Как играть
Чтобы начать играть, нужно открыть консоль и перейти в папку с проектом. Дальше просто выполните скрипт:
```sh
./project_start
```

- Управление:  
'ESC' - выйти из игры  
'W' - вверх  
'A' - влево  
'S' - вниз  
'D' - вправо  
Есть управление стрелочками  

Если вы хотите **изменить код игры**, то вам не нужно ничего перекомпелировать и удалять вручную. После внесения изменений в файлы игры, просто снова запустите скрипт `project_start`, он всё сделает за вас.

Если вы захотите воспользоваться **отладчиком GDB**, то нужно скомпилировать игру с отладочной информацией:
```sh
./project_start debug
```
А потом в отдельном окне консоли подключиться к запущенному процессу игры, используя этот скрипт:
```sh
./debugger_start
```

