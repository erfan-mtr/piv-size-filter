cmake_minimum_required(VERSION 2.8) 
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
PROJECT (pivfilter)
find_package(OpenCV REQUIRED)
set( NAME_SRC
    main.cpp
)

set( NAME_HEADERS       
     # include/header.h
)

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
add_executable( pivfilter ${NAME_SRC} ${NAME_HEADERS} )

target_link_libraries( pivfilter ${OpenCV_LIBS})
