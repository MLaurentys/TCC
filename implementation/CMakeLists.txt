cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(FILES
domineering/src/main.cpp
domineering/src/domineering.cpp
domineering/src/dom_evaluator.cpp
lib/evaluator.cpp
lib/union_find.cpp)

set(HEADERS
domineering/include/definitions.hpp
domineering/include/dom_evaluator.hpp
domineering/include/domineering.hpp
lib/evaluator/hpp
lib/union_find.hpp)

add_subdirectory(game_numbers)
project(tcc)
add_executable(a.out ${FILES})
set_target_properties(a.out PROPERTIES PUBLIC_HEADER ${HEADERS})
target_link_libraries(a.out PUBLIC game_number)