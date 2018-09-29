/*
ID: icoder_0020
PROG: Shubham and Subarrays
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	vector< vector<int> > V((N*(N-1)), vector<int>(N, 0)); 
	int sum = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	int count = 0;
	for(int i = 0; i<N; i++)
	{
		for(int j = i; j<N; j++)
		{
			for(int k = i; k<=j; k++)
			{
				V[count][k-i] = A[k];
			}
			set<int> s(V[count].begin(), V[count].end());
			V[count].assign(s.begin(), s.end());
			count++;
		}
	}
	for(int i = 0; i<(N*(N-1)); i++)
	{
		for(int j = i+1; j<(N*(N-1)); j++)
		{
			if(V[i] == V[j])
			{
				sum++;
			}
		}
	}
	cout<<(N*(N-1))-sum<<"\n";
	return 0;
}