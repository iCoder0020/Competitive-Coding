/*
ID: iCoder0020
PROG: Valeriy and Deque
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N,Q;
	cin>>N>>Q;
	deque<int>D;
	for(int n = 0; n<N; n++)
	{
		int temp;
		cin>>temp;
		D.push_back(temp);
	}
	int idx = 0;
	int maxm = -1;
	int cyc = N-1;
	for(int n = 0; n<N; n++)
	{
		if(D[n] >= maxm)
		{
			maxm = D[n];
			idx = n;
		}
	}
	pair<int,int> u[idx];
	pair<int,int> v[cyc];
	for(int n = 0; n<idx + cyc; n++)
	{
		int A = D[0];
		int B = D[1];
		D.pop_front();
		D.pop_front();
		if(n < idx)
			u[n] = {A,B};
		else
			v[n-idx] = {A,B};
		if(A>B)
		{
			D.push_front(A);
			D.push_back(B);
		}
		else
		{
			D.push_front(B);
			D.push_back(A);
		}
	}
	while(Q--)
	{
		int m;
		cin>>m;
		if(m-1 >= idx)
		{
			m = (m - (idx+1))%cyc;
			cout<<v[m].first<<" "<<v[m].second;
		}
		else
		{
			m--;
			cout<<u[m].first<<" "<<u[m].second;
		}
		cout<<endl;
	}
	return 0; 
}