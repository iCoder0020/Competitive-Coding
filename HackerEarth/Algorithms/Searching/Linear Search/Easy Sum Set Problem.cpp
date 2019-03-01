/*
ID: icoder_0020
PROG: Easy Sum Set Problem
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int N,M;
	cin>>N;
	int A[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	cin>>M;
	int C[M];
	bool c[100];
	for(int n = 0; n<100; n++)
	{
		c[n] = false;
	}
	for(int m = 0; m<M; m++)
	{
		cin>>C[m];
		c[C[m]-1] = true;
	}
	set <int> B;
	for(int n = 0; n<N; n++)
	{
		for(int m = 0; m<M; m++)
		{
			B.insert(C[m] - A[n]);
		}
	}
	for(auto it = B.begin(); it!=B.end(); it++)
	{
		bool correct = true;
		for(int n = 0; n<N; n++)
		{
			if(c[*it + A[n]-1] == false)
			{
				correct = false;
			}
		}
		if(correct)
		{
			cout<<*it<<" ";
		}
	}
	cout<<endl;
}
