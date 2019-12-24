#include <iostream>
using namespace std;

class Array
{
	private:
		int *a;
		int n;
		int length;
	public:
		Array(int l=5)
		{
			length = n = l;
			a = new int[length];
		}
		void input()
		{
			for(int i=0; i < n; i++)
				cin >> a[i];
		}
		void output()
		{
			for(int i=0; i < n; i++)
				cout << a[i] << " ";
			cout << endl;
		}
		int findmax()
		{
			int Max = a[0];
			for(int i=1; i < n; i++)
				if(a[i] > Max)
					Max = a[i];
			return Max;
		}
		int find(int m)
		{
			for(int i=0; i < n; i++)
				if(a[i] == m)
					return i;
			return -1;
		}
		void sort()
		{
			for(int i=0; i < n-1; i++)
			{
				for(int j = 0; j < n - i - 1; j++)
				{
					if (a[j] > a[j + 1]) 
					{
						int temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
				}
			}
		}
		void insert(int t)
		{
			if(n+1 > length)
				expend(5);
			a[n] = t;
			for(int i=n-1; i >= 0; i--)
			{
				if(a[i] > a[i+1])
				{
					int tem = a[i];
					a[i] = a[i+1];
					a[i+1] = tem;
				}else
				{
					n++;
					return;
				}
			}
			n++;
		}
		void expend(int offset)
		{
			int * tem = new int[n+offset];
			for(int i=n-1; i >= 0; i--)
				tem[i] = a[i];
			delete [] a;
			a = tem;
		}
};

int main( )
{
	int t;
	Array arr;
	arr.input();
	arr.output();
	cout << "�����Ϊ��" << arr.findmax() << endl;
	cout << "3���±�Ϊ��" << arr.find(3) << endl;
	arr.sort();
	cout << "�����Ϊ��" << endl;
	arr.output();
	cout << "��������Ҫ��������֣�";
	cin >> t;
	arr.insert(t);
	cout << "�����Ϊ��" << endl;
	arr.output();
	return 0;
}

