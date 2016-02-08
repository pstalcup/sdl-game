add_library(src
        Scene.cpp Scene.h
        Game.cpp Game.h
        AssetManager.cpp AssetManager.h
        Pointers.h
        GameData.cpp GameData.h)

target_include_directories(src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})