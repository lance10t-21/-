#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
int main()
{
	freopen("out.txt","w",stdout);
	srand(time(0));
	int i,j,k;
	int a[105];
	for(i=0;i<10;i++)
	{
		int max=-1;
		int flag=rand()%104+1;
		printf("สýื้ %d:\n",i+1);
		for(j=1;j<=flag;j++)
		{
			a[j]=rand()%105+1;	
			printf("%d ",a[j]);
		}printf("\n");
		
		for(j=1;j<=flag;j++)
		{
			int min=105;
			for(k=j;k<=flag;k++)
			{
				if(a[k]<min)min=a[k];	
				if(max<min*(k-j+1))max=min*(k-j+1);
			}	
		}
		printf("%d\n",max);
			
	}
	return 0;	
} 
