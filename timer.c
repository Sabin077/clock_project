#include <stdio.h>
#include<time.h>
#include<stdlib.h>
int main() {
    // int hour,minute,seconds;
    
    // printf("Hours: ");
    // scanf("%d", &hour);
    // printf("Minutes: ");
    // scanf("%d", &minute);
    // printf("Seconds: ");
    // scanf("%d", &seconds);

    // seconds=hour*3600+minute*60+seconds;
    
    // while (seconds > 0) {
    //     printf("%d...\n", seconds);
    //     sleep(1);
    //     seconds--;
    // }

    // printf("Time's up!");
    int choice,total_time,minute,seconds;
    time_t current_time;  //time_t is a datatype which is used to store time related datas
     char real_time[100];
    while(1){
        system("clear");
        time(&current_time); //time() is a library function defined in time.h header file which is used here to get the current system time
        strftime(real_time, sizeof(real_time), "%H:%M", localtime(&current_time));//strftime() is a function which converts current time into string format
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(5) Start Timer\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t ________________\n");
    printf("\t\t\t\t\t\t\t\t\t|                |\n");  
    printf("\t\t\t\t\t\t\t\t\t|                |\n");
    printf("\t\t\t\t\t\t\t\t\t|                |\n"); 
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
        
    case 5:
        
        printf("\t\t\t\t\tMinutes: ");
        scanf("%d", &minute);
        printf("\t\t\t\t\tSeconds: ");
        scanf("%d", &seconds);

         total_time=minute*60+seconds;
         while (total_time >0) {

            printf("\r");  // move cursor to position 0
            printf("\t\t\t\t\t%d Minutes %d Seconds", minute, seconds);
            fflush(stdout);  // flush the output of stdout
            

            sleep(1);
            seconds--;
            total_time--;
            if (seconds == 0) {
                minute--;
                seconds = 59;
            }
         }

        printf("\n\t\t\t\t\tTime Over!!\n");
        sleep(4);
         continue;
    
    default:
        printf("\t\t\t\t\tInvalid choice\n");
        sleep(2);
        continue;
    }
    //sleep(60);
     }

    return 0;
}
