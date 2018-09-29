/*
ID: iCoder0020
PROG: Maximum Reduction
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli z(vector <lli> A, int K, int l, int r)
{
	if(A.size() < K)
	{
		return 0;
	}
	else
	{

	}
}

int main()
{
	int N,K;
	lli num;
	cin>>N>>K;
	vector <lli> A;
	for(int n = 0; n<N; n++)
	{
		cin>>num;
		A.push_back(num);
	}
	cout<<z(A, K, 0, N)<<"\n";
	return 0;
}