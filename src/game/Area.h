//
// Здесь функции для работы с GameObject *area[][]
//

#ifndef SGM_SRC_GAME_AREA_H_
#define SGM_SRC_GAME_AREA_H_

#include "GameObject.h"
#include "../const.h"

// Дополнительная структура для хранения объектов. С ее помощью удобнее искать объекты по координатам.
// Текущая реализация - двумерный масив ссылок на GameObject
typedef GameObject *Area[AREA_H][AREA_W];

// Заполняет массив нулями
void area_init(Area area);

// Добавляет GameObject на координаты (x, y)ю
// Проверяет, есть ли там еще элемент. Если есть и у него НЕТ группы - отчищает память с ним.
// Иначе заменяет его координаты
// TODO
void area_insert_gameobject(Area area, GameObject *game_object);

#endif //SGM_SRC_GAME_AREA_H_
