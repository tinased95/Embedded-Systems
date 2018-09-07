#define DBG_MAIN_POS  1  //PORTB :PTB1
#define DBG_ISR_POS   0  //PORTB :PTB0

#define SW_POS		  6  //PORTD :PTD6

#define Red_LED_POS   1  //PORTA
#define Green_LED_POS 2  //PORTA
#define Blue_LED_POS  12 //PORTA

void init_switch(void);
void init_RGB_LEDs(void);
void control_RGB_LEDs(int R, int G, int B);
void init_debug_signals(void);

volatile unsigned count = 0;

void init_switch(void) {
	// enable clock for port D
	SIM->SCGC5 |=  SIM_SCGC5_PORTD_MASK; 

	//Select GPIO and enable pull-up resistors and 
	//interrupts on falling edges for pin	connected to switch
	PORTD->PCR[SW_POS] |= PORT_PCR_MUX(1) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_IRQC(0x0a);
	
	// Set port D switch bit to inputs
	PTD->PDDR &= ~MASK(SW_POS);
	
	// Enable Interrupts
	NVIC_SetPriority(PORTD_IRQn, 128);
	NVIC_ClearPendingIRQ(PORTD_IRQn); 
	NVIC_EnableIRQ(PORTD_IRQn);
}

void init_debug_signals(void){
	// enable clock for port B
	SIM->SCGC5 |=  SIM_SCGC5_PORTB_MASK;

	// Make 2 pins GPIO
	PORTB->PCR[DBG_ISR_POS]   &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DBG_ISR_POS]   |= PORT_PCR_MUX(1);          
	PORTB->PCR[DBG_MAIN_POS]  &= ~PORT_PCR_MUX_MASK;          
	PORTB->PCR[DBG_MAIN_POS]  |= PORT_PCR_MUX(1);

	// Set port B debugers bit to outputs
	PTB->PDDR |= MASK(Blue_LED_POS);
	PTB->PDDR |= MASK(Red_LED_POS);
	PTB->PDDR |= MASK(Green_LED_POS);
}

void init_RGB_LEDs(void){
	// enable clock for port A
	SIM->SCGC5 |=  SIM_SCGC5_PORTA_MASK; 

	// Set 3 pins GPIO
	PORTA->PCR[Red_LED_POS]   &= ~PORT_PCR_MUX_MASK;          
	PORTA->PCR[Red_LED_POS]   |= PORT_PCR_MUX(1);          
	PORTA->PCR[Green_LED_POS] &= ~PORT_PCR_MUX_MASK;          
	PORTA->PCR[Green_LED_POS] |= PORT_PCR_MUX(1);    
	PORTA->PCR[Blue_LED_POS]  &= ~PORT_PCR_MUX_MASK;          
	PORTA->PCR[Blue_LED_POS]  |= PORT_PCR_MUX(1);

	// Set port A LED bit to outputs
	PTA->PDDR |= MASK(Blue_LED_POS);
	PTA->PDDR |= MASK(Red_LED_POS);
	PTA->PDDR |= MASK(Green_LED_POS);
}

void control_RGB_LEDs(int R, int G, int B){
	PTA->PDOR = 0x00000000;
	if(R == 1){
		PTA->PDOR |= MASK(Red_LED_POS);
	}
	if(G == 2){
		PTA->PDOR |= MASK(Green_LED_POS);
	}
	if(B == 4){
		PTA->PDOR |= MASK(Blue_LED_POS);
	}
}

void PORTD_IRQHandler(void) {
	DEBUG_PORT->PSOR = MASK(DBG_ISR_POS);

	// clear pending interrupts
	NVIC_ClearPendingIRQ(PORTD_IRQn);

	if ((PORTD->ISFR & MASK(SW_POS))) {
		count++;
	}

	// clear status flags 
	PORTD->ISFR = 0xffffffff; //reset ISFR
	DEBUG_PORT->PCOR = MASK(DBG_ISR_POS);
}

int main (void) {
	init_switch();
	init_RGB_LEDs();
	init_debug_signals();
	__enable_irq();
	
	while (1) {
		DEBUG_PORT->PTOR = MASK(DBG_MAIN_POS);
		control_RGB_LEDs(count & 1, count & 2, count & 4);	
	}
}
