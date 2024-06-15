

project(stm32f4xx_hal_driver)

add_library(stm32f4xx_hal_driver STATIC)

target_compile_definitions(stm32f4xx_hal_driver PUBLIC 
	STM32F446xx
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(stm32f4xx_hal_driver PUBLIC
    stm32f4xx_hal_driver/Inc
    stm32f4xx_hal_driver/Inc/Legacy
    ../app/inc/hal
)

target_sources(stm32f4xx_hal_driver PRIVATE
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_tim.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_tim_ex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_uart.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_rcc.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_rcc_ex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_flash.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_flash_ex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_flash_ramfunc.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_gpio.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_dma_ex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_dma.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_pwr.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_pwr_ex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_cortex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_exti.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_pcd.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_pcd_ex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_ll_usb.c
)
target_link_libraries(stm32f4xx_hal_driver PUBLIC
    cmsis_5
    cmsis_device_f4
)
