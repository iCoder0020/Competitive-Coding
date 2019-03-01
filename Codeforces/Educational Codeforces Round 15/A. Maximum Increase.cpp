/*
ID: iCoder0020
PROG: Maximum Increase
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	int count = 1;
	int max_count = 1;
	for(int n = 1; n<N; n++)
	{
		if(A[n] > A[n-1])
		{
			count++;
		}
		else
		{
			max_count = max(max_count, count);
			count = 1;
		}
	}
	max_count = max(max_count, count);
	cout<<max_count<<endl;
	return 0;
}