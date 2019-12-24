#include <iostream>
using namespace std; 

class BasicShape
{
	protected:
		double area;		//�洢��� 

	public:
		double getArea();
		virtual void CalcArea(){};
};

double BasicShape::getArea()
{
	return area;
}

class Circle:public BasicShape
{
	private:
		int centerX;		//Բ���ĵ�X���� 
		int centerY;		//Բ���ĵ�Y����
		double radius;		//Բ�İ뾶 

	public:
		Circle(int, int, double);
		int GetCenterX() const;
		int GetCenterY() const;
		virtual void CalcArea();
};
Circle::Circle(int X, int Y, double rad)
{
	centerX = X;
	centerY = Y;
	radius = rad;
	CalcArea();
}
int Circle::GetCenterX() const
{
	return centerX;
}
int Circle::GetCenterY() const
{
	return centerY;
}
void Circle::CalcArea()
{
	area = (3.14159 * radius * radius);
}

class Rectangle:public BasicShape
{
	private:
		long width;
		long length;
	
	public:
		Rectangle(long, long);
		long getWidth();
		long getLength();
		virtual void CalcArea();
};
Rectangle::Rectangle(long wid, long len)
{
	width = wid;
	length = len;
	CalcArea();
}
long Rectangle::getWidth()
{
	return width;
}
long Rectangle::getLength()
{
	return length;
}
void Rectangle::CalcArea()
{
	area = (length * width);
}

int main()
{
	Circle objCircle(1,1,2);

	cout << "Բ��X���� = " << objCircle.GetCenterX() << endl;
	cout << "Բ��Y���� = " << objCircle.GetCenterY() << endl;
	cout << "Բ�İ� �� = " << 2 << endl;
	cout << "Բ�����Ϊ��" << objCircle.getArea() << endl;

	Rectangle objRec(3,4);
	cout << "���εĿ� = " << objRec.getWidth() << endl;
	cout << "���εĳ� = " << objRec.getLength() << endl;
	cout << "���ε����Ϊ��" << objRec.getArea() << endl;

	return 0;
}
