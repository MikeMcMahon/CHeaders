#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

int GM_HIDE_CURSOR = 0x000000001;

int GM_InitGame(struct Scene *scene, int window_width, int window_height, const char *window_title, int flags) {

    DEBUG_LOG("Initializing the Scene/Window");
    scene->w = window_width;
    scene->h = window_height;
    scene->window = SDL_CreateWindow(
            window_title,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            scene->w,
            scene->h,
            SDL_WINDOW_SHOWN);

    if ((flags & GM_HIDE_CURSOR) == GM_HIDE_CURSOR)
        SDL_ShowCursor(0);

    if (scene->window == NULL) {
        DEBUG_ERR(SDL_GetError());
        return -1;
    }

    scene->renderer = SDL_CreateRenderer(
            scene->window,
            -1,
            SDL_RENDERER_ACCELERATED);

    if (scene->window == NULL) {
        DEBUG_ERR(SDL_GetError());
        return -1;
    }

    scene->surface = SDL_GetWindowSurface(scene->window);
    if (scene->surface == NULL) {
        DEBUG_ERR(SDL_GetError());
        return -1;
    }

    scene->texture = SDL_CreateTextureFromSurface(
            scene->renderer,
            scene->surface);

    SDL_FillRect(scene->surface, NULL, SDL_MapRGBA(scene->surface->format, 0, 0, 0, 255));
    if (scene->texture == NULL) {
        DEBUG_ERR(SDL_GetError());
        return -1;
    }

    return 0;
}

#endif
