#include <bits/stdc++.h>

using namespace std;

#define int long long

bool bs(vector<int>&A, int N, int K, int X)
{
	if(K<N)
		return false;
	int p = 0;
	int cnt = 0;
	vector<int>P(A);
	// cout<<"Try: "<<K<<" days"<<endl;
	while(cnt<K-N)
	{
		// cout<<"Day: "<<cnt<<endl;
		int i = -1;
		for(int n = N-1; n>=0; n--)
		{
			if(P[n]>X)
			{
				i = n;
				break;
			}
		}
		if(i == -1)
			return true;
		P[i] -= X;
		X *= 2;
		for(int n = N-1; n>=i; n--)
			P[n] = min(A[n], 2*P[n]);
		cnt++;
		if(K == 6)
			cout<<cnt<<" "<<X<<endl;
	}
	int i = -1;
	for(int n = N-1; n>=0; n--)
	{
		if(X>=A[n])
		{
			i = n; 
			break;
		}
	}
	if(i == -1)
		return false;
	for(int n = i; n<N; n++)
	{
		if(X<A[n])
			return false;
		X = 2*A[n];
	}
	return true;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int TC;
	cin>>TC;
	while(TC--)
	{
		int N,X;
		cin>>N>>X;
		vector<int>A(N);
		for(int n = 0; n<N; n++)
			cin>>A[n]; 
		sort(A.begin(), A.end());
		int lo = 1, mid, hi = 1e12;
		while(lo<hi)
		{
			mid = lo + (hi-lo)/2;
			if(bs(A,N,mid,X))
				hi = mid;
			else
				lo = mid+1;
		}
		cout<<lo<<endl;
	}
	return 0;
}