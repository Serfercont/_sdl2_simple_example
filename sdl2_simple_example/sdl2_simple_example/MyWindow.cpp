#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "MyWindow.h"
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
using namespace std;

MyWindow::MyWindow(const std::string& title, int w, int h) : _width(w), _height(h) {

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    _window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_OPENGL);
    if (!_window) throw exception(SDL_GetError());

    _ctx = SDL_GL_CreateContext(_window);
    if (!_ctx) throw exception(SDL_GetError());
    if (SDL_GL_MakeCurrent(_window, _ctx) != 0) throw exception(SDL_GetError());
    if (SDL_GL_SetSwapInterval(1) != 0) throw exception(SDL_GetError());

    ImGui::CreateContext();
    ImGui_ImplSDL2_InitForOpenGL(_window, _ctx);
    ImGui_ImplOpenGL3_Init("#version 130");
}

MyWindow::~MyWindow() {
    ImGui_ImplSDL2_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext();
    SDL_GL_DeleteContext(_ctx);
    SDL_DestroyWindow(static_cast<SDL_Window*>(_window));
}

void MyWindow::swapBuffers() const {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("New Scene")) {

            }
            if (ImGui::MenuItem("Open Scene")) {

            }
            if (ImGui::MenuItem("Save")) {

            }
            if (ImGui::MenuItem("Save As")) {

            }
            if (ImGui::MenuItem("Build Settings")) {

            }
            if (ImGui::MenuItem("Exit")) {
                SDL_Event quit_event;
                quit_event.type = SDL_QUIT;
                SDL_PushEvent(&quit_event);
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit")) {
            if (ImGui::MenuItem("Select"))
            {

            }
            if (ImGui::MenuItem("Deselect")) {

            }
            if (ImGui::MenuItem("Duplicate")) {

            }
            if (ImGui::MenuItem("Delete")) {

            }
            if (ImGui::MenuItem("Project Settings")) {

            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Assets")) {
            if (ImGui::MenuItem("Create")) {

            }
            if (ImGui::MenuItem("Import Asset"))
            {

            }
            if (ImGui::MenuItem("Import Package")) {

            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("GameObjects")) {
            if (ImGui::MenuItem("Test"))
            {

            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Component")) {
            if (ImGui::MenuItem("Test"))
            {

            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Window")) {
            if (ImGui::MenuItem("Test"))
            {

            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(static_cast<SDL_Window*>(_window));
}

