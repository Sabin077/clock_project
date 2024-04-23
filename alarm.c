#include <stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void add_alarm();
void close_alarm(int);
void check_alarm();
void snooze_alarm(int);
char real_time[100], alarm_time[100];
time_t current_time;  //time_t is a datatype which is used to store time related data
int count,flag;

int alarm() {
    int choice;
    char reader[100]; 
     while(1){
        here:

        //initialize count to 0
        count=0;
        system("clear");
        time(&current_time); //time() is a library function defined in time.h header file which is used here to get the current system time
        strftime(real_time, sizeof(real_time), "%H:%M", localtime(&current_time));//strftime() is a function which converts current time into string format
         printf("\n\n\n\n\n\n\n\n");
         printf("Time=%s\n",real_time);
         printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(6) Add Alarm\n");
         printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(7) Close Alarm\n\n\n");
         printf("\t\t\t\t\t\t\t\t\t ________________\n");
         printf("\t\t\t\t\t\t\t\t\t|                |\n"); 
        //to read the alarm time from the file and print in box
            FILE *fp1;
            fp1 = fopen("alarm.txt","r");
            
             while(fscanf(fp1, "%s", reader)!=EOF){ 
                count++; 

              printf("\t\t\t\t\t\t\t\t\t| %d)  %s      |\n",count, reader );  
              }  
    printf("\t\t\t\t\t\t\t\t\t|________________|\n"); 
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t (1)\t\t\t (2)\t\t\t (3)\t\t\t (4)\t\t\t (5)\n");
    printf("\t\t\t\t\tCLOCK\t\t\tALARM\t\t\tTIMER\t\t       CALANDER\t\t\t EXIT\n\n");

    flag=0;
    //to compare time with alarm time
    check_alarm();
    if(flag==1){
        goto here;
    }

    printf("\t\t\t\t\tEnter your choice \n");
    printf("\t\t\t\t\t");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
            return 1;
        case 2:
            continue;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            exit(0);
        case 6:
            add_alarm();
            goto here;
        case 7:
            /*to delete in a file we need to copy it to another file except the line we want to delete
            and again copy to our original file*/
            int alarm_no;
            printf("\t\t\t\t\tEnter Alarm No: ");
            scanf("%d",&alarm_no);
            close_alarm(alarm_no);
            continue;
        default:
            printf("\t\t\t\t\tInvalid choice\n");
            sleep(2);
            continue;
        }

    //sleep(10);
     }

}

void add_alarm(){
            printf("\t\t\t\t\tSet Alarm(HH:MM):");
            scanf("%s",alarm_time);
            //save time in file
            FILE *fp;
            fp = fopen("alarm.txt","a");
            fprintf(fp,"%s\n",alarm_time);
            fclose(fp);
}

void close_alarm(int alarm_no){
            int count;
            //to copy from alarm.txt to temp.txt
            FILE *fp4;
            fp4 = fopen("alarm.txt","r");
            FILE *fp5;
            fp5 = fopen("temp.txt","w");
            char reader[100];
            count=0;
            while(fscanf(fp4, "%s", reader)!=EOF){
                    count++;
                    if(count==alarm_no){continue;}
                  fprintf(fp5,"%s\n",reader);
                  }  
            fclose(fp4);
            fclose(fp5);

            //to copy from temp.txt to alarm.txt
            FILE *fp6;
            fp6 = fopen("alarm.txt","w");
            FILE *fp7;
            fp7 = fopen("temp.txt","r");
            while(fscanf(fp7, "%s", reader)!=EOF){
                  fprintf(fp6,"%s\n",reader);
                  }  
            fclose(fp6);
            fclose(fp7);
}

void check_alarm(){
    //24-hr format ma check garne alarm ko status
    FILE *fp_check;
    fp_check = fopen("alarm.txt","r");

    count=0;

    while(fscanf(fp_check, "%s", alarm_time)!=EOF){ 
        count++;
         if(strcmp(alarm_time, real_time)==0){ 
             //put beep sounnd here
            flag=1;
            for(int i=1;i<=3;i++){
                printf("\t\t\t\t\tAlarm is ringing\n");
                sleep(1);
            }

            char alarm_choice;
            printf("\t\t\t\t\tPress 's' to Snooze or 'c' to Close Alarm:");
            scanf("%s",&alarm_choice);

                if(alarm_choice=='c'|| alarm_choice=='C'){
                    close_alarm(count);
                    break;
                }
                else if(alarm_choice=='s'|| alarm_choice=='S'){
                    snooze_alarm(count);
                    break;
                }
         }  
              
    }
    fclose(fp_check);
}

void snooze_alarm(int count){
    time_t snooze_time=current_time+10*60;  //it will add 10 minutes to current time
    strftime(real_time, sizeof(real_time), "%H:%M", localtime(&snooze_time));
    //before adding snooze time we need to close the previous
    close_alarm(count);
    //to upadte snooze time as snooze time will be 10 minutes later
  
      FILE *fp_snooze;
            fp_snooze = fopen("alarm.txt","a");
            fprintf(fp_snooze,"%s\n",real_time);
            fclose(fp_snooze);
}