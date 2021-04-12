#include "FreeRTOS.h"
#include "task.h"
#include "stdbool.h"

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
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define PERIPH_BASE           ((u32)0x40000000)

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

/****************************************************************
//#include "rt_misc.h"    clib startup code
//#include "stm32f10x_it.h" 
there is no need to inclued this file. Add stm32f10x_it.c into project 
which includes stm32f10x_it.h will automaticlly include this file into the project.
*****************************************************************/

static TaskHandle_t AppTaskCreate_Handle = NULL;

static TaskHandle_t TestTask_Handle =NULL;

static TaskHandle_t TestTask1_Handle =NULL;

static void AppTaskCreate(void);

static void TestTask(void);

static void TestTask1(void);

bool i=1;
bool TaskCreateFLAG= 1;
bool Task1CreateFLAG = 1;


int main()
{	
UBaseType_t xReturn =pdPASS;
xReturn = xTaskCreate((TaskFunction_t) AppTaskCreate,
					  (const char *)		"AppTaskCreate",
					  (uint16_t) 				512,
					  (void *)					NULL,
					  (UBaseType_t) 		    1,
					  (TaskHandle_t *)& AppTaskCreate_Handle);
if (pdPASS == xReturn ) 
	vTaskStartScheduler();
else
	return -1;
}

static void AppTaskCreate(void)
{		
BaseType_t xReturn = pdPASS;
	
	taskENTER_CRITICAL();
	
	xReturn = xTaskCreate((TaskFunction_t) 	TestTask,
						  (const char *)		"TestTask",
						  (uint16_t )				512,
						  (void *)					NULL,
						  (UBaseType_t )		2,
						  (TaskHandle_t *)	& TestTask_Handle);
											
	xReturn = xTaskCreate((TaskFunction_t) 	TestTask1,
						  (const char *)		"TestTask1",
						  (uint16_t )				512,
						  (void *)					NULL,
						  (UBaseType_t )		3,
						  (TaskHandle_t *)	& TestTask1_Handle);
												
	if( pdPASS == xReturn )				
			vTaskDelete(AppTaskCreate_Handle);
	
	taskEXIT_CRITICAL();												
}

static void TestTask(void)
{
	while(1){
		TaskCreateFLAG = 1;
		vTaskDelay(3);
		TaskCreateFLAG =0 ;
		vTaskDelay(3);
	}
}

static void TestTask1(void)
{
	while(1){
		Task1CreateFLAG = 1;
		vTaskDelay(2);
		Task1CreateFLAG = 0;
		vTaskDelay(2);
	}
}
