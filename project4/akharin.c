#include "MKL25Z4.h"                  
const uint32_t led_mask[] = {1UL<< 7, 1UL <<0, 1UL<< 3 , 1UL<< 4, 1UL <<5, 1UL << 6 , 1UL << 10 , 1UL << 11 ,1UL << 12 ,1UL<<0 };

#define goN   0
#define waitN 1
#define goE   2
#define waitE 3
#define goNW    4
#define waitNW  5
//#define emg     6


struct State {
  uint32_t Out; 
  uint32_t Time;  // 1 ms units
  uint32_t Next[6]; // list of next states
}; 
typedef const struct State STyp;

STyp FSM[6] = {
 {0x418,3000,{waitN,waitN}}, 
 {0x411, 500,{goE,goE}},
 {0x4C0,3000,{waitE,waitE}},
 {0x4A0,500,{goNW,goNW}},
 {0x1090,3000,{waitNW,waitNW}},
 {0x890,500,{goN,goN}}
};

void delay(unsigned int length_ms)
{
    SIM_SCGC5 |= SIM_SCGC5_LPTMR_MASK;  // Make sure clock is enabled
    LPTMR0_CSR = 0;                     // Reset LPTMR settings         
    LPTMR0_CMR = length_ms;             // Set compare value (in ms)

  // Use 1kHz LPO with no prescaler
    LPTMR0_PSR = LPTMR_PSR_PCS(1) | LPTMR_PSR_PBYP_MASK;
    
    // Start the timer and wait for it to reach the compare value
    LPTMR0_CSR = LPTMR_CSR_TEN_MASK;
    while (!(LPTMR0_CSR & LPTMR_CSR_TCF_MASK))
        ;
    
    LPTMR0_CSR = 0;                     // Turn off timer
}

/*----------------------------------------------------------------------------
  Function that initializes LEDs
 *----------------------------------------------------------------------------*/
void initialize(void) {

  SIM->SCGC5    |= (1UL<<12 | 1UL<<11 | 1UL <<  10) | (1UL <<  9);      /* Enable Clock to Port D & C & B & A */ 
  
  PORTC->PCR[7] = (1UL <<  8);                     /* Pin PTC ha are GPIO */
  PORTC->PCR[0] = (1UL <<  8);                      
  PORTC->PCR[3]  = (1UL <<  8);                     
  PORTC->PCR[4] = (1UL <<  8);                    
  PORTC->PCR[5] = (1UL <<  8);                      
  PORTC->PCR[6]  = (1UL <<  8);                     
	PORTC->PCR[10] = (1UL <<  8);                      
  PORTC->PCR[11] = (1UL <<  8);                      
  PORTC->PCR[12]  = (1UL <<  8); 
  

  FPTC->PDOR &= (led_mask[0] | led_mask[1] | led_mask[2] |led_mask[3] | led_mask[4] | led_mask[5] | led_mask[6]| led_mask[7]| led_mask[8] );          /* switch Red/Green LED off  */
  FPTC->PDDR = (led_mask[0] | led_mask[1] | led_mask[2] |led_mask[3] | led_mask[4] | led_mask[5]  | led_mask[6]| led_mask[7]| led_mask[8] );          /* enable PTB10/9/8/2/1/0 as Output */

		//set pinD0 to GPIO(MUX=001 IN PCREG),IRQC(19:16)=1010I=>Interrupt on falling edge, PE=1 &PS=0 
		PORTD -> PCR[0] |= 0xA0102;
		//input
	PTD ->PDDR |= (0<<0); 
	PTD -> PDOR |= (0<<0);
	
	PORTD_ISFR = PORT_ISFR_ISF(0x01);
	NVIC_SetPriority(PORTD_IRQn,128);
	NVIC_EnableIRQ(PORTD_IRQn);
}

void PORTD_IRQHandler(void)
{
	FPTC->PCOR   = led_mask[2];   /* Red LED On*/
  FPTC->PCOR   = led_mask[1];   /* Yellow LED Off*/
  FPTC->PSOR   = led_mask[0];   /* Green LED Off*/

  
  FPTC->PCOR   = led_mask[5];   /* Red LED On*/
  FPTC->PCOR   = led_mask[4];   /* Yellow LED Off*/
  FPTC->PSOR   = led_mask[3];   /* Green LED Off*/ 
	
	FPTC->PCOR   = led_mask[8];   /* Red LED On*/
  FPTC->PCOR   = led_mask[7];   /* Yellow LED Off*/
  FPTC->PSOR   = led_mask[6];   /* Green LED Off*/

	PORTD_ISFR = PORT_ISFR_ISF(0x01);
}

volatile uint32_t msTicks;                            /* counts 1ms timeTicks */
/*----------------------------------------------------------------------------
  SysTick_Handler
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void) {
  msTicks++;                        /* increment counter necessary in Delay() */
}

/*------------------------------------------------------------------------------
  delays number of tick Systicks (happens every 1 ms)
 *------------------------------------------------------------------------------*/
__INLINE static void Delay (uint32_t dlyTicks) {
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks);
}



/*----------------------------------------------------------------------------
 *      Main: Initialize
 *---------------------------------------------------------------------------*/
int main (void) {
	SystemCoreClockUpdate();
  initialize();           // initialize clocks, ports and timer
  SysTick_Config(10000);      /* Turn the SysTick timer on  */
  int CS;  // index of current state
  uint32_t Input=0; 
  
  
  CS = goN; // start state
  while(1) {
		
    PTC->PDOR= FSM[CS].Out;  // set l8ights
    delay(FSM[CS].Time);
		//Input++;
   // Input =(PTA->PDIR & 0x06) >> 1;  // read sensors
    CS = FSM[CS].Next[Input];  
  }
  
 /* while(1){
      if(PTA->PDIR & led_mask[7]){
        //PTA1 nayoomade
      }
      else{ //PTA1 oomade
  north_LEDRed_On();      //Red LED on
    Delay(0x500);
  north_LEDYellow_On();      //Yellow LED on
    Delay(0x500);
  north_LEDGreen_On();      //Green LED on
    Delay(0x500);
  LED_Off();      //all LEDs OFF
    Delay(0x500);
        
    west_LEDRed_On();      //Red LED on
    Delay(0x500);
  west_LEDYellow_On();      //Yellow LED on
    Delay(0x500);
  west_LEDGreen_On();      //Green LED on
    Delay(0x500);
  LED_Off();      //all LEDs OFF
    Delay(0x500);
      }
    
  }*/
}