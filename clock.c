#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// #include "alarm.c"
// #include "timer.c"
char * getdate();
int clocks(){

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
    printf("\t\t\t\t\t\t\t\t\t|  %s   |\n",getdate()); 
    printf("\t\t\t\t\t\t\t\t\t|                |\n");
    printf("\t\t\t\t\t\t\t\t\t|________________|\n"); 
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t (1)\t\t\t (2)\t\t\t (3)\t\t\t (4)\n");
    printf("\t\t\t\t\tCLOCK\t\t\tALARM\t\t\tTIMER\t\t\tEXIT\n\n");
    printf("\t\t\t\t\tEnter your choice \n");
    printf("\t\t\t\t\t");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        continue;
    case 2:
       // pop();
       return 2;
    case 3:
         //timers();
         return 3;
    case 4:
        exit(0);
    default:
        printf("\t\t\t\t\tInvalid choice\n");
        sleep(2);
        continue;
    }
    //sleep(60);
     }

}
char * getdate()
{
    time_t t;

    static char * date_str; 
    static char * year;

    time(&t);
    date_str = ctime(&t) + 4;
    date_str[6] = 0;

    year = date_str + 15;
    year[5] = 0;

    strcat(date_str, year);

    return date_str;
}
