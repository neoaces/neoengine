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
  backends/imgui_impl_opengl3.h
  backends/imgui_impl_opengl3.cpp
  backends/imgui_impl_glfw.h
  backends/imgui_impl_glfw.cpp
  )
target_include_directories(imgui PUBLIC ./ 
  ${CMAKE_SOURCE_DIR}/include/glfw/include 
  ${CMAKE_SOURCE_DIR}/include/glad
  ${CMAKE_SOURCE_DIR}/include/KHR
  ${CMAKE_SOURCE_DIR}/include/glm
)
target_link_libraries(imgui PUBLIC SDL2::SDL2 ${CMAKE_SOURCE_DIR}/include/glfw/libglfw3.a)