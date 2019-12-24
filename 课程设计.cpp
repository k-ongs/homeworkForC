#include <iostream>
#include <string>
using namespace std; 

struct student
{
	int num;		//学号
	string name;	//姓名
	string sex;		//性别 
	int age;		//年龄 
};

class manage
{
	private:
		student *students;		//学生列表
	public:
		void add(student stu);
		void show();
		void search(int num);
		void search(string name);
		void edit(int num);
		void del(int num);
};



int main()
{
	student student1;
	student1.name = "周雄";
	cout <<  student1.name;
	return 0;
}
