cmake_minimum_required(VERSION 3.22)

project(hal)
add_library(hal INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(CXX C ASM)

target_compile_definitions(hal INTERFACE 
	STM32F446xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(hal INTERFACE
    inc
)

target_sources(hal INTERFACE
    src/gpiopin.cpp
)

target_link_directories(hal INTERFACE
)

target_link_libraries(hal INTERFACE
)

