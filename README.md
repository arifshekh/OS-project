#include<stdio.h>
int main()
{
	int n,a,i,k,t_q,temp,flag,time,count;
	float trnaround_time=0,wt_time=0;
	int p[20],at[20],bt[20],tat[20],Q[20],rt[20];
	printf("enter the number of process=");
	scanf("%d",&n);
	temp=n;
	for(i=0;i<n;i++)
	{
		 p[i]=(i+1);
		 printf("enter arrival time for process p[%d] :",(i+1));
		 scanf("%d",&at[i]);
		 printf("enter burst time for process p[%d] :",(i+1));
		 scanf("%d",&bt[i]);
		 rt[i]=bt[i];
		 printf("faculty(1) or student(0) :");
		 scanf("%d",&Q[i]);
	}
	printf("Enter time-quantum : ");
	scanf("%d",&t_q);
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
	for(i=0;i<n;i++)
	{
		 for(k=i+1;k<n;k++)
		 {
		 	  if(Q[i]>Q[k])
		 	  {
		 	  	 for(time=0,count=0;temp!=0;)
		 	  	 {
		 	  	    if((rt[count]<=t_q) && rt[count]>0)
					  {
					  	 time=time+rt[count];
					  	 rt[count]=0;
					  	 flag=1;
					  } 
					  else if(rt[count]>0)
					  {
					  	 rt[count]=rt[count]-t_q;
					  	 time=time+t_q;
					  }
					  if((rt[count]==0) && (flag==1))
					  {
					  	 temp--;
					  	 printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
					  	 wt_time=wt_time+time-at[count]-bt[count];
					  	 trnaround_time=trnaround_time+time-at[count];
					  	 flag=0;
					  }
					  if(count==n-1) 
                         count=0; 
                      else if(at[count+1]<=time) 
                         count++; 
                      else 
                         count=0; 
			     }
		 	  	 
			  }
		 }
		 
	}
	 printf("\nAverage Waiting Time= %f\n",wt_time/n); 
     printf("Avg Turnaround Time = %f",trnaround_time/n); 
	return 0;
}
