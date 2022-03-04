//
/// Здесь описывается структура "взгляда" на поле - Взятие части поля
//

#ifndef SGM_SRC_ENGINE_RENDERS_SCREEN_VIEW_H_
#define SGM_SRC_ENGINE_RENDERS_SCREEN_VIEW_H_

#include "../../../objects/Area.h"
#include "../../../geometry/Position.h"

typedef struct View_s View;

extern View *View_new(Area *area, int x, int y, int width, int height);

extern Position View_get_pos(View *view);

extern int View_get_width(View *view);

extern int View_get_height(View *view);

extern GameObject *View_get_GameObject(View *view, int x, int y, int z);

#endif //SGM_SRC_ENGINE_RENDERS_SCREEN_VIEW_H_
