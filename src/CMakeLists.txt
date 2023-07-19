add_executable(neoengine 
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
    glad.c
    SquareBody.h
    SquareBody.cpp
    ShaderProg.cpp
    ShaderProg.h
)

# Copies the ttf file into the executable's directory
add_custom_command (
        TARGET neoengine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/assets/Inter.ttf
                ${CMAKE_CURRENT_BINARY_DIR}/Inter.ttf
)
add_custom_command (
        TARGET neoengine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/assets/fs.glsl
                ${CMAKE_CURRENT_BINARY_DIR}/fs.glsl
)
add_custom_command (
        TARGET neoengine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/assets/vs.glsl
                ${CMAKE_CURRENT_BINARY_DIR}/vs.glsl
)

set_target_properties(neoengine PROPERTIES BUILD_RPATH "/Library/Frameworks")

target_link_libraries(neoengine PUBLIC imgui 
    "-framework Cocoa" "-framework IOKit" "-framework CoreVideo"
)
target_include_directories(neoengine PUBLIC 
    ${CMAKE_SOURCE_DIR}/include/glad 
    ${CMAKE_SOURCE_DIR}/include/KHR # dependency of glad
)
