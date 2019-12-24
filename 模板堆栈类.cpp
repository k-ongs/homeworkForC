#include <iostream>
using namespace std;

template <class T>
class Tstack
{
private:
	T *data;
	int top;//栈顶
	int size;//规模
	int length;//长度 
public:
	Tstack(int n = 5);
	void push(T x);
	T peek();
	T pop();
	bool isEmpty();
	bool isFull();
	void clear(); 
};

template <class T>
Tstack<T>::Tstack(int n)
{
	top = 0;
	size = n;
	length = n;
	data = new T[n];
}

template <class T>
void Tstack<T>::push(T x)
{
	if(isFull())
	{
		T *tem = new T[length + size];
		length += size;
		for(int i=0; i<length; i++)
			tem[i] = data[i];
		delete [] data;
		data = tem;
	}
	data[top++] = x;
}

template <class T>
T Tstack<T>::pop()
{
	if(isEmpty())
		return data[top];
	else
		return data[--top];
}

template <class T>
T Tstack<T>::peek()
{
	return data[top];
	
}

template <class T>
bool Tstack<T>::isEmpty()
{
	if(top <= 0)
		return true;
	return false;
}

template <class T>
bool Tstack<T>::isFull()
{
	if(top >= length)
		return true;
	return false;
}
template <class T>
void Tstack<T>::clear()
{
	delete [] data;
	top = 0;
	length = size;
	data = new T[size];
} 

int main()
{
	Tstack<int> s1(10); //定义整型堆栈
	Tstack<char> s2(10); //定义字符堆栈

	for(int k=1;k<15;k++)
		s1.push(k);

	while(!s1.isEmpty())
		cout<<s1.pop() << " ";
	cout << endl;

	for(char ch='A';ch<'H';ch++)
		s2.push(ch);

	while(!s2.isEmpty())
		cout << s2.pop() << " ";
	cout << endl;

	return 0;
}
