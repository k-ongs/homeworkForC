#include <iostream>
#include <string>
using namespace std; 

struct student
{
	int num;		//ѧ��
	string name;	//����
	string sex;		//�Ա� 
	int age;		//���� 
};

class manage
{
	private:
		student *students;		//ѧ���б�
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
	student1.name = "����";
	cout <<  student1.name;
	return 0;
}
