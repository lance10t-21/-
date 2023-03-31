#include"complex.h"
#include<iostream>
#include<time.h>
int main()
{
	freopen("out2.txt","w",stdout); 
	clock_t start_t,end_t;

	int x[10000],y[10000];
	for(int i=0;i<10000;i++)
	{
		x[i]=10000-rand();
		y[i]=10000-rand();
	}	
	complex<int> a(x,y,10000);
	complex<int> b(x,y,10000);;
	printf("ÂÒÐò£º\n");
	start_t=clock();
	a.mergesort(0,a.size());
	end_t=clock();
	printf("¹é²¢:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	start_t=clock();
	b.bubbleSort(0,b.size());
	end_t=clock();
	printf("Ã°ÅÝ:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	printf("Ë³Ðò£º\n");
	start_t=clock();
	a.mergesort(0,a.size());
	end_t=clock();
	printf("¹é²¢:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	start_t=clock();
	b.bubbleSort(0,b.size());
	end_t=clock();
	printf("Ã°ÅÝ:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);

	
	
	complex<int> c(x,y,10000);
	complex<int> d(x,y,10000);
	
	
	printf("ÄæÐò£º\n");
	start_t=clock();
	c.mergesort(0,c.size());
	end_t=clock();
	printf("¹é²¢:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	start_t=clock();
	d.bubbleSort(0,d.size());
	end_t=clock();
	printf("Ã°ÅÝ:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	return 0;
}
