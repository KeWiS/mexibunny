cmake_minimum_required(VERSION 3.24)
project(mexibunny)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR "C:/Users/Michal/Desktop/Michal/Studia/III rok/SGD/SDL2-2.26.4/include")
set(SDL2_LIB_DIR "C:/Users/Michal/Desktop/Michal/Studia/III rok/SGD/SDL2-2.26.4/lib/x64")

set(SDL2MIXER_INCLUDE_DIR "C:/Users/Michal/Desktop/Michal/Studia/III rok/SGD/SDL2_mixer-2.6.3/include")
set(SDL2MIXER_LIB_DIR "C:/Users/Michal/Desktop/Michal/Studia/III rok/SGD/SDL2_mixer-2.6.3/lib/x64")


include_directories(${SDL2_INCLUDE_DIR} ${SDL2MIXER_INCLUDE_DIR})
add_executable(${PROJECT_NAME} src/main.cpp src/core/game.h src/core/game.cpp)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/SDL2.lib ${SDL2_LIB_DIR}/SDL2main.lib ${SDL2MIXER_LIB_DIR}/SDL2_mixer.lib)