cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

# Variables
set(GAME_LIBRARIES_DIR "${CMAKE_SOURCE_DIR}/lib")
set(HELPERS_DIR "${CMAKE_SOURCE_DIR}/helpers")
set(INTERMEDIATES_DIR "${CMAKE_SOURCE_DIR}/intermediates")
include(${HELPERS_DIR}/ucm.cmake)

# Binary
set(EXECUTABLE_NAME "Game")
project(${EXECUTABLE_NAME})
ucm_add_dirs(src TO SOURCES RECURSIVE)
add_executable(${EXECUTABLE_NAME} ${SOURCES})
# We make it fully static
ucm_set_runtime(STATIC)

# Build Dependencies
include(${HELPERS_DIR}/BuildDependencies.cmake)

# Modules
set(CMAKE_MODULE_PATH "${GAME_LIBRARIES_DIR}" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "${GAME_LIBRARIES_DIR}" ${CMAKE_PREFIX_PATH})
set(CMAKE_PREFIX_PATH ${HELPERS_DIR} ${CMAKE_MODULE_PATH})

# SFML
set(SFML_ROOT "${GAME_LIBRARIES_DIR}/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 REQUIRED graphics window system)
if(SFML_FOUND)
    include(${HELPERS_DIR}/IncludeSFML.cmake)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} sfml-graphics)
endif()

# bullet3
# We are doing this manual process for now until we find the correct usage of the cmake files under lib/bullet
include(${GAME_LIBRARIES_DIR}/bullet3/lib/cmake/bullet/BulletConfig.cmake)
set(BULLET_ROOT "${BULLET_ROOT_DIR}")
find_package(Bullet REQUIRED LinearMath Bullet3Common BulletInverseDynamics BulletCollision BulletDynamics BulletSoftBody CONFIG)
if(BULLET_FOUND)
    include_directories(${GAME_LIBRARIES_DIR}/bullet3/include/bullet)
    target_link_libraries(${EXECUTABLE_NAME} ${BULLET_LIBRARIES})
endif()

# OpenGL
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES})
endif()

# GLM
find_package(glm REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})

# GLEW
set(GLEW_USE_STATIC_LIBS TRUE)

find_package(glew REQUIRED CONFIG)
include_directories( ${GAME_LIBRARIES_DIR}/glew/include)
target_link_libraries(${EXECUTABLE_NAME} GLEW::glew_s)

add_custom_command(
        TARGET ${EXECUTABLE_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/model/cube.obj
        ${CMAKE_CURRENT_BINARY_DIR}/cube.obj)

add_custom_command(
        TARGET ${EXECUTABLE_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/model/plane.obj
        ${CMAKE_CURRENT_BINARY_DIR}/plane.obj)

add_custom_command(
        TARGET ${EXECUTABLE_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/model/stairs.obj
        ${CMAKE_CURRENT_BINARY_DIR}/stairs.obj)

add_custom_command(
        TARGET ${EXECUTABLE_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/model/suzanne.obj
        ${CMAKE_CURRENT_BINARY_DIR}/suzanne.obj)