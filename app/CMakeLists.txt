cmake_minimum_required(VERSION 3.22)

project(app)
add_library(app INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(app INTERFACE 
	USE_HAL_DRIVER 
	STM32F446xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(app INTERFACE
    inc
)

target_sources(app INTERFACE
    src/main.cpp
    src/stm32f4xx_it.c
    src/stm32f4xx_hal_msp.c
    src/system_stm32f4xx.c
    src/sysmem.c
    src/syscalls.c
    ../ext/cmsis_device_f4/Source/Templates/gcc/startup_stm32f446xx.s
)

target_link_directories(app INTERFACE
)

target_link_libraries(app INTERFACE
)

# Validate that app code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


