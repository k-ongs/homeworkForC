#include <iostream>
using namespace std; 

class BasicShape
{
	protected:
		double area;		//存储面积 

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
		int centerX;		//圆中心的X坐标 
		int centerY;		//圆中心的Y坐标
		double radius;		//圆的半径 

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

	cout << "圆的X坐标 = " << objCircle.GetCenterX() << endl;
	cout << "圆的Y坐标 = " << objCircle.GetCenterY() << endl;
	cout << "圆的半 径 = " << 2 << endl;
	cout << "圆的面积为：" << objCircle.getArea() << endl;

	Rectangle objRec(3,4);
	cout << "矩形的宽 = " << objRec.getWidth() << endl;
	cout << "矩形的长 = " << objRec.getLength() << endl;
	cout << "矩形的面积为：" << objRec.getArea() << endl;

	return 0;
}
