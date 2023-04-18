#include<iostream>
#define Base_size 1000
template <typename T> class stack
{
protected:
	T* elem;
	int capacity;
	int size=1;
	
public:
	stack(){elem=new T[Base_size];}
	
	~stack(){delete [] elem;}
	T push(T a){elem[size++]=a;}
	T pop(){
		T temp=elem[size-1];
		elem[size--]='\0';
		return temp;
	}
	T top(){return elem[size-1];}
	bool empty(){return size-1;}
};
