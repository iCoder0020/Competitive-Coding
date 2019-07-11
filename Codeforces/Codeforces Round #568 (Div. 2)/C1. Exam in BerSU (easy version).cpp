/*
ID: iCoder0020
PROG: Exam in BerSU (easy version)
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
	vector<vector<int>>times(N);
	vector<int>ans(N);
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(n == 0)
			prefix[n] = A[n];
		else
			prefix[n] = prefix[n-1] + A[n];
		for(int i = 0; i<n; i++)
			times[n].push_back(A[i]);
		sort(times[n].begin(), times[n].end(), greater<int>());
	}
	for(int n = 0; n<N; n++)
	{
		if(prefix[n] <= M)
			ans[n] = 0;
		else
		{	
			int cnt = 0;
			int sum = prefix[n];
			while(sum > M)
			{
				sum -= times[n][cnt];
				cnt++;
			}
			ans[n] = cnt;
		}
	}
	for(auto it:ans)
		cout<<it<<" ";
	cout<<endl;
	return 0; 
}