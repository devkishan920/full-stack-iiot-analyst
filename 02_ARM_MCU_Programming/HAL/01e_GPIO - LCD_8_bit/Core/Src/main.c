#include "main.h"
#include "stm32f4xx.h"

UART_HandleTypeDef huart2;
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);



void PORTS_init(void);

void PORTS_init(void)	//	Step 1
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET); // drive R/W LOW
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET); // drive EN LOW
	HAL_Delay(500);
}


void LCD_command(unsigned char command);	//	Step 2

void LCD_command(unsigned char command)
{
	/* RS = 0, R/W = 0 */
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET); // drive R/W LOW
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET); // drive RS LOW
	HAL_Delay(500);

	HAL_GPIO_WritePin(GPIOC, 0xFF, GPIO_PIN_RESET); // Clear previous data
	HAL_GPIO_WritePin(GPIOC, command, GPIO_PIN_SET); // Put command on data bus

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);	/* pulse E high */
	HAL_Delay(0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);/* clear E */

	if (command < 4)
		HAL_Delay(2); 				/* command 1 and 2 needs up to 1.64ms */
	else
		HAL_Delay(1);
}

void LCD_data(char data);	// Step 3

void LCD_data(char data)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET); // drive R/W LOW
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET); // drive RS HIGH
	HAL_Delay(1);

	HAL_GPIO_WritePin(GPIOC, 0xFF, GPIO_PIN_RESET); // Clear previous data
	HAL_GPIO_WritePin(GPIOC, data, GPIO_PIN_SET); // Put command on data bus

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);	/* pulse E high */
	HAL_Delay(0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);/* clear E */
}

void LCD_init(void);	// Step 4

void LCD_init(void)
{
  LCD_command(0x38);		/*set 8-bit data, 2-line, 5x7 font */
  LCD_command(0x06);		/*move cursor right after each char */
  LCD_command(0x01);		/*clear screen, move cursor to home */
  LCD_command(0x0F);		/*turn on display, cursor blinking */
}

void LCD_string(char []);

void LCD_string(char str[])
{
	for(int i=0;str[i]!='\0';i++)
	{
	  LCD_data(str[i]);
	}
}

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  PORTS_init();
  LCD_init();

  while (1)
  {
	  LCD_string("Hello World\0");
	  HAL_Delay(500);
  }
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PC0 PC1 PC2 PC3
                           PC4 PC5 PC6 PC7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PB5 PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */


