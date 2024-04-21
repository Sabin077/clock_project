#include<stdio.h>
#include<stdlib.h>
int main(){
        FILE *fp4;
        fp4 = fopen("alarm.txt","r");
        FILE *fp5;
        fp5 = fopen("temp.txt","w");
        
        // char ch;
        // while (1)
        // {
        //     ch=fgetc(fp4);
        //     if(ch==EOF){
        //         break;
        //     }
        //     fputc(ch,fp5);
        //      //printf("text copied successfully");
        // }
        // printf("text copied successly");
        int c;
        char reader[100];
        c=0;
        while(fscanf(fp4, "%s", reader)!=EOF){
                c++;
                if(c==2){continue;}
              fprintf(fp5,"%s\n",reader);
              }  
        printf("ok\n");


        fclose(fp4);
        fclose(fp5);
//

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