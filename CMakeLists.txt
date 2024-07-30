cmake_minimum_required(VERSION 3.5.0)
project(terminal-wordle VERSION 0.1.0 LANGUAGES C CXX)

add_executable(terminal-wordle main.cpp)
target_include_directories(terminal-wordle PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${CMAKE_CURRENT_SOURCE_DIR}/classes"
                            )
add_subdirectory(classes)
target_link_libraries(terminal-wordle PUBLIC Utility)
configure_file(wordlist.csv ${CMAKE_CURRENT_BINARY_DIR}/wordlist.csv COPYONLY)