#include"complex.h"
#include<iostream>
using namespace std;
int main()
{
	freopen("out.txt","w",stdout); 
	int i;
	printf("生成随机复数向量：\n");
	complex<int> c;
					//生成随机复数向量a+bi。
					//a，b小于3
					//此处复数类内的base_size为10，固定生成10个随机复数向量，根据排列组合可知
					//此处一定存在相同的复数向量。
	for(int i=0;i<c.size();i++)c.get(i); 
	
	
	//printf("%d\n",c.size());
	//c.bubbleSort(0,c.size());
	c.deduplicate();
	c.selectionSort(0,c.size());
	
	printf("去重+排序结果:\n");
	
	for(int i=0;i<c.size();i++)c.get(i);
	 
	c.unsort();
	printf("置乱结果：\n");
	for(int i=0;i<c.size();i++)c.get(i);
	
	printf("插入随机向量到末尾：\n");
	int a=rand()%3;
	int b=rand()%3;
	c.insert(a,b);
	for(int i=0;i<c.size();i++)c.get(i);
	printf("\n");
	printf("查找复数%d+%di:\n",a,b);
	int flag=c.find(a,b,0,c.size());
	printf("%d\n",flag);
	//c.insert(2,3,5);
	
	
	


	
	
	
	
	
	return 0;
}
