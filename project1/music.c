#include "mbed.h"
#include "time.h"


PwmOut buzzer(PTD2);
 
int main(){
    wait(0.6);
    
	//E4
    buzzer.period(1.0/329.63); 
    buzzer =0.5;
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
    
	//D4#    
    buzzer.period(1.0/311.13);
    buzzer =0.5; 
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
     
	//E4
    buzzer.period(1.0/329.63); 
    buzzer =0.5;
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
    
	//D4#
    buzzer.period(1.0/311.13); 
    buzzer =0.5;    
    wait(0.35);
    buzzer=0.0;
    wait(0.1);

	//E4
    buzzer.period(1.0/329.63); 
    buzzer =0.5;     
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
      
	//B3
    buzzer.period(1.0/246.94); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//D4
    buzzer.period(1.0/293.66); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//C4
    buzzer.period(1.0/261.63); 
    buzzer =0.5;  
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
     
	//A3
    buzzer.period(1.0/220.0); 
    buzzer =0.5;
    wait(1);
    buzzer=0.0;
    wait(0.1);
	
    //D3
    buzzer.period(1.0/146.83); 
    buzzer =0.5;
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
    
	//F3    
    buzzer.period(1.0/174.61); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
    
	//A3	
    buzzer.period(1.0/220.0); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
    
	//D3
    buzzer.period(1.0/256.94); 
    buzzer =0.5;    
    wait(1);
    buzzer=0.0;
    wait(0.1);

	//F3
    buzzer.period(1.0/174.61); 
    buzzer =0.5;     
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
     
	//a3#
    buzzer.period(1.0/233.08); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//b3
    buzzer.period(1.0/246.94); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//C4
    buzzer.period(1.0/261.63); 
    buzzer =0.5;  
    wait(1);
    buzzer=0.0;
    wait(0.1);
    
	//E4
    buzzer.period(1.0/329.63); 
    buzzer =0.5;
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
    
	//D4#    
    buzzer.period(1.0/311.13); 
    buzzer =0.5; 
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
    
	//E4	
    buzzer.period(1.0/329.63); 
    buzzer =0.5;
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
    
	//D4#
    buzzer.period(1.0/311.13); 
    buzzer =0.5;    
    wait(0.35);
    buzzer=0.0;
    wait(0.1);

	//E4
    buzzer.period(1.0/329.63); 
    buzzer =0.5;     
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
    
	//B3	
    buzzer.period(1.0/246.94); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//D4
    buzzer.period(1.0/293.66); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//C4
    buzzer.period(1.0/261.63); 
    buzzer =0.5;  
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
     
	//A3
    buzzer.period(1.0/220.0); 
    buzzer =0.5;
    wait(1);
    buzzer=0.0;
    wait(0.1);
    
	//D3
    buzzer.period(1.0/146.83); 
    buzzer =0.5;
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
        
	//F3
    buzzer.period(1.0/174.61); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
     
	//A3
    buzzer.period(1.0/220.0); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
    
	//B3
    buzzer.period(1.0/246.94); 
    buzzer =0.5;
    wait(1);
    buzzer=0.0;
    wait(0.1);
        
	//F3
    buzzer.period(1.0/174.61); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
     
	//C4
    buzzer.period(1.0/261.63); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
    
	//B3
    buzzer.period(1.0/246.94); 
    buzzer =0.5;    
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//A3
    buzzer.period(1.0/220); 
    buzzer =0.5;     
    wait(1);
    buzzer=0.0;
    wait(0.1);

	//B3
    buzzer.period(1.0/246.94); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//C4
    buzzer.period(1.0/261.63); 
    buzzer =0.5;  
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
                            
	//D4
    buzzer.period(1.0/293.66); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
    
	//E4
    buzzer.period(1.0/329.63); 
    buzzer =0.5;
    wait(1);
    buzzer=0.0;
    wait(0.1);
        
	//G3
    buzzer.period(1.0/196.0); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
     
	//F4
    buzzer.period(1.0/349.23); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
    
	//E4
    buzzer.period(1.0/329.23); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
    
	//D4
    buzzer.period(1.0/293.63); 
    buzzer =0.5;
    wait(1);
    buzzer=0.0;
    wait(0.1);
    
	//E3
    buzzer.period(1.0/164.81); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
        
	//E4
    buzzer.period(1.0/329.63); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
     
	//D4
    buzzer.period(1.0/293.63); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
    
	//C4
    buzzer.period(1.0/261.63); 
    buzzer =0.5; 
    wait(1);
    buzzer=0.0;
    wait(0.1);
    
	//D3
    buzzer.period(1.0/146.83); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
    
	//D4
    buzzer.period(1.0/293.63); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
        
	//C4
    buzzer.period(1.0/261.63); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
     
	//B3
    buzzer.period(1.0/246.94); 
    buzzer =0.5;
    wait(1.4);
    buzzer=0.0;
    wait(0.1);
    
	//E4
    buzzer.period(1.0/329.23); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
    
	//D4#
    buzzer.period(1.0/311.13); 
    buzzer =0.5; 
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
     
	//E4
    buzzer.period(1.0/329.63); 
    buzzer =0.5;
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
    
	//D4#
    buzzer.period(1.0/311.13); 
    buzzer =0.5;    
    wait(0.35);
    buzzer=0.0;
    wait(0.1);

	//E4
    buzzer.period(1.0/329.63); 
    buzzer =0.5;     
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
    
	//B3
    buzzer.period(1.0/246.94); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//D4
    buzzer.period(1.0/293.66); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//C4
    buzzer.period(1.0/261.63); 
    buzzer =0.5;  
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
                            
	//A3
    buzzer.period(1.0/220.0); 
    buzzer =0.5;
    wait(1);
    buzzer=0.0;
    wait(0.1);
    
	//D3
    buzzer.period(1.0/146.83); 
    buzzer =0.5;
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
    
	//F3
    buzzer.period(1.0/174.61); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
     
	//A3
    buzzer.period(1.0/220.0); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
    buzzer.period(1.0/246.94); //b3
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//C4
    buzzer.period(1.0/261.63); 
    buzzer =0.5;  
    wait(1);
    buzzer=0.0;
    wait(0.1);
    
	//E4
    buzzer.period(1.0/329.63); 
    buzzer =0.5;
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
        
	//D4#
    buzzer.period(1.0/311.13); 
    buzzer =0.5; 
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
     
	//E4
    buzzer.period(1.0/329.63); 
    buzzer =0.5;
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
    
	//D4#
    buzzer.period(1.0/311.13); 
    buzzer =0.5;    
    wait(0.35);
    buzzer=0.0;
    wait(0.1);

	//E4
    buzzer.period(1.0/329.63); 
    buzzer =0.5;     
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
    
	//B3
    buzzer.period(1.0/246.94); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//D4
    buzzer.period(1.0/293.66); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//C4
    buzzer.period(1.0/261.63); 
    buzzer =0.5;  
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
                      
	//A3
    buzzer.period(1.0/220.0); 
    buzzer =0.5;
    wait(1);
    buzzer=0.0;
    wait(0.1);
    
	//D3
    buzzer.period(1.0/146.83); 
    buzzer =0.5;
    wait(0.35);
    buzzer=0.0;
    wait(0.1);
        
	//F3
    buzzer.period(1.0/174.61); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
     
	//A3
    buzzer.period(1.0/220.0); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
    
	//B3
    buzzer.period(1.0/246.94); 
    buzzer =0.5;
    wait(1);
    buzzer=0.0;
    wait(0.1);
        
	//F3
    buzzer.period(1.0/174.61); 
    buzzer =0.5; 
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
     
	//C4
    buzzer.period(1.0/261.63); 
    buzzer =0.5;
    wait(0.4);
    buzzer=0.0;
    wait(0.1);
    
	//B3
    buzzer.period(1.0/246.94); 
    buzzer =0.5;    
    wait(0.4);
    buzzer=0.0;
    wait(0.1);

	//A3
    buzzer.period(1.0/220); 
    buzzer =0.5;     
    wait(1);
    buzzer=0.0;
    wait(0.1);
    
    
}