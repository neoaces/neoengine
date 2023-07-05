# vendor/imgui/CMakeLists.txt
set(CMAKE_CXX_STANDARD 20)
find_package(SDL2 REQUIRED)
add_library(imgui STATIC
  imgui.cpp
  imgui.h
  imconfig.h
  imgui_demo.cpp
  imgui_draw.cpp
  imgui_internal.h
  imgui_tables.cpp
  imgui_widgets.cpp
  imstb_rectpack.h
  imstb_textedit.h
  imstb_truetype.h
  backends/imgui_impl_sdl2.h
  backends/imgui_impl_sdl2.cpp
  backends/imgui_impl_sdlrenderer2.h
  backends/imgui_impl_sdlrenderer2.cpp)

target_include_directories(imgui PUBLIC ./)
target_link_libraries(imgui PUBLIC SDL2::SDL2)