/*
ID: ishan_sang
PROG: ALTARAY
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T,N;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		long long int A[N];
		int dp[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			dp[n] = 1; 
		}
		for(int n = N-2; n>=0; n--)
		{
			if(A[n]*A[n+1]<0)
			{
				dp[n] = dp[n+1] + 1;
			}
		}
		for(int n = 0; n<N; n++)
		{
			cout<<dp[n]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}