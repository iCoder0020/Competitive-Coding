/*
ID: iCoder0020
PROG: Brutality
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,K;
	cin>>N>>K;
	long long int A[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	string S;
	cin>>S;


	long long int dmg = 0;

	vector <pair<int,int>> V;

	int start = 0;
	int end = 0;

	for(int n = 1; n<N; n++)
	{
		while(n<N && S[n] == S[n-1])
		{
			n++;
		}
		end = n-1;
		V.push_back({start, end});
		start = end+1;
	
	}
		if(start == N-1)
		{
			V.push_back({N-1, N-1});
		}

	for(auto it = V.begin(); it!=V.end(); it++)
	{
		int i = (*it).first;
		int j = (*it).second;
		vector <int> B;
		for(int n = i; n<=j; n++)
		{
			B.push_back(A[n]);
		}
		sort(B.begin(), B.end(), greater<int>());
		long long int d = 0;
		int size = B.size();
		for(int n = 0; n<min(K, size); n++)
		{
			d += B[n];
		}
		//cout<<d<<endl;
		dmg += d;
	}

	cout<<dmg<<endl;

	return 0;
}