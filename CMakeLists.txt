cmake_minimum_required(VERSION 3.24)
project(mexibunny)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR "C:/Users/Michal/Desktop/Michal/Studia/III rok/SGD/SDL2-2.26.4/include")
set(SDL2_LIB_DIR "C:/Users/Michal/Desktop/Michal/Studia/III rok/SGD/SDL2-2.26.4/lib/x64")

set(SDL2MIXER_INCLUDE_DIR "C:/Users/Michal/Desktop/Michal/Studia/III rok/SGD/SDL2_mixer-2.6.3/include")
set(SDL2MIXER_LIB_DIR "C:/Users/Michal/Desktop/Michal/Studia/III rok/SGD/SDL2_mixer-2.6.3/lib/x64")


include_directories(${SDL2_INCLUDE_DIR} ${SDL2MIXER_INCLUDE_DIR})
add_executable(${PROJECT_NAME} src/main.cpp src/core/game.h src/core/game.cpp src/core/render_helper.h src/core/render_helper.cpp src/game_objects/player.h src/game_objects/player.cpp src/game_objects/character.h src/game_objects/character.cpp src/game_objects/entity.h src/game_objects/entity.cpp src/game_objects/grass.h src/game_objects/grass.cpp src/core/constants.h src/enums/movement.h src/core/texture_holder.h src/physics/engine.h src/physics/engine.cpp src/physics/vector2D.h src/physics/vector2D.cpp src/core/animator.h src/core/animator.cpp src/physics/rigid_body.h src/physics/rigid_body.cpp src/utility/randomizer.h src/utility/randomizer.cpp src/map/map.h src/map/map.cpp src/map/level.h src/map/level.cpp src/physics/collision_detector.h src/physics/collision_detector.cpp)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/SDL2.lib ${SDL2_LIB_DIR}/SDL2main.lib
        ${SDL2_LIB_DIR}/SDL2_image.lib ${SDL2MIXER_LIB_DIR}/SDL2_mixer.lib)