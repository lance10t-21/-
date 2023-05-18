#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stdio.h>
#include<time.h>
int _elem[10000];
void init(){
	for(int i=10000;i>1;i--)_elem[10000-i]=i;
}
void random(){
	srand(time(0));
	for(int i=0;i<10000;i++)_elem[i]=rand()%10000+1;
}
void swap(int lo,int hi){
	int temp=_elem[lo];
	_elem[lo]=_elem[hi];
	_elem[hi]=temp;
} 
int min(int a,int b){
	if(a>b)return b;
	else return a;
} 
int bubbleSort(){
	for(int i=0;i<10000;i++)
    	for(int j=0;j<10000-1-i;j++)
        	if(_elem[j]>_elem[j+1])
					swap(j,j+1);  
	}
int insertSort(){
	int temp,i,j,k;
	for(int i=1;i<10000;i++)
	{
		j=0;
		temp=_elem[i];
		while(_elem[i]>_elem[j]&&j<i)j++;
		k=i+1;
		while(k-->j)_elem[k]=_elem[k-1];
		_elem[j]=temp;
	} 
}
int selectSort(){
	int min1=0;
	for(int i=0;i<9999;min1=++i){
		for(int j=i+1;j<10000;j++)if(_elem[j]<=_elem[min1])min1=j;
		swap(min1,i);
	}
}
int mergeSort(){
	int* a=_elem;
    int* b = new int[10000];
    for(int i=1;i<10000;i+=i) {
    	for(int start=0;start<10000;start+=i*2) {
            int low=start, mid=min(start+i,10000),high=min(start+2*i,10000);
            int k=low;
            int s1=low,e1=mid;
            int s2=mid,e2=high;
            while (s1 < e1 && s2 < e2)b[k++]=a[s1]<a[s2]?a[s1++]:a[s2++];
            while(s1<e1)b[k++]=a[s1++];
            while (s2<e2)b[k++]=a[s2++];
        }
        int* temp=a;
        a=b;
        b=temp;
    }
}
int Paritition1(int A[], int low, int high) {
	int pivot = A[low];
	while (low < high) {
		while (low < high && A[high] >= pivot)--high;
    	A[low] = A[high];
    	while (low < high && A[low] <= pivot)++low;
    	A[high] = A[low];
   }
   A[low] = pivot;
   return low;
}
void QuickSort(int A[], int low, int high){
	if(low<high)
	{
    int pivot = Paritition1(A, low, high);
    QuickSort(A, low, pivot - 1);
    QuickSort(A, pivot + 1, high);
	}
}

int main()
{
	clock_t start_t,end_t;

	printf("Ëæ»úÐòÁÐ:\n"); 
	random();
	start_t=clock();
	insertSort();
	end_t=clock();
	printf("²åÈë:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	random();
	start_t=clock();
	bubbleSort();
	end_t=clock();
	printf("Ã°ÅÝ:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	random();
	start_t=clock();
	selectSort();
	end_t=clock();
	printf("Ñ¡Ôñ:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	random();
	start_t=clock();
	mergeSort();
	end_t=clock();
	printf("¹é²¢:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	random();
	start_t=clock();
	QuickSort(_elem,0,100);
	end_t=clock();
	printf("¿ìÅÅ:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	
	printf("Ë³Ðò:\n"); 
	start_t=clock();
	insertSort();
	end_t=clock();
	printf("²åÈë:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	start_t=clock();
	bubbleSort();
	end_t=clock();
	printf("Ã°ÅÝ:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	start_t=clock();
	selectSort();
	end_t=clock();
	printf("Ñ¡Ôñ:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	start_t=clock();
	mergeSort();
	end_t=clock();
	printf("¹é²¢:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	start_t=clock();
	QuickSort(_elem,0,10000);
	end_t=clock();
	printf("¿ìÅÅ:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	
	printf("ÄæÐò£º\n");
	init();
	start_t=clock();
	insertSort();
	end_t=clock();
	printf("²åÈë:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	init();
	start_t=clock();
	bubbleSort();
	end_t=clock();
	printf("Ã°ÅÝ:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	init();
	start_t=clock();
	selectSort();
	end_t=clock();
	printf("Ñ¡Ôñ:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	init();
	start_t=clock();
	mergeSort();
	end_t=clock();
	printf("¹é²¢:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	init();
	start_t=clock();
	QuickSort(_elem,0,10000);
	end_t=clock();
	printf("¿ìÅÅ:%f sec\n",float(end_t-start_t)/CLOCKS_PER_SEC);
	
	
} 
