/*
ID: iCoder0020
PROG: Flipping Game
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
	int count = 0;
	int max_count = 0;
	int i,j;
	i = 0;
	j = 0;
	for(int n = 0; n<N; n++)
	{
		if(A[n] == 1)
		{
			j++;
			count = j-i;
		}
		else
		{
			while(n<N && A[n] != 1)
			{
				n++;
			}
			if(n == N)
			{
				count = n-i;
			}
			else
			{
				count = n-i+1;
			}
			i = n;
		}
		max_count = max(count, max_count);
	}
	max_count = max(count, max_count);
	cout<<max_count<<endl;
	return 0;
}