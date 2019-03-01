/*
ID: ishan_sang
PROG: CROFT
LANG: C++
*/
 
#include <bits/stdc++.h>

using namespace std;

bool mysort(pair<int,int> A, pair<int,int> B)
{
	if(A.second > B.second)
	{
		return true;
	}
	return false;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		pair<int,int> A[N];
		pair<int,int> B[N];
		pair<int,int> C[N];

		for(int n = 0; n<N; n++)
		{
			A[n].first = n;
			cin>>A[n].second;
		}
		for(int n = 0; n<N; n++)
		{
			B[n].first = n;
			cin>>B[n].second;
		}

		for(int n = 0; n<N; n++)
		{
			C[n].first = n;
			C[n].second = A[n].second + B[n].second;
		}
		sort(C, C+N, mysort);

		int lara = 0;
		int jonah = 0;

		for(int n = 0; n<N; n++)
		{
			if(n%2 == 0)
			{
				lara += A[C[n].first].second;
			}
			else
			{
				jonah += B[C[n].first].second;
			}
		}
		if(lara > jonah)
		{
			cout<<"First";
		}
		else if(lara == jonah)
		{
			cout<<"Tie";
		}
		else
		{
			cout<<"Second";
		}
		cout<<endl;
	}
	return 0;
}
 