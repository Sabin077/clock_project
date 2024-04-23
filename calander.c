#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int month,year,daycode;
//two arrays are made to store months name and no of days in month
//first element is made empty so it will be easy to access as 1 for january and so on
int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{   "",
	"\n\n\n\t\t\t\t\t\t\t\t\tJanuary",
	"\n\n\n\t\t\t\t\t\t\t\t\tFebruary",
	"\n\n\n\t\t\t\t\t\t\t\t\tMarch",
	"\n\n\n\t\t\t\t\t\t\t\t\tApril",
	"\n\n\n\t\t\t\t\t\t\t\t\tMay",
	"\n\n\n\t\t\t\t\t\t\t\t\tJune",
	"\n\n\n\t\t\t\t\t\t\t\t\tJuly",
	"\n\n\n\t\t\t\t\t\t\t\t\tAugust",
	"\n\n\n\t\t\t\t\t\t\t\t\tSeptember",
	"\n\n\n\t\t\t\t\t\t\t\t\tOctober",
	"\n\n\n\t\t\t\t\t\t\t\t\tNovember",
	"\n\n\n\t\t\t\t\t\t\t\t\tDecember"
};

//protypes
int inputyear();
int inputmonth();
void addevent();
int determinedaycode();
int checkleapyear();
void calendar();
void showevent();
void removeevent(int);
void bstoad(int,int,int);
void adtobs(int,int,int);

int choice;

int calander()
{	while(1){
        system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(6) Open Calander\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(7) Mark Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(8) Show Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(9) Remove Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(10) BS to AD\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(11) AD to BS\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t (1)\t\t\t (2)\t\t\t (3)\t\t\t (4)\t\t\t (5)\n");
        printf("\t\t\t\t\tCLOCK\t\t\tALARM\t\t\tTIMER\t\t       CALANDER\t\t\t EXIT\n\n");
        printf("\t\t\t\t\tEnter your choice \n");
        printf("\t\t\t\t\t");
        scanf("%d",&choice);
        here:
        switch (choice)
        {
            case 1:
                return 1;
            case 2:
               return 2;
            case 3:
                 return 3;
            case 4:
                continue;
            case 5:
                exit(0);
            case 6:
                year=inputyear();
                month=inputmonth();
	            daycode=determinedaycode();
	            checkleapyear();
	            calendar();
	            goto here;
            case 7:
                addevent();
                break;
            case 8:
                showevent();
                goto here;
            case 9:
                int event_no;
                printf("\t\t\t\t\tEnter event number:");
                scanf("%d",&event_no);
                removeevent(event_no);
                showevent();
                goto here;
            case 10:
                int bs_y,bs_m,bs_d;
                printf("\t\t\t\t\tEnter date in BS\n");
                printf("\t\t\t\t\tYear:");
                scanf("%d",&bs_y);
                printf("\t\t\t\t\tMonth:");
                scanf("%d",&bs_m);
                printf("\t\t\t\t\tDay:");
                scanf("%d",&bs_d);
                bstoad(bs_y,bs_m,bs_d);
                goto here;
            case 11:
                int ad_y,ad_m,ad_d;
                printf("\t\t\t\t\tEnter date in AD\n");
                printf("\t\t\t\t\tYear:");
                scanf("%d",&ad_y);
                printf("\t\t\t\t\tMonth:");
                scanf("%d",&ad_m);
                printf("\t\t\t\t\tDay:");
                scanf("%d",&ad_d);
                adtobs(ad_y,ad_m,ad_d);
                goto here;
            default:
                printf("\t\t\t\t\tInvalid choice\n");
                sleep(2);
                continue;
            }
        //sleep(60);
     }
}

int inputyear()
{
	int year;
	printf("\t\t\t\t\tEnter the year: ");
	scanf("%d",&year);
	return year;
}
int inputmonth()
{
	int month;
	printf("\t\t\t\t\tEnter the month: ");
	scanf("%d",&month);
	return month;
}

int determinedaycode()// to get the day number of the first day of that year,
{
	int daycode;
	int d1,d2,d3;
	
	d1=(year-1.)/4.0;  //yo number of century ho
	d2=(year-1.)/100.; //yo number of year with in the century
	d3=(year-1.)/400.;// yo no of year with in last century
	daycode=(year+d1-d2+d3)%7; //formula ho yo chai
	return daycode;
}

int checkleapyear()
{
	if(year%4==0 && year%100!= 0 || year%400==0)
	{
		days_in_month[2]=29;
	}
	else
	{
		days_in_month[2]=28;
	}
}

