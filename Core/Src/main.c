/**
 ******************************************************************************
 * @file           : main.c
 * @author         : it32bit
 * @brief          : Main program body
 ******************************************************************************
 * This software is licensed under the MIT License.
 * Provided "as is", without warranty of any kind.
 * The author is not liable for any damages resulting from its use.
 ******************************************************************************
 */

#include <stdint.h>
#include "main.h"
#include "app_main.hpp"
#include <unistd.h>

/**
 * @brief System Clock Configuration
 * @retval None
 * @details
 * The system Clock is configured as follows :
 *    System Clock source            = PLL (HSE)
 *    SYSCLK(Hz)                     = 168000000
 *    HCLK(Hz)                       = 168000000
 *    AHB Prescaler                  = 1
 *    AHB Perypheral(Hz) Memory, DMA = 168000000
 *    APB1 Prescaler                 = 4
 *    APB1 Perypheral(Hz)            = 42000000
 *    APB2 Prescaler                 = 2
 *    APB2 Perypheral(Hz)            = 84000000
 *    HSE Frequency(Hz)              = 8000000
 *    PLL_M                          = 8
 *    PLL_N                          = 336
 *    PLL_P                          = 2
 *    PLL_Q                          = 7
 *    VDD(V)                         = 3.3
 *    Main regulator output voltage  = Scale1 mode
 *    Flash Latency(WS)              = 5
 */
static void SystemClock_Config(void);

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
    /* Configure the system clock */
    SystemClock_Config();

    /* Initialize all configured peripherals */
    HAL_Init();

    /* Call the C++ application entry point with infinite loop */
    App_cpp();

    /* Execution should never reach here because App_cpp() runs an infinite loop. */
    for (;;)
    {
        ;
    }
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
    uint32_t loop = 0;
    __disable_irq();
    while (1)
    {
        ++loop;
    }
}

/**
 * @description  : Static function
 */

static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Configure the main internal regulator output voltage */
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /** Initializes the RCC Oscillators according to the specified parameters
    in the RCC_OscInitTypeDef structure. */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState       = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState   = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource  = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM       = 8;
    RCC_OscInitStruct.PLL.PLLN       = 336;
    RCC_OscInitStruct.PLL.PLLP       = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ       = 7;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks */
    RCC_ClkInitStruct.ClockType =
        RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
    {
        Error_Handler();
    }
}

void uart2_send_char(char c)
{
    while (!(USART2->SR & USART_SR_TXE))
        ; // Wait until TX buffer is empty
    USART2->DR = c;
}

int _write(int file, char* ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        uart2_send_char(ptr[i]);
    }
    return len;
}

// int __io_putchar(int ch)
// {
//     uart2_send_char(ch);
//     return ch;
// }