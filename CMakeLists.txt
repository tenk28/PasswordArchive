cmake_minimum_required(VERSION 3.20)

project("password_archive")

file(GLOB srcs "src/**")
add_executable(${PROJECT_NAME} ${srcs})
