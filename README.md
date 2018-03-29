#include<stdio.h>
int main()
{
	int n,a,i,trn;
	int p[20],at[20],bt[20],tat[20],par;
	printf("enter the number of process=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		 p[i]=(i+1);
		 printf("enter arrival time for process p[%d] :",(i+1));
		 scanf("%d",&at[i]);
		 printf("enter burst time for process p[%d] :",(i+1));
		 scanf("%d",&bt[i]);
		 printf("faculty(1) or student(0) :");
		 scanf("%d",&par[i]);
	}
	printf("Enter trunarround time : ");
	scanf("%d",&trn);
	return 0;
}
