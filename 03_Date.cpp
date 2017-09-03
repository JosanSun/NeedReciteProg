/*
 * ---------------------------------------------------
 *  Copyright (c) 2017 josan All rights reserved.
 * ---------------------------------------------------
 *
 *               �����ߣ� Josan
 *             ����ʱ�䣺 2017/9/3 21:16:39
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ISYEAR(x) (((x % 100 != 0 && x % 4 == 0)||(x % 400 == 0)) ? 1 : 0)

const int dayOfMonth[13][2] = {
	{0, 0},
	{31, 31},
	{28, 29},
	{31, 31},
	{30, 30},
	{31, 31},
	{30, 30},
	{31, 31},
	{31, 31},
	{30, 30},
	{31, 31},
	{30, 30},
	{31, 31}
};

const string monthName[13] = {
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"Auguest",
	"September",
	"October",
	"November",
	"December"
};

const string weekName[7] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};

//����Ԥ���������
int buf[5001][13][32];

class myDate
{
public:
	myDate(int d, int m, int y) :day(d), month(m), year(y)
	{

	}
	void operator++();
	int getDay()const
	{
		return day;
	}
	int getMon()const
	{
		return month;
	}
	int getYear()const
	{
		return year;
	}
private:
	int day;
	int month;
	int year;
};

void myDate::operator++()
{
	++day;
	if(day > dayOfMonth[month][ISYEAR(year)])
	{
		day = 1;
		++month;
		if(12 < month)
		{
			month = 1;
			++year;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	myDate tmp(0, 1, 1);
	int cnt = 0;
	while(5001 != tmp.getYear())
	{
		buf[tmp.getYear()][tmp.getMon()][tmp.getDay()] = cnt++;
		++tmp;
	}
	int d1, m1, y1;
	int d2, m2, y2;
	while(cin >> y1 >> m1 >> d1)
	{
		cin >> y2 >> m2 >> d2;
		cout << abs(buf[y2][m2][d2] - buf[y1][m1][d1]) + 1 << endl;
	}
	return 0;
}

/*
http://ac.jobdu.com/problem.php?pid=1096
��Ŀ������
���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ����
���룺
�ж������ݣ�ÿ�����������У��ֱ��ʾ�������ڣ���ʽΪYYYYMMDD
�����
ÿ���������һ�У������ڲ�ֵ
�������룺
20110412
20110422
���������
11
*/


int main01()
{
	freopen("in01.txt", "r", stdin);
	myDate tmp(0, 1, 1);
	int cnt = 0;
	while(5001 != tmp.getYear())
	{
		buf[tmp.getYear()][tmp.getMon()][tmp.getDay()] = cnt++;
		++tmp;
	}
	int d1, y1;
	string m1;
	int mon;
	while(cin >> d1 >> m1 >> y1)
	{
		for(mon = 1; mon < 13; ++mon)
		{
			if(monthName[mon] == m1)
			{
				break;
			}
		}
		int days = buf[y1][mon][d1] - buf[2017][9][3];
		days += 7;
		//���������������ͳһ�����Ʋ����˼ά
		cout << weekName[(days % 7 + 7) % 7] << endl;   
	}
	return 0;
}

/*
http://ac.jobdu.com/problem.php?pid=1043
��Ŀ������
We now use the Gregorian style of dating in Russia. The leap years are years with number divisible by 4 but not divisible by 100, or divisible by 400.
For example, years 2004, 2180 and 2400 are leap. Years 2004, 2181 and 2300 are not leap.
Your task is to write a program which will compute the day of week corresponding to a given date in the nearest past or in the future using today��s agreement about dating.
���룺
There is one single line contains the day number d, month name M and year number y(1000��y��3000). The month name is the corresponding English name starting from the capital letter.
�����
Output a single line with the English name of the day of week corresponding to the date, starting from the capital letter. All other letters must be in lower case.
�������룺
9 October 2001
14 October 2001
���������
Tuesday
Sunday
��ʾ��
Month and Week name in Input/Output:
January, February, March, April, May, June, July, August, September, October, November, December
Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
*/