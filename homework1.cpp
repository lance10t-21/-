#include"complex.h"
#include<iostream>
using namespace std;
int main()
{
	freopen("out.txt","w",stdout); 
	int i;
	printf("�����������������\n");
	complex<int> c;
					//���������������a+bi��
					//a��bС��3
					//�˴��������ڵ�base_sizeΪ10���̶�����10�������������������������Ͽ�֪
					//�˴�һ��������ͬ�ĸ���������
	for(int i=0;i<c.size();i++)c.get(i); 
	
	
	//printf("%d\n",c.size());
	//c.bubbleSort(0,c.size());
	c.deduplicate();
	c.selectionSort(0,c.size());
	
	printf("ȥ��+������:\n");
	
	for(int i=0;i<c.size();i++)c.get(i);
	 
	c.unsort();
	printf("���ҽ����\n");
	for(int i=0;i<c.size();i++)c.get(i);
	
	printf("�������������ĩβ��\n");
	int a=rand()%3;
	int b=rand()%3;
	c.insert(a,b);
	for(int i=0;i<c.size();i++)c.get(i);
	printf("\n");
	printf("���Ҹ���%d+%di:\n",a,b);
	int flag=c.find(a,b,0,c.size());
	printf("%d\n",flag);
	//c.insert(2,3,5);
	
	
	


	
	
	
	
	
	return 0;
}
