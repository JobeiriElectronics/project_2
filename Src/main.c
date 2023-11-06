#include "stm32f4xx_hal.h"

#define _GPIOA_CLK_ENABLE __HAL_RCC_GPIOA_CLK_ENABLE()
#define _GPIOB_CLK_ENABLE __HAL_RCC_GPIOB_CLK_ENABLE()
#define _GPIOC_CLK_ENABLE __HAL_RCC_GPIOC_CLK_ENABLE()
#define _GPIOD_CLK_ENABLE __HAL_RCC_GPIOD_CLK_ENABLE()
#define _GPIOE_CLK_ENABLE __HAL_RCC_GPIOE_CLK_ENABLE()
#define _GPIOF_CLK_ENABLE __HAL_RCC_GPIOF_CLK_ENABLE()
#define _GPIOG_CLK_ENABLE __HAL_RCC_GPIOG_CLK_ENABLE()

#define _USART1_CLK_ENABLE __HAL_RCC_USART1_CLK_ENABLE()
#define _USART2_CLK_ENABLE __HAL_RCC_USART2_CLK_ENABLE()
#define _USART3_CLK_ENABLE __HAL_RCC_USART3_CLK_ENABLE()
#define _USART4_CLK_ENABLE __HAL_RCC_USART4_CLK_ENABLE()
#define _USART5_CLK_ENABLE __HAL_RCC_USART5_CLK_ENABLE()
#define _USART6_CLK_ENABLE __HAL_RCC_USART6_CLK_ENABLE()
#define _USART7_CLK_ENABLE __HAL_RCC_USART7_CLK_ENABLE()
#define _USART8_CLK_ENABLE __HAL_RCC_USART8_CLK_ENABLE()

#define _ADC_CLK_ENABLE __HAL_RCC_ADC_CLK_ENABLE()

// GPIO FUNCTION DECLARATION
void gpio_pa3_init (void);
void gpio_pg3_init (void);
void gpio_pc2_init (void);
void gpio_pc3_init (void);

// UART FUNCTION DECLARATION
void uart_tx_pa9_init (void);
void uart_rx_pa10_init (void);

// GLOBAL VARIABLE
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
UART_HandleTypeDef huart4;
UART_HandleTypeDef huart5;
UART_HandleTypeDef huart6;

uint16_t buttonStatus;
char message [20] = "Hello from STM32 \r\n";

int main (void)
{

	HAL_Init();
	uart_tx_pa9_init();

	// GPIO FUNCTION DECLARATION
	//gpio_pa3_init();
	//gpio_pc2_init();
	// gpio_pg3_init();
	// gpio_pc3_init();


	while(1)
	{
		// GPIO WORKING
		// buttonStatus = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
		// HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, buttonStatus);
		// buttonStatus = HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_3);
		// HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, buttonStatus);

		//UART WORKING
		HAL_UART_Transmit (&huart1, (uint8_t *) message, 20, 100);
		HAL_Delay(10);

	}
}

// GPIO FUCTION DEFINITION
void gpio_pa3_init (void)
{
	_GPIOA_CLK_ENABLE;

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}
void gpio_pg3_init (void)
{
	_GPIOG_CLK_ENABLE;

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
}
void gpio_pc2_init (void)
{
	_GPIOC_CLK_ENABLE;

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = GPIO_PIN_2;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}
void gpio_pc3_init (void)
{
	_GPIOC_CLK_ENABLE;

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

// UART1 FUNCTION DEFINITION
void uart_tx_pa9_init (void)
{
	_GPIOA_CLK_ENABLE;

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = GPIO_PIN_9;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	_USART1_CLK_ENABLE;

	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = USART_WORDLENGTH_8B;
	huart1.Init.StopBits = USART_STOPBITS_1;
	huart1.Init.Parity = USART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init(&huart1);
}
void uart_rx_pa10_init(void)
{
	_GPIOA_CLK_ENABLE;

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = GPIO_PIN_10;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	_USART1_CLK_ENABLE;

	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = USART_WORDLENGTH_8B;
	huart1.Init.StopBits = USART_STOPBITS_1;
	huart1.Init.Parity = USART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init(&huart1);
}

// UART3 FUNCTION DEFINITION
void uart_tx_pb10_init (void)
{
	_GPIOB_CLK_ENABLE;

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = GPIO_PIN_10;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART3;

	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	_USART3_CLK_ENABLE;

	huart3.Instance = USART3;
	huart3.Init.BaudRate = 115200;
	huart3.Init.WordLength = USART_WORDLENGTH_8B;
	huart3.Init.StopBits = USART_STOPBITS_1;
	huart3.Init.Parity = USART_PARITY_NONE;
	huart3.Init.Mode = UART_MODE_TX;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init(&huart3);
}
void uart_rx_pB11_init(void)
{
	_GPIOA_CLK_ENABLE;

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = GPIO_PIN_11;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART3;

	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	_USART1_CLK_ENABLE;

	huart3.Instance = USART3;
	huart3.Init.BaudRate = 115200;
	huart3.Init.WordLength = USART_WORDLENGTH_8B;
	huart3.Init.StopBits = USART_STOPBITS_1;
	huart3.Init.Parity = USART_PARITY_NONE;
	huart3.Init.Mode = UART_MODE_RX;
	huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart3.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init(&huart3);
}

void SysTick_Handler (void)
{
	HAL_IncTick();
}

