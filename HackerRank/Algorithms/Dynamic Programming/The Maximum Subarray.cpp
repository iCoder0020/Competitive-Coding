/*
ID: iCoder0020
PROG: The Maximum Subarray
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int T;
	int N;
	cin>>T;
	long long int sum, ans;
	bool is_pos;
	long long int m;
	for(int t =0; t<T; t++)
	{
		cin>>N;
		long long int A[N];
		long long int dp[N];
		for(int n = 0; n<N; n++)
		{
			dp[n] = 0;
			cin>>A[n];
		}
		ans = 0;
		sum = 0;
		is_pos = false;
		m = -100000;
		for(int n = 0; n<N; n++)
		{
			if(A[n] > 0)
			{
				is_pos = true;
				sum += A[n];
			}
			if(!is_pos)
			{
				m = max(m, A[n]);
			}
		}
		if(!is_pos)
		{
			cout<<m<<" "<<m<<"\n";
		}
		else
		{
			for(int n = 0; n<N; n++)
			{
				if(n == 0)
				{
					dp[n] = A[n];
				}
				else
				{
					dp[n] = max(dp[n-1] + A[n], A[n]);
				}
				ans = max(ans, dp[n]);
			}
			cout<<ans<<" "<<sum<<"\n";
		}
	}
	return 0;
}