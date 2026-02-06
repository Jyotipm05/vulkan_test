#pragma once
#define GLFW_INCLUDE_VULKAN
#include <string>
#include <GLFW/glfw3.h>

namespace lve {
    class LveWindow {
    public:
        LveWindow(int width, int height, std::string name);
        ~LveWindow();

        [[nodiscard]] bool shouldClose() const {
            return glfwWindowShouldClose(window);
        }

    private:
        void initWindow();
        const int width;
        const int height;
        std::string windowName;
        GLFWwindow* window{};
    };
}
