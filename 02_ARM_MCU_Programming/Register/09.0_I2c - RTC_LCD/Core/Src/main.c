#include "stm32f4xx.h"

void set_date_time(void);
void set_alarm(void);
void get_date_time(char *time, char *date);
void Error_Handler(void);

char timeData[15];
char dateData[15];


void set_date_time(void) {
    // Clear the existing time register values
    RTC->TR &= ~((1U << 20) | (0x3F << 16) | (0x7F << 8) | (0x7F << 0));

    // Set hours to 14 (0x14 in BCD)
    RTC->TR |= (1 << 20);  // HT = 1
    RTC->TR |= (4 << 16);  // HU = 4

    // Set minutes to 57 (0x57 in BCD)
    RTC->TR |= (5 << 12);  // MNT = 5
    RTC->TR |= (7 << 8);   // MNU = 7

    // Set seconds to 0 (0x00 in BCD)
    RTC->TR |= (0 << 4);   // ST = 0
    RTC->TR |= (0 << 0);   // SU = 0

    // Clear the existing date register values
    RTC->DR &= ~((1U << 20) | (0xF << 16) | (0x7 << 13) | (0x3F << 8) | (0xF << 4) | (0xF << 0));
    // Set year to 2025 (0x25 in BCD)
    RTC->DR |= (2 << 20);  // YT = 2
    RTC->DR |= (5 << 16);  // YU = 5

    // Set weekday to Tuesday (0x3 in BCD)
    RTC->DR |= (3 << 13);  // WDU = 3

    // Set month to February (0x2 in BCD)
    RTC->DR |= (0 << 12);  // MT = 0
    RTC->DR |= (2 << 8);   // MU = 2

    // Set day to 4 (0x4 in BCD)
    RTC->DR |= (0 << 4);   // DT = 0
    RTC->DR |= (4 << 0);   // DU = 4
}


void set_alarm(void)
{
  RTC->CR &= ~RTC_CR_ALRAE;
  while (!(RTC->ISR & RTC_ISR_ALRAWF));
  RTC->ALRMAR = (0x15 << RTC_ALRMAR_HT_Pos) | (0x02 << RTC_ALRMAR_MNT_Pos) | (0x00 << RTC_ALRMAR_ST_Pos) | (RTC_ALRMAR_MSK4);

  RTC->CR |= RTC_CR_ALRAE | RTC_CR_ALRAIE;
  EXTI->IMR |= EXTI_IMR_IM18;
  EXTI->RTSR |= EXTI_RTSR_TR18;
  NVIC_EnableIRQ(RTC_Alarm_IRQn);
}

void get_date_time(char *time, char *date)
{
  uint32_t timeReg = RTC->TR;
  uint32_t dateReg = RTC->DR;
  uint8_t hours = (timeReg & RTC_TR_HT) >> RTC_TR_HT_Pos;
  uint8_t minutes = (timeReg & RTC_TR_MNT) >> RTC_TR_MNT_Pos;
  uint8_t seconds = (timeReg & RTC_TR_ST) >> RTC_TR_ST_Pos;
  uint8_t day = (dateReg & RTC_DR_DU) >> RTC_DR_DU_Pos;
  uint8_t month = (dateReg & RTC_DR_MU) >> RTC_DR_MU_Pos;
  uint8_t year = (dateReg & RTC_DR_YU) >> RTC_DR_YU_Pos;

  sprintf(time, "%02d:%02d:%02d", hours, minutes, seconds);
  sprintf(date, "%02d-%02d-%02d", day, month, year + 2000);
}

void RTC_Alarm_IRQHandler(void)
{
  if (RTC->ISR & RTC_ISR_ALRAF)
  {
    RTC->ISR &= ~RTC_ISR_ALRAF;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
  }
}

void rtc_init()
{
  RCC->APB1ENR |= RCC_APB1ENR_PWREN;
}

int main()
{
  GPIO_Init();
  UART2_Init();
  I2C1_Init();
  RTC_Init();
  lcd_init();
  set_date_time();
  set_alarm();

  while (1)
  {
    get_date_time(timeData, dateData);
    lcd_put_cur(0, 0);
    lcd_send_string(timeData);
    lcd_put_cur(1, 0);
    lcd_send_string(dateData);
    HAL_Delay(500);
  }
}









