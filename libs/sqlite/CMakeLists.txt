cmake_minimum_required(VERSION 3.20)

project("sqlite")

file(GLOB srcs "src/**")
add_library(${PROJECT_NAME} ${srcs})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        "${PROJECT_SOURCE_DIR}/include/sqlite"
)

target_include_directories(${PROJECT_NAME}
    INTERFACE
        "${PROJECT_SOURCE_DIR}/include"
)
