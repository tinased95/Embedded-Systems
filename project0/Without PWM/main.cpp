#include "mbed.h"

DigitalOut LedOut(PTD2);
DigitalIn SwitchIn(PTE4);

int period=100;
int on_time=0;
int count=0;
int LedState;

int new_in;
int old_in=1;

int main(){
    while(1){
        new_in = SwitchIn;
        if(count <= on_time){
            count++;
            LedState=1;
            }
        else if(count> on_time && count <= period){
            count ++;
            LedState=0;
            }
        else if( count >period){   
                count=0;
        }
                
        if(new_in==1 && old_in == 0 ) {
            on_time+=20;
        }
        if(on_time > 100){
            on_time=0;
        }
        LedOut=LedState;
        old_in=new_in;
    }
}