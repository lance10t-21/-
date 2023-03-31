#include"complex.h"
#include<iostream>
#include<time.h>
int main()
{
	clock_t start_t,end_t;
	complex<int> a;

	start_t=clock();
	a.bubbleSort(0,a.size());
	
	for(int i=0;i<a.size();i++)a.get(i);
	
	//a.unsort();
	//a.mergesort(0,a.size());
//for(int i=0;i<a.size();i++)a.get(i);
	 


	return 0;
}
