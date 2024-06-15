cmake_minimum_required(VERSION 3.22)

project(stm32cubemx)
add_library(stm32cubemx INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(stm32cubemx INTERFACE 
	USE_HAL_DRIVER 
	STM32F446xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(stm32cubemx INTERFACE
    inc
)

target_sources(stm32cubemx INTERFACE
    src/main.c
    src/stm32f4xx_it.c
    src/stm32f4xx_hal_msp.c
    src/system_stm32f4xx.c
    src/sysmem.c
    src/syscalls.c
    ../ext/cmsis_device_f4/Source/Templates/gcc/startup_stm32f446xx.s
)

target_link_directories(stm32cubemx INTERFACE
)

target_link_libraries(stm32cubemx INTERFACE
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


