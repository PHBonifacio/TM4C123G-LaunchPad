#include <TM4C123GH6PM.h>
#include <stdint.h>              /* Definicao de tipos inteiros, maximos e minimos */
#include "gpio.h"
#include "timer.h"

void GPIOF_Init()
{
    SYSCTL->RCGCGPIO |= 0x20; //1 - Ativar o clock (RCGCGPIO)
    while (!(SYSCTL->PRGPIO & 0x20));                     //2 - Verificar se o port está pronto (PRGPIO)
    GPIOF->LOCK = 0x4C4F434B; //3 - Destravar o port (LOCK e CR)
    GPIOF->CR = 0x1F;
    GPIOF->AMSEL = 0x00; //4 - Desabilitar função analógica (AMSEL)
    GPIOF->PCTL = 0x00;  //5 - Selecionar a função dos pinos (PCTL)
    GPIOF->DIR = 0x0E;   //6 - Definir o sentido dos pinos (DIR)
    GPIOF->AFSEL = 0x00; //7 - Desabilitar funções alternativas (AFSEL)
    GPIOF->PUR = 0x11;   //8 - Habilitar pull-ups (PUR)
    GPIOF->DEN = 0x1F;   //9 - Habilitar função digital (DEN)
}

freq_t led_freq = FREQ_1HZ;
color_t led_color = RED;

void PLL_Init()
{
    // 1) Habilitar o divisor fe frequência SYSDIV
    SYSCTL->RCC |= 0x000400000;
    // 2) Configurar o sistema para usar o RCC2 para recursos avançados como
    // PLL de 400 MHz e divisão do clock por valores não inteiros
    SYSCTL->RCC2 |= 0x80000000; // USERCC2
    // 3) Bypass do PLL enqunato inicializar
    SYSCTL->RCC2 |= 0x00000800; // BYPASS2, PLL bypass
    // 4) Selecionar o valor do cristal e a fonto do oscilador
    SYSCTL->RCC &= ~0x000007C0;  // limpar o campo XTAL
    SYSCTL->RCC += 0x00000540;   // configurar para um cristal de 16 MHz
    SYSCTL->RCC2 &= ~0x00000070; // limpar o campo do oscilador
    SYSCTL->RCC2 += 0x00000000;  // configurar a fonte como main oscillator
    // 5) Ativar o PLL limpando o PWRDN
    SYSCTL->RCC2 &= ~0x00002000;
    // 6) Ajustar o divisor desejado e o LSB do divisor do sistema (bit 22 para 400 MHz de PLL)
    SYSCTL->RCC2 |= 0x40000000;                                    // usar 400 MHz de PLL
    //SYSCTL->RCC2 = (SYSCTL->RCC2 & ~0x1FC00000) + (SYSDIV2 << 22); // configurar para clock de 80 MHz
    // 7) Aguardar o PLL começar a operar fazendo polling no PLLLRIS
    while ((SYSCTL->RIS & 0x00000040) == 0)
    {
    }; // Aguargar pelo bit PLLLRIS
    // 8) Habilitar o PLL limpando o BYPASS
    SYSCTL->RCC2 &= ~0x00000800;
    SystemCoreClockUpdate();
}

int main()
{
    pin_debounce_t sw1;
    pin_debounce_t sw2;

    Pin_Debounce_Init(&sw1, PIN_HIGH);
    Pin_Debounce_Init(&sw2, PIN_HIGH);

    GPIOF_Config();

	//PLL_Init();
   
    SysTick_Config(SystemCoreClock / 1000);
    while (1)
    {
	    Pin_Debounce_Update(&sw1, GPIO_Read_Pin(GPIOF, PIN4));
        Pin_Debounce_Update(&sw2, GPIO_Read_Pin(GPIOF, PIN0));
        if (FALLING == Pin_Debounce(&sw1))
        {
            //GPIO_Toggle(GPIOF, PIN2);
            GPIO_Inc_Leds_Color(&led_color);
        }

        if (FALLING == Pin_Debounce(&sw2))
        {
            //GPIO_Toggle(GPIOF, PIN3);
            led_freq++;
        }

    }
}

void SysTick_Handler(void)
{
    static uint16_t ms_count = 0;

    ms_count++;

    switch (led_freq)
    {
        case FREQ_1HZ:
            if (0 == (ms_count % 1000))
            {
                GPIO_Toggle_Led_Color(led_color);
            }

        break;

        case FREQ_2HZ:
            if (0 == (ms_count % 500))
            {
                GPIO_Toggle_Led_Color(led_color);
            }
            
        break;

        case FREQ_5HZ:
            if (0 == (ms_count % 200))
            {
                GPIO_Toggle_Led_Color(led_color);
            }
            
        break;

        case FREQ_10HZ:
            if (0 == (ms_count % 100))
            {
                GPIO_Toggle_Led_Color(led_color);
            }
            
        break;

        case FREQ_20HZ:
            if (0 == (ms_count % 50))
            {
                GPIO_Toggle_Led_Color(led_color);
            }
            
        break;

        case FREQ_50HZ:
            if (0 == (ms_count % 20))
            {
                GPIO_Toggle_Led_Color(led_color);
            }
            
        break;

        case FREQ_100HZ:
            if (0 == (ms_count % 10))
            {
                GPIO_Toggle_Led_Color(led_color);
            }
            
        break;
        
        default:
            led_freq = FREQ_1HZ;
        break;
    }
}
