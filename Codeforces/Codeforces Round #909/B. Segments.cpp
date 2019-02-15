/*
ID: iCoder0020
PROG: Segments
LANG: C++                  
*/

#include <iostream>

using namespace std;

int ans(int N)
{
	if(N <= 2)
	{
		return N;
	}
	else
	{
		return ans(N-2) + N;
	}
}

int main()
{
	int N;
	cin>>N;
	cout<<ans(N)<<"\n";
	return 0;
}