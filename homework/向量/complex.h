#include<iostream>
#include<stdio.h>
#define base_size 10
#include<ctime>
#include<cstdlib>
#include<math.h>
using namespace std;

typedef int Rank;
template <typename T>
class complex
{
protected:
	T *elem1;
	T *elem2;
	double *mod;
	Rank _size;
	int _capacity;
void expand(){
	if(_size<_capacity)return;				//未满 
	if(_capacity<base_size)_capacity = base_size;    //不低于Base_size	
	T* oldelem1 = elem1;
	T* oldelem2 = elem2;
	double* oldmod = mod;
	elem1 = new T[_capacity<<=1];
	elem2 = new T[_capacity<<=1];
	mod = new double[_capacity<<=1];
	for(int i=0;i<_size;i++){
		elem1[i]=oldelem1[i];
		elem2[i]=oldelem2[i];
		mod[i]=oldmod[i]; 
		}
	delete []oldelem1;	
	delete []oldelem2;
	delete []oldmod;
	}
	void shrink(){
	if(_capacity<base_size*2)return;				//保证缩小后仍大于Base_size 
	if(_capacity<_size*2)return;				//保证空间利用大于50% 
	T* oldelem1 = elem1;
	T* oldelem2 = elem2;
	double* oldmod = mod;
	elem1=new T[_capacity>>=1];
	elem2=new T[_capacity>>=1];
	mod = new double[_capacity>>=1];
	for(int i=0;i<_size;i++){
		elem1[i]=oldelem1[i];
		elem2[i]=oldelem2[i];
		mod[i]=oldmod[i]; 
		}
	delete []oldelem1;	
	delete []oldelem2;
	delete []oldmod;	
	}	
	
	
	
void copyFrom(T const* A,T const* B,Rank lo,Rank hi){
	elem1 = new T[_capacity=2 * (hi - lo) ];
	elem2 = new T[_capacity=2 * (hi - lo) ];
	mod = new double[_capacity=2 * (hi - lo) ];
	_size = 0;
	while(lo<hi)
	{	
	elem1[_size]=A[lo];	
	elem2[_size]=B[lo];	
	mod[_size]=sqrt((elem1[_size]*elem1[_size])+(elem2[_size]*elem2[_size]));
	_size++;
	lo++;
	}


	  //复制 
}
public:
		
