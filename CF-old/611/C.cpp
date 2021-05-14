#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	set<int> S;
	for(int n = 0; n<N; n++)
		S.insert(n+1);
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		S.erase(A[n]);
	}

	for(auto it: S)
	{
		if(A[it-1] == 0)
		{
			for(auto jt: S)
			{
				if(it != jt)
				{
					A[it-1] = jt;
					S.erase(jt);
					break;
				}
			}
		}
	}

	for(int n = 0; n<N; n++)
	{
		if(A[n] == 0)
		{
			for(auto it: S)
			{
				if(it != n+1)
				{
					A[n] = it;
					S.erase(it);
					break;
				}
			}
		}
	}
	for(int n = 0; n<N; n++)
		cout<<A[n]<<" ";
	cout<<endl;
	return 0;
}
