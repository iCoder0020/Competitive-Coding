/*
ID: iCoder0020
PROG: A Prank
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	int dp = 0;
	int index1 = 0;
	int index2 = 0;
	int dp_max = 0;
	int dp_max_index1 = 0;
	int dp_max_index2 = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	if(N == 1)
	{
		cout<<"0\n";
	}
	else
	{
		for(int n = 0; n<N-1; n++)
		{
			if(dp == 0)
			{
				index1 = n;
			}
			if(A[n] == A[n+1]-1)
			{
				dp++;
				index2 = n+1;
			
				if(dp > dp_max)
				{
					dp_max = dp;
					dp_max_index1 = index1;
					dp_max_index2 = index2;
				}
			}
			else
			{
				dp = 0;
			}
		}
		int dp_end = 0;
		if(A[N-1] == 1000)
		{
			for(int n = N-1; n>=1; n--)
			{
				if(A[n] == A[n-1]+1)
				{
					dp_end++;
				}
				else
				{
					break;
				}
			}
		}
		if(dp_max_index1 == 0 && A[0] == 1)
		{
			dp_max++;
		}
		if(dp_max_index2 == N-1 && A[N-1] == 1000)
		{
			dp_max++;
		}
		if(dp_max == 0)
		{
			cout<<dp_max<<endl;
		}
		else
		{
			cout<<max(dp_max-1,dp_end)<<endl;
		}
	}
	return 0;
}