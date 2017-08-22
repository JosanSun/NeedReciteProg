#define _CRT_SECURE_NO_WARNINGS
/*
 * ---------------------------------------------------
 *  Copyright (c) 2017 josan All rights reserved.
 * ---------------------------------------------------
 *
 *               创建者： Josan
 *             创建时间： 2017/8/22 9:23:18
 */
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

void print(int* a, int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << setw(4) << a[i];
	}
	cout << endl;
}

int main()
{
	freopen("out.txt", "w", stdout);
	void insertSortStraight(int*, int);
	void insertSortShell(int*, int);
	void swapSortBubble(int*, int);
	void swapSortQuick(int*, int);
	void selectionSortSimple(int*, int);
	void selectionSortHeap(int*, int);


	srand((unsigned int)time(nullptr));
	int n = rand() % 100;
	int* a = new int[n];
	for(int i = 0; i < n; ++i)
	{
		a[i] = rand() % 100;
	}
	cout << "The origin array: \n";
	print(a, n);
	insertSortStraight(a, n);
	cout << "After insertSortStraight, the array is \n";
	print(a, n);

	cout << endl << endl;
	for(int i = 0; i < n; ++i)
	{
		a[i] = rand() % 100;
	}
	cout << "The origin array: ";
	print(a, n);
	insertSortShell(a, n);
	cout << "After insertSortShell, the array is ";
	print(a, n);

	cout << endl << endl;
	for(int i = 0; i < n; ++i)
	{
		a[i] = rand() % 100;
	}
	cout << "The origin array: ";
	print(a, n);
	swapSortBubble(a, n);
	cout << "After swapSortBubble, the array is ";
	print(a, n);

	cout << endl << endl;
	for(int i = 0; i < n; ++i)
	{
		a[i] = rand() % 100;
	}
	cout << "The origin array: ";
	print(a, n);
	swapSortQuick(a, n);
	cout << "After swapSortQuick, the array is ";
	print(a, n);

	cout << endl << endl;
	for(int i = 0; i < n; ++i)
	{
		a[i] = rand() % 100;
	}
	cout << "The origin array: ";
	print(a, n);
	selectionSortSimple(a, n);
	cout << "After selectionSortSimple, the array is ";
	print(a, n);

	cout << endl << endl;
	for(int i = 0; i < n; ++i)
	{
		a[i] = rand() % 100;
	}
	cout << "The origin array: ";
	print(a, n);
	selectionSortHeap(a, n);
	cout << "After selectionSortHeap, the array is ";
	print(a, n);

	delete[] a;
	return 0;
}

void insertSortStraight(int* a, int n)
{
	for(int i = 1; i < n; ++i)
	{
		int tem = a[i];
		int j = i;
		for(; 1 <= j&&tem < a[j - 1]; --j)
		{
			a[j] = a[j - 1];
		}
		a[j] = tem;
	}
}

void insertSortShell(int* a, int n)
{
	for(int step = (n >> 1); 1 <= step; step >>= 1)
	{
		for(int st = 0; st < step; ++st)
		{
			for(int i = st + step; i < n; i+=step)
			{
				int tem = a[i];
				int j = i;
				for(; st + step <= j&&tem < a[j - step]; j -= step)
				{
					a[j] = a[j - step];
				}
				a[j] = tem;
			}
		}
	}
}

void swapSortBubble(int* a, int n)
{
	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < n - i; ++j)
		{
			if(a[j + 1] < a[j])
			{
				int tem = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tem;
			}
		}
	}
}

static int Partition(int* a, int st, int ed)
{
	int tem = a[st];
	while(st < ed)
	{
		while(st < ed&&tem <= a[ed])
		{
			--ed;
		}
		a[st] = a[ed];
		while(st < ed&&a[st] <= tem)
		{
			++st;
		}
		a[ed] = a[st];
	}
	a[st] = tem;
	return st;
}

static void swapSortQuickInner(int* a, int st, int ed)
{
	if(ed - st < 2)
	{
		return;
	}
	int pos = Partition(a, st, ed - 1);
	swapSortQuickInner(a, st, pos);
	swapSortQuickInner(a, pos + 1, ed);
}

void swapSortQuick(int * a, int n)
{
	swapSortQuickInner(a, 0, n);
}

void selectionSortSimple(int* a, int n)
{
	for(int i = 0; i < n - 1; ++i)
	{
		int minIdx = i;
		for(int j = i + 1; j < n; ++j)
		{
			if(a[j] < a[minIdx])
			{
				minIdx = j;
			}
		}
		if(minIdx != i)
		{
			int tem = a[minIdx];
			a[minIdx] = a[i];
			a[i] = tem;
		}
	}
}

void heapAdjust(int* a, int n, int pos)
{
	int tem = a[pos];
	int i = pos;
	for(int j = pos * 2 + 1; j < n; j = j * 2 + 1)
	{
		if(j + 1 < n&&a[j] < a[j + 1])
		{
			++j;
		}
		if(tem >= a[j])
		{
			break;
		}
		else
		{
			a[i] = a[j];
			i = j;
		}
	}
	a[i] = tem;
}

static void createHeap(int* a, int n)
{
	for(int i = (n - 1) / 2; 0 <= i; --i)
	{
		heapAdjust(a, n, i);
	}
}

void selectionSortHeap(int* a, int n)
{
	createHeap(a, n);
	for(int i = n - 1; 0 < i; --i)
	{
		int tem = a[0];
		a[0] = a[i];
		a[i] = tem;
		heapAdjust(a, i, 0);
	}
}