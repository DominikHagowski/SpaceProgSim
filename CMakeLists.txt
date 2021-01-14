cmake_minimum_required(VERSION 3.6)

project(Rocketsim VERSION 0.0 LANGUAGES CXX C)

add_executable(Rocketsim "src/Main.cpp")

add_subdirectory(GameEngine)
target_link_libraries(Rocketsim Engine)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Rocketsim)

