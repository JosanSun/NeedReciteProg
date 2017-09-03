#ifndef UF_H_
#define UF_H_

#include <vector>
using std::vector;

class UF
{
public:
	UF(int n);
	virtual void unionOp(int p, int q) = 0;
	virtual int find(int p) = 0;
	bool connected(int p, int q);
	int count();
protected:
	vector<int> id;
	//cnt��ʾ���ϵĸ���
	int cnt;
};

//Quick-Find�㷨
class UFQuickFind :public UF
{
public:
	UFQuickFind(int n) :UF(n)
	{

	}
	void unionOp(int p, int q);
	int find(int p);
};

//Quick-Union�㷨
class UFQuickUnion :public UF
{
public:
	UFQuickUnion(int n) :UF(n)
	{

	}
	void unionOp(int p, int q);
	int find(int p);
};

class WeightedUFQuickUnion :public UFQuickUnion
{
public:
	WeightedUFQuickUnion(int n) :UFQuickUnion(n)
	{
		sz.resize(n);
		for(int i = 0; i < n; ++i)
		{
			sz[i] = 1;
		}
	}
	void unionOp(int p, int q);
protected:
	vector<int> sz;
};

class PathCompressWeightedUFQuickUnion :public WeightedUFQuickUnion
{
public:
	PathCompressWeightedUFQuickUnion(int n) :WeightedUFQuickUnion(n)
	{

	}
	int find(int p);
};


#endif
