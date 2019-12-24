#include <iostream>
#include <cstring>
using namespace std;

class String {
	private:
		char *text;
		int len;
	public:
	    String();
		String(const char *str);
		~String();
		char *get_text(){return text;}//获取字符串
		int get_len(){return len;}//获取字符串长度 
		void printStr(){ cout<<text<<endl; }//输出字符串 
		
		String &Stringcat(String &x);//串对象连接
		String &Stringcpy(String &y);//串对象拷贝
		int Stringcmp(String &z); //串对象比较
		
		String &operator=(String y);
		String &operator+=(String &y);
		String operator+(String &y);
		bool operator>(String &y);
		bool operator<(String &y);
		bool operator==(String &y);
};

String::String()
{
	len = 0;
    text = new char[1];
    *text = '\0';
}

String::String(const char *str)
{
    len = strlen(str);
    text = new char[len + 1];
    strcpy(text, str);
}

String::~String()
{
    delete[] text;
    len = 0;
}

String &String::Stringcat(String &x)
{
	String tem(text);
	len += x.get_len();
	delete[] text;
    text = new char[len + 1];
    strcpy(text, tem.text);
    strcat(text, x.text);
    return *this;
}

String &String::Stringcpy(String &y)
{
	if (this == &y) return *this;

    delete[] text;

    len = y.get_len();
    text = new char[len + 1];
    strcpy(text, y.get_text());

    return *this;
}

int String::Stringcmp(String &z)
{
	return strcmp(text, z.get_text());// 左<右，返回负数
}

String &String::operator=(String y)
{
	if (this == &y) return *this;

    delete[] text;

    len = y.get_len();
    text = new char[len + 1];
    strcpy(text, y.get_text());

    return *this;
} 
String &String::operator+=(String &y)
{
	return Stringcat(y);
}
String String::operator+(String &x)
{
	String tem;
	tem.len = len + x.get_len();
    tem.text = new char[tem.len + 1];
    strcpy(tem.text, text);
    strcat(tem.text, x.text);
    return tem;
}
bool String::operator>(String &y)
{
	if(Stringcmp(y) < 0)
		return false;
	return true;	
}
bool String::operator<(String &y)
{
	if(Stringcmp(y) < 0)
		return true;
	return false;	
}
bool String::operator==(String &y)
{
	if(Stringcmp(y) == 0)
		return true;
	return false;	
}

int main()
{
    char a[] = "Hello", b[] = "World!";
    String s1(a), s2(b), s3;

	cout << "s1=";
    s1.printStr();
    cout << "s2=";
    s2.printStr();
    
    cout << "s3.Stringcat(s1).Stringcat(s2) = ";
    s3.Stringcat(s1).Stringcat(s2).printStr();
    cout << "s3.Stringcpy(s1) = ";
    s3.Stringcpy(s1).printStr();
    
    cout << "s3.Stringcmp(s1) = " << s3.Stringcmp(s1) << endl;
    cout << "s3.Stringcmp(s2) = " << s3.Stringcmp(s2) << endl;
    
    cout << "s1=";
    s1.printStr();
    cout << "s2=";
    s2.printStr();
    
    cout << "s3 = s1 = ";
    s3 = s1;
    s3.printStr();
    cout << "s3 += s2 = ";
    s3 += s2;
    s3.printStr();
    cout << "s3 = s1 + s2 = ";
    s3 = s1 + s2;
    s3.printStr();
    cout << "s1 > s2 = " << (s1 > s2) << endl;
    cout << "s1 < s2 = " << (s1 < s2) << endl;
	cout << "s1 == s2 = " << (s1 == s2) << endl;

}
