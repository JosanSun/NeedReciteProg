/*
 * ---------------------------------------------------
 *  Copyright (c) 2017 josan All rights reserved.
 * ---------------------------------------------------
 *
 *               创建者： Josan
 *             创建时间： 2017/9/3 18:04:47
 */
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
	int n[3] = {10, 200, 10000};

	ofstream fout("tinyUnsortedNum.txt");
	//coutbk作为cout对象的写入缓冲区的临时存储对象
	streambuf* coutbk;
	coutbk = cout.rdbuf(fout.rdbuf());
	srand(static_cast<unsigned int>(time(nullptr)));
	int tmp = 0;
	cout << n[0] << endl;
	for(int j = 0; j < n[0]; ++j)
	{
		int num = rand() % 500;
		cout << left << setw(4) << num;
		tmp = (tmp + 1) % 10;
		if(0 == tmp)
		{
			cout << endl;
		}
	}
	fout.close();

	fout.open("mediumUnsortedNum.txt");
	cout.rdbuf(fout.rdbuf());
	tmp = 0;
	cout << n[1] << endl;
	for(int j = 0; j < n[1]; ++j)
	{
		int num = rand() % 500;
		cout << left << setw(4) << num;
		tmp = (tmp + 1) % 10;
		if(0 == tmp)
		{
			cout << endl;
		}
	}
	fout.close();

	fout.open("largeUnsortedNum.txt");
	cout.rdbuf(fout.rdbuf());
	tmp = 0;
	cout << n[2] << endl;
	for(int j = 0; j < n[2]; ++j)
	{
		int num = rand() % 500;
		cout << left << setw(4) << num;
		tmp = (tmp + 1) % 10;
		if(0 == tmp)
		{
			cout << endl;
		}
	}


	fout.close();
	cout.rdbuf(coutbk);
	return 0;
}