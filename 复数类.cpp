#include <iostream>
using namespace std;
class complex
{
	private:
		double real;
		double image;
	public:
		complex(double r,double i);
		complex operator+(const complex &c);
		complex operator-(const complex &c);
		complex operator*(const complex &c);
		complex operator/(const complex &c);
		bool operator==(const complex &c);

		void display();
};

complex::complex(double r = 0.0, double i = 0.0)
{
	real = r;
	image = i;
}
 
//�ӷ�����: (real1 + image1i) + (real2 + image2i) = (real1 + real2) + (image1 + image2)i;
complex complex:: operator + (const complex &c)
{
	complex tmp;
	tmp.real = real + c.real;
	tmp.image = image + c.image;
	return tmp;
}
 
//��������: (real1 + image1i) - (real2 + image2i) = (real1 - real2) + (image1 - image2)i;
complex complex::operator - (const complex &c)
{
	complex tmp;
	tmp.real = real - c.real;
	tmp.image = image - c.image;
	return tmp;
}
 
//�˷�����:(real1 + image1i) * (real2 + image2i) = (real1*real2 - image1*image2) + (image1*real2 + real1*image2)i
complex complex::operator*(const complex &c)
{
	complex tmp;
	tmp.real = real*c.real - image*c.image;
	tmp.image = image*c.real + real*c.image;
	return tmp;
}

//��������: (real1 + image1i) / (real2 + image2i) = [(real1*real2 + image1*image2) / (real2^2 + image2^2)] + [(image1*real2 - real1*image2) / (real2^2 + image2^2)]i
complex complex::operator/(const complex &c)
{
	complex tmp; 
	tmp.real =  (real * c.real + image*c.image) / (c.real*c.real + c.image*c.image);//deno*((real*c.real) + (image*c.image));
	tmp.image = (image*c.real - real*c.image) / (c.real*c.real + c.image*c.image);
	return tmp;
}

bool complex::operator==(const complex &c)
{
	return (real == c.real) && (image == c.image);
}

void complex::display()
{
	cout << real;
	if(image >= 0)
		cout << " + " << image;
	else
		cout << " - " << -image;
	cout << "i" << endl;
}

int main() {
	complex c1(14.0, 12.0);
	complex c2(4.0, 2.0);
	complex ret;

	cout << "c1 = ";
	c1.display();//���c1+c2 
	cout << "c2 = "; 
	c2.display();

	cout << "c1 + c2 =";
	ret = c1 + c2;
	ret.display();
	
	cout << "c1 - c2 =";
	ret = c1 - c2;
	ret.display();
	
	cout << "c1 * c2 =";
	ret = c1 * c2;
	ret.display();
	
	cout << "c1 / c2 =";
	ret = c1 / c2;
	ret.display();

	return 0;
}
