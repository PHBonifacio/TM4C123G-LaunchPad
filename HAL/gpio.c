#include "gpio.h"
void GPIOF_Config(void)
{
    /*  ENABLE GPIOF CLOCK */
    SYSCTL->RCGCGPIO |= RCGCGPIO_GPIOF_ENABLE; 
    /*  WAIT GPIOF BE READY FOR ACCESS */
    while(0 == PRGPIO_GPIOF_STATUS);
    /*  UNLOCK GPIOF */
    GPIOF->LOCK = GPIOLOCK_UNLOCK_VALUE;
    GPIOF->CR = GPIOCR_GPIOF;
    /*  DISABLE ANALOG FUNCTION */
    GPIOF->AMSEL &= (uint32_t)(GPIOAMSEL_PIN_0_DISABLE & GPIOAMSEL_PIN_1_DISABLE \
        & GPIOAMSEL_PIN_2_DISABLE & GPIOAMSEL_PIN_3_DISABLE & GPIOAMSEL_PIN_4_DISABLE);
    /*  DISABLE ALTERNATE FUNCTION */
    GPIOF->AFSEL = GPIOAFSEL_DISABLE_ALL;
    GPIOF->PCTL = GPIOPCTL_DISABLE_ALL;
    /*  CONFIGURE PINS AS OUTPUTS */
    GPIOF->DIR |= (uint32_t)(GPIODIR_PIN1_OUTPUT | GPIODIR_PIN2_OUTPUT | \
        GPIODIR_PIN3_OUTPUT);
    /*  CONFIGURE PINS AS INPUTS */
    GPIOF->DIR &= (uint32_t)(GPIODIR_PIN0_INPUT & GPIODIR_PIN4_INPUT);
    /*  ENABLE PULL UP ON INPUT PINS */
    GPIOF->PUR |= (uint32_t)(GPIOPUR_PIN0_ENABLED | GPIOPUR_PIN4_ENABLED);
    /*  CONFIGURE PINS AS DIGITAL */
    GPIOF->DEN |= (uint32_t)(GPIODEN_PIN0_ENABLED | GPIODEN_PIN1_ENABLED | \
        GPIODEN_PIN2_ENABLED | GPIODEN_PIN3_ENABLED | GPIODEN_PIN4_ENABLED);
}

pin_status_t GPIO_Read_Pin(GPIOA_Type* GPIOx, pin_t pin)
{
    uint32_t a = 0X01 << pin;
    a &= GPIOx->DATA;
    
    if (0x00 == (GPIOx->DATA & (0X01 << pin)))
    {
        return PIN_LOW;
    }
    else
    {
        return PIN_HIGH;
    }
    
}

void GPIO_Write(GPIOA_Type* GPIOx, pin_t pin, pin_status_t status)
{
    if (PIN_ON == status)
    {
        GPIOx->DATA |= (uint32_t)(0x01 << pin);
    }
    else
    {
        GPIOx->DATA &= (uint32_t)(~(0x01 << pin));
    }
    
}

void GPIO_Toggle(GPIOA_Type* GPIOx, pin_t pin)
{
    GPIOx->DATA ^= (uint32_t)(0x01 << pin);
}

void Pin_Debounce_Init(pin_debounce_t* pin_deb, pin_status_t status)
{
    pin_deb->last_state = status;
    pin_deb->new_state = status;
}

void Pin_Debounce_Update(pin_debounce_t* pin_deb, pin_status_t status)
{
    pin_deb->last_state = pin_deb->new_state;
    pin_deb->new_state = status;
}

edge_t Pin_Debounce(pin_debounce_t* pin_deb)
{
    edge_t status = NOTHING;

    if ((PIN_HIGH == pin_deb->last_state) && (PIN_LOW == pin_deb->new_state))
    {
        status = FALLING;
    }
    else if ((PIN_LOW == pin_deb->last_state) && (PIN_HIGH == pin_deb->new_state))
    {
        status = RISING;
    }
    
    return status;
}

void GPIO_Inc_Leds_Color(color_t* color)
{
    if (*color < WHITE)
    {
        *color += 0x02;
    }
    else
    {
        *color = BLACK;
    }
		
		GPIOF->DATA = 0xFFFFFFF1;
    
}

void GPIO_Toggle_Led_Color(color_t color)
{
    GPIOF->DATA ^= color;
}

void GPIO_Set_Led_Color(color_t color)
{
    GPIOF->DATA = color;
}
