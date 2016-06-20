add_library(input GLFWKeyboard.cpp GLFWKeyboard.h Keyboard.cpp Keyboard.h)
target_link_libraries(input ${ext_libraries})