void calendar()
{
	int day;
        system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(6) Open Calander\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(7) Mark Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(8) Show Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(9) Remove Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(10) BS to AD\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(11) AD to BS\n");

        // for (month=0;month<12;month++)
		printf("\t\t\t\t\t\t\t\t\t%s",months[month]);
		printf("\n\n\t\t\t\t\t\t\t\t\tSun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		
        printf("\t\t\t\t\t\t\t\t\t");
		// Correct the position for the first date
		for (day=1;day<(1+daycode*5);day++)
		{
			printf(" ");
		}
		
		// Print all the dates for one month
		for (day=1;day<=days_in_month[month];day++)
		{
			printf("%2d",day);
			
			//Is day before Sat? Else start next line Sun.
			if ((day+daycode)%7>0)
				printf("   " );
			else
				printf("\n\t\t\t\t\t\t\t\t\t");
		}
        // printf("\t\t\t\t\t\t\t\t\t ________________\n");
        // printf("\t\t\t\t\t\t\t\t\t|                |\n");  
        // printf("\t\t\t\t\t\t\t\t\t|                |\n");
        // // printf("\t\t\t\t\t\t\t\t\t|     %s      |\n",real_time); 
        // // printf("\t\t\t\t\t\t\t\t\t|  %s   |\n",getdate()); 
        // printf("\t\t\t\t\t\t\t\t\t|                |\n");
        // printf("\t\t\t\t\t\t\t\t\t|________________|\n"); 
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t (1)\t\t\t (2)\t\t\t (3)\t\t\t (4)\t\t\t (5)\n");
        printf("\t\t\t\t\tCLOCK\t\t\tALARM\t\t\tTIMER\t\t       CALANDER\t\t\t EXIT\n\n");
        printf("\t\t\t\t\tEnter your choice \n");
        printf("\t\t\t\t\t");
        scanf("%d",&choice);

}

void addevent(){
    printf("\t\t\t\t\tEnter day to mark: ");
    int day;
    scanf("%d",&day);
    char event_note[100];
    printf("\t\t\t\t\tEnter event(no whitespace allowded): ");
    scanf("%s",event_note);
    FILE *fp_event;
    fp_event = fopen("event.txt","a");
    fprintf(fp_event,"%d-%d-%d ",year,month,day);
    fprintf(fp_event,"%s\n",event_note);
    fclose(fp_event);
    printf("\t\t\t\t\tEvent added successfully\n");
    sleep(2);
}

showevent(){
    char reader[100];
    int count=0;
   

    system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(6) Open Calander\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(7) Mark Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(8) Show Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(9) Remove Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(10) BS to AD\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(11) AD to BS\n");

        //to print data from event,txt
        FILE *fp_show;
        fp_show =fopen("event.txt","r");
        while(fgets(reader, 100, fp_show)){ 
                count++;
                printf("\t\t\t\t\t\t\t\t\t %d) %s",count, reader );
              }  
        fclose(fp_show);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t (1)\t\t\t (2)\t\t\t (3)\t\t\t (4)\t\t\t (5)\n");
        printf("\t\t\t\t\tCLOCK\t\t\tALARM\t\t\tTIMER\t\t       CALANDER\t\t\t EXIT\n\n");
        printf("\t\t\t\t\tEnter your choice \n");
        printf("\t\t\t\t\t");
        scanf("%d",&choice);
}

removeevent(int event_no){

            int count;
            //to copy from event.txt to temp.txt
            FILE *fp_e1;
            fp_e1 = fopen("event.txt","r");
            FILE *fp_t1;
            fp_t1 = fopen("temp.txt","w");
            char reader[100];
            count=0;
            while(fgets(reader, 100, fp_e1)){ 
                count++;
                if(count==event_no){continue;}
                    fprintf(fp_t1,"%s",reader);
                }  
            fclose(fp_e1);
            fclose(fp_t1);

            //to copy from temp.txt to event.txt
            FILE *fp_e2;
            fp_e2 = fopen("event.txt","w");
            FILE *fp_t2;
            fp_t2 = fopen("temp.txt","r");
            while(fgets(reader, 100, fp_t2)){ 
                fprintf(fp_e2,"%s",reader);
            }  
            fclose(fp_e2);
            fclose(fp_t2);
}

bstoad(int y,int m,int d){
//to save original date of bs as to display later
int o_y=y,o_m=m,o_d=d;

if(d>17)
  d=d-17;
 else
 {
  d=d+30;
  m=m-1;
  d=d-17;
 }

 if(m>8)
  m=m-8;
 else
 {
  m=m+12;
  y=y-1;
  m=m-8;
 }
    
 y=y-56;

system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(6) Open Calander\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(7) Mark Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(8) Show Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(9) Remove Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(10) BS to AD\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(11) AD to BS\n");

        printf("\t\t\t\t\t\t   BS              AD\n");
        printf("\t\t\t\t\t\t%d-%d-%d\t%d-%d-%d",o_y,o_m,o_d,y,m,d);
        
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t (1)\t\t\t (2)\t\t\t (3)\t\t\t (4)\t\t\t (5)\n");
        printf("\t\t\t\t\tCLOCK\t\t\tALARM\t\t\tTIMER\t\t       CALANDER\t\t\t EXIT\n\n");
        printf("\t\t\t\t\tEnter your choice \n");
        printf("\t\t\t\t\t");
        scanf("%d",&choice);
}

adtobs(int y,int m,int d){
//to save original date of ad as to display later
int o_y=y,o_m=m,o_d=d;

if(d<17)
  d=d+17;
 else
 {
  d=d-30;
  m=m+1;
  d=d+17;
 }

 if(m<8)
  m=m+8;
 else
 {
  m=m-12;
  y=y+1;
  m=m+8;
 }
    
 y=y+56;

system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(6) Open Calander\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(7) Mark Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(8) Show Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(9) Remove Event\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(10) BS to AD\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(11) AD to BS\n");

        printf("\t\t\t\t\t\t   AD              BS\n");
        printf("\t\t\t\t\t\t%d-%d-%d\t%d-%d-%d",o_y,o_m,o_d,y,m,d);
        
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t (1)\t\t\t (2)\t\t\t (3)\t\t\t (4)\t\t\t (5)\n");
        printf("\t\t\t\t\tCLOCK\t\t\tALARM\t\t\tTIMER\t\t       CALANDER\t\t\t EXIT\n\n");
        printf("\t\t\t\t\tEnter your choice \n");
        printf("\t\t\t\t\t");
        scanf("%d",&choice);
}
