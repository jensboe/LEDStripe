#pragma once
#include "gpiopin.hpp"

namespace board
{
    using ld1 = gpiopin<pin::PB0, mode::PushPull>;
    using logic1 = gpiopin<pin::PG2, mode::PushPull>;
    using logic2 = gpiopin<pin::PG3, mode::PushPull>;
    using ld2 = gpiopin<pin::PB7, mode::PushPull>;
    using ld3 = gpiopin<pin::PB14, mode::PushPull>;
    using btn = gpiopin<pin::PC13, mode::Input>;

    void init()
    {
        // Enable the FLASH instruction cache.
        FLASH->ACR |= FLASH_ACR_ICEN;
        // Enable the FLASH data cache.
        FLASH->ACR |= FLASH_ACR_DCEN;
        // Enable the FLASH prefetch buffer.
        FLASH->ACR |= FLASH_ACR_PRFTEN;
        NVIC_SetPriorityGrouping(3);
        // Set ticks to 1 kHz
        SysTick_Config(SystemCoreClock / (1000U / 1));
        // set Tic Prio to 0
        uint32_t prioritygroup = 0x00U;
        prioritygroup = NVIC_GetPriorityGrouping();
        NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(prioritygroup, 0, 0));
        // Enable some systems
        __HAL_RCC_SYSCFG_CLK_ENABLE();
        __HAL_RCC_PWR_CLK_ENABLE();
        ld1::init();
        ld2::init();
        ld3::init();
        btn::init();
        logic1::init();
        logic2::init();
    }
}
