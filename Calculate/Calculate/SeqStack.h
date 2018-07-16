#include<iostream>
using namespace std;

const int stackIncreament = 20;
template<class T>
class SeqStack
{
public:
	SeqStack(int sz = 100);
	~SeqStack() { delete[]elements; }
	void Push(const T& x);
	bool Pop(T& x);
	bool getTop(T& x)const;
	bool isEmpty()const { return (top == -1) ? true : false; }
	bool isFull()const { return (top == maxSize - 1) ? true : false; }

	int getSize()const { return (top + 1); }
	void makeEmpty() { top = -1; }

private:
	T* elements;
	int top;
	int maxSize;
	void overflowProcess();
};

template<class T>
SeqStack<T>::SeqStack(int sz) :top(-1), maxSize(sz)
{
	elements = new T[maxSize];
	if (elements == nullptr)
	{
		cerr << "·ÖÅäÄÚ´æÊ§°Ü£¡";
	}
}

template<class T>
void SeqStack<T>::overflowProcess()
{
	T* newArray = new T[maxSize + stackIncreament];
	if (newArray == nullptr)
	{
		cerr << "´æ´¢·ÖÅäÊ§°Ü£¡" << endl;
		exit(1);
	}
	for (int i = 0; i <= top; i++) newArray[i] = elements[i];
	maxSize = maxSize + stackIncreament;
	delete[] elements;
	elements = newArray;
}

template<class T>
void SeqStack<T>::Push(const T& x)
{
	if (isFull()) overflowProcess();
	elements[++top] = x;
}

template<class T>
bool SeqStack<T>::Pop(T& x)
{
	if (isEmpty()) return false;
	x = elements[top--];
	return true;
}

template<class T>
bool SeqStack<T>::getTop(T& x)const
{
	if (isEmpty()) return false;
	x = elements[top];
	return true;
}

