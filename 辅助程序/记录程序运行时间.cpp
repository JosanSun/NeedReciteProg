#include <ctime>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	clock_t t_st, t_ed;
	t_st = clock();
	//--------------- start of main --------------
	
	
	
	//--------------- end   of main --------------
	t_ed = clock();
	cout << "The time of program is " << t_ed - t_st << " ms." << endl;
	
	return 0;
}