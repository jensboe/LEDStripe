cmake_minimum_required(VERSION 3.22)

project(hal)
add_library(hal)

# Enable CMake support for ASM and C languages
enable_language(CXX C ASM)

target_compile_definitions(hal PUBLIC 
	STM32F446xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(hal PUBLIC
    inc
)

target_sources(hal PRIVATE
    src/gpio.cpp
)

target_link_directories(hal PUBLIC
)

target_link_libraries(hal PUBLIC
)

