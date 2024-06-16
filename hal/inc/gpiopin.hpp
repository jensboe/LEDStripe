#pragma once
#include "stm32f446ze.hpp"

enum class mode
{
    Input,
    PushPull,
    OpenDrain,
    Analog
};

template <pin PIN, mode MODE>
struct gpiopin
{
public:
    static void init()
    {
        enablePort();
        setMode();
    }

    static void setMode()
    {
        switch (MODE)
        {
        case mode::Input:
            set2bit(&getGpioRegister()->MODER, 0, getPinPos() * 2);
            break;
        case mode::PushPull:
            set2bit(&getGpioRegister()->MODER, 1, getPinPos() * 2);
            break;
        case mode::OpenDrain:
            set2bit(&getGpioRegister()->MODER, 1, getPinPos() * 2);
            setbit(&getGpioRegister()->OTYPER, getPinPos());
            break;
        case mode::Analog:
            set2bit(&getGpioRegister()->MODER, 3, getPinPos() * 2);
            break;
        }
    }
    static void set()
    {
        setbit(&getGpioRegister()->BSRR, getPinPos());
    }
    static void reset()
    {
        setbit(&getGpioRegister()->BSRR, getPinPos() << 16);
    }
    static void toggle()
    {
        uint32_t odr = getGpioRegister()->ODR;
        getGpioRegister()->BSRR = ((odr & (1 << getPinPos())) << 16) | (~odr & (1 << getPinPos()));
    }
    static bool get()
    {
        return ((getGpioRegister()->IDR) >> getPinPos()) & 0x1;
    }

private:
    static constexpr void setbit(volatile uint32_t *const reg, size_t pos)
    {
        *reg |= (1 << pos);
    }
    static constexpr void clearbit(volatile uint32_t *const reg, const size_t pos)
    {
        *reg |= ~(1 << pos);
    }
    static constexpr void set2bit(volatile uint32_t *const reg, const size_t value, const size_t pos)
    {
        auto temp = *reg & ~(0x3 << pos);
        temp |= ((value & 0x3) << pos);
        *reg = temp;
    }

    static constexpr void enablePort()
    {
        switch (getGpio())
        {
        case gpio::A:
            setbit(&RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN_Pos);
            break;
        case gpio::B:
            setbit(&RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN_Pos);
            break;
        case gpio::C:
            setbit(&RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN_Pos);
            break;
        case gpio::D:
            setbit(&RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN_Pos);
            break;
        case gpio::E:
            setbit(&RCC->AHB1ENR, RCC_AHB1ENR_GPIOEEN_Pos);
            break;
        case gpio::F:
            setbit(&RCC->AHB1ENR, RCC_AHB1ENR_GPIOFEN_Pos);
            break;
        case gpio::G:
            setbit(&RCC->AHB1ENR, RCC_AHB1ENR_GPIOGEN_Pos);
            break;
        case gpio::H:
            setbit(&RCC->AHB1ENR, RCC_AHB1ENR_GPIOHEN_Pos);
            break;
        default:
            break;
        }
        __NOP();
    }
    static constexpr int32_t getPinPos()
    {
        switch (PIN)
        {
        case pin::PA0:
        case pin::PB0:
        case pin::PC0:
        case pin::PD0:
        case pin::PF0:
        case pin::PG0:
        case pin::PH0:
            return 0;
            break;
        case pin::PA1:
        case pin::PB1:
        case pin::PC1:
        case pin::PD1:
        case pin::PE1:
        case pin::PF1:
        case pin::PG1:
        case pin::PH1:
            return 1;
            break;
        case pin::PA2:
        case pin::PB2:
        case pin::PC2:
        case pin::PD2:
        case pin::PE2:
        case pin::PF2:
        case pin::PG2:
            return 2;
            break;
        case pin::PA3:
        case pin::PB3:
        case pin::PC3:
        case pin::PD3:
        case pin::PE3:
        case pin::PF3:
        case pin::PG3:
            return 3;
            break;
        case pin::PA4:
        case pin::PB4:
        case pin::PC4:
        case pin::PD4:
        case pin::PE4:
        case pin::PF4:
        case pin::PG4:
            return 4;
            break;
        case pin::PA5:
        case pin::PB5:
        case pin::PC5:
        case pin::PD5:
        case pin::PE5:
        case pin::PF5:
        case pin::PG5:
            return 5;
            break;
        case pin::PA6:
        case pin::PB6:
        case pin::PC6:
        case pin::PD6:
        case pin::PF6:
        case pin::PG6:
            return 6;
            break;
        case pin::PA7:
        case pin::PB7:
        case pin::PC7:
        case pin::PD7:
        case pin::PE7:
        case pin::PF7:
        case pin::PG7:
            return 7;
            break;
        case pin::PA8:
        case pin::PB8:
        case pin::PC8:
        case pin::PD8:
        case pin::PE8:
        case pin::PF8:
        case pin::PG8:
            return 8;
            break;
        case pin::PA9:
        case pin::PB9:
        case pin::PC9:
        case pin::PD9:
        case pin::PE9:
        case pin::PF9:
        case pin::PG9:
            return 9;
            break;
        case pin::PA10:
        case pin::PB10:
        case pin::PC10:
        case pin::PD10:
        case pin::PE10:
        case pin::PF10:
        case pin::PG10:
            return 10;
            break;
        case pin::PA11:
        case pin::PB11:
        case pin::PC11:
        case pin::PD11:
        case pin::PE11:
        case pin::PF11:
        case pin::PG11:
            return 11;
            break;
        case pin::PA12:
        case pin::PB12:
        case pin::PC12:
        case pin::PD12:
        case pin::PE12:
        case pin::PF12:
        case pin::PG12:
            return 12;
            break;
        case pin::PA13:
        case pin::PB13:
        case pin::PC13:
        case pin::PD13:
        case pin::PE13:
        case pin::PF13:
        case pin::PG13:
            return 13;
            break;
        case pin::PA14:
        case pin::PB14:
        case pin::PC14:
        case pin::PD14:
        case pin::PE14:
        case pin::PF14:
        case pin::PG14:
            return 14;
            break;

        case pin::PA15:
        case pin::PB15:
        case pin::PC15:
        case pin::PD15:
        case pin::PE15:
        case pin::PF15:
        case pin::PG15:
            return 15;
            break;
        }
    }

