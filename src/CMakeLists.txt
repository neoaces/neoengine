add_executable( neoengine 
    app.cpp 
    body.h 
    Force.h 
    Vector.cpp 
    Vector.h 
    Body.cpp 
    GraphicsEngine.cpp 
    GraphicsEngine.h 
    NeoEngine.cpp 
    NeoEngine.h
)

# Copies the ttf file into the executable's directory
add_custom_command(
        TARGET neoengine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/assets/Inter.ttf
                ${CMAKE_CURRENT_BINARY_DIR}/Inter.ttf)

set_target_properties(neoengine PROPERTIES BUILD_RPATH "/Library/Frameworks")
target_link_libraries(neoengine PUBLIC imgui)