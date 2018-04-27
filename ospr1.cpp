#include<stdio.h>
Printf("NAME:G.MUNESWARARAO\n SECTION:K1651 \t Rollno:A24 \n  ASSIGNED PROJECT :4 \n SUBMITTED TO:AMANPREET KAUR\n");
struct processes
{
	char proc_name[10];
	int arr_time;
	int bur_time;
};
int main()
{
	int n,i,j;
	printf("Enter no of processes:\t");
	scanf("%d",&n);
	
	processes p[n];
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter process name:\t");
		scanf("%s",&p[i].proc_name);
		printf("Enter Burst Time:\t");
		scanf("%d",&p[i].bur_time);
		printf("Enter Arrival Time:\t");
		scanf("%d",&p[i].arr_time);
	}	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].arr_time >= p[j+1].arr_time)
			{
				processes t = p[j];
				p[j] = p[j+1];
				p[j+1] = t;
			}
			else
			{
				continue;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].arr_time == p[j+1].arr_time && p[j].bur_time>p[j+1].bur_time)
			{
				processes t = p[j];
				p[j] = p[j+1];
				p[j+1] = t;
			}
			else
			{
				continue;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("\n\nEnter process name:%s\t",p[i].proc_name);
		printf("\nEnter Burst Time:%d\t",p[i].bur_time);
		printf("\nEnter Arrival Time%d\t",p[i].arr_time);
	}	
	int sum = 0;
	for(i=0;i<n;i++)
	{
		sum = sum+p[i].arr_time;
	}
	
	printf("\n Average Waiting time = %d\n",sum/n);
	
	int sum2 = 0;
	for(i=0;i<n;i++)
	{
		sum2 = sum2+(p[i].bur_time-p[i].arr_time);
	}
	
	printf("\n Average Waiting time = %d\n",sum2/n);
}
