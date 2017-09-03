#ifndef SORTEX_H_
#define SORTEX_H_

typedef int Comparable;

#include <vector>
using std::vector;

class sortEx
{
public:
	//static bool lessThan(Comparable v, Comparable w);
	void exch(int i, int j);
	bool isSorted()const;
	void show()const;
	virtual void sort() = 0;
protected:
	sortEx(int n = 0);
	vector<Comparable> a;
};

class insertSortStraight :public sortEx
{
public:
	insertSortStraight(int n):sortEx(n){ }
	void sort();
};

class insertSortShell :public sortEx
{
public:
	insertSortShell(int n) :sortEx(n)
	{
	}
	void sort();
};

class swapSortBubble :public sortEx
{
public:
	swapSortBubble(int n) :sortEx(n)
	{
	}
	void sort();
};

class swapSortQuick :public sortEx
{
public:
	swapSortQuick(int n) :sortEx(n)
	{
	}
	void sort();
private:
	int Partition(int st, int ed);   //[st, ed]
	void sort(int st, int ed);       //[st, ed)
};


class selectionSortSimple :public sortEx
{
public:
	selectionSortSimple(int n) :sortEx(n)
	{
	}
	void sort();
};

class selectionSortHeap :public sortEx
{
public:
	selectionSortHeap(int n) :sortEx(n)
	{
	}
	void sort();
private:
	void createHeap();
	void heapAdjust(int totalN, int pos);
};

class mergeSort :public sortEx
{
public:
	mergeSort(int n) :sortEx(n)
	{
		aux.resize(n);
	}
	//自顶向下的归并
	void sort();
	//自底向上的归并
	void sortAnther();
private:
	void sort(int st, int ed);            //[st, ed]
	void merge(int st, int mid, int ed);  //[st, ed]
	vector<Comparable> aux;
	int minNum(int a, int b)
	{
		return a < b ? a : b;
	}
};

class countSort :public sortEx
{
public:
	countSort(int n) :sortEx(n)
	{
	}
	void sort();
};

class radixSort :public sortEx
{
public:
	radixSort(int n) :sortEx(n), RADIX(10)
	{
	}
	void sort();
private:
	int getRadix(int num, int sq);
	void Distribute(int sq, vector<int>& cnt);
	void Collect(int sq, vector<int>& cnt, vector<int>& tmp);
	const int RADIX;
};

#endif