cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

# Variables
set(GAME_LIBRARIES_DIR "${CMAKE_SOURCE_DIR}/lib")
set(HELPERS_DIR "${CMAKE_SOURCE_DIR}/helpers")

include(${HELPERS_DIR}/ucm.cmake)

# Binary
set(EXECUTABLE_NAME "Game")
project(${EXECUTABLE_NAME})
ucm_add_dirs(src TO SOURCES RECURSIVE)
message(${SOURCES})
add_executable(${EXECUTABLE_NAME} ${SOURCES})
# We make it fully static
ucm_set_runtime(STATIC)

# Build Dependencies
include(${HELPERS_DIR}/BuildDependencies.cmake)

# Modules
set(CMAKE_MODULE_PATH "${GAME_LIBRARIES_DIR}/SFML/lib/cmake/SFML" ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH "${GAME_LIBRARIES_DIR}/SFML/lib/cmake/SFML" ${CMAKE_PREFIX_PATH})
set(CMAKE_PREFIX_PATH ${HELPERS_DIR} ${CMAKE_MODULE_PATH})

# SFML
set(SFML_ROOT "${GAME_LIBRARIES_DIR}/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 REQUIRED graphics window system)
if(SFML_FOUND)
    include(helpers/IncludeSFML.cmake)
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
