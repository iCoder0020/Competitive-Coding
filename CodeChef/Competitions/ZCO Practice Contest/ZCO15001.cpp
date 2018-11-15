/*
ID: ishan_sang
PROG: ZCO15001
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main()
{
	int N;
	cin>>N;
	vector <int> A;
	vector <int> B;
	int C;
	int temp;
	for(int n = 0; n<N; n++)
	{
		cin>>temp;
		A.push_back(temp);
	}
	if(N == 1)
	{
		C = 1;
	}
	else
	{
		int l,r;
		int length;
		int max_length;
		int l_max = -1;
		int r_max = -1;
		for(int n = 0; n<A.size(); n++)
		{
			for(l = n-1,r = n+1; l>=0, r<A.size(); l--,r++)
			{
				if(A[l] == A[r])
				{

				}
			}
		}
	}
	cout<<C<<endl;
	return 0;
}