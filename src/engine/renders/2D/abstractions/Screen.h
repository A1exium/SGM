///
/// Содержит структуру экрана. В ней содержатся "экраны" - области, куда выводится изображение.
/// Задача - Переводить изображение с "взгляда" на экран
/// Проекцирует часть поля на часть экрана
///

#ifndef SGM_SRC_ENGINE_RENDERS_SCREEN_SCREEN_H_
#define SGM_SRC_ENGINE_RENDERS_SCREEN_SCREEN_H_

#include "../../../geometry/Position.h"
#include "../../../objects/Area.h"
#include "View.h"

typedef struct Screen_s Screen;

typedef struct Pixel_s Pixel;

Screen *Screen_new(int width, int height, View *view);

void Screen_refresh(Screen scr);

#endif //SGM_SRC_ENGINE_RENDERS_SCREEN_SCREEN_H_
