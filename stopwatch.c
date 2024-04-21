#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include<unistd.h>


int main()
{
    
    int m=0,s=0;
    char ch;
    printf("enter 's' to start: ");
    scanf(" %c",&ch);
    if(ch=='s'){
            while (1)
            {
                sleep(1);
                s++;
                if(s==60){
                    s=0;
                    m++;
                }
                printf("\r%d:%d",m,s); // \r is used to move the cursor to the beginning of the line
                fflush(stdout);         // fflush is used to clear the buffer
               // ch=getchar();
               //scanf("%c",&ch);
                if(ch=='c'){
                    break;
                }
                // else if(ch=='r'){
                //     m=0;
                //     s=0;
                // }
                
            }
            
    }
}