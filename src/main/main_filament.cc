#include <filament/Engine.h>
#include <filament/Renderer.h>
#include <filament/SwapChain.h>
#include <filament/View.h>
#include <filament/Scene.h>
#include <filament/Camera.h>

#include <SDL2/SDL.h>

int main(int argc, char** argv) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Create an SDL window
    SDL_Window* window = SDL_CreateWindow("Filament Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800, 600,
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window) {
        fprintf(stderr, "Failed to create SDL window: %s\n", SDL_GetError());
        return 1;
    }

    // Get the native window handle / SDL window info for Filament
    void* nativeWindow = (void*)window;

    // Create the Filament engine and related entities
    using namespace filament;
    Engine* engine = Engine::create();
    SwapChain* swapChain = engine->createSwapChain(nativeWindow);
    Renderer* renderer = engine->createRenderer();

    // Create a scene and view
    Scene* scene = engine->createScene();
    View* view = engine->createView();
    view->setScene(scene);

    // Create a camera
    Camera* camera = engine->createCamera(engine->getEntityManager().create());
    camera->setProjection(Camera::Projection::PERSPECTIVE, 45.0,
                          double(800)/double(600),
                          0.1, 100.0);
    camera->lookAt({0,0,3}, {0,0,0}, {0,1,0});
    view->setCamera(camera);

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Render loop
        if (renderer->beginFrame(swapChain)) {
            renderer->render(view);
            renderer->endFrame();
        }
    }

    // Cleanup
    engine->destroy(swapChain);
    engine->destroy(renderer);
    engine->destroy(view);
    engine->destroy(scene);
    engine->destroy(camera);
    Engine::destroy(&engine);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
