#ifndef __GPIO_H__
#define __GPIO_H__
#include <TM4C123GH6PM.h>
#include <stdint.h>

#define PIN_ON                      1
#define PIN_OFF	                    0
/*  DEFINES FOR GPIOS */
#define GPIOA_NUM                   0
#define GPIOB_NUM                   1
#define GPIOC_NUM                   2
#define GPIOD_NUM                   3
#define GPIOE_NUM                   4
#define GPIOF_NUM                   5
/*  DEFINES FOR PINS OF GPIOS */
#define PIN_0	                    0
#define PIN_1	                    1
#define PIN_2	                    2
#define PIN_3	                    3
#define PIN_4	                    4
#define PIN_5	                    5
#define PIN_6	                    6
#define PIN_7	                    7
/*  DEFINES RCCGPIO FOR ENABLE OR DISABLE GPIO CLOCK */
#define RCGCGPIO_GPIOA_ENABLE	    (1UL << GPIOA_NUM)
#define RCGCGPIO_GPIOA_DISABLE	    (~(1UL << GPIOA_NUM))
#define RCGCGPIO_GPIOB_ENABLE	    (1UL << GPIOB_NUM)
#define RCGCGPIO_GPIOB_DISABLE	    (~(1UL << GPIOB_NUM))
#define RCGCGPIO_GPIOC_ENABLE	    (1UL << GPIOC_NUM)
#define RCGCGPIO_GPIOC_DISABLE	    (~(1UL << GPIOC_NUM))
#define RCGCGPIO_GPIOD_ENABLE	    (1UL << GPIOD_NUM)
#define RCGCGPIO_GPIOD_DISABLE	    (~(1UL << GPIOD_NUM))
#define RCGCGPIO_GPIOE_ENABLE	    (1UL << GPIOE_NUM)
#define RCGCGPIO_GPIOE_DISABLE	    (~(1UL << GPIOE_NUM))
#define RCGCGPIO_GPIOF_ENABLE	    (1UL << GPIOF_NUM)
#define RCGCGPIO_GPIOF_DISABLE	    (~(1UL << GPIOF_NUM))
#define RCGCGPIO_DISABLE_ALL	    0x00
#define RCGCGPIO_ENABLE_ALL	        0x3F
/*  DEFINES PRGPIO FOR CHECK IF PERIPHERAL IS READY, CHECK IF IT IS 1(READY) */
#define PRGPIO_GPIOA_STATUS         (0x01 || (SYSCTL->PRGPIO >> GPIOA_NUM))
#define PRGPIO_GPIOB_STATUS         (0x01 || (SYSCTL->PRGPIO >> GPIOB_NUM))
#define PRGPIO_GPIOC_STATUS         (0x01 || (SYSCTL->PRGPIO >> GPIOC_NUM))
#define PRGPIO_GPIOD_STATUS         (0x01 || (SYSCTL->PRGPIO >> GPIOD_NUM))
#define PRGPIO_GPIOE_STATUS         (0x01 || (SYSCTL->PRGPIO >> GPIOE_NUM))
#define PRGPIO_GPIOF_STATUS         (0x01 || (SYSCTL->PRGPIO >> GPIOF_NUM))
/*  UNLOCK VALUE TO ENABLE WRITE ACCESS ON GPIOCR REGISTER  */
#define GPIOLOCK_UNLOCK_VALUE	0x4C4F434B
/*  GPIO COMMIT CONTROL REGISTER */
#define GPIOCR_GPIOA	            /*  UNDEFINED */
#define GPIOCR_GPIOB	            /*  UNDEFINED */
#define GPIOCR_GPIOC	            /*  UNDEFINED */
#define GPIOCR_GPIOD	            /*  UNDEFINED */
#define GPIOCR_GPIOE	            /*  UNDEFINED */
#define GPIOCR_GPIOF	            0x1F
/*  GPIO ANALOG MODE SELECT */
#define GPIOAMSEL_PIN_0_ENABLE	    (1 << PIN_0)
#define GPIOAMSEL_PIN_0_DISABLE	    (~(1 << PIN_0))
#define GPIOAMSEL_PIN_1_ENABLE	    (1 << PIN_1)
#define GPIOAMSEL_PIN_1_DISABLE	    (~(1 << PIN_1))
#define GPIOAMSEL_PIN_2_ENABLE	    (1 << PIN_2)
#define GPIOAMSEL_PIN_2_DISABLE	    (~(1 << PIN_2))
#define GPIOAMSEL_PIN_3_ENABLE	    (1 << PIN_3)
#define GPIOAMSEL_PIN_3_DISABLE	    (~(1 << PIN_3))
#define GPIOAMSEL_PIN_4_ENABLE	    (1 << PIN_4)
#define GPIOAMSEL_PIN_4_DISABLE	    (~(1 << PIN_4))
#define GPIOAMSEL_PIN_5_ENABLE	    (1 << PIN_5)
#define GPIOAMSEL_PIN_5_DISABLE	    (~(1 << PIN_5))
#define GPIOAMSEL_PIN_6_ENABLE	    (1 << PIN_6)
#define GPIOAMSEL_PIN_6_DISABLE	    (~(1 << PIN_6))
#define GPIOAMSEL_PIN_7_ENABLE	    (1 << PIN_7)
#define GPIOAMSEL_PIN_7_DISABLE	    (~(1 << PIN_7))
#define GPIOAMSEL_ENABLE_ALL	    0x3F
#define GPIOAMSEL_DISABLE_ALL	    0x00
/*  GPIOAFSEL register is the mode control select register. */
#define GPIOAFSEL_DISABLE_ALL	    0x00
/*  GPIOPCTL REGISTER IS USED IN CONJUNCTION WITH THE GPIOAFSEL REGISTER AND 
    SELECTS THE SPECIFIC PERIPHERAL SIGNAL FOR EACH GPIO PIN WHEN USING THE 
    ALTERNATE FUNCTION MODE.  */