//#include "main.h"
//#include "stm32f4xx_hal.h"
//
//#define RS GPIO_PIN_5   /* PB5 mask for reg select */
//#define RW GPIO_PIN_6   /* PB6 mask for read/write */
//#define EN GPIO_PIN_7   /* PB7 mask for enable */
//
//UART_HandleTypeDef huart2;
//void SystemClock_Config(void);
//static void MX_GPIO_Init(void);
//static void MX_USART2_UART_Init(void);
//
//void delayMs(int n);
//void LCD_command(unsigned char command);
//void LCD_string(char str[]);
//void LCD_data(char data);
//void LCD_init(void);
//void PORTS_init(void);
//
//int main(void) {
//    HAL_Init();
//    SystemClock_Config();
//    MX_GPIO_Init();
//    MX_USART2_UART_Init();
//
//    LCD_init(); /* initialize LCD controller */
//
//    /* Display a message on the LCD */
//    LCD_string("Hello, World!");
//
//    while (1) {
//        // Main loop can be empty or used for other tasks
//    }
//}
//
///* Initialize ports for LCD */
//void PORTS_init(void) {
//    __HAL_RCC_GPIOB_CLK_ENABLE();
//    __HAL_RCC_GPIOC_CLK_ENABLE();
//
//    GPIO_InitTypeDef GPIO_InitStruct = {0};
//
//    /* Configure GPIO pins for PB5, PB6, PB7 */
//    GPIO_InitStruct.Pin = RS | RW | EN;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//    /* Configure GPIO pins for PC0-PC7 */
//    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 |
//                          GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
//    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
//}
//
//void LCD_command(unsigned char command) {
//    HAL_GPIO_WritePin(GPIOB, RS, GPIO_PIN_RESET); // RS = 0
//    HAL_GPIO_WritePin(GPIOB, RW, GPIO_PIN_RESET); // RW = 0
//    HAL_Delay(1);
//
//    HAL_GPIO_WritePin(GPIOC, 0xFF, GPIO_PIN_RESET); // Clear previous data
//    HAL_GPIO_WritePin(GPIOC, command, GPIO_PIN_SET); // Put command on data bus
//
//    HAL_GPIO_WritePin(GPIOB, EN, GPIO_PIN_SET); // Pulse E high
//    HAL_Delay(1);
//    HAL_GPIO_WritePin(GPIOB, EN, GPIO_PIN_RESET); // Clear E
//
//    if (command < 4) {
//        HAL_Delay(2); // Command 1 and 2 need up to 1.64ms
//    } else {
//        HAL_Delay(1); // All others 40 us
//    }
//}
//
//void LCD_data(char data) {
//    HAL_GPIO_WritePin(GPIOB, RS, GPIO_PIN_SET); // RS = 1
//    HAL_GPIO_WritePin(GPIOB, RW, GPIO_PIN_RESET); // RW = 0
//    HAL_Delay(1);
//
//    HAL_GPIO_WritePin(GPIOC, 0xFF, GPIO_PIN_RESET); // Clear previous data
//    HAL_GPIO_WritePin(GPIOC, data, GPIO_PIN_SET); // Put data on data bus
//
//    HAL_GPIO_WritePin(GPIOB, EN, GPIO_PIN_SET); // Pulse E high
//    HAL_Delay(1);
//    HAL_GPIO_WritePin(GPIOB, EN, GPIO_PIN_RESET); // Clear E
//}
//
//void LCD_string(char str[]) {
//    for (int i = 0; str[i] != '\0'; i++) {
//        LCD_data(str[i]);
//    }
//}
//
//void LCD_init(void) {
//    PORTS_init();
//    HAL_Delay(30); /* initialization sequence */
//    LCD_command(0x30);
//    HAL_Delay(10);
//    LCD_command(0x30);
//    HAL_Delay(1);
//    LCD_command(0x30);
//    LCD_command(0x38); /* set 8-bit data, 2-line, 5x7 font */
//    LCD_command(0x06); /* move cursor right after each char */
//    LCD_command(0x01); /* clear screen, move cursor to home */
//    LCD_command(0x0F); /* turn on display, cursor blinking */
//}
//
//void delayMs(int n) {
//    HAL_Delay(n);
//}
//
//void SystemClock_Config(void) {
//    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
//    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
//
//    __HAL_RCC_PWR_CLK_ENABLE();
//    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
//
//    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
//    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
//    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
//    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
//    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
//    RCC_OscInitStruct.PLL.PLLM = 16;
//    RCC_OscInitStruct.PLL.PLLN = 336;
//    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
//    RCC_OscInitStruct.PLL.PLLQ = 2;
//    RCC_OscInitStruct.PLL.PLLR = 2;
//    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
//        Error_Handler();
//    }
//
//    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
//                                  RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
//    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
//    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
//    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
//
//    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
//        Error_Handler();
//    }
//}
//
///**
//  * @brief USART2 Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_USART2_UART_Init(void) {
//    huart2.Instance = USART2;
//    huart2.Init.BaudRate = 115200;
//    huart2.Init.WordLength = UART_WORDLENGTH_8B;
//    huart2.Init.StopBits = UART_STOPBITS_1;
//    huart2.Init.Parity = UART_PARITY_NONE;
//    huart2.Init.Mode = UART_MODE_TX_RX;
//    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
//    if (HAL_UART_Init(&huart2) != HAL_OK) {
//        Error_Handler();
//    }
//}
//
///**
//  * @brief GPIO Initialization Function
//  * @param None
//  * @retval None
//  */
//static void MX_GPIO_Init(void) {
//    GPIO_InitTypeDef GPIO_InitStruct = {0};
//
//    /* GPIO Ports Clock Enable */
//    __HAL_RCC_GPIOC_CLK_ENABLE();
//    __HAL_RCC_GPIOH_CLK_ENABLE();
//    __HAL_RCC_GPIOA_CLK_ENABLE();
//    __HAL_RCC_GPIOB_CLK_ENABLE();
//
//    /*Configure GPIO pin Output Level */
//    HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
//
//    /*Configure GPIO pin Output Level */
//    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
//
//    /*Configure GPIO pin : LD2_Pin */
//    GPIO_InitStruct.Pin = LD2_Pin;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//    HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);
//
//    /*Configure GPIO pin : PB7 */
//    GPIO_InitStruct.Pin = GPIO_PIN_7;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//}
//
///**
//  * @brief  This function is executed in case of error occurrence.
//  * @retval None
//  */
//void Error_Handler(void) {
//    __disable_irq();
//    while (1) {
//    }
//}
//
//#ifdef USE_FULL_ASSERT
///**
//  * @brief  Reports the name of the source file and the source line number
//  *         where the assert_param error has occurred.
//  * @param  file: pointer to the source file name
//  * @param  line: assert_param error line source number
//  * @retval None
//  */
//void assert_failed(uint8_t *file, uint32_t line) {
//    printf("Wrong parameters value: file %s on line %d\r\n", file, line);
//}
//#endif /* USE_FULL_ASSERT */
