/*
 * ---------------------------------------------------
 *  Copyright (c) 2017 josan All rights reserved.
 * ---------------------------------------------------
 *
 *               创建者： Josan
 *             创建时间： 2017/9/3 15:28:42
 */
#include <iostream>
#include <vector>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <queue>
#include <functional>
#include <cassert>
#include "9sortEx.h"
using namespace std;

sortEx::sortEx(int n /* = 0 */)
{
	assert(0 <= n);
	a.resize(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
}

void sortEx::exch(int i, int j)
{
	Comparable tmp;
	tmp = a[i];
	a[i] = a[j];
}

bool sortEx::isSorted()const
{
	int n = static_cast<int>(a.size());
	for(int i = 1; i < n; ++i)
	{
		if(a[i - 1] > a[i])
		{
			return false;
		}
	}
	return true;
}

void sortEx::show()const
{
	assert(isSorted());
	int n = static_cast<int>(a.size());
	int sz = 0;
	for(int i = 0; i < n; ++i)
	{
		cout << left << setw(4) << a[i];
		sz = (sz + 1) % 10;
		if(0 == sz)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void insertSortStraight::sort()
{
	int n = static_cast<int>(a.size());
	for(int i = 1; i < n; ++i)
	{
		Comparable tem = a[i];
		int j = i;
		for(; 1 <= j&&tem < a[j - 1]; --j)
		{
			a[j] = a[j - 1];
		}
		a[j] = tem;
	}
}

void insertSortShell::sort()
{
	int n = static_cast<int>(a.size());
	for(int step = (n >> 1); 1 <= step; step >>= 1)
	{
		for(int st = 0; st < step; ++st)
		{
			for(int i = st + step; i < n; i += step)
			{
				Comparable tem = a[i];
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

void swapSortBubble::sort()
{
	int n = static_cast<int>(a.size());
	for(int i = 1; i < n; ++i)
	{
		for(int j = 0; j < n - i; ++j)
		{
			if(a[j + 1] < a[j])
			{
				exch(j, j+1);
			}
		}
	}
}

void swapSortQuick::sort()
{
	int n = static_cast<int>(a.size());
	sort(0, n);
}

void swapSortQuick::sort(int st, int ed)
{
	if(ed - st < 2)
	{
		return;
	}
	int pos = Partition(st, ed - 1);
	sort(st, pos);
	sort(pos + 1, ed);
}

int swapSortQuick::Partition(int st, int ed)
{
	Comparable tem = a[st];
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

void selectionSortSimple::sort()
{
	int n = static_cast<int>(a.size());
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
			exch(i, minIdx);
		}
	}
}

//使用标准库的优先队列，进行堆排序
void selectionSortHeap::sort()
{
	int n = static_cast<int>(a.size());
	priority_queue<int, vector<int>, greater<int>> Q;   //小顶堆
	//默认是大顶堆
	// priority_queue<int, vector<int>, less<int>> Q;    //使用priority_queue<int> Q;一样
	for(auto x : a)
	{
		Q.push(x);
	}
	int i = 0;
	while(!Q.empty())
	{
		a[i++] = Q.top();
		Q.pop();
	}
}

//void selectionSortHeap::sort()
//{
//	int n = static_cast<int>(a.size());
//	createHeap();
//	for(int i = n - 1; 0 < i; --i)
//	{
//		exch(i, 0);
//		heapAdjust(i, 0);
//	}
//}
//
//void selectionSortHeap::createHeap()
//{
//	int n = static_cast<int>(a.size());
//	for(int i = (n - 1) / 2; 0 <= i; --i)
//	{
//		heapAdjust(n, i);
//	}
//}
//
//void selectionSortHeap::heapAdjust(int totalN, int pos)
//{
//	int n = static_cast<int>(a.size());
//	Comparable tem = a[pos];
//	int i = pos;
//	for(int j = pos * 2 + 1; j < n; j = j * 2 + 1)
//	{
//		if(j + 1 < n&&a[j] < a[j + 1])
//		{
//			++j;
//		}
//		if(tem >= a[j])
//		{
//			break;
//		}
//		else
//		{
//			a[i] = a[j];
//			i = j;
//		}
//	}
//	a[i] = tem;
//}

void mergeSort::sort()
{
	int n = static_cast<int>(a.size());
	sort(0, n - 1);
}

void mergeSort::sort(int st, int ed)
{
	if(st < ed)
	{
		int mid = st + (ed - st) / 2;
		sort(st, mid);
		sort(mid + 1, ed);
		merge(st, mid, ed);
	}
}

void mergeSort::merge(int st, int mid, int ed)
{
	int i = st;
	int j = mid + 1;
	for(int k = st; k <= ed; ++k)
	{
		aux[k] = a[k];
	}

	for(int k = st; k <= ed; ++k)
	{
		if(i > mid)
		{
			a[k] = aux[j++];
		}
		else if(j > ed)
		{
			a[k] = aux[i++];
		}
		else if(aux[j] < aux[i])
		{
			a[k] = aux[j++];
		}
		else
		{
			a[k] = aux[i++];
		}
	}
}

void mergeSort::sortAnther()
{
	int n = static_cast<int>(a.size());
	for(int sz = 1; sz < n; sz <<= 1)
	{
		for(int st = 0; st < n - sz; st += sz * 2)
		{
			merge(st, st + sz + 1, minNum(st + sz + sz - 1, n - 1));
		}
	}
}
void countSort::sort()
{
	//假设数组元素在0~499之间
	vector<int> cntAux(500, 0);
	int n = static_cast<int>(a.size());
	for(int i = 0; i < n; ++i)
	{
		++cntAux[a[i]];
	}
	for(int i = 1; i < 500; ++i)
	{
		cntAux[i] += cntAux[i - 1];
	}

	vector<Comparable> tmp(a);
	for(int i = n - 1; 0 <= i; --i)
	{
		a[--cntAux[tmp[i]]] = tmp[i];
	}
}

void radixSort::sort()
{
	int n = static_cast<int>(a.size());
	int d = 3;
	vector<int> cnt(RADIX);
	vector<Comparable> tmp(n);

	for(int i = 0; i < d; ++i)
	{
		//分配
		Distribute(i, cnt);
		//收集
		Collect(i, cnt, tmp);
	}
}

int radixSort::getRadix(int num, int sq)
{
	return (num / static_cast<int>(pow(RADIX, sq))) % RADIX;
}

void radixSort::Distribute(int sq, vector<int>& cnt)
{
	//初始化
	int n = static_cast<int>(a.size());
	for(auto& x : cnt)
	{
		x = 0;
	}
	for(int i = 0; i < n; ++i)
	{
		int ord = getRadix(a[i], sq);
		++cnt[ord];
	}
}

void radixSort::Collect(int sq, vector<int>& cnt, vector<int>& tmp)
{
	int n = static_cast<int>(a.size());
	for(int i = 1; i < RADIX; ++i)
	{
		cnt[i] += cnt[i - 1];
	}
	for(int i = 0; i < n; ++i)
	{
		tmp[i] = a[i];
	}
	for(int i = n - 1; 0 <= i; --i)
	{
		int ord = getRadix(tmp[i], sq);
		a[--cnt[ord]] = tmp[i];
	}
}

