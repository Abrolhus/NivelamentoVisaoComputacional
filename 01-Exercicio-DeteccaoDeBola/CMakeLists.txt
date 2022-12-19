cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)
project(main)
find_package(OpenCV REQUIRED)
set(SOURCES
    main.cpp
    )
add_executable(ball ${SOURCES})
target_link_libraries(ball ${OpenCV_LIBS})
