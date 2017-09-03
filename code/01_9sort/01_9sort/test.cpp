/*
 * ---------------------------------------------------
 *  Copyright (c) 2017 josan All rights reserved.
 * ---------------------------------------------------
 *
 *               �����ߣ� Josan
 *             ����ʱ�䣺 2017/9/3 16:50:31
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "9sortEx.h"
using namespace std;

#define INPUTTEST 0
#define OUTPUTTEST 0
template <typename T>
static void testSort(const string& sortName)
{
	ifstream fin("tinyUnsortedNum.txt");
	//cinbk��Ϊcin����Ķ�ȡ����������ʱ�洢����
	streambuf* cinbk;
	//[old]streambuf* rdbuf(streambuf* newbf);  
	//��������������������µĶ�ȡ�����������ؾɵĻ����� 
	cinbk = cin.rdbuf(fin.rdbuf());
	string str(sortName);
	str += "tinySortedNum.txt";
	ofstream fout(str);
	//coutbk��Ϊcout�����д�뻺��������ʱ�洢����
	streambuf* coutbk;
	coutbk = cout.rdbuf(fout.rdbuf());
	//--------------- start of test --------------
	clock_t t_st, t_ed;
	t_st = clock();
	int n;
	cin >> n;
	T sTiny(n);
	sTiny.sort();
	//sTiny.show();
	t_ed = clock();
	cout << "The time of sort is " << t_ed - t_st << " ms." << endl;

	fin.close();
	fin.open("mediumUnsortedNum.txt");
	fout.close();
	str = sortName;
	str += "mediumSortedNum.txt";
	fout.open(str);
	t_st = clock();
	cin >> n;
	T sMedium(n);
	sMedium.sort();
	//sMedium.show();
	t_ed = clock();
	cout << "The time of sort is " << t_ed - t_st << " ms." << endl;

	fin.close();
	fin.open("largeUnsortedNum.txt");
	fout.close();
	str = sortName;
	str += "largeSortedNum.txt";
	fout.open(str);
	t_st = clock();
	cin >> n;
	T sLarge(n);
	sLarge.sort();
	//sLarge.show();
	t_ed = clock();
	cout << "The time of sort is " << t_ed - t_st << " ms." << endl;
	//--------------- end   of test --------------
	fout.close();
	cout.rdbuf(coutbk);
	fin.close();
	cin.rdbuf(cinbk);
}

static void test()
{
	testSort<insertSortStraight>("insertSortStraight");
	testSort<insertSortShell>("insertSortShell");
	testSort<swapSortBubble>("swapSortBubble");
	testSort<swapSortQuick>("swapSortQuick");
	testSort<selectionSortSimple>("selectionSortSimple");
	testSort<selectionSortHeap>("selectionSortHeap");
	testSort<mergeSort>("mergeSort");
	testSort<countSort>("countSort");
	testSort<radixSort>("radixSort");
}

int main(int argc, char* argv[])
{
#if INPUTTEST
	ifstream fin("tinyUnsortedNum.txt");
	//cinbk��Ϊcin����Ķ�ȡ����������ʱ�洢����
	streambuf* cinbk;
	//[old]streambuf* rdbuf(streambuf* newbf);  
	//��������������������µĶ�ȡ�����������ؾɵĻ����� 
	cinbk = cin.rdbuf(fin.rdbuf());
#endif
#if OUTPUTTEST
	ofstream fout("out.txt");
	//coutbk��Ϊcout�����д�뻺��������ʱ�洢����
	streambuf* coutbk;
	coutbk = cout.rdbuf(fout.rdbuf());
#endif
	//--------------- start of main --------------
	test();
	//--------------- end   of main --------------
#if OUTPUTTEST
	fout.close();
	cout.rdbuf(coutbk);
#endif
#if INPUTTEST
	fin.close();
	cin.rdbuf(cinbk);
#endif	
	return 0;
}
