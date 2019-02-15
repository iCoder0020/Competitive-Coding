/*
ID: iCoder0020
PROG: Disturbed People
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	int K = 0;
	cin>>N;
	int A[N];
	vector <int> zero;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	for(int n = 1; n<N-1; n++)
	{
		if(A[n] == 0 && A[n-1] == 1 && A[n+1] == 1)
		{
			zero.push_back(n);
		}
	}
	for(int n = 0; n<zero.size(); n++)
	{
		if(n+1 < zero.size())
		{
			if(zero[n+1] - zero[n] == 2)
			{
				n++;
			}
		}
		K++;
	}
	cout<<K<<endl;
	return 0;
}