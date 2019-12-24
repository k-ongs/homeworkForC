#include <iostream>
using namespace std;
class Tdate{              //类定义
	private: 
		int year,month,day;
		int days[13];
	public:
		Tdate();						//构造函数 
		Tdate(int,int,int);
		Tdate(Tdate& x); 
		void setdate(int,int,int);
		void display( );
		Tdate tomorrow( ); //求明天
		bool isleap( );   //是否是闰年
		Tdate yesterday();//求昨天
		Tdate addn(int  n);//加上n天
		int totalday  ( );//求总天数
		int  subdate(Tdate t);//日期相减
		int countDays();
		Tdate operator ++(int);
		Tdate operator --(int);
		Tdate operator+(int n);
		Tdate operator-(int n);
		int operator-(Tdate &t);
};

Tdate::Tdate()
{
	setdate(2000,9,9);
}
Tdate::Tdate(int Y,int M,int D)
{
	setdate(Y,M,D);
}
Tdate::Tdate(Tdate& x)
{
	setdate(x.year, x.month, x.day);
}
void Tdate::setdate(int Y,int M,int D)
{
	days[1] = days[3] = days[5] = days[7] = days[8] = days[10] = days[12] = 31;
	days[4] = days[6] = days[9] = days[11] = 30;
	year = Y;
	if(isleap())
		days[2] = 29;
	else
		days[2] = 28;
	month = M > 12 || M < 1 ? 1 : M;
	day = D > days[month] || D < 1 ? 1 : D;
}

void Tdate::display()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}
Tdate Tdate::tomorrow()//求明天
{
	if(day+1 <= days[month])
	{
		Tdate tem(year, month, day+1);
		return tem;
	}
		
	
	if(month+1 < 12)
	{
		Tdate tem(year, month+1, 1);
		return tem;
	}

	Tdate tem(year+1, 1, 1);
	return tem;
}
bool Tdate::isleap()
{
	if(year%4==0 && year%100!=0 || year%400==0)
		return true;
	else
		return false;
}
Tdate Tdate::yesterday()//求昨天
{
	if(day-1 > 0)
	{
		Tdate tem(year, month, day-1);
		return tem;
	}
		

	if(month-1 > 0)
	{
		Tdate tem(year, month-1, days[month-1]);
		return tem;
	}
	
	Tdate tem(year-1, 12, 31);
	return tem;
}
Tdate Tdate::addn(int n)//加上n天
{
	if(n>0)
	{
		while(day+n > days[month])
		{
			n = n - (days[month] - day) - 1;
			day = 1;
			if(month+1 <= 12)
				month++;
			else
			{
				month = 1;
				year++;
				if(isleap())
					days[2] = 29;
				else
					days[2] = 28;
			}
		}
		day = day+n;

		return *this;
	}else
	{
		//9-9    n=-40
		//9 -40  -31
		//8 31	 n=-31
		//7 31
		while(day+n <= 0)
		{
			
			n = day + n;
			if(month-1 >= 0)
				month--;
			else
			{
				month = 12;
				year--;
				if(isleap())
					days[2] = 29;
				else
					days[2] = 28;
			}
			day = days[month];
		}
		day = day+n;
		
		return *this;
	}
}
int Tdate::totalday()//求总天数
{
	int n=0,i;
	for(i=1; i<= month;i++)
		n+=days[i];
	n = n + day;
	return n;
}
int Tdate::subdate(Tdate t)
{
	int sum=0, t1 ,t2, start, end;
	if(year < t.year)
	{
		start = year+1;
		end = t.year;
	}else
	{
		end = year;
		start = t.year + 1;
	}

	for(int y=start; y<=end; y++)
	{
		if(y%4==0 && y%100!=0 || y%400==0)
			sum += 366;
		else
			sum += 365;
	}
 	
	if(year < t.year)
	{
		if(isleap())
			t1 = totalday();
		else
			t1 = totalday() + 1;
		
		if(t.isleap())
			t2 = t.totalday() - 1;
		else
			t2 = t.totalday();
			
		sum += t2 - t1;
	}else{
		if(isleap())
			t1 = totalday() - 1;
		else
			t1 = totalday();
		
		if(t.isleap())
			t2 = t.totalday();
		else
			t2 = t.totalday() + 1;
			
		sum += t1 - t2;
	}
	
	return sum;
}

Tdate Tdate::operator ++(int)
{
	if(day+1 <= days[month])
	{
		day++;
		return *this;
	}
		
	
	if(month+1 < 12)
	{
		month++;
		day = 1;
		return *this;
	}
	year++;
	month = 1;
	day = 1;
	Tdate tem(year+1, 1, 1);
	return *this;
}
Tdate Tdate::operator --(int)
{
	if(day-1 > 0)
	{
		day--;
		return *this;
	}

	if(month-1 > 0)
	{
		month--;
		day = days[month];
		return *this;
	}
	
	year--;
	month = 12;
	day = 31;

	return *this;
}
Tdate Tdate::operator+(int n)
{
	if(n>0){
		while(day+n > days[month])
		{
			n = n - (days[month] - day) - 1;
			day = 1;
			if(month+1 <= 12)
				month++;
			else
			{
				month = 1;
				year++;
				if(isleap())
					days[2] = 29;
				else
					days[2] = 28;
			}
		}
		day = day+n;
	}
	return *this;
}
Tdate Tdate::operator-(int n)
{
	if(n>0){
		n = n * -1;
		while(day+n <= 0)
		{
			
			n = day + n;
			if(month-1 >= 0)
				month--;
			else
			{
				month = 12;
				year--;
				if(isleap())
					days[2] = 29;
				else
					days[2] = 28;
			}
			day = days[month];
		}
		day = day+n;
	}
	return *this;
}
int Tdate::operator-(Tdate &t)
{
	int sum=0, t1 ,t2, start, end;
	if(year < t.year)
	{
		start = year+1;
		end = t.year;
	}else
	{
		end = year;
		start = t.year + 1;
	}

	for(int y=start; y<=end; y++)
	{
		if(y%4==0 && y%100!=0 || y%400==0)
			sum += 366;
		else
			sum += 365;
	}
 	
	if(year < t.year)
	{
		if(isleap())
			t1 = totalday();
		else
			t1 = totalday() + 1;
		
		if(t.isleap())
			t2 = t.totalday() - 1;
		else
			t2 = t.totalday();
			
		sum += t2 - t1;
	}else{
		if(isleap())
			t1 = totalday() - 1;
		else
			t1 = totalday();
		
		if(t.isleap())
			t2 = t.totalday();
		else
			t2 = t.totalday() + 1;
			
		sum += t1 - t2;
	}
	
	return sum;
}


int main() {
	Tdate date1(2001,9,9),date2(2001,9,9);
	date1.display();
	date1.tomorrow().display();
	date1.yesterday().display();
	date1--.display();
	date1++.display();
	date1.addn(5000).display();
	(date1 + 2500).display();
	(date1 - 2500).display();
	cout << date2 - date1 << endl;
	cout << date1.subdate(date2) << endl;
	return 0;
}
