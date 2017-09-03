/*
 * ---------------------------------------------------
 *  Copyright (c) 2017 josan All rights reserved.
 * ---------------------------------------------------
 *
 *               �����ߣ� Josan
 *             ����ʱ�䣺 2017/9/2 21:10:10
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include "02UF.h"
 //������Կ��ƿ���
#define INPUTTEST 1
 //������Կ��ƿ���
#define OUTPUTTEST 1
using namespace std;

static void testUFQuickFind()
{
#if OUTPUTTEST
	ofstream fout("outUFQuickFind.txt");
	//coutbk��Ϊcout�����д�뻺��������ʱ�洢����
	streambuf* coutbk;
	coutbk = cout.rdbuf(fout.rdbuf());
#endif 
	//����tinyUF.txt
	ifstream fin("tinyUF.txt");
	//cinbk��Ϊcin����Ķ�ȡ����������ʱ�洢����
	streambuf* cinbk;
	//[old]streambuf* rdbuf(streambuf* newbf);  
	//��������������������µĶ�ȡ�����������ؾɵĻ����� 
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

	//����mediumUF.txt
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

	//����largeUF.txt
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
	//coutbk��Ϊcout�����д�뻺��������ʱ�洢����
	streambuf* coutbk;
	coutbk = cout.rdbuf(fout.rdbuf());
#endif 
	//����tinyUF.txt
	ifstream fin("tinyUF.txt");
	//cinbk��Ϊcin����Ķ�ȡ����������ʱ�洢����
	streambuf* cinbk;
	//[old]streambuf* rdbuf(streambuf* newbf);  
	//��������������������µĶ�ȡ�����������ؾɵĻ����� 
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

	//����mediumUF.txt
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

	//����largeUF.txt
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
	//coutbk��Ϊcout�����д�뻺��������ʱ�洢����
	streambuf* coutbk;
	coutbk = cout.rdbuf(fout.rdbuf());
#endif 
	//����tinyUF.txt
	ifstream fin("tinyUF.txt");
	//cinbk��Ϊcin����Ķ�ȡ����������ʱ�洢����
	streambuf* cinbk;
	//[old]streambuf* rdbuf(streambuf* newbf);  
	//��������������������µĶ�ȡ�����������ؾɵĻ����� 
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

	//����mediumUF.txt
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

	//����largeUF.txt
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
	//coutbk��Ϊcout�����д�뻺��������ʱ�洢����
	streambuf* coutbk;
	coutbk = cout.rdbuf(fout.rdbuf());
#endif 
	//����tinyUF.txt
	ifstream fin("tinyUF.txt");
	//cinbk��Ϊcin����Ķ�ȡ����������ʱ�洢����
	streambuf* cinbk;
	//[old]streambuf* rdbuf(streambuf* newbf);  
	//��������������������µĶ�ȡ�����������ؾɵĻ����� 
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

	//����mediumUF.txt
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

	//����largeUF.txt
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
	//-----------������-----------------
	testUFQuickFind();
	testUFQuickUnion();
	testWeightedUFQuickUnion();
	testPathCompressWeightedUFQuickUnion();
	return 0;
}

