#include <stdio.h>
#include<time.h>
#include<stdlib.h>


void start_timer();

int choice,total_time,minute,seconds;
int timer(){

    
    time_t current_time;  //time_t is a datatype which is used to store time related datas
     char real_time[100];
    while(1){
        system("clear");
        time(&current_time); //time() is a library function defined in time.h header file which is used here to get the current system time
        strftime(real_time, sizeof(real_time), "%H:%M", localtime(&current_time));//strftime() is a function which converts current time into string format
        printf("\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(6) Start Timer\n\n\n\n");
        printf("\t\t\t\t\t\t_________  _________                   _________   ___\n");
        printf("\t\t\t\t\t\t    |          |      |\\          /|  |           |   \\\n");
        printf("\t\t\t\t\t\t    |          |      | \\        / |  |           |   |\n");
        printf("\t\t\t\t\t\t    |          |      |  \\      /  |  |________   |___/\n");
        printf("\t\t\t\t\t\t    |          |      |   \\    /   |  |           |\\\n");
        printf("\t\t\t\t\t\t    |          |      |    \\  /    |  |           | \\\n");
        printf("\t\t\t\t\t\t    |      ____|____  |     \\/     |  |_________  |  \\\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t (1)\t\t\t (2)\t\t\t (3)\t\t\t (4)\t\t\t (5)\n");
        printf("\t\t\t\t\tCLOCK\t\t\tALARM\t\t\tTIMER\t\t       CALANDER\t\t\t EXIT\n\n");
        printf("\t\t\t\t\tEnter your choice \n");
        printf("\t\t\t\t\t");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                return 1;
            case 2:
                return 2;
            case 3:
                continue;
            case 4:
                return 4;
            case 5:
                exit(0);
            case 6:
                 start_timer();
                 continue;
            default:
                printf("\t\t\t\t\tInvalid choice\n");
                sleep(2);
                continue;
        }
        //sleep(60);
         }
}   
//this function is called in case 5
void     start_timer(){
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
}