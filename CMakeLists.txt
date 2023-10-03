cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# to produce compile_commands.json:
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PROJECT_NAME "ray")
set(MAIN_FILE "src/main.cpp")
set(SRC_FILES src/ray.cpp 
              src/sphere.cpp 
              src/hitable_list.cpp)

set(INCLUDE_DIR "include")

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${MAIN_FILE} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC -lsfml-graphics -lsfml-window -lsfml-system)
