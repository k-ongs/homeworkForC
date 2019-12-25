#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
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
		int size;
		int index;
		int length;
		student *students;		//ѧ���б�
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
		cout << endl << "[ϵͳ��Ϣ] ���ʧ�ܣ�ѧ��Ϊ'" << stu.num << "'��ѧ���Ѵ��ڣ�" << endl;
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
	cout << endl << "[ϵͳ��Ϣ] ��ӳɹ���" << endl; 
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
				cout << endl << "[ϵͳ��Ϣ] �ҵ�����Ϊ'" << name << "'��ѧ����Ϣ���£�" << endl << endl;
				cout << setw(12) << setfill(' ') << "ѧ��" << setw(8) << setfill(' ') << "����" << setw(8) << setfill(' ') << "�Ա�" << setw(8) << setfill(' ') << "����" << endl;
			}
			n++; 
			cout << setw(12) << setfill(' ') << students[i].num << setw(8) << setfill(' ') << students[i].name << setw(8) << setfill(' ') << students[i].sex << setw(8) << setfill(' ') << students[i].age << endl;
		}
	}
	if(n)
		cout  << endl;
	else
		cout << endl << "[ϵͳ��Ϣ] û���ҵ�����Ϊ'" << name << "'��ѧ����Ϣ" <<endl;
	return;
}
void manage::edit(student stu)
{
	int stdId = search(stu.num);
	if(stdId == -1)
	{
		cout << endl << "[ϵͳ��Ϣ] �޸�ʧ�ܣ�ѧ��Ϊ'" << stu.num << "'��ѧ�������ڣ�" << endl;
		return;
	}
	students[stdId].name = stu.name;
	students[stdId].sex = stu.sex;
	students[stdId].age = stu.age;
	cout << endl << "[ϵͳ��Ϣ] �޸ĳɹ���" << endl;
	return;
}
void manage::del(int num)
{
	int stdId = search(num);
	if(stdId == -1)
	{
		cout << endl << "[ϵͳ��Ϣ] ɾ��ʧ�ܣ�ѧ��Ϊ'" << num << "'��ѧ�������ڣ�" << endl;
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
	cout << endl << "[ϵͳ��Ϣ] ɾ���ɹ���" << endl;
	return ;
} 

void manage::show()
{
	if(index <= 0){
		cout << endl << "[ϵͳ��Ϣ] ����ѧ����Ϣ��" << endl << endl;
		return;
	}
	cout.setf(ios::left);
	cout << endl << "[ϵͳ��Ϣ] ѧ���б����£�" << endl; 
	cout << setw(12) << setfill(' ') << "ѧ��" << setw(8) << setfill(' ') << "����" << setw(8) << setfill(' ') << "�Ա�" << setw(8) << setfill(' ') << "����" << endl;
	for(int i=0; i < index; i++)
	{
		cout << setw(12) << setfill(' ') << students[i].num << setw(8) << setfill(' ') << students[i].name << setw(8) << setfill(' ') << students[i].sex << setw(8) << setfill(' ') << students[i].age << endl;
	}
	cout << endl;
	return; 
}
void manage::display(int num)
{
	cout << endl << "[ϵͳ��Ϣ] ��ѯ������£�" << endl; 
	cout.setf(ios::left);
	cout << setw(12) << setfill(' ') << students[num].num << setw(8) << setfill(' ') << students[num].name << setw(8) << setfill(' ') << students[num].sex << setw(8) << setfill(' ') << students[num].age << endl << endl;
	return; 
} 

manage manageStudent;

int menu1()
{
	int choice;
	cout << "########################################" << endl;
	cout << "#           ѧ��������Ϣϵͳ           #" << endl;
	cout << "#               ѡ����               #" << endl;
	cout << "#                                      #" << endl;
	cout << "#             1����Ϣ¼��              #" << endl;
	cout << "#             2����ѯ����              #" << endl;
	cout << "#             3���޸Ĺ���              #" << endl;
	cout << "#             4��ɾ������              #" << endl;
	cout << "#             0���˳�����              #" << endl;
	cout << "#                                      #" << endl;
	cout << "########################################" << endl;
	cout << "��ѡ���ܣ�";
	cin >> choice;
	return choice;
}
void informationEntry()
{
	int choice = 3;
	student studentTem;
	while(choice){
		cout << "####################################" << endl;
		cout << "#           ѧ����Ϣ¼��           #" << endl;
		cout << "#             ѡ����             #" << endl;
		cout << "#                                  #" << endl;
		cout << "#           1��ѧ���б�            #" << endl;
		cout << "#           2�����ѧ��            #" << endl;
		cout << "#           0���������˵�          #" << endl;
		cout << "#                                  #" << endl;
		cout << "####################################" << endl;
		cout << "��ѡ���ܣ�";
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
				cout << "��ʼ����ѧ�����ݣ�" << endl; 
				cout << "������ѧ��(����)��";
				cin >> studentTem.num;
				cout << "����������(�ַ�)��";
				cin >> studentTem.name;
				cout << "�������Ա�(��Ů)��";
				cin >> studentTem.sex;
				cout << "����������(����)��";
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
		cout << "#           ѧ����Ϣ��ѯ           #" << endl;
		cout << "#             ѡ����             #" << endl;
		cout << "#                                  #" << endl;
		cout << "#           1��ѧ���б�            #" << endl;
		cout << "#           2��ͨ��������ѯ        #" << endl;
		cout << "#           3��ͨ��ѧ�Ų�ѯ        #" << endl;
		cout << "#           0���������˵�          #" << endl;
		cout << "#                                  #" << endl;
		cout << "####################################" << endl;
		cout << "��ѡ���ܣ�";
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
				cout << "��������Ҫ��ѯ��������";
				cin >> name;
				manageStudent.search(name);
				break;
			}
			case 3:
			{
				int num,stdId;
				cout << "��������Ҫ��ѯ��ѧ�ţ�";
				cin >> num;
				stdId = manageStudent.search(num); 
				if(stdId == -1)
				{
					cout << endl << "[ϵͳ��Ϣ] û�в�ѯ��ѧ��Ϊ'" << num << "'��ѧ����" << endl;
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
		cout << "#           ѧ����Ϣ�޸�           #" << endl;
		cout << "#             ѡ����             #" << endl;
		cout << "#                                  #" << endl;
		cout << "#           1��ѧ���б�            #" << endl;
		cout << "#           2���޸�ѧ��            #" << endl;
		cout << "#           0���������˵�          #" << endl;
		cout << "#                                  #" << endl;
		cout << "####################################" << endl;
		cout << "��ѡ���ܣ�";
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
				cout << "��������Ҫ�޸���Ϣ��ѧ�ţ�";
				cin >> studentTem.num;
				cout << "����������(�ַ�)��";
				cin >> studentTem.name;
				cout << "�������Ա�(��Ů)��";
				cin >> studentTem.sex;
				cout << "����������(����)��";
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
		cout << "#           ѧ����Ϣɾ��           #" << endl;
		cout << "#             ѡ����             #" << endl;
		cout << "#                                  #" << endl;
		cout << "#           1��ѧ���б�            #" << endl;
		cout << "#           2��ɾ��ѧ��            #" << endl;
		cout << "#           0���������˵�          #" << endl;
		cout << "#                                  #" << endl;
		cout << "####################################" << endl;
		cout << "��ѡ���ܣ�";
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
				cout << "��������Ҫɾ����Ϣ��ѧ�ţ�";
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
