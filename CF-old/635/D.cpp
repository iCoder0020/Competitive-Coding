#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF -1

int minm;

int sq(int x)
{
	return x*x;
}

void dist(int a, int b, int c)
{
	if(minm == -1)
		minm = sq(a-b) + sq(b-c) + sq(c-a);
	minm = min(minm, sq(a-b) + sq(b-c) + sq(c-a));
}

void getnearest(int x, vector<int>&A, vector<int>&B)
{
	int i1 = lower_bound(A.begin(), A.end(), x) - A.begin();
	int i2 = upper_bound(A.begin(), A.end(), x) - A.begin() - 1;

	int j1 = lower_bound(B.begin(), B.end(), x) - B.begin();
	int j2 = upper_bound(B.begin(), B.end(), x) - B.begin() - 1;

	i1 = min((int)(A.size()-1), i1);
	i2 = max(0LL, i2);

	j1 = min((int)(B.size()-1), j1);
	j2 = max(0LL, j2);

	dist(x,A[i1],B[j1]);
	dist(x,A[i2],B[j1]);
	dist(x,A[i1],B[j2]);
	dist(x,A[i2],B[j2]);
}

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		vector<int>A(a),B(b),C(c);
		for(int n = 0; n<a; n++)
			cin>>A[n];
		for(int n = 0; n<b; n++)
			cin>>B[n];
		for(int n = 0; n<c; n++)
			cin>>C[n];
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		sort(C.begin(), C.end());
		minm = INF;
		for(int i = 0; i<a; i++)
			getnearest(A[i],B,C);
		for(int i = 0; i<b; i++)
			getnearest(B[i],A,C);
		for(int i = 0; i<c; i++)
			getnearest(C[i],A,B);
		cout<<minm<<endl;
	}
	return 0;
}
