/*
ID: iCoder0020
PROG: Grading Students
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T,N;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>N;
		if(((5*((N/5)+1)-N)<3)&&(N>=38))
		{
			N=(5*((N/5)+1));
		}
		cout<<N<<"\n";
	}
	return 0;
}