/*
ID: iCoder0020
PROG: Roman and Browser
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,K;
	cin>>N>>K;
	int A[N];
	int B[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	int ans;
	int max_ans = 0;
	for(int m = 0; m<K; m++)
	{
		for(int n = 0; n<N; n++)
		{
			B[n] = A[n];
		}
		for(int n = m; n<N; n+=K)
		{
			B[n] = 0;
		}
		int e = 0;
		int s = 0;
		for(int n = 0; n<N; n++)
		{
			if(B[n] == 1)
			{
				e++;
			}
			if(B[n] == -1)
			{
				s++;
			}
		}
		ans = abs(e-s);
		if(ans > max_ans)
		{
			max_ans = ans;
		}
	}
	cout<<max_ans<<endl;
	return 0;
}