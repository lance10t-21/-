#include<iostream>
#include<cstdlib>
#include"complex.h"
int main()
{
	freopen("out3.txt","w",stdout); 
	complex<int> a;
	a.bubbleSort(0,a.size());
	//for(int i=0;i<a.size();i++)a.get(i);
	cout<<endl;
	int s1=rand()%3;
	int s2=rand()%3;
	a.search(0,2,0,a.size());
}
