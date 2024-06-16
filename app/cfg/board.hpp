#pragma once
#include "gpiopin.hpp"

namespace board
{
    using ld1 = gpiopin<pin::PB0, mode::PushPull>;
    using ld2 = gpiopin<pin::PB7, mode::PushPull>;
    using ld3 = gpiopin<pin::PB14, mode::PushPull>;
    using btn = gpiopin<pin::PC13, mode::Input>;

    void init()
    {
        ld1::init();
        ld2::init();
        ld3::init();
        btn::init();
    }
}
