/*
ID: iCoder0020
PROG: Long Jumps
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int N,L,X,Y;
	cin>>N>>L>>X>>Y;
	int A[N];
	bool a = false, b = false;
	vector<int>marks;
	for(int n = 0; n<N; n++)
		cin>>A[n];
	for(int n = 0; n<N-1; n++)
	{
		int i = lower_bound(A+n+1, A+N, A[n]+X)-A;
		if(i<N && A[i] == X+A[n])
			a = true;

		int j = lower_bound(A+n+1, A+N, A[n]+Y)-A;
		if(j<N && A[j] == Y+A[n])
			b = true;
	}
	if(!a && !b)
	{
		bool c = false;
		for(int n = 0; n<N; n++)
		{
			int k1 = lower_bound(A+n+1, A+N, A[n]+X+Y)-A;
			if(k1<N && A[k1] == A[n]+X+Y && A[n]+X <L)
			{
				marks.push_back(A[n]+X);
				c = true;
				break;
			}
			int k2 = lower_bound(A+n+1, A+N, A[n]-X+Y)-A;
			if(k2<N && A[k2] == A[n]-X+Y)
			{
				if(A[n]+Y<L)
					marks.push_back(A[n]+Y);
				else if(A[n]-X>0)
					marks.push_back(A[n]-X);
				else
					continue;
				c = true;
				break;
			}
		}
		if(!c)
		{
			marks.push_back(X);
			marks.push_back(Y);
		}
	}
	else
	{
		if(!a)
			marks.push_back(X);
		if(!b)
			marks.push_back(Y);
	}
	cout<<marks.size()<<endl;
	for(auto it: marks)
		cout<<it<<" ";
	cout<<endl;
	return 0;
}