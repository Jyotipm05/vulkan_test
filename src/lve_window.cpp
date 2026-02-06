// #pragma once
#include "lve_window.hpp"

#include <utility>

namespace lve {
    LveWindow::LveWindow(const int width, const int height, std::string name) : width(width), height(height),
        windowName(std::move(name)) {
        initWindow();
    }
    LveWindow::~LveWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }


    void LveWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }
}
