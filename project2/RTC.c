#include "mbed.h"
DigitalOut red1(PTB10);
DigitalOut green1(PTB11);

DigitalOut red2(PTE2);
DigitalOut green2(PTE3);

DigitalOut red3(PTE4);
DigitalOut green3(PTE5);



InterruptIn switch1(PTD1);
InterruptIn switch2(PTD2); 

int flag_task1=1;
int flag_task2=1;
int flag_task3=0;
int flag_task4=0;


//task1
void task1(){ //LED red blinking at 0.25Hz
        red1=1;
        wait(2);
        red1=0;
        wait(2); 
}
//task2
void task2(){//LED green blinking at 0.25 Hz
        green1=1;
        wait(2);
        green1=0;
        wait(2); 
}
//task3
void RTC_Seconds_IRQHandler(){//LED red and LED green light up alternatively at 0.25 Hz
    flag_task3=1;
}
//task4
void  MCG_IRQHandler(){//LED red and LED green blinking simultaneously at 0.25 Hz
    flag_task4=1;  
}
void init_switch(){
    __enable_irq();
    
    switch1.mode(PullUp);            // Enable internal pullup
    switch1.fall(&RTC_Seconds_IRQHandler);
    
    switch2.mode(PullUp);            // Enable internal pullup
    switch2.fall(&MCG_IRQHandler); 
}

void schedular(){
    if(flag_task4==1){
        for(int count=1;count<=2;count++){
        red3=1;
        green3=1;
        wait(2);
        red3=0;
        green3=0;
        wait(2);
        }
        green3=0;
        red3=0;
        flag_task4=0;      
    }
    else if(flag_task3==1 && flag_task4==0){
        for(int count=1;count<=2;count++){
        red2=1;
        green2=0;
        wait(2);
        red2=0;
        green2=1;
        wait(2); 
        }
        green2=0;
        red2=0;
        flag_task3=0;
        }
    else if(flag_task4==0&& flag_task3==0 && flag_task2==1 && flag_task1==1){
        task1();
        task2();
        }
    }
int main(){
    init_switch();   
    while (true) {
         schedular(); 
        }
}