    static constexpr GPIO_TypeDef *getGpioRegister()
    {
        switch (getGpio())
        {
        case gpio::A:
            return GPIOA;
            break;
        case gpio::B:
            return GPIOB;
            break;
        case gpio::C:
            return GPIOC;
            break;
        case gpio::D:
            return GPIOD;
            break;
        case gpio::E:
            return GPIOE;
            break;
        case gpio::F:
            return GPIOF;
            break;
        case gpio::G:
            return GPIOG;
            break;
        case gpio::H:
            return GPIOH;
            break;
        default:
            return nullptr;
            break;
        }
    }
    static constexpr gpio getGpio()
    {
        switch (PIN)
        {
        case pin::PA0:
        case pin::PA1:
        case pin::PA2:
        case pin::PA3:
        case pin::PA4:
        case pin::PA5:
        case pin::PA6:
        case pin::PA7:
        case pin::PA8:
        case pin::PA9:
        case pin::PA10:
        case pin::PA11:
        case pin::PA12:
        case pin::PA13:
        case pin::PA14:
        case pin::PA15:
            return gpio::A;
            break;
        case pin::PB0:
        case pin::PB1:
        case pin::PB2:
        case pin::PB3:
        case pin::PB4:
        case pin::PB5:
        case pin::PB6:
        case pin::PB7:
        case pin::PB8:
        case pin::PB9:
        case pin::PB10:
        case pin::PB11:
        case pin::PB12:
        case pin::PB13:
        case pin::PB14:
        case pin::PB15:
            return gpio::B;
            break;
        case pin::PC0:
        case pin::PC1:
        case pin::PC2:
        case pin::PC3:
        case pin::PC4:
        case pin::PC5:
        case pin::PC6:
        case pin::PC7:
        case pin::PC8:
        case pin::PC9:
        case pin::PC10:
        case pin::PC11:
        case pin::PC12:
        case pin::PC13:
        case pin::PC14:
        case pin::PC15:
            return gpio::C;
            break;
        case pin::PD0:
        case pin::PD1:
        case pin::PD2:
        case pin::PD3:
        case pin::PD4:
        case pin::PD5:
        case pin::PD6:
        case pin::PD7:
        case pin::PD8:
        case pin::PD9:
        case pin::PD10:
        case pin::PD11:
        case pin::PD12:
        case pin::PD13:
        case pin::PD14:
        case pin::PD15:
            return gpio::D;
            break;

        case pin::PE1:
        case pin::PE2:
        case pin::PE3:
        case pin::PE4:
        case pin::PE5:

        case pin::PE7:
        case pin::PE8:
        case pin::PE9:
        case pin::PE10:
        case pin::PE11:
        case pin::PE12:
        case pin::PE13:
        case pin::PE14:
        case pin::PE15:
            return gpio::E;
            break;
        case pin::PF0:
        case pin::PF1:
        case pin::PF2:
        case pin::PF3:
        case pin::PF4:
        case pin::PF5:
        case pin::PF6:
        case pin::PF7:
        case pin::PF8:
        case pin::PF9:
        case pin::PF10:
        case pin::PF11:
        case pin::PF12:
        case pin::PF13:
        case pin::PF14:
        case pin::PF15:
            return gpio::F;
            break;
        case pin::PG0:
        case pin::PG1:
        case pin::PG2:
        case pin::PG3:
        case pin::PG4:
        case pin::PG5:
        case pin::PG6:
        case pin::PG7:
        case pin::PG8:
        case pin::PG9:
        case pin::PG10:
        case pin::PG11:
        case pin::PG12:
        case pin::PG13:
        case pin::PG14:
        case pin::PG15:
            return gpio::G;
            break;
        case pin::PH0:
        case pin::PH1:
            return gpio::H;
            break;
        }
    }
};