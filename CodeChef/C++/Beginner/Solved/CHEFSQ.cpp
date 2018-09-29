/*
ID: ishan_sang
PROG: CHEFSQ
LANG: C++
*/

#include <iostream>

using namespace std;

int main()
{
	int T,N,n;
	int count;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		int A[N];
		for(int j = 0; j<N; j++)
		{
			cin>>A[j];
		}
		cin>>n;
		int a[n];
		for(int j = 0; j<n ;j++)
		{
			cin>>a[j];
		}
		if(n > N)
		{
			cout<<"No\n";
			continue;
		}
		count = 0;
		for(int j = 0; j<n; j++)
		{
			for(int k = 0; k<N; k++)
			{
				if(A[k] == a[j])
				{
					count++;
					break;
				}
			}
		}
		if(count == n)
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
	return 0;
}