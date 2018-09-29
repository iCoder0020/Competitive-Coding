/*
ID: ishan_sang
PROG: FLOW017
LANG: C++                  
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	int A[3];
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		for(int i = 0; i<3; i++)
		{
			cin>>A[i];
		}
		sort(A, A+3);
		cout<<A[1]<<"\n";
	}
	return 0;
}