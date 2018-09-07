#include "mbed.h"
#include "rtos.h"

float timer1=0;
float timer4=0;

int new_in;
int old_in=1;

int new_in2;
int old_in2=1;

int count=0;

Thread t1;
Thread t2;
Thread t3;
Thread t4;
Thread t5;

DigitalIn SW1(PTD1);
DigitalIn SW2(PTD2); 

AnalogIn T1(PTB2); //  temperature  sensor T1 on A0
float T; // average temperature
float K=3.3*100; // scaling coefficient for calculating 
int temps[32];
int index=0;
int test=0;
float average=0.0;

void updateTime();
void updateAndDisplayTime();
void readTemperature();
void getAverage();

void updateTime() { //task1
    timer1+=0.1;
    count++;
    //printf("timer: %f \n",timer1);  updating but not showing
    if(count%10==0){   
        t4.start(updateAndDisplayTime);
        }  
        if(count%50==0){
            t2.start(readTemperature);
            }
}
 void updateAndDisplayTime(){ //task4
    timer4+=1;
    printf("timer: %f \n",timer4);



    new_in = SW1;
    if(new_in==1 && old_in == 0 ){
        printf("Temperature (in Celsius) is %4.2f \r\n",T);
        printf("associated time is %4.2f \r\n", timer4);
        }
    old_in=new_in;
    
    new_in2 = SW2;
    if(new_in2==1 && old_in2 == 0 ){
        printf("Average Temperature (in Celsius) is %4.2f \r\n",average);
        
        }
    old_in2=new_in2;
    
}
void readTemperature(){ //task2
        T=T1*K; 
        temps[index]=T;
        
        if(index==32){
        index=0;
        test=1;
        }
        //printf("Temperature (in Celsius) is %4.2f \r\n",T); 
        t3.start(getAverage);
        index++;
}
void getAverage(){//task3
    for(int i=0;i<32;i++){
        average+=temps[i];
        }
        if (test==0){
            average/=index;
        }
        else if (test ==1){
            average/=32;
        }
        //printf("average: %4.2f \n",average);
    }
 


int main(void) {
    RtosTimer t1(updateTime);
    
    t1.start(100);
    
    Thread::wait(osWaitForever);
}