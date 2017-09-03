/*
 * ---------------------------------------------------
 *  Copyright (c) 2017 josan All rights reserved.
 * ---------------------------------------------------
 *
 *               创建者： Josan
 *             创建时间： 2017/9/2 21:10:10
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include "02UF.h"
 //输入测试控制开关
#define INPUTTEST 1
 //输出测试控制开关
#define OUTPUTTEST 1
using namespace std;

static void testUFQuickFind()
{
#if OUTPUTTEST
	ofstream fout("outUFQuickFind.txt");
	//coutbk作为cout对象的写入缓冲区的临时存储对象
	streambuf* coutbk;
	coutbk = cout.rdbuf(fout.rdbuf());
#endif 
	//测试tinyUF.txt
	ifstream fin("tinyUF.txt");
	//cinbk作为cin对象的读取缓冲区的临时存储对象
	streambuf* cinbk;
	//[old]streambuf* rdbuf(streambuf* newbf);  
	//调用这个方法可以设置新的读取缓冲区，返回旧的缓冲区 
	cinbk = cin.rdbuf(fin.rdbuf());
	//--------- start of program -------------
	clock_t t_st, t_ed;
	t_st = clock();
	int n;
	int p, q;
	cin >> n;
	UFQuickFind uf(n);
	while(cin >> p >> q)
	{
		if(uf.connected(p, q))
		{
			continue;
		}
		uf.unionOp(p, q);
		////cout << p << "  " << q << endl;
	}
	cout << uf.count() << " components" << endl;
	t_ed = clock();
	cout << "The time of copy with tinyUF.txt is " << t_ed - t_st << " ms." << endl;

	//测试mediumUF.txt
	cout << "-----------------------------------" << endl;
	cin.clear();
	ifstream fin1("mediumUF.txt");
	cin.rdbuf(fin1.rdbuf());
	t_st = clock();
	cin >> n;
	UFQuickFind uf1(n);
	while(cin >> p >> q)
	{
		if(uf1.connected(p, q))
		{
			continue;
		}
		uf1.unionOp(p, q);
		////cout << p << "  " << q << endl;
	}
	cout << uf1.count() << " components" << endl;
	t_ed = clock();
	cout << "The time of copy with mediumUF.txt is " << t_ed - t_st << " ms." << endl;

	//测试largeUF.txt
	cout << "-----------------------------------" << endl;
	cin.clear();
	ifstream fin2("largeUF.txt");
	cin.rdbuf(fin2.rdbuf());
	t_st = clock();
	cin >> n;
	UFQuickFind uf2(n);
	while(cin >> p >> q)
	{
		if(uf2.connected(p, q))
		{
			continue;
		}
		uf2.unionOp(p, q);
		////cout << p << "  " << q << endl;
	}
	cout << uf2.count() << " components" << endl;
	t_ed = clock();
	cout << "The time of copy with largeUF.txt is " << t_ed - t_st << " ms." << endl;

	//--------- end of program -------------
	fin.close();
	fin1.close();
	//fin2.close();
	cin.clear();
	cin.rdbuf(cinbk);
#if OUTPUTTEST
	fout.close();
	cout.rdbuf(coutbk);
#endif
}

static void testUFQuickUnion()
{
#if OUTPUTTEST
	ofstream fout("outUFQuickUnion.txt");
	//coutbk作为cout对象的写入缓冲区的临时存储对象
	streambuf* coutbk;
	coutbk = cout.rdbuf(fout.rdbuf());
#endif 
	//测试tinyUF.txt
	ifstream fin("tinyUF.txt");
	//cinbk作为cin对象的读取缓冲区的临时存储对象
	streambuf* cinbk;
	//[old]streambuf* rdbuf(streambuf* newbf);  
	//调用这个方法可以设置新的读取缓冲区，返回旧的缓冲区 
	cinbk = cin.rdbuf(fin.rdbuf());
	//--------- start of program -------------
	clock_t t_st, t_ed;
	t_st = clock();
	int n;
	int p, q;
	cin >> n;
	UFQuickUnion uf(n);
	while(cin >> p >> q)
	{
		if(uf.connected(p, q))
		{
			continue;
		}
		uf.unionOp(p, q);
		////cout << p << "  " << q << endl;
	}
	cout << uf.count() << " components" << endl;
	t_ed = clock();
	cout << "The time of copy with tinyUF.txt is " << t_ed - t_st << " ms." << endl;

	//测试mediumUF.txt
	cout << "-----------------------------------" << endl;
	cin.clear();
	ifstream fin1("mediumUF.txt");
	cin.rdbuf(fin1.rdbuf());
	t_st = clock();
	cin >> n;
	UFQuickUnion uf1(n);
	while(cin >> p >> q)
	{
		if(uf1.connected(p, q))
		{
			continue;
		}
		uf1.unionOp(p, q);
		////cout << p << "  " << q << endl;
	}
	cout << uf1.count() << " components" << endl;
	t_ed = clock();
	cout << "The time of copy with mediumUF.txt is " << t_ed - t_st << " ms." << endl;

	//测试largeUF.txt
	cout << "-----------------------------------" << endl;
	cin.clear();
	ifstream fin2("largeUF.txt");
	cin.rdbuf(fin2.rdbuf());
	t_st = clock();
	cin >> n;
	UFQuickUnion uf2(n);
	while(cin >> p >> q)
	{
		if(uf2.connected(p, q))
		{
			continue;
		}
		uf2.unionOp(p, q);
		////cout << p << "  " << q << endl;
	}
	cout << uf2.count() << " components" << endl;
	t_ed = clock();
	cout << "The time of copy with largeUF.txt is " << t_ed - t_st << " ms." << endl;

	//--------- end of program -------------
	fin.close();
	fin1.close();
	//fin2.close();
	cin.clear();
	cin.rdbuf(cinbk);
#if OUTPUTTEST
	fout.close();
	cout.rdbuf(coutbk);
#endif
}

static void testWeightedUFQuickUnion()
{
#if OUTPUTTEST
	ofstream fout("outWeightedUFQuickUnion.txt");
	//coutbk作为cout对象的写入缓冲区的临时存储对象
	streambuf* coutbk;
	coutbk = cout.rdbuf(fout.rdbuf());
#endif 
	//测试tinyUF.txt
	ifstream fin("tinyUF.txt");
	//cinbk作为cin对象的读取缓冲区的临时存储对象
	streambuf* cinbk;
	//[old]streambuf* rdbuf(streambuf* newbf);  
	//调用这个方法可以设置新的读取缓冲区，返回旧的缓冲区 
	cinbk = cin.rdbuf(fin.rdbuf());
	//--------- start of program -------------
	clock_t t_st, t_ed;
	t_st = clock();
	int n;
	int p, q;
	cin >> n;
	
	WeightedUFQuickUnion uf(n);
	while(cin >> p >> q)
	{
		if(uf.connected(p, q))
		{
			continue;
		}
		uf.unionOp(p, q);
		////cout << p << "  " << q << endl;
	}
	cout << uf.count() << " components" << endl;
	t_ed = clock();
	cout << "The time of copy with tinyUF.txt is " << t_ed - t_st << " ms." << endl;

	//测试mediumUF.txt
	cout << "-----------------------------------" << endl;
	cin.clear();
	ifstream fin1("mediumUF.txt");
	cin.rdbuf(fin1.rdbuf());
	t_st = clock();
	cin >> n;
	WeightedUFQuickUnion uf1(n);
	while(cin >> p >> q)
	{
		if(uf1.connected(p, q))
		{
			continue;
		}
		uf1.unionOp(p, q);
		//cout << p << "  " << q << endl;
	}
	cout << uf1.count() << " components" << endl;
	t_ed = clock();
	cout << "The time of copy with mediumUF.txt is " << t_ed - t_st << " ms." << endl;

	//测试largeUF.txt
	cout << "-----------------------------------" << endl;
	cin.clear();
	ifstream fin2("largeUF.txt");
	cin.rdbuf(fin2.rdbuf());
	t_st = clock();
	cin >> n;
	WeightedUFQuickUnion uf2(n);
	while(cin >> p >> q)
	{
		if(uf2.connected(p, q))
		{
			continue;
		}
		uf2.unionOp(p, q);
		//cout << p << "  " << q << endl;
	}
	cout << uf2.count() << " components" << endl;
	t_ed = clock();
	cout << "The time of copy with largeUF.txt is " << t_ed - t_st << " ms." << endl;

	//--------- end of program -------------
	fin.close();
	fin1.close();
	//fin2.close();
	cin.clear();
	cin.rdbuf(cinbk);
#if OUTPUTTEST
	fout.close();
	cout.rdbuf(coutbk);
#endif
}

static void testPathCompressWeightedUFQuickUnion()
{
#if OUTPUTTEST
	ofstream fout("outPathCompressWeightedUFQuickUnion.txt");
	//coutbk作为cout对象的写入缓冲区的临时存储对象
	streambuf* coutbk;
	coutbk = cout.rdbuf(fout.rdbuf());
#endif 
	//测试tinyUF.txt
	ifstream fin("tinyUF.txt");
	//cinbk作为cin对象的读取缓冲区的临时存储对象
	streambuf* cinbk;
	//[old]streambuf* rdbuf(streambuf* newbf);  
	//调用这个方法可以设置新的读取缓冲区，返回旧的缓冲区 
	cinbk = cin.rdbuf(fin.rdbuf());
	//--------- start of program -------------
	clock_t t_st, t_ed;
	t_st = clock();
	int n;
	int p, q;
	cin >> n;

	PathCompressWeightedUFQuickUnion uf(n);
	while(cin >> p >> q)
	{
		if(uf.connected(p, q))
		{
			continue;
		}
		uf.unionOp(p, q);
		//cout << p << "  " << q << endl;
	}
	cout << uf.count() << " components" << endl;
	t_ed = clock();
	cout << "The time of copy with tinyUF.txt is " << t_ed - t_st << " ms." << endl;

	//测试mediumUF.txt
	cout << "-----------------------------------" << endl;
	cin.clear();
	ifstream fin1("mediumUF.txt");
	cin.rdbuf(fin1.rdbuf());
	t_st = clock();
	cin >> n;
	PathCompressWeightedUFQuickUnion uf1(n);
	while(cin >> p >> q)
	{
		if(uf1.connected(p, q))
		{
			continue;
		}
		uf1.unionOp(p, q);
		//cout << p << "  " << q << endl;
	}
	cout << uf1.count() << " components" << endl;
	t_ed = clock();
	cout << "The time of copy with mediumUF.txt is " << t_ed - t_st << " ms." << endl;

	//测试largeUF.txt
	cout << "-----------------------------------" << endl;
	cin.clear();
	ifstream fin2("largeUF.txt");
	cin.rdbuf(fin2.rdbuf());
	t_st = clock();
	cin >> n;
	PathCompressWeightedUFQuickUnion uf2(n);
	while(cin >> p >> q)
	{
		if(uf2.connected(p, q))
		{
			continue;
		}
		uf2.unionOp(p, q);
		//cout << p << "  " << q << endl;
	}
	cout << uf2.count() << " components" << endl;
	t_ed = clock();
	cout << "The time of copy with largeUF.txt is " << t_ed - t_st << " ms." << endl;

	//--------- end of program -------------
	fin.close();
	fin1.close();
	//fin2.close();
	cin.clear();
	cin.rdbuf(cinbk);
#if OUTPUTTEST
	fout.close();
	cout.rdbuf(coutbk);
#endif
}


int main()
{
	//-----------主程序-----------------
	testUFQuickFind();
	testUFQuickUnion();
	testWeightedUFQuickUnion();
	testPathCompressWeightedUFQuickUnion();
	return 0;
}

