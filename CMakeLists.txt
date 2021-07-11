cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(PROJECT_NAME "maze-game-gdi") # а может в кавчки надо?
set(PROJECT_HOMEPAGE_URL "https://github.com/miroslavbel/maze-game-gdi")

set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME} HOMEPAGE_URL ${PROJECT_HOMEPAGE_URL} LANGUAGES CXX)

include_directories(
   "include/"
   "include/engine"
)

add_executable(${PROJECT_NAME}
   "src/main.cpp"

   "src/engine/MazeSize.cpp"
)
