add_library(src
        Scene.cpp Scene.h
        Game.cpp Game.h
        AssetManager.cpp AssetManager.h
        Pointers.h
        GameData.cpp GameData.h IComponent.h render/Hand.cpp render/Hand.h render/HPBar.cpp render/HPBar.h)

target_include_directories(src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})