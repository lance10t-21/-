#include<iostream>
#include<cstdlib>
#include"complex.h"
int main()
{
	freopen("out3.txt","w",stdout); 
	complex<int> a;
	printf("生成有序向量：\n");
	a.bubbleSort(0,a.size());
	for(int i=0;i<a.size();i++)a.get(i);
	cout<<endl;
	int s1=rand()%3;
	int s2=rand()%3;
	printf("查找模位于0，2之间的复数：\n",s1,s2);
	a.search(0,2,0,a.size());
}
