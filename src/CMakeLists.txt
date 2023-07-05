add_executable(
    neoengine 
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

set_target_properties(neoengine PROPERTIES BUILD_RPATH "/Library/Frameworks")
target_link_libraries(neoengine PUBLIC imgui)