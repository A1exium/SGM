//
/// Здесь описывается структура "взгляда" на поле - Взятие части поля
//

#ifndef SGM_SRC_ENGINE_RENDERS_SCREEN_VIEW_H_
#define SGM_SRC_ENGINE_RENDERS_SCREEN_VIEW_H_

#include "../../../objects/Area.h"

typedef struct View_s View;

View *View_new(Area *area, int x, int y, int width, int height);

#endif //SGM_SRC_ENGINE_RENDERS_SCREEN_VIEW_H_
