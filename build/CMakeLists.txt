cmake_minimum_required(VERSION 3.16.3)

project(SCS)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Werror -Wall -Wextra) 
#-Wconversion
#-fsanitize=address

file(GLOB scs_glob_files
     "../main/server/src/*.cpp"
     "../main/client/src/*.cpp"
     "../main/thread/src/*.cpp"
     "../main/network/src/*.cpp"
     "../main/support/src/*.cpp"
     "../conf/*.cpp"
)

add_executable(${PROJECT_NAME} ${scs_glob_files})