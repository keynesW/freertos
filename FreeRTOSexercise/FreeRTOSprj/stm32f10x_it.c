//include stm32f10x_it.h will inderectly include all the .h file under stm32f10x_it.h in the prj

#include "stm32f10x_it.h"
//This is an include chain for declarations of expection handler functions.
//expection handle function should be defined in this file.

/*
void NMIException(void);
void HardFaultException(void);
void MemManageException(void);
void BusFaultException(void);
void UsageFaultException(void);
void DebugMonitor(void);


void SysTickHandler(void);
void WWDG_IRQHandler(void);
void PVD_IRQHandler(void);
void TAMPER_IRQHandler(void);
void RTC_IRQHandler(void);
void FLASH_IRQHandler(void);
void RCC_IRQHandler(void);
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI4_IRQHandler(void);
void DMAChannel1_IRQHandler(void);
void DMAChannel2_IRQHandler(void);
void DMAChannel3_IRQHandler(void);
void DMAChannel4_IRQHandler(void);
void DMAChannel5_IRQHandler(void);
void DMAChannel6_IRQHandler(void);
void DMAChannel7_IRQHandler(void);
void ADC_IRQHandler(void);
void USB_HP_CAN_TX_IRQHandler(void);
void USB_LP_CAN_RX0_IRQHandler(void);
void CAN_RX1_IRQHandler(void);
void CAN_SCE_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
void TIM1_BRK_IRQHandler(void);
void TIM1_UP_IRQHandler(void);
void TIM1_TRG_COM_IRQHandler(void);
void TIM1_CC_IRQHandler(void);
void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);
void I2C1_EV_IRQHandler(void);
void I2C1_ER_IRQHandler(void);
void I2C2_EV_IRQHandler(void);
void I2C2_ER_IRQHandler(void);
void SPI1_IRQHandler(void);
void SPI2_IRQHandler(void);
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);
void EXTI15_10_IRQHandler(void);
void RTCAlarm_IRQHandler(void);
void USBWakeUp_IRQHandler(void);
*/





/**********************************************************************
//void SVCHandler(void);
//void PendSVC(void);
//these two functions (interrupt service routing) and the function 
//bellow are used for the FreeRTOS kernel. 
//User should not modify or use these functions.
***********************************************************************/
void SysTick_Handler(void){

		#if ( INCLUDE_xTaskGetSchedulerState == 1 )
				
					if( xTaskGetSchedulerState() != taskscheduler_not_started){
		#endif
					xPortSysTickHandler();									//Defined in port.c  used for task exchanging when timeslice of 
																									//a Task is used out
		#if ( INCLUDE_xTaskGetSchedulerState == 1 )
					}
		#endif
	
}
/*
the comments below were found in stm32f10x_gpio.h and stm32f10x_map.h

typedef struct
{
  vu32 CRL;
  vu32 CRH;
  vu32 IDR;
  vu32 ODR;
  vu32 BSRR;
  vu32 BRR;
  vu32 LCKR;
} GPIO_TypeDef;

#define EXT extern

ifndef
    debug   	 :  #define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)

#define GPIOA_BASE                        (APB2PERIPH_BASE + 0x0800)

#define GPIOA  (Struct{ ... } * ( APB2PERIPH_BASE + 0X800 ))
//////////////////////////////////////////////////////////////////
#ifdef  
	debug        :  EXT GPIO_TypeDef          *GPIOA;
this used for debug
/////////////////////////////////////////////////////////////////
core_cm3.h
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address                  

stm32f10x_map.h

typedef struct
{
  vu32 Enable[2];
  u32 RESERVED0[30];
  vu32 Disable[2];
  u32 RSERVED1[30];
  vu32 Set[2];
  u32 RESERVED2[30];
  vu32 Clear[2];
  u32 RESERVED3[30];
  vu32 Active[2];
  u32 RESERVED4[62];
  vu32 Priority[11];
} NVIC_TypeDef;

#define NVIC                  ((NVIC_TypeDef *) NVIC_BASE)
*/