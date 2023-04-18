#include<stdio.h>
template <typename T> class queue
{
protected:
	T* elem;
	int capacity;
	int size=0;
	int base=0;
	
public:
	queue(){elem=new T[10000];}
	
	~queue(){delete [] elem;}
	T enqueue(T a){elem[size++]=a;}
	T dequeue(){
		T temp=elem[base];
		elem[base++]='\0';
		//base++;
		return temp;
	}
	T front(){return elem[base];}
	bool empty(){return size-base;}
};
