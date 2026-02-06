cmake_minimum_required(VERSION 4.0)

# Configure vcpkg toolchain file early so CMake can find packages installed via vcpkg.
# Prefer environment variables VCPKG_ROOT or VCPKG_PATH if set.
if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    if (DEFINED ENV{VCPKG_ROOT})
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
    elseif (DEFINED ENV{VCPKG_PATH})
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
    endif()
endif()

project(vulkan_test VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Try to find glm via package config (vcpkg or system). If not available, fetch it.
find_package(glm CONFIG QUIET)
find_package(glfw3 CONFIG REQUIRED)
find_package(VulkanHeaders CONFIG)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/lve_window.hpp
        src/lve_window.cpp
        src/first_app.hpp
        src/first_app.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        glm::glm
        glfw
        Vulkan::Headers
)