/*
ID: iCoder0020
PROG: Nick and Array
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	vector<int>pos;
	vector<int>neg;
	vector<int>zero;
	int A[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(A[n] > 0)
			pos.push_back(A[n]);
		else if(A[n] < 0)
			neg.push_back(A[n]);
		else
			zero.push_back(A[n]);
	}	
	if(N == 1)
	{
		if(A[0] < 0)
			A[0] = -A[0]-1;
		cout<<A[0];
	}	
	else if(zero.size() == N)
	{
		if(N&1)
		{
			for(int n = 0; n<N; n++)
				cout<<"0 ";
		}
		else
		{
			for(int n = 0; n<N; n++)
				cout<<"-1 ";
		}
	}
	else
	{
		if(N&1)
		{
			int max_abs = 0;
			for(int n = 0; n<N; n++)
			{
				if(A[n]>=0)
					A[n] = -A[n]-1;
				if(abs(max_abs) < abs(A[n]))
					max_abs = A[n];
			}
			bool once = false;
			for(int n = 0; n<N; n++)
			{
				if(A[n] == max_abs && !once)
				{
					cout<<-A[n]-1<<" ";
					once = true;
				}
				else
					cout<<A[n]<<" ";
			}
		}
		else
		{
			for(int n = 0; n<N; n++)
			{
				if(A[n]>=0)
					cout<<-A[n]-1<<" ";
				else
					cout<<A[n]<<" ";
			}
		}
	}
	cout<<endl;
	return 0; 
}