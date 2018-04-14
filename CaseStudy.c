#include<stdio.h>
struct file{
	
	int allocation[30];
	int maximum[30];
	int need[30];
	int flag;
};
	
void main()
{
	struct file f[30];
	int fl;
	int i,j,k,process,no,resource,count=0,id,newResource,b,g;
	int avail[30],seq[30]; //seq is maintain sequence of process
	clrscr();
	 
	 printf("Enter Number of Process\n");
	 scanf("%d",&no);
	 
	 printf("Enter Number of Resources\n");
	 scanf("%d",&resource);
	 
	 for(i=0;i<no;i++)//for the process
	 {
		 printf("Enter the Details of Process %d \n",i);
		 
		 printf("Enter Allocation\t\t");
		 for(j=0;j<resource;j++)//for the resources
		 {
			 scanf("%d",&f[i].allocation[j]); 
		 } 
		 printf("Enter Max\t\t");
		 for(j=0;j<resource;j++)
		 {
			  scanf("%d",&f[i].maximum[j]); 
		 } 
		 f[i].flag=0;
	 }
	 printf("Enter Available Resources\t\t");
	 for(i=0;i<resource;i++)
	 {
		 scanf("%d",&avail[i]);
	 }
	 	 printf("Enter New Request Details \t\t");
		 	 printf("Enter Process Id\t\t");
			 scanf("%d",&id);
			 
	printf("Enter Request for Process\t\t");
	for(i=0;i<resource;i++)
	{
		scanf("%d",&newResource);
		f[id].allocation[i] +=newResource;
		avail[i]=avail[i]-newResource;
	}
	for(i=0;i<no;i++)
	{
		for(j=0;j<resource;j++)
		{
			f[i].need[j]=f[i].maximum[j]- f[i].allocation[j];
			if(f[i].need[j]<0)
			{
				f[i].need[j]=0;
			}
		}
	}
	count=0;
	fl=0;
	while(count!=no)
	{
		g=0;
		for(j=0;j<no;jj++)
		{
			if(f[i].flag=0)
			{
				b=0;
				for(process=0;process<resource;i++) 
				{
					if(avail[process]>=f[j].need[process])//saftey algorithm need<=work
					{
						b=b+1;
					}
					else{
						b=b-1;
					}
				}
				if(b=resource)
				{
					printf("\nProcess %d is Visited",j);
					seq[fl++]=j;
					f[j].flag=1;
					for(k=0;k<resource;k++)
					{
						avail[k]+=f[j].allocation[k];
					}
					count++;
					printf("(");
					for(k=0;k<resource;k++)
					{
						printf("%3d",avail[k]);
					}
					printf(")");	
					
				}
				g=1;
			}
			
		}
		if(g==0)
		{
			printf("\nRequest Not Granted");
			printf("System is in unsafe state");
			goto y;
		}
	}
	printf("\n System is in safe state");
	printf("The Safe Sequence is ( ");
	for(i=0<i<fl;i++)
	{
		printf("Process %d ",seq[i]);
	}
	printf(" )");
	
	y:printf("\nProcess\t\tAllocation\t\tMaximum\t\tNeed\n");
	for(i=0;i<n;i++)
	{
		printf("Process %d\t",i);
		for(j=0;j<resource;j++)
		{
		

		printf("%6d",f[i].allocation[j]);
		}	
		for(j=0;j<resource;j++)
		{
			printf("%6d",f[i].maximum[j]);
		}
		for(j=0;j<resource;j++)
		{
			printf("%6d",f[i].need[j]);
		}
		printf("\n");
	}
	
}