#define GPIOPCTL_DISABLE_ALL	    0x00
/*  GPIODIR REGISTER IS THE DATA DIRECTION REGISTER. */
#define GPIODIR_PIN0_OUTPUT	        (1 << PIN_0)
#define GPIODIR_PIN0_INPUT	        (~(1 << PIN_0))
#define GPIODIR_PIN1_OUTPUT	        (1 << PIN_1)
#define GPIODIR_PIN1_INPUT	        (~(1 << PIN_1))
#define GPIODIR_PIN2_OUTPUT	        (1 << PIN_2)
#define GPIODIR_PIN2_INPUT	        (~(1 << PIN_2))
#define GPIODIR_PIN3_OUTPUT	        (1 << PIN_3)
#define GPIODIR_PIN3_INPUT	        (~(1 << PIN_3))
#define GPIODIR_PIN4_OUTPUT	        (1 << PIN_4)
#define GPIODIR_PIN4_INPUT	        (~(1 << PIN_4))
#define GPIODIR_PIN5_OUTPUT	        (1 << PIN_5)
#define GPIODIR_PIN5_INPUT	        (~(1 << PIN_5))
#define GPIODIR_PIN6_OUTPUT	        (1 << PIN_6)
#define GPIODIR_PIN6_INPUT	        (~(1 << PIN_6))
#define GPIODIR_PIN7_OUTPUT	        (1 << PIN_7)
#define GPIODIR_PIN7_INPUT	        (~(1 << PIN_7))
/*   GPIOPUR REGISTER IS THE PULL-UP CONTROL REGISTER */
#define GPIOPUR_PIN0_ENABLED	    (1 << PIN_0)
#define GPIOPUR_PIN0_DISABLED	    (~(1 << PIN_0))
#define GPIOPUR_PIN1_ENABLED	    (1 << PIN_1)
#define GPIOPUR_PIN1_DISABLED	    (~(1 << PIN_1))
#define GPIOPUR_PIN2_ENABLED	    (1 << PIN_2)
#define GPIOPUR_PIN2_DISABLED	    (~(1 << PIN_2))
#define GPIOPUR_PIN3_ENABLED	    (1 << PIN_3)
#define GPIOPUR_PIN3_DISABLED	    (~(1 << PIN_3))
#define GPIOPUR_PIN4_ENABLED	    (1 << PIN_4)
#define GPIOPUR_PIN4_DISABLED	    (~(1 << PIN_4))
#define GPIOPUR_PIN5_ENABLED	    (1 << PIN_5)
#define GPIOPUR_PIN5_DISABLED	    (~(1 << PIN_5))
#define GPIOPUR_PIN6_ENABLED	    (1 << PIN_6)
#define GPIOPUR_PIN6_DISABLED	    (~(1 << PIN_6))
#define GPIOPUR_PIN7_ENABLED	    (1 << PIN_7)
#define GPIOPUR_PIN7_DISABLED	    (~(1 << PIN_7))
#define GPIOPUR_ENABLE_ALL	        0xFF
#define GPIOPUR_DISABLE_ALL	        0x00
/*  GPIODEN register is the digital enable register. */
#define GPIODEN_PIN0_ENABLED	    (1 << PIN_0)
#define GPIODEN_PIN0_DISABLED	    (~(1 << PIN_0))
#define GPIODEN_PIN1_ENABLED	    (1 << PIN_1)
#define GPIODEN_PIN1_DISABLED	    (~(1 << PIN_1))
#define GPIODEN_PIN2_ENABLED	    (1 << PIN_2)
#define GPIODEN_PIN2_DISABLED	    (~(1 << PIN_2))
#define GPIODEN_PIN3_ENABLED	    (1 << PIN_3)
#define GPIODEN_PIN3_DISABLED	    (~(1 << PIN_3))
#define GPIODEN_PIN4_ENABLED	    (1 << PIN_4)
#define GPIODEN_PIN4_DISABLED	    (~(1 << PIN_4))
#define GPIODEN_PIN5_ENABLED	    (1 << PIN_5)
#define GPIODEN_PIN5_DISABLED	    (~(1 << PIN_5))
#define GPIODEN_PIN6_ENABLED	    (1 << PIN_6)
#define GPIODEN_PIN6_DISABLED	    (~(1 << PIN_6))
#define GPIODEN_PIN7_ENABLED	    (1 << PIN_7)
#define GPIODEN_PIN7_DISABLED	    (~(1 << PIN_7))
#define GPIODEN_ENABLE_ALL	        0xFF
#define GPIODEN_DISABLE_ALL	        0x00

