/*
输入一个数k代表方阵大小 
输出解和解的总数 
*/
#include<stdio.h>
int a[1001],sum=0;
int b[1001]={0},c[1001]={0},d[1001]={0};
int k;
void print()
{
    int i;
    for(i=1;i<=k;i++)printf("%d ",a[i]);
    printf("\n");		
    sum++; 
}       
int search(int i)
{
    int j;
    for(j=1;j<=k;j++)
    if(b[j]!=1&&c[i+j]!=1&&d[i-j+k-1]!=1)
	{
    	a[i]=j;
    	b[j]=1;
    	c[i+j]=1;
    	d[i-j+k-1]=1;
    	if(i==k)print();
    	else search(i+1);
    	b[j]=0;
    	c[i+j]=0;
    	d[i-j+k-1]=0;
	}
}
int main()
{
	scanf("%d",&k);
    search(1);
    printf("%d\n",sum);
    return 0;
}
