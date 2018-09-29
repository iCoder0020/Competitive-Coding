/*
ID: iCoder0020
PROG: Visiting a Friend
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int n,m;
	int a,b;
	int count = 0;
	cin>>m>>n;
	int A[n+1];
	for(int i = 0; i<=n; i++)
	{
		A[i] = 0;
	}
	for(int i = 0; i<m; i++)
	{
		cin>>a>>b;
		if(A[b] == 0 && b == n)
		{
			A[n] = 1;
			count++;
		}
		for(int j = a; j<b; j++)
		{
			if(A[j] == 0 && j<=n)
			{
				A[j] = 1;
				count++;
			}
		}
	}
	if(count == n+1)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
}