//#include "stm32f4xx.h"
//#include "stm32f446xx.h"
//
//#define SLAVE_ADDRESS_LCD 0x4E // change this according to your setup
//
//void SystemClock_Config(void);
//void GPIO_Init(void);
//void UART2_Init(void);
//void I2C1_Init(void);
//void RTC_Init(void);
//
//void lcd_send_cmd(char cmd);
//void lcd_send_data(char data);
//void lcd_clear(void);
//void lcd_put_cur(int row, int col);
//void lcd_init(void);
//void lcd_send_string(char *str);
//
//void set_date_time(void);
//void set_alarm(void);
//void get_date_time(char *time, char *date);
//void Error_Handler(void);
//
//char timeData[15];
//char dateData[15];
//
//void lcd_send_cmd(char cmd) {
//    // Send upper nibble
//    uint8_t data_u = (cmd & 0xF0);
//    uint8_t data_l = ((cmd << 4) & 0xF0);
//    uint8_t data_t[4];
//    data_t[0] = data_u | 0x0C; // en=1, rs=0
//    data_t[1] = data_u | 0x08; // en=0, rs=0
//    data_t[2] = data_l | 0x0C; // en=1, rs=0
//    data_t[3] = data_l | 0x08; // en=0, rs=0
//
//    // I2C1 Transmit
//    while(!(I2C1->SR1 & I2C_SR1_TXE));
//    I2C1->DR = SLAVE_ADDRESS_LCD;
//    for(int i=0; i<4; i++) {
//        while(!(I2C1->SR1 & I2C_SR1_TXE));
//        I2C1->DR = data_t[i];
//    }
//}
//
//void lcd_send_data(char data) {
//    uint8_t data_u = (data & 0xF0);
//    uint8_t data_l = ((data << 4) & 0xF0);
//    uint8_t data_t[4];
//    data_t[0] = data_u | 0x0D; // en=1, rs=1
//    data_t[1] = data_u | 0x09; // en=0, rs=1
//    data_t[2] = data_l | 0x0D; // en=1, rs=1
//    data_t[3] = data_l | 0x09; // en=0, rs=1
//
//    // I2C1 Transmit
//    while(!(I2C1->SR1 & I2C_SR1_TXE));
//    I2C1->DR = SLAVE_ADDRESS_LCD;
//    for(int i=0; i<4; i++) {
//        while(!(I2C1->SR1 & I2C_SR1_TXE));
//        I2C1->DR = data_t[i];
//    }
//}
//
//void lcd_clear(void) {
//    lcd_send_cmd(0x80);
//    for (int i = 0; i < 70; i++) {
//        lcd_send_data(' ');
//    }
//}
//
//void lcd_put_cur(int row, int col) {
//    switch (row) {
//    case 0: col |= 0x80; break;
//    case 1: col |= 0xC0; break;
//    }
//    lcd_send_cmd(col);
//}
//
//void lcd_init(void) {
//    HAL_Delay(50);
//    lcd_send_cmd(0x30);
//    HAL_Delay(5);
//    lcd_send_cmd(0x30);
//    HAL_Delay(1);
//    lcd_send_cmd(0x30);
//    HAL_Delay(10);
//    lcd_send_cmd(0x20);
//    HAL_Delay(10);
//    lcd_send_cmd(0x28);
//    HAL_Delay(1);
//    lcd_send_cmd(0x08);
//    HAL_Delay(1);
//    lcd_send_cmd(0x01);
//    HAL_Delay(1);
//    lcd_send_cmd(0x06);
//    HAL_Delay(1);
//    lcd_send_cmd(0x0C);
//}
//
//void set_date_time(void) {
//    RTC->TR = (0x14 << RTC_TR_HU_Pos) | (0x57 << RTC_TR_MNU_Pos) | (0x00 << RTC_TR_SU_Pos);
//    RTC->DR = (0x25 << RTC_DR_YU_Pos) | (RTC_WEEKDAY_TUESDAY << RTC_DR_WDU_Pos) | (0x2 << RTC_DR_MU_Pos) | (0x4 << RTC_DR_DU_Pos);
//}
//
//void set_alarm(void) {
//    RTC->CR &= ~RTC_CR_ALRAE;
//    while (!(RTC->ISR & RTC_ISR_ALRAWF));
//    RTC->ALRMAR = (0x15 << RTC_ALRMAR_HT_Pos) | (0x02 << RTC_ALRMAR_MNT_Pos) | (0x00 << RTC_ALRMAR_ST_Pos) | (RTC_ALRMAR_MSK4);
//    RTC->CR |= RTC_CR_ALRAE | RTC_CR_ALRAIE;
//    EXTI->IMR |= EXTI_IMR_IM18;
//    EXTI->RTSR |= EXTI_RTSR_TR18;
//    NVIC_EnableIRQ(RTC_Alarm_IRQn);
//}
//
//void get_date_time(char *time, char *date) {
//    uint32_t timeReg = RTC->TR;
//    uint32_t dateReg = RTC->DR;
//    uint8_t hours = (timeReg & RTC_TR_HT) >> RTC_TR_HT_Pos;
//    uint8_t minutes = (timeReg & RTC_TR_MNT) >> RTC_TR_MNT_Pos;
//    uint8_t seconds = (timeReg & RTC_TR_ST) >> RTC_TR_ST_Pos;
//    uint8_t day = (dateReg & RTC_DR_DU) >> RTC_DR_DU_Pos;
//    uint8_t month = (dateReg & RTC_DR_MU) >> RTC_DR_MU_Pos;
//    uint8_t year = (dateReg & RTC_DR_YU) >> RTC_DR_YU_Pos;
//
//    sprintf(time, "%02d:%02d:%02d", hours, minutes, seconds);
//    sprintf(date, "%02d-%02d-%02d", day, month, year + 2000);
//}
//
//void RTC_Alarm_IRQHandler(void) {
//    if (RTC->ISR & RTC_ISR_ALRAF) {
//        RTC->ISR &= ~RTC_ISR_ALRAF;
//        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
//    }
//}
//
//int main(void) {
//    // Hardware and peripherals initialization
//    SystemClock_Config();
//    GPIO_Init();
//    UART2_Init();
//    I2C1_Init();
//    RTC_Init();
//    lcd_init();
//    set_date_time();
//    set_alarm();
//
//    while (1) {
//        get_date_time(timeData, dateData);
//        lcd_put_cur(0, 0);
//        lcd_send_string(timeData);
//        lcd_put_cur(1, 0);
//        lcd_send_string(dateData);
//        HAL_Delay(500);
//    }
//}
//
//void SystemClock_Config(void) {
//    RCC->CR |= RCC_CR_HSION;
//    while (!(RCC->CR & RCC_CR_HSIRDY));
//    RCC->CFGR = RCC_CFGR_SW_HSI;
//    RCC->PLLCFGR = (16 << RCC_PLLCFGR_PLLM_Pos) | (336 << RCC_PLLCFGR_PLLN_Pos) | (1 << RCC_PLLCFGR_PLLP_Pos);
//    RCC->CR |= RCC_CR_PLLON;
//    while (!(RCC->CR & RCC_CR_PLLRDY));
//    RCC->CFGR |= RCC_CFGR_SW_PLL;
//    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
//    PWR->CR |= PWR_CR_VOS_1;
//}
//
//void GPIO_Init(void) {
//    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN;
//    GPIOA->MODER |= GPIO_MODER_MODER5_0;
//}
//
//void UART2_Init(void) {
//    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
//    GPIOA->MODER |= GPIO_MODER_MODER2_1 | GPIO_MODER_MODER3_1;
//    GPIOA->AFR[0] |= (7 << GPIO_AFRL_AFSEL2_Pos) | (7 << GPIO_AFRL_AFSEL3_Pos);
//    USART2->BRR = 0x683;
//    USART2->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE;
//}
//
//void I2C1_Init(void) {
//    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
//    GPIOB->MODER |= GPIO_MODER_MODER8_1 | GPIO_MODER_MODER9_1;
//    GPIOB->AFR[1] |= (4 << GPIO_AFRH_AFSEL8_Pos) | (4 << GPIO_AFRH_AFSEL9_Pos);
//    I2C1->CR2 = 0x20;
//    I2C1->CCR = 0x80;
//    I2C1->TRISE = 0x21;
//    I2C1->CR1 |= I2C_CR1_PE;
//}
//
//void RTC_Init(void) {
//    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
//}
