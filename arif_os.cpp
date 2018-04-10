#include<stdio.h>
#include<windows.h>
#include<time.h>
struct query
{
       int p,at,bt,wt,trn,rem_time;
};


void arrival_time(struct query a[],int pro)
{
       int i,j;
       struct query temp;
       for(i=0;i<pro;i++)
       {
              for(j=i+1;j<pro;j++)
              {
                     if(a[i].at > a[j].at)
                     {
                           temp = a[i];
                           a[i] = a[j];
                           a[j] = temp;
                     }
              }
       }
       return;
}
int round_robin(struct query x[],int p)
{
	int i,j,time,remains,flag=0,tq;
       float avgwait=0,avgturn=0;
	p=p+1;
       remains=p;
       arrival_time(x,p);
       printf("Enter Time  : ");
       scanf("%d",&tq);
       printf("\n\t\tGantt Chart\t\t\n");
       printf("0");
       for(time=0,i=0;remains!=0;)
       {
              if(x[i].rem_time<=tq && x[i].rem_time>0)
              {
                     time = time + x[i].rem_time;
                     printf(" -> [P%d] <- %d",x[i].p,time);
                     x[i].rem_time=0;
                     flag=1;
              }
              else if(x[i].rem_time > 0)
              {
                     x[i].rem_time = x[i].rem_time - tq;
                     time = time + tq;
                     printf(" -> [P%d] <- %d",x[i].p,time);
              }
              if(x[i].rem_time==0 && flag==1)
              {
                     remains--;
                     x[i].trn = time-x[i].at;
                     x[i].wt = time-x[i].at-x[i].bt;
                     avgwait = avgwait + time-x[i].at-x[i].bt;
                     avgturn = avgturn + time-x[i].at;
                     flag=0;
              }
              if(i==p-1)
                     i=0;
              else if(x[i+1].at <= time)
                     i++;
              else
                     i=0;
       }
       printf("\n\nProcess  Arrival_time  Burst_time   Turnaround_time   Waiting_time\n\n");
       
       for(i=0;i<p;i++)
       {
              printf("P%d\t%d\t%d\t%d\t%d\n",x[i].p,x[i].at,x[i].bt,x[i].trn,x[i].wt);
       }
       printf("\n\n");
       avgwait = avgwait/p;
       avgturn = avgturn/p;
       printf("Average Waiting Time : %.2f\n",avgwait);
       printf("Average Turnaround Time : %.2f\n",avgturn);
}
int main()
{
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	if(str_t.wHour==10)
	{
		system("cls");
       int i,j,time,remain,flag=0,ts;
       struct query student[100],faculty[100];
       float avgwait=0,avgturn=0;
       int pros=-1,prof=-1,id;
       ch:
    {	system("cls");
		printf("Enter priority (0 for Student And 1 for Faculty):");
    	scanf("%d",&id);
    	if(id==0)
    	{pros++;
    	printf("Enter Arrival Time and Burst Time of the Request: S%d : \n",pros+1);
    	scanf("%d%d",&student[pros].at,&student[pros].bt);
    	student[pros].p = pros;
        student[pros].rem_time = student[pros].bt;
        if(student[pros].at>120 ||student[pros].bt<=0 ||student[pros].at<0 )
        {pros--;}
		}
		else if(id==1)
		{prof++;
    	printf("Enter Arrival Time and Burst Time of the Request: P%d : \n",prof+1);
    	scanf("%d%d",&faculty[prof].at,&faculty[prof].bt);
    	faculty[prof].p = prof;
        faculty[prof].rem_time = faculty[prof].bt;
        if(faculty[prof].at>120 ||faculty[prof].bt<=0 ||faculty[prof].at<0)
        {prof--;}
		}
		else
		{printf("Wrong Input. Please Try Again.\n");goto ch;}
       mh:
       	{
       printf("Select an Option:\n");
       printf("1. Enter Another Request.\n");
       printf("2. Round Robin.\n");
       int y;
       scanf("%d",&y);
		   switch(y)
	       {
	       	case 1:
	       		{goto ch;}
	       	case 2:
	       		{goto ch1;}
			default:
				{printf("Wrong Input. enter again.\n");goto mh;}
		   }
   		}
   	}
      ch1:{
      	if(pros>1)
	{printf("Student\n");
	round_robin(student,pros);}
	      else
		{printf("No. of processes is less than 2");}
	if(prof>1)
	{printf("Faculty\n");
	round_robin(faculty,prof);}
	      else
		{printf("No. of processes is less than 2");}
      	}
      }
    else
    {printf(" Please login in between 10:00 am to 12:00 am only.");
	}
}

