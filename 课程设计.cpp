#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
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
		int size;
		int index;
		int length;
		student *students;		//学生列表
		void expend();
	public:
		manage(int siset = 5);
		~manage();
		void add(student stu);
		void show();
		void display(int num);
		int search(int num);
		void search(string name);
		void edit(student stu);
		void del(int num);
};

manage::manage(int siset)
{
	ifstream infile("students.txt");
	if(infile)
	{
		infile >> size;
		infile >> index;
		infile >> length;
		students = new student[length];
		for(int i=0; i < index; i++)
		{
			infile >> students[i].num >> students[i].name >> students[i].sex >> students[i].age;
		}
	}else{
		index = 0;
		size = siset;
		length = size;
		students = new student[size];
	}
	return;
}
manage::~manage()
{
	if(index > 0)
	{
		ofstream outfile("students.txt");
		if(outfile)
		{
			outfile << size << " " << index << " " << length << endl;
			for(int i=0; i < index; i++)
			{
				outfile << students[i].num << " " << students[i].name << " " << students[i].sex << " " << students[i].age << endl;
			}
			outfile.close();
		}
	}
}

void manage::expend()
{
	length += size;
	student * tem = new student[length];
	for(int i=0; i <= index; i++)
		tem[i] = students[i];
	delete [] students;
	students = tem;
	return;
}

void manage::add(student stu)
{
	if(search(stu.num) > -1)
	{
		cout << endl << "[系统信息] 添加失败，学号为'" << stu.num << "'的学生已存在！" << endl;
		return;
	}else
	{
		if(index+1 > length)
			expend();
		students[index] = stu;
		for(int i=index-1; i >= 0; i--)
		{
			if(students[i].num > students[i+1].num)
			{
				student tem = students[i];
				students[i] = students[i+1];
				students[i+1] = tem;
			}else
			{
				index++;
				return;
			}
		}
		index++;
	}
	cout << endl << "[系统信息] 添加成功！" << endl; 
	return;
}
int manage::search(int num)
{
	int low = 0 ,high = index, middle;

	while(low < high)
	{
	   middle = (low + high)/2;
       if(num == students[middle].num)
		   return middle;
	   else if(num > students[middle].num)
		   low = middle +1;
	   else if(num < students[middle].num)
		   high = middle;
	}
	return -1;
}
void manage::search(string name)
{
	int n = 0, t=1;
	cout.setf(ios::left);
	for(int i=0; i < index; i++)
	{
		if(students[i].name == name)
		{
			if(t)
			{
				t = 0;
				cout << endl << "[系统信息] 找到名字为'" << name << "'的学生信息如下：" << endl << endl;
				cout << setw(12) << setfill(' ') << "学号" << setw(8) << setfill(' ') << "姓名" << setw(8) << setfill(' ') << "性别" << setw(8) << setfill(' ') << "年龄" << endl;
			}
			n++; 
			cout << setw(12) << setfill(' ') << students[i].num << setw(8) << setfill(' ') << students[i].name << setw(8) << setfill(' ') << students[i].sex << setw(8) << setfill(' ') << students[i].age << endl;
		}
	}
	if(n)
		cout  << endl;
	else
		cout << endl << "[系统信息] 没有找到名字为'" << name << "'的学生信息" <<endl;
	return;
}
void manage::edit(student stu)
{
	int stdId = search(stu.num);
	if(stdId == -1)
	{
		cout << endl << "[系统信息] 修改失败，学号为'" << stu.num << "'的学生不存在！" << endl;
		return;
	}
	students[stdId].name = stu.name;
	students[stdId].sex = stu.sex;
	students[stdId].age = stu.age;
	cout << endl << "[系统信息] 修改成功！" << endl;
	return;
}
void manage::del(int num)
{
	int stdId = search(num);
	if(stdId == -1)
	{
		cout << endl << "[系统信息] 删除失败，学号为'" << num << "'的学生不存在！" << endl;
		return;
	}
	for(int i=0; i < index; i++)
		if(students[i].num == num)
		{
			for(int j=i; j < index-1; j++)
			{
				students[j] = students[j+1];
			}
			break;
		}
	index--;
	cout << endl << "[系统信息] 删除成功！" << endl;
	return ;
} 

void manage::show()
{
	if(index <= 0){
		cout << endl << "[系统信息] 暂无学生信息！" << endl << endl;
		return;
	}
	cout.setf(ios::left);
	cout << endl << "[系统信息] 学生列表如下：" << endl; 
	cout << setw(12) << setfill(' ') << "学号" << setw(8) << setfill(' ') << "姓名" << setw(8) << setfill(' ') << "性别" << setw(8) << setfill(' ') << "年龄" << endl;
	for(int i=0; i < index; i++)
	{
		cout << setw(12) << setfill(' ') << students[i].num << setw(8) << setfill(' ') << students[i].name << setw(8) << setfill(' ') << students[i].sex << setw(8) << setfill(' ') << students[i].age << endl;
	}
	cout << endl;
	return; 
}
void manage::display(int num)
{
	cout << endl << "[系统信息] 查询结果如下：" << endl; 
	cout.setf(ios::left);
	cout << setw(12) << setfill(' ') << students[num].num << setw(8) << setfill(' ') << students[num].name << setw(8) << setfill(' ') << students[num].sex << setw(8) << setfill(' ') << students[num].age << endl << endl;
	return; 
} 

