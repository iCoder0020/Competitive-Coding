/*
ID: ishan_sang
PROG: RECIPE
LANG: C++                  
*/

#include <iostream>

using namespace std;

int GCD(int a, int b)
{
	if(b>a)
	{
		return GCD(b, a);
	}
	if(b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b, a%b);
	}
}

int main()
{
	int T, N, gcd;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(n > 0)
			{
				gcd = GCD(gcd, A[n]); 
			}
			else
			{
				gcd = A[n];
			}
		}
		for(int n = 0; n<N; n++)
		{
			cout<<A[n]/gcd<<" ";
		}
		cout<<"\n";
	}
	return 0;
}