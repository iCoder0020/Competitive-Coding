/*
ID: iCoder0020
PROG: Easy Problem
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

#define MOD 998244353

using namespace std;

int main()
{
	int N;
	cin>>N;
	string S;
	cin>>S;
	int arr[N];
	for(int n = 0; n<N; n++)
	{
		cin>>arr[n];
	}
	vector<pair<int, int>> H;
	vector<pair<int, int>> A;
	vector<pair<int, int>> R;
	vector<pair<int, int>> D;
	vector<li> candidates;
	for(int n = 0; n<N; n++)
	{
		if(S[n] == 'h')
		{
			H.push_back({n, arr[n]});
		}
		if(S[n] == 'a')
		{
			A.push_back({n, arr[n]});
		}
		if(S[n] == 'r')
		{
			R.push_back({n, arr[n]});
		}
		if(S[n] == 'd')
		{
			D.push_back({n, arr[n]});
		}
	} 
	if(H.size() == 0 || A.size() == 0 || R.size() == 0 || D.size() == 0)
	{
		cout<<0<<endl;
	}
	else
	{
		li sum;

		sum = 0;
		for(int i = 0; i<H.size(); i++)
		{
			if(H[i].first > A[0].first)
			{
				break;
			}
			else
			{
				sum += H[i].second;
			}
		}

		candidates.push_back(sum);

		sum = 0;
		for(int i = 0; i<A.size(); i++)
		{
			if(A[i].first > R[0].first)
			{
				break;
			}
			else
			{
				sum += A[i].second;
			}
		}

		candidates.push_back(sum);

		sum = 0;
		for(int i = 0; i<R.size(); i++)
		{
			if(R[i].first > D[0].first)
			{
				break;
			}
			else
			{
				sum += R[i].second;
			}
		}

		candidates.push_back(sum);

		sum = 0;
		for(int i = 0; i<D.size(); i++)
		{
			
			sum += D[i].second;
		}

		candidates.push_back(sum);

		int min_sum = sum;

		for(int i = 0; i<candidates.size(); i++)
		{
			if(candidates[i]<min_sum)
			{
				min_sum = candidates[i];
			}
		}
		cout<<min_sum<<endl;
	}
	return 0;
}