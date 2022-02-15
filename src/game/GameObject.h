//
// Created by alexium on 14.02.2022.
//

#ifndef SGM_SRC_GAME_GAMEOBJECT_H_
#define SGM_SRC_GAME_GAMEOBJECT_H_

typedef enum t_GameObjectType {
  None,
  Player,
  Nishal,
} GameObjectType;

struct s_GameObject;
typedef struct s_GameObject GameObject;

// Создает новый объект в координатах
GameObject *GameObject_new(GameObjectType type, int x, int y);

// Освобождает память
void gameObject_drop(GameObject *gameobject);

// Двигает объект на дельту по координатам
void gameObject_move(GameObject *obj, int dx, int dy);

// "Телепортирует" объект на координаты
void gameObject_teleport(GameObject *obj, int x, int y);

#endif //SGM_SRC_GAME_GAMEOBJECT_H_
