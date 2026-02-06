#include "first_app.hpp"

namespace lve {
    void FirstApp::run() const {
        while (!lveWindow.shouldClose()) {
            glfwPollEvents();
        }
    }
}
