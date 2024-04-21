#include <stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int count;
int main() {
    int choice;
    char reader[100]; 
    time_t current_time;  //time_t is a datatype which is used to store time related datas
     char real_time[100], alarm_time[100];
     while(1){
        here:

        //initialize count to 0
        count=0;
        system("clear");
        time(&current_time); //time() is a library function defined in time.h header file which is used here to get the current system time
        strftime(real_time, sizeof(real_time), "%H:%M", localtime(&current_time));//strftime() is a function which converts current time into string format
    printf("\n\n\n\n\n\n\n\n");
    printf("Time=%s\n",real_time);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(5) Add Alarm\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(6) Close Alarm\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t ________________\n");
    printf("\t\t\t\t\t\t\t\t\t|                |\n");  
            FILE *fp1;
            fp1 = fopen("alarm.txt","r");
            
             while(fscanf(fp1, "%s", reader)!=EOF){ 
                count++; 

              printf("\t\t\t\t\t\t\t\t\t| %d)  %s      |\n",count, reader );  
              }  
    printf("\t\t\t\t\t\t\t\t\t|________________|\n"); 
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t (1)\t\t\t (2)\t\t\t (3)\t\t\t (4)\n");
    printf("\t\t\t\t\tCLOCK\t\t\tALARM\t\t\tTIMER\t\t\tEXIT\n");


      //24-hr format ma check garne alarm ko status
    FILE *fp2;
            fp2 = fopen("alarm.txt","r");
            
             while(fscanf(fp2, "%s", alarm_time)!=EOF){ 

                     if(strcmp(alarm_time, real_time)==0){ 
                        //put beep sounnd here
                        
                        for(int i=1;i<=3;i++){
                            printf("\t\t\t\t\tAlarm is ringing\n");
                            sleep(1);
                        }
                        char stop;
                        printf("\t\t\t\t\tPress 's' to stop:");
                        scanf("%s",&stop);
                        while (1)
                        {
                            if(stop=='s'|| stop=='S'){
                                break;
                            }
                            printf("Alarm is ringing");
                        }
                      }  
              
              }

    printf("\t\t\t\t\tEnter your choice \n");
    printf("\t\t\t\t\t");
    scanf("%d",&choice);



  
   
    


    switch (choice)
    {
        case 1:
            continue;
            
        case 2:
            continue;
            
        case 3:
            continue;;
        case 4:
            exit(0);
            
        case 5:
            printf("\t\t\t\t\tSet Alarm(HH:MM):");
            scanf("%s",alarm_time);
            //save time in file
            FILE *fp;
            fp = fopen("alarm.txt","a");
            fprintf(fp,"%s\n",alarm_time);
            fclose(fp);
            goto here;
            
        case 6:
            /*to delete in a file we need to copy it to another file except the line we want to delete
            and again copy to our original file*/
            int alarm_no,count;
            printf("\t\t\t\t\tEnter Alarm No: ");
            scanf("%d",&alarm_no);
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
            continue;
        
        default:
            printf("\t\t\t\t\tInvalid choice\n");
            sleep(2);
            continue;
        }

    //sleep(10);
     }
    
    

return 0;
}
