cmake_minimum_required(VERSION 3.20)

project("password_archive")

add_subdirectory(libs)

file(GLOB srcs "src/**")

add_executable(${PROJECT_NAME} ${srcs})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        sqlite
)
