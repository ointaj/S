cmake_minimum_required(VERSION 3.16.3)

project(SCS)

set(CMAKE_CXX_STANDARD 17)

file(GLOB hehSCXS CONFIGURE_DEPENDS
     "../main/server/headers/*.hpp"
     "../main/client/headers/*.hpp"
     "../main/thread/headers/*.hpp"
     "../main/network/headers/*.hpp"
     "../main/support/headers/*.hpp"
     "../main/server/src/*.cpp"
     "../main/client/src/*.cpp"
     "../main/thread/src/*.cpp"
     "../main/network/src/*.cpp"
     "../main/support/src/*.cpp"
)

add_executable(${PROJECT_NAME} ${hehSCXS})


#add_subdirectory("/")

# target_link_directories(${PROJECT_NAME} PRIVATE
#                             "../main/server/headers"
#                             "../main/server/src"
# )

# target_include_directories(${PROJECT_NAME} PUBLIC
#                             "../main/server/headers"
#                             "../main/server/src"
# )

# target_link_libraries(${PROJECT_NAME} )