#include<cstdlib>
#include<stdio.h>
#include<algorithm>
//using namespace std;
#include<iostream>
typedef int Rank;
#define Base_size 3
using namespace std;
template <typename T>class Vector
{
protected:
	Rank _size;								//当前向量长度 
	int _capacity;						   //向量空间大小 
	T* _elem;                              //向量内容 
	
	
	
	void expand(){
	if(_size<_capacity)return;				//未满 
	if(_capacity<Base_size)_capacity = Base_size;    //不低于Base_size	
	T* oldelem = _elem;
	_elem = new T[_capacity<<=1];
	for(int i=0;i<_size;i++)_elem[i]=oldelem[i];
	delete []oldelem;	
	}
	void shrink(){
	if(_capacity<Base_size*2)return;				//保证缩小后仍大于Base_size 
	if(_capacity<_size*2)return;				//保证空间利用大于50% 
	T *oldelem=_elem;
	_elem=new T[_capacity>>=1];
	for(int i=0;i<_size;i++)_elem[i]=oldelem[i];
	delete []oldelem;	
	}
/*	Rank max(){
	max(0,_size);}
	Rank max(Rank lo,Rank hi){
		T max;
		for(int i=lo;i<hi;i++)if(max<_elem[i])max=_elem[i];
		return max;
	}
*/
	
	void merge(Rank lo,Rank hi);
	void mergeSort(Rank lo,Rank hi);
	//Rank partition (Rank lo,Rank hi);
	void quickSort(Rank lo,Rank hi);
	void heapSort(Rank lo,Rank hi);

public:
	Vector(int c=Base_size,int s=0,T v=0)
		{_elem = new T[_capacity = c];for(_size=0;_size<s;_size=_size+1)_elem[_size]=v;}	
	Vector (T const* A,Rank n){ copyFrom(A,0,n); }
	Vector (T const* A,Rank lo,Rank hi){ copyFrom(A,lo,hi);}
	Vector (Vector<T> const& V){copyFrom(V._elem,0,V._size);}
	Vector (Vector<T> const& V,Rank lo,Rank hi){copyFrom( V._elem,lo,hi); }
	
	void copyFrom(T const* A,Rank lo,Rank hi){
	_elem = new T[_capacity=2 * (hi - lo) ];
	_size = 0;
	while(lo<hi)_elem[_size++]=A[lo++];   //复制 
	}
	
	~Vector() { delete [] _elem;}
	
	Rank get(Rank r){
	if(r>=_size)return 0;
	else return _elem[r];
	}
	void selectionSort(Rank lo,Rank hi){
	
	for(int i=lo;i<hi-1;i++)
	{
		Rank min1=i;
			for(int j=i+1;j<hi;j++)if(_elem[j]<=_elem[min1])min1=j;
			
			swap(min1,i);
			
		}
	}
	void bubbleSort(Rank lo,Rank hi){
		  for(int i=lo;i<hi-1;i++)
        	for(int j=lo;j<hi-1-i;j++)
                if(_elem[j]>_elem[j+1])
					swap(j,j+1);
                
	}
	Rank size()  {
	return /*_capacity;*/_size;}
	bool empty() const {
	return !_size;}
	bool disorded() const{
	for(int i=0;i<_size;i++)if(_elem[i]>_elem[i+1])return 0;	
	return 1;
	}//此处有序为从小到大。0为无序，1为有序 
	
	
	Rank find ( T const& e)const{return find(e,0,_size);}
	Rank find (T const& e,Rank lo,Rank hi)const
	{
	for(Rank i=hi;i>lo;i--)if(e==_elem[i])return i;
	return -1;
	}
	
	
	Rank search(T const& e)const{
		return(_size<=0)?-1:search(e,0,_size);
	}
	
	
	Rank search(T*A,T const& e,Rank lo,Rank hi)const	//二分查找 
	{
		while(lo<hi)
		{
			Rank mi=(lo+hi)>>1;
			if( e < _elem[mi] )hi = mi;
			else if(_elem[mi] < e)lo=mi+1;
			else return mi;
		}
		return -1;
	}
	
	//T& operator[] (Rank r) const;
	
	Vector<T> &operator= ( Vector<T> const& );
	
	
	T remove( Rank r ){remove(r,r+1);}
	void remove(Rank lo,Rank hi)
	{
	Rank j=hi;
	for(int i=lo;i<_size-hi+lo;i++)_elem[i]=_elem[j++];
	_size=_size-hi+lo;
	shrink();
	}
	
	
	Rank insert(Rank r,T const& e)
	{
		if(_size++>=_capacity)expand();
		for(int i=_size;i>r;i--)_elem[i]=_elem[i-1];
		_elem[r]=e;
	}
	
	void swap(Rank lo,Rank hi){
		T temp=_elem[lo];
		_elem[lo]=_elem[hi];
		_elem[hi]=temp;
	} 
	Rank insert(T const& e){ 
		return insert(_size,e); }
	void Sort(Rank lo, Rank hi){sort(_elem+lo,_elem+hi);}
	void Sort() {sort(_elem,_elem+_size);}
	void unsort(Rank lo,Rank hi){
		for(int i=_size;i>0;i--)
		{
			Rank s=rand()%i;
			swap(i,s);			
		}
	}
	void unsort(){unsort(0,_size);}
	
	
	int deduplicate();
	
	
	int uniquify();
	void traverse(void(*)(T&));
	
	template<typename VST>void traverse(VST&);

};