	complex (int s=base_size){
		srand(time(0));
		elem1 = new T[_size = base_size ];for(_size=0;_size<s;_size=_size+1)elem1[_size]=rand()%3;
		elem2 = new T[_size = base_size ];for(_size=0;_size<s;_size=_size+1)elem2[_size]=rand()%3;
		mod = new double[_size = base_size];
		for(_size=0;_size<s;_size++)mod[_size]=sqrt( elem1[_size]*elem1[_size] +elem2[_size]*elem2[_size]);
	}
	complex (T const* A,T const* B,int n){ copyFrom(A,B,0,n); }
	complex (T const* A,T const* B,Rank lo,Rank hi){ copyFrom(A,B,lo,hi);}
	//Vector (Vector<T> const& V){copyFrom(V._elem,0,V._size);}
	//Vector (Vector<T> const& V,Rank lo,Rank hi){copyFrom( V._elem,lo,hi); }
	//complex()

	
	~complex(){delete [] elem1;delete [] elem2;delete [] mod;}
	


void merge(int low, int mid, int hight)
{
	double* b = new double[hight - low + 1];
	int i = low, j = mid + 1, k = 0;
	while (i <= mid && j <= hight)  
	{
		if (mod[i] <= mod[j])
		{
			b[k++] = mod[i++]; 
		}
		else
		{
			b[k++] = mod[j++];
		}
	}
	while (i <= mid) 
	{
		b[k++] = mod[i++];
	}
	while (j <= hight)
	{
		b[k++] = mod[j++];
	}
	k = 0;
	for (int i = low; i <= hight; i++)
	{
		mod[i] = b[k++];
	}
	delete[]b;
}
void mergesort(int low, int hight)
{
	if (low < hight)
	{
		int mid = (low + hight) / 2;
		mergesort(low, mid);          //对 a[low,mid]进行排序
		mergesort(mid + 1, hight);    //对 a[mid+1,hight]进行排序
		merge(low, mid, hight);       //进行合并操作
	}
	//for(int i=0;i<_size;i++)cout<<mod[i]<<" ";
	//cout<<endl;
}
/*void Merge(Rank lo,Rank mid,Rank hi){
    //low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    int i=lo,j=mid+1,k=0; //mid+1为第2有序区第1个元素，j指向第1个元素
    T *temp1=new int[hi-lo+1]; //temp数组暂存合并的有序序列
    T *temp2=new int[hi-lo+1];
    double *temp3=new double[hi-lo+1];
    
	while(i<=mid && j<=hi)
	{
        if(mod[i] <= mod[j])
		{
		 //较小的先存入temp中
	 	temp3[k++]=mod[i++];
		temp1[k]=elem1[i];
		temp2[k]=elem2[i];
    	}
        else {
        temp3[k++]=mod[j++];
		temp1[k]=elem1[j];
		temp2[k]=elem2[j];
        		
		}

    }
    while(i<=mid) //若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
	{	
	temp3[k++]=mod[i++];
    temp1[k]=elem1[i];
    temp2[k]=elem2[i];


	}
    while(j<=hi)//同上
    {	
	temp3[k++]=mod[j++];
    temp1[k]=elem1[j];
    temp2[k]=elem2[j];
	

	}
    for(i=lo,k=0;i<=hi;i++,k++)//将排好序的存回low到high区间
		{
		elem1[i]=temp1[k];
		elem2[i]=temp2[k];
		mod[i]=temp3[k];
		cout<<elem1[i]<<" "<<elem2[i]<<" "<<mod[i]<<" "<<endl;
		}
	cout<<endl;
    delete []temp1;
	delete []temp2;
	delete []temp3;

}


void MergeSort(Rank lo,Rank hi){
    if(lo<hi){
        int mid=(lo+hi)/2;
        MergeSort(lo,mid);
        MergeSort(mid+1,hi);
        Merge(lo,mid,hi);
    }
}*/




Rank insert(T e1,T e2){insert(_size,e1,e2);
}
Rank insert(Rank r,T const& e1,T const& e2)
	{
		if(_size++>=_capacity)expand();
		for(int i=_size;i>r;i--)
		{
		elem1[i]=elem1[i-1];	
		elem2[i]=elem2[i-1];
		mod[i]=mod[i-1];
		}
		elem1[r]=e1;
		elem2[r]=e2;
		mod[r]=sqrt(e1*e1+e2*e2);
	}

Rank size(){
	return _size;
}
void unsort(Rank lo,Rank hi){
		for(int i=_size-1;i>0;i--)
		{
			Rank s=rand()%i;
			swap(i,s);			
		}
	}
	void unsort(){unsort(0,_size);}	
void swap(Rank a,Rank b)
	{
		T temp;
		temp=elem1[a];
		elem1[a]=elem1[b];
		elem1[b]=temp;
		temp=elem2[a];
		elem2[a]=elem2[b];
		elem2[b]=temp;
		double t;
		t=mod[a];
		mod[a]=mod[b];
		mod[b]=t;
	}
void bubbleSort(Rank lo,Rank hi){
		  for(Rank i=lo;i<hi;i++)
        	for(Rank j=lo;j<hi;j++)
			{
        		if(mod[j]>mod[j+1])swap(j,j+1); 
        		else if(mod[j]==mod[j+1]&&elem1[j]>elem1[j+1])swap(j,j+1);
			}
                
	}
	
void selectionSort(Rank lo,Rank hi){
	for(int i=lo;i<hi;i++)
	{
			Rank min1=i;
			for(int j=i+1;j<hi;j++)
			{
			if(mod[j]<mod[min1])min1=j;	
			if(mod[j]==mod[min1]&&elem1[j]<elem1[min1])min1=j;
			}
			swap(i,min1);
		}
	}
	
void get(int r){
	if(r>=_size)return;
	else printf("%d + %di mod %f\n",elem1[r],elem2[r],mod[r]);
	}
int deduplicate(){
	//int oldsize=_size;
	Rank i=1;
	while(i<_size)
		{
		if( find( i,0,i) >= 0)remove(i);
		else i++;
		}
}
//Rank find ( T const& e1,T const& e2)const{return find(e,0,_size);}
Rank find (Rank e,Rank lo,Rank hi)const
{
	while( lo<hi-- )if((elem1[e]==elem1[hi])&&(elem2[e]==elem2[hi]))return hi;
	return hi;
}
Rank find(T e1,T e2,Rank lo,Rank hi)const
	{
	for(Rank i=hi;i>lo;i--)if( e1==elem1[i]&&e2==elem2[i])return i;
	return -1;
	}
int remove( Rank r ){remove(r,r+1);}
int remove(Rank lo,Rank hi)
{
	if(lo==hi)return 0;
	while(hi<_size)
	{
		elem1[lo]=elem1[hi];
		elem2[lo]=elem2[hi];
		mod[lo]=mod[hi];
		lo++;
		hi++;
	}
	_size=lo;
	shrink();
}	
};

