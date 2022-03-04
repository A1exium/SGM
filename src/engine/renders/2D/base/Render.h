//
// Created by alexium on 04.03.2022.
//

#ifndef SGM_SRC_ENGINE_RENDERS_2D_SCREEN_RENDER_H_
#define SGM_SRC_ENGINE_RENDERS_2D_SCREEN_RENDER_H_

#include "View.h"
#include "Picture.h"

struct Render_s;
typedef struct Render_s Render;

extern Render *Render_new(View *view, int width, int height);

extern Picture Render_render(Render *render);

#endif //SGM_SRC_ENGINE_RENDERS_2D_SCREEN_RENDER_H_
