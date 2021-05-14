#include <bits/stdc++.h>

using namespace std;

#define int long long

bool bs(int mid, vector<int>&A, vector<int>&C, int N)
{
	vector<int>idx(mid);
	vector<int>cnt(mid);
	for(int i = 0; i<mid; i++)
	{
		idx[i] = i;
		cnt[i] = 0;
	}
	for(int i = 0; i<mid; i++)
	{
		while(1)
		{
			int k = A[idx[i]];
			cnt[i]++;
			if(cnt[i] > C[k])
				return false;
			idx[i] += mid;
			if(idx[i] >= N)
				break;
		}
	}
	return true;
}

int32_t main()
{
	int N,K;
	cin>>N>>K;
	vector<int>A(N);
	vector<int>C(K+1);
	for(int n = 0; n<N; n++)
		cin>>A[n];
	for(int k = 1; k<=K; k++)
		cin>>C[k];
	sort(A.begin(), A.end(), greater<int>());
	int lo = 1, mid, hi = N;
	while(lo<hi)
	{
		int mid = lo + (hi-lo)/2;
		if(bs(mid, A, C, N))
			hi = mid;
		else
			lo = mid+1;
	}
	vector<int>idx(lo);
	vector<int>cnt(lo);
	for(int i = 0; i<lo; i++)
	{
		idx[i] = i;
		cnt[i] = 0;
	}
	cout<<lo<<endl;
	for(int i = 0; i<lo; i++)
	{
		while(1)
		{
			int k = A[idx[i]];
			cnt[i]++;
			idx[i] += lo;
			if(idx[i] >= N)
				break;
		}
		cout<<cnt[i]<<" ";
		for(int j = i; j<N; j+=lo)
			cout<<A[j]<<" ";
		cout<<endl;
	}
	return 0;
}
