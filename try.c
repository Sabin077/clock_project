// #include <time.h>
// #include <stdio.h>
// 
// time_t current_time;
// time_t tenMinutesAgo;
// 
// int main() {
//   char* c_time_string;
//   current_time = time(NULL);
//   tenMinutesAgo = current_time + 10*60;//the time 10 minutes ago is 10*60
// 
//   c_time_string = ctime(&tenMinutesAgo);//convert the time tenMinutesAgo into a string format in the local time format
// 
//   printf("The time 10 minutes ago in seconds from the epoch is: %i\n", (int)tenMinutesAgo);
//   printf("The time 10 minutes ago from the epoch in the local time format is: %s\n", c_time_string);
// 
//   return 0;
// }
// 
// 


#include<stdio.h>
#include<time.h>
int main(){


    char real_time[100];
    time_t current_time;  //time_t is a datatype which is used to store time related data

        time(&current_time); //time() is a library function defined in time.h header file which is used here to get the current system time
        strftime(real_time, sizeof(real_time), "%H:%M", localtime(&current_time));
    printf("Current time : %s\n", real_time);
    
    time_t ten=current_time+10*60;
    strftime(real_time, sizeof(real_time), "%H:%M", localtime(&ten));
    printf("10 minutes from now : %s\n", real_time);




        return 0;
     }