manage manageStudent;

int menu1()
{
	int choice;
	cout << "########################################" << endl;
	cout << "#           学生管理信息系统           #" << endl;
	cout << "#               选择功能               #" << endl;
	cout << "#                                      #" << endl;
	cout << "#             1、信息录入              #" << endl;
	cout << "#             2、查询功能              #" << endl;
	cout << "#             3、修改功能              #" << endl;
	cout << "#             4、删除功能              #" << endl;
	cout << "#             0、退出程序              #" << endl;
	cout << "#                                      #" << endl;
	cout << "########################################" << endl;
	cout << "请选择功能：";
	cin >> choice;
	return choice;
}
void informationEntry()
{
	int choice = 3;
	student studentTem;
	while(choice){
		cout << "####################################" << endl;
		cout << "#           学生信息录入           #" << endl;
		cout << "#             选择功能             #" << endl;
		cout << "#                                  #" << endl;
		cout << "#           1、学生列表            #" << endl;
		cout << "#           2、添加学生            #" << endl;
		cout << "#           0、返回主菜单          #" << endl;
		cout << "#                                  #" << endl;
		cout << "####################################" << endl;
		cout << "请选择功能：";
		cin >> choice;
		switch (choice)
		{		
			case 1:
			{ 
				manageStudent.show();
				break;
			}
			case 2:
			{
				cout << "开始输入学生数据：" << endl; 
				cout << "请输入学号(数字)：";
				cin >> studentTem.num;
				cout << "请输入姓名(字符)：";
				cin >> studentTem.name;
				cout << "请输入性别(男女)：";
				cin >> studentTem.sex;
				cout << "请输入年龄(数字)：";
				cin >> studentTem.age; 
				manageStudent.add(studentTem);	
				break;
			} 
			default:
				break;
		}
	}
}

void informationService()
{
	int choice = 4;
	student studentTem;
	while(choice){
		cout << "####################################" << endl;
		cout << "#           学生信息查询           #" << endl;
		cout << "#             选择功能             #" << endl;
		cout << "#                                  #" << endl;
		cout << "#           1、学生列表            #" << endl;
		cout << "#           2、通过姓名查询        #" << endl;
		cout << "#           3、通过学号查询        #" << endl;
		cout << "#           0、返回主菜单          #" << endl;
		cout << "#                                  #" << endl;
		cout << "####################################" << endl;
		cout << "请选择功能：";
		cin >> choice;
		switch (choice)
		{		
			case 1:
			{ 
				manageStudent.show();
				break;
			}
			case 2:
			{
				string name;
				cout << "请输入需要查询的姓名：";
				cin >> name;
				manageStudent.search(name);
				break;
			}
			case 3:
			{
				int num,stdId;
				cout << "请输入需要查询的学号：";
				cin >> num;
				stdId = manageStudent.search(num); 
				if(stdId == -1)
				{
					cout << endl << "[系统信息] 没有查询到学号为'" << num << "'的学生！" << endl;
				}else{
					manageStudent.display(stdId);
				}
				break;
			} 
			default:
				break;
		}
	}
}
void informationEdit()
{
	int choice = 3;
	student studentTem;
	while(choice){
		cout << "####################################" << endl;
		cout << "#           学生信息修改           #" << endl;
		cout << "#             选择功能             #" << endl;
		cout << "#                                  #" << endl;
		cout << "#           1、学生列表            #" << endl;
		cout << "#           2、修改学生            #" << endl;
		cout << "#           0、返回主菜单          #" << endl;
		cout << "#                                  #" << endl;
		cout << "####################################" << endl;
		cout << "请选择功能：";
		cin >> choice;
		switch (choice)
		{		
			case 1:
			{ 
				manageStudent.show();
				break;
			}
			case 2:
			{
				student studentTem; 
				cout << "请输入需要修改信息的学号：";
				cin >> studentTem.num;
				cout << "请输入姓名(字符)：";
				cin >> studentTem.name;
				cout << "请输入性别(男女)：";
				cin >> studentTem.sex;
				cout << "请输入年龄(数字)：";
				cin >> studentTem.age;
				manageStudent.edit(studentTem);	
				break;
			} 
			default:
				break;
		}
	}
}
void informationDeletion()
{
	int choice = 3;
	student studentTem;
	while(choice){
		cout << "####################################" << endl;
		cout << "#           学生信息删除           #" << endl;
		cout << "#             选择功能             #" << endl;
		cout << "#                                  #" << endl;
		cout << "#           1、学生列表            #" << endl;
		cout << "#           2、删除学生            #" << endl;
		cout << "#           0、返回主菜单          #" << endl;
		cout << "#                                  #" << endl;
		cout << "####################################" << endl;
		cout << "请选择功能：";
		cin >> choice;
		switch (choice)
		{		
			case 1:
			{ 
				manageStudent.show();
				break;
			}
			case 2:
			{
				int num; 
				cout << "请输入需要删除信息的学号：";
				cin >> num;
				manageStudent.del(num);	
				break;
			} 
			default:
				break;
		}
	}
}
int main()
{
	int choice = 5;
	while(choice){
		choice = menu1();
		switch (choice)
		{
			case 1:
				informationEntry();
				break;
			case 2:
				informationService();
				break;
			case 3:
				informationEdit();
				break;
			case 4:
				informationDeletion();
				break; 
			default:
				break;
		}
	}
	return 0;
}