typedef enum
{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
} pin_t;

typedef enum
{
    PIN_LOW,
    PIN_HIGH
} pin_status_t;

typedef struct 
{
    pin_status_t last_state;
    pin_status_t new_state;
} pin_debounce_t;

typedef enum 
{
    NOTHING,
    RISING,
    FALLING
} edge_t;

typedef enum
{
    BLACK = 0x00,
    RED   = 0x02,
    BLUE =  0x04,
    MAGEN = 0x06,
    GREEN = 0x08,
    YELLO = 0x0A,
    CYAN  = 0x0C,
    WHITE = 0x0E,
} color_t;


void GPIOF_Config(void);
void GPIO_Write(GPIOA_Type* GPIOx, pin_t pin, pin_status_t status);
void GPIO_Toggle(GPIOA_Type* GPIOx, pin_t pin);
pin_status_t GPIO_Read_Pin(GPIOA_Type* GPIOx, pin_t pin);
void Pin_Debounce_Init(pin_debounce_t* pin_deb, pin_status_t status);
void Pin_Debounce_Update(pin_debounce_t* pin_deb, pin_status_t status);
edge_t Pin_Debounce(pin_debounce_t* pin_deb);
void GPIO_Inc_Leds_Color(color_t* color);
void GPIO_Toggle_Led_Color(color_t color);
void GPIO_Set_Led_Color(color_t color);
#endif
