/*
 * ---------------------------------------------------
 *  Copyright (c) 2017 josan All rights reserved.
 * ---------------------------------------------------
 *
 *               创建者： Josan
 *             创建时间： 2017/8/21 9:49:09
 */

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
	for(int stepInc = n >> 1; 1 <= stepInc; stepInc >>= 1)
	{
		for(int st = 0; st < stepInc; ++st)
		{
			for(int i = st + stepInc; i < n; i += stepInc)
			{
				int tem = a[i];
				int j = i;
				for(; stepInc + st <= j&&tem < a[j - stepInc]; j -= stepInc)
				{
					a[j] = a[j - stepInc];
				}
				a[j] = tem;
			}
		}
	}
}

void swapSortBubble(int* a, int n)
{
	for(int i = 0; i < n - 1; ++i)
	{
		for(int j = 0; j < n - i - 1; ++j)
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
	/* 此处可以优化 */
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
	int pivotLoc = Partition(a, st, ed - 1);
	swapSortQuickInner(a, st, pivotLoc);
	swapSortQuickInner(a, pivotLoc + 1, ed);
}

void swapSortQuick(int* a, int n)
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
			minIdx = j;
		}
		if(minIdx != i)
		{
			int tem = a[minIdx];
			a[minIdx] = a[i];
			a[i] = tem;
		}
	}
}

static void HeapAdjust(int* a, int n, int adjPos)
{
	int adjVal = a[adjPos];
	for(int i = 2 * adjPos + 1; i < n; i = 2 * i + 1)
	{
		if(i + 1 < n && a[i] < a[i + 1])
		{
			++i;
		}
		if(a[i] < adjVal)
		{
			break;
		}
		a[adjPos] = a[i];
		adjPos = i;
	}
	a[adjPos] = adjVal;
}

static void createMaxHeap(int* a, int n)
{
	for(int i = (n - 2) / 2; 0 <= i; --i)
	{
		HeapAdjust(a, n, i);
	}
}

void selectionSortHeap(int* a, int n)
{
	createMaxHeap(a, n);
	for(int i = n - 1; 0 <= i; --i)
	{
		int tem = a[0];
		a[0] = a[i];
		a[i] = tem;
		HeapAdjust(a, i, 0);
	}
}

static void merge(int* a, int st, int mid, int ed)
{
	int* b = new int[mid - st + 1];
	for(int i = 0; i < mid - st + 1; ++i)
	{
		b[i] = a[i + st];
	}

	int k = st;
	for(int i = st, j = mid + 1; i <= mid || j <= ed;)
	{
		if((i <= mid&&j <= ed&&b[i - st] <= a[j]) || ed < j)
		{
			a[k++] = b[i - st];
			++i;
		}
		else if(i <= mid&&j <= ed&&a[j] < b[i - st])
		{
			a[k++] = a[j];
			++j;
		}
		else
		{
			break;
		}
	}
	delete[] b;
}

static void mergeSortInner(int* a, int st, int ed)
{
	if(st < ed)
	{
		int mid = st + (ed - st) / 2;
		mergeSortInner(a, st, mid);
		mergeSortInner(a, mid + 1, ed);
		merge(a, st, mid, ed);
	}
}

inline void mergeSort(int* a, int n)
{
	mergeSortInner(a, 0, n - 1);
}

void countSort(int* a, int n)
{
	int* cnt = new int[100]{0};
	for(int i = 0; i < n; ++i)
	{
		++cnt[a[i]];
	}
	for(int i = 1; i < 100; ++i)
	{
		cnt[i] += cnt[i - 1];
	}
	int* tmp = new int[n];
	for(int i = 0; i < n; ++i)
	{
		tmp[i] = a[i];
	}
	for(int i = n - 1; 0 <= i; --i)
	{
		a[--cnt[tmp[i]]] = tmp[i];
	}
}

static int getRadix(int num, int seq, int RADIX)
{
	return (num / (int)pow(RADIX, seq)) % RADIX;
}

static void Distribute(int* a, int n, int sq, int* cnt, int* tmp, int RADIX)
{
	memset(cnt, 0, sizeof(int)*RADIX);
	for(int i = 0; i < n; ++i)
	{
		int ord = getRadix(a[i], sq, RADIX);
		++cnt[ord];
	}
}

static void Collect(int*a, int n, int sq, int* cnt, int* tmp, int RADIX)
{
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
		int ord = getRadix(tmp[i], sq, RADIX);
		a[--cnt[ord]] = tmp[i];
	}
}

void radixSort(int* a, int n)
{
	int keyNum = 2;
	int RADIX = 10;
	int* cnt = new int[RADIX];
	int* tmp = new int[n];
	for(int i = 0; i < keyNum; ++i)
	{
		Distribute(a, n, i, cnt, tmp, RADIX);
		Collect(a, n, i, cnt, tmp, RADIX);
	}
}