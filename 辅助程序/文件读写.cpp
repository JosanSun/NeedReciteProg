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
	//测试tinyUF.txt
	ifstream fin("in.txt");
	//cinbk作为cin对象的读取缓冲区的临时存储对象
	streambuf* cinbk;
	//[old]streambuf* rdbuf(streambuf* newbf);  
	//调用这个方法可以设置新的读取缓冲区，返回旧的缓冲区 
	cinbk = cin.rdbuf(fin.rdbuf());
#endif
#if OUTPUTTEST
	ofstream fout("out.txt");
	//coutbk作为cout对象的写入缓冲区的临时存储对象
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