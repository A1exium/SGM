//
// GameObject - основная структура объекта. Все, что существует в игре - это GameObject.
//

#ifndef SGM_SRC_GAME_GAMEOBJECT_H_
#define SGM_SRC_GAME_GAMEOBJECT_H_

// Всевозможные типы объектов
typedef enum GameObjectType_t {
  None,
  Player,
  Nishal,
} GameObjectType;

struct s_GameObject;
typedef struct s_GameObject GameObject;

// Создает новый объект возвращает указатель на него
GameObject *GameObject_new(GameObjectType type, int x, int y);

// Освобождает память объекта, удаляет его из всех связанных с ним структур(из area, из group)
// TODO
void gameObject_free(GameObject *gameobject);

// Возвращает тип объекта. Нужно для корректной работы других функций
GameObjectType gameObject_get_type(GameObject *obj);

// Двигает объект на дельту по координатам
// Сигнатура может измениться
// TODO
void gameObject_move(GameObject *obj, int dx, int dy);

// "Телепортирует" объект на координаты
// Сигнатура может измениться
// TODO
void gameObject_teleport(GameObject *obj, int x, int y);

#endif //SGM_SRC_GAME_GAMEOBJECT_H_
