#include <chrono>

#include "SDL2/SDL.h"
#include "absl/log/absl_log.h"
#include "absl/log/globals.h"
#include "absl/log/initialize.h"
#include "absl/status/status.h"
#include "absl/strings/str_format.h"

absl::Status Loop(SDL_Window* window) {
  auto start = std::chrono::high_resolution_clock::now();
  
  // TODO: SHOW SOMETHING...
  // Render();
  
  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  ABSL_LOG(INFO) << "Render time: " << duration.count() << "ms";

  if (SDL_UpdateWindowSurface(window) != 0) {
    ABSL_LOG(ERROR) << "Error updating window surface: " << SDL_GetError();
  }
  bool quit = false;
  SDL_Event event;
  while (!quit) {
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        quit = true;
        // stop_render_ = true;
      }
    }
  }
  SDL_Quit();
  return absl::OkStatus();
}

absl::Status Run() {
  const int kWindowWidth = 800;
  const int kWindowHeight = 600;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
    return absl::InternalError(
        absl::StrFormat("Error initializing SDL: %s", SDL_GetError()));
  }

  auto window = std::unique_ptr<SDL_Window, std::function<void(SDL_Window*)>>(
      SDL_CreateWindow("Main SDL Window", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, kWindowWidth, kWindowHeight, 0),
      SDL_DestroyWindow);

  if (!window) {
    return absl::InternalError(
        absl::StrFormat("Error creating window: %s", SDL_GetError()));
  }

  SDL_Surface* surface = SDL_GetWindowSurface(window.get());
  if (!surface) {
    return absl::InternalError(
        absl::StrFormat("Error getting window surface: %s", SDL_GetError()));
  }

  auto status = Loop(window.get());

  SDL_Quit();
  return status;
}


int main(int argc, char** argv) {
  absl::InitializeLog();
  absl::SetStderrThreshold(absl::LogSeverityAtLeast::kInfo);


  auto status = Run();

  if (!status.ok()) {
    ABSL_LOG(ERROR) << status.message();
    return 1;
  }

  return 0;
}