#include "02UF.h"

UF::UF(int n):cnt(n)
{
	id.resize(n);
	for(int i = 0; i < n; ++i)
	{
		id[i] = i;
	}
}

bool UF::connected(int p, int q)
{
	return find(p) == find(q);
}

int UF::count()
{
	return cnt;
}


void UFQuickFind::unionOp(int p, int q)
{
	int pID = find(p);
	int qID = find(q);
	if(pID == qID)
	{
		return;
	}
	int n = static_cast<int>(id.size());
	//��pID�Ľ�㣬�鲢��qID�Ľ��
	for(int i = 0; i != n; ++i)
	{
		if(pID == id[i])
		{
			id[i] = qID;
		}
	}
	--cnt;
}

int UFQuickFind::find(int p)
{
	return id[p];
}

void UFQuickUnion::unionOp(int p, int q)
{
	int pRoot = find(p);
	int qRoot = find(q);
	if(pRoot == qRoot)
	{
		return;
	}
	//��pRoot�Ľ�㣬�鲢��qRoot�Ľ��
	id[pRoot] = qRoot;
}

int UFQuickUnion::find(int p)
{
	//�ҵ�����������
	while(p != id[p])
	{
		p = id[p];
	}
	return p;
}

void WeightedUFQuickUnion::unionOp(int p, int q)
{
	int pID = find(p);
	int qID = find(q);
	if(pID == qID)
	{
		return;
	}
	if(sz[pID] < sz[qID])
	{
		id[pID] = qID;
		sz[qID] += sz[pID];
	}
	else
	{
		id[qID] = pID;
		sz[pID] += sz[qID];
	}
	--cnt;
}

int PathCompressWeightedUFQuickUnion::find(int p)
{
	while(p != id[p])
	{
		id[p] = id[id[p]];
		p = id[p];
	}
	return p;
}

