#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	map<int,vector<int>>M;
	M.clear();
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		M[A[n]].push_back(n);
	}
	int cnt = 0;
	for(auto it: M)
	{
		int k = 0;
		sort(it.second.begin(), it.second.end());
		while(k+1<it.second.size())
		{
			A[it.second[k]] = -1;
			A[it.second[k+1]] = 2*(it.first);
			M[2*(it.first)].push_back(it.second[k+1]);
			k+=2;
			cnt++;
		}
	}
	cout<<N-cnt<<endl;
	for(int n = 0; n<N; n++)
		if(A[n] != -1)
			cout<<A[n]<<" ";
	cout<<endl;
	return 0;
}
