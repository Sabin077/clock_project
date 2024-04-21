#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include "alarm.c"

int main() {

    int choice;
    time_t current_time;  //time_t is a datatype which is used to store time related datas
     char real_time[100];
    while(1){
        system("clear");
        time(&current_time); //time() is a library function defined in time.h header file which is used here to get the current system time
        strftime(real_time, sizeof(real_time), "%H:%M", localtime(&current_time));//strftime() is a function which converts current time into string format
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t ________________\n");
    printf("\t\t\t\t\t\t\t\t\t|                |\n");  
    printf("\t\t\t\t\t\t\t\t\t|                |\n");
    printf("\t\t\t\t\t\t\t\t\t|     %s      |\n",real_time); 
    printf("\t\t\t\t\t\t\t\t\t|                |\n"); 
    printf("\t\t\t\t\t\t\t\t\t|________________|\n"); 
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t (1)\t\t\t (2)\t\t\t (3)\t\t\t (4)\n");
    printf("\t\t\t\t\tCLOCK\t\t\tALARM\t\t\tTIMER\t\t\tEXIT\n");
    printf("\t\t\t\t\tEnter your choice \n");
    printf("\t\t\t\t\t");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        continue;
        break;
    case 2:
    //alarm();
        break;
    case 3:
        break;
    case 4:
        exit(0);
        break;
    
    default:
        printf("\t\t\t\t\tInvalid choice\n");
        sleep(2);
        continue;
        break;
    }
    sleep(60);
     }
return 0;
}
