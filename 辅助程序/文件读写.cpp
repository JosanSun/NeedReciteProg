#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


int main(int argc, char* argv[])
{
	freopen("in.txt", "r", stdout);
	freopen("out.txt", "w", stdout);
	
	
	return 0;
}


#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
#if INPUTTEST
	//����tinyUF.txt
	ifstream fin("in.txt");
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