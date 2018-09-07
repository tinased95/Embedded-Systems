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

int count1=0;
int count2=0;
int count3=0;
int count4=0;


void scheduler();

//task1
void task1(){ //LED red blinking at 0.25Hz
        red1=1;
        wait(2);
        red1=0;
        wait(2);
       // scheduler(); 
}
//task2
void task2(){//LED green blinking at 0.25 Hz
        green1=1;
        wait(2);
        green1=0;
        wait(2); 
        //scheduler();
}
//task3
void RTC_Seconds_IRQHandler(){//LED red and LED green light up alternatively at 0.25 Hz
    flag_task3=1;
    scheduler();
}
//task4
void  MCG_IRQHandler(){//LED red and LED green blinking simultaneously at 0.25 Hz
    if(flag_task3==1)
    flag_task3=0;
    
    flag_task4=1;  
    scheduler();
}
void init_switch(){
    __enable_irq();
    
    switch1.mode(PullUp);            // Enable internal pullup
    switch1.fall(&RTC_Seconds_IRQHandler);
    
    switch2.mode(PullUp);            // Enable internal pullup
    switch2.fall(&MCG_IRQHandler); 
}

void scheduler(){
    if(flag_task4==1){
        red3=1;
        green3=1;
        wait(2);
        red3=0;
        green3=0;
        wait(2);
        count1++;
        green3=0;
        red3=0;
            if(count1==2 | flag_task3==1){
                flag_task4=0; 
                count1=0;
                }     
    }
    else if(flag_task3==1 ){
        red2=1;
        green2=0;
        wait(2);
        red2=0;
        green2=1;
        wait(2); 
        count2++;
        green2=0;
        red2=0;
            if(count2==2 | flag_task4==1){
                flag_task3=0; 
                count2=0;
                }
        }
    else if(flag_task4==0&& flag_task3==0 && flag_task2==1 && flag_task1==1){
        //wait(0.5);
       // if(flag_task4==0 && flag_task3==0){
        task1();
        task2();
       // }
        }
    }
int main(){
    init_switch();   
    while (true) {
         scheduler(); 
        }
}