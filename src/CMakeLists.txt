find_package(SDL2 REQUIRED)

add_executable(neoengine app.cpp body.h Force.h Vector.cpp Vector.h)
set_target_properties(neoengine PROPERTIES
    BUILD_RPATH "/Library/Frameworks"    
    )
target_link_libraries(neoengine SDL2::SDL2)