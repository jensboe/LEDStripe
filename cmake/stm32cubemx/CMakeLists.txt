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
    ../../Core/Inc
    ../../ext/stm32f4xx_hal_driver/Inc
    ../../ext/stm32f4xx_hal_driver/Inc/Legacy
)

target_sources(stm32cubemx INTERFACE
    ../../Core/Src/main.c
    ../../Core/Src/stm32f4xx_it.c
    ../../Core/Src/stm32f4xx_hal_msp.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_tim.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_tim_ex.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_uart.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_rcc.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_rcc_ex.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_flash.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_flash_ex.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_flash_ramfunc.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_gpio.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_dma_ex.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_dma.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_pwr.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_pwr_ex.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_cortex.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_exti.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_pcd.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_pcd_ex.c
    ../../ext/stm32f4xx_hal_driver/Src/stm32f4xx_ll_usb.c
    ../../Core/Src/system_stm32f4xx.c
    ../../Core/Src/sysmem.c
    ../../Core/Src/syscalls.c
    ../../ext/cmsis_device_f4/Source/Templates/gcc/startup_stm32f446xx.s
)

target_link_directories(stm32cubemx INTERFACE
)

target_link_libraries(stm32cubemx INTERFACE
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


