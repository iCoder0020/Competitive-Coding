#include <bits/stdc++.h>

using namespace std;

#define int long long

void ask(vector<int>&q)
{
	cout<<"? ";
	for(auto it: q)
		cout<<it<<" ";
	cout<<endl;
	fflush(stdout);
}

void answer(int x)
{
	cout<<"! "<<x<<endl;
}

void ab_to_hogya(vector<int>&A, int N, int K)
{
	vector<int>v;
	vector<int>q;
	for(int n = 1; n<=N && q.size()<K; n++)
	{
		if(A[n] != -1)
		{
			q.push_back(n);
			v.push_back(A[n]);
		}
	}
	ask(q);
	int pos,x;
	cin>>pos>>x;
	sort(v.begin(), v.end());
	int ans = lower_bound(v.begin(), v.end(), x) - v.begin();
	answer(ans+1);
}

int32_t main()
{
	int N,K;
	cin>>N>>K;
	if(K == 1)
	{
		answer(1);
	}
	else
	{
		set<int>S;
		vector<int>A(N+1, -1);
		int pos,x;
		vector<int>q(K);
		for(int n = 1; n<=N-K+1; n++)
		{
			for(int m = n; m<n+K; m++)
				q[m-n] = m;
			ask(q);
			cin>>pos>>x;
			S.insert(pos);
			A[pos] = x;
		}
		if(S.size() >= K)
			ab_to_hogya(A, N, K);
		else
		{
			int rem = K-1;
			
		}
	}
	return 0;
}
