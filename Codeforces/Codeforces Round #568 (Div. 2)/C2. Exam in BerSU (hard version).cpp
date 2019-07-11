/*
ID: iCoder0020
PROG: Exam in BerSU (hard version)
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N,M;
	cin>>N>>M;
	int A[N];
	int prefix[N] = {0};
	int time_freq[101] = {0};
	int ans[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(n == 0)
			prefix[n] = A[n];
		else
			prefix[n] = prefix[n-1] + A[n];
	}
	for(int n = 0; n<N; n++)
	{
		if(prefix[n] <= M)
			ans[n] = 0;
		else
		{	
			int m = 100;
			int temp = 0;
			int diff = prefix[n]-M;
			while(diff>0)
			{
				if(m*time_freq[m] <= diff)
				{
					diff -= m*time_freq[m];
					temp+=time_freq[m];
					m--;
				}
				else
				{
					int r = (int)(ceil(((double)diff/(double)m)));
					temp += r;
					diff = 0;
				}
			}
			ans[n] = temp;
		}
		time_freq[A[n]]++;
	}
	for(auto it:ans)
		cout<<it<<" ";
	cout<<endl;
	return 0; 
}