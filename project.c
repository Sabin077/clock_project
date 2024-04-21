#include <stdio.h>
#include <stdlib.h>
#include "welcome.c"
#include "clock.c"
#include "timer.c"
#include "alarm.c"

int main() {
    system("clear");
    welcome();
    int a;
    a=clocks();


    while(1){
        if(a==1)
            a=clocks();
        
        else if(a==2)
            a=alarm();
        
        else if(a==3)
            a=timer();

        else
            break;


    }


    return 0;
}