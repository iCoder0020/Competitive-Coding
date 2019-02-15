/*
ID: iCoder0020
PROG: Circular Dance
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N][2];
	for(int n = 0; n<N; n++)
	{
		for(int m = 0; m<2; m++)
		{
			cin>>A[n][m];
		}
	}
	vector <int> order(N,0);
	vector <bool> visited(N,false);
	order[0] = 1;
	visited[0] = true;
	int i = 0;
	int cnt = 0;
	int temp = N;
	while(temp--)
	{
		for(int m = 0; m<2; m++)
		{
			if(A[i][(m+1)%2] == A[A[i][m]-1][0] || A[i][(m+1)%2] == A[A[i][m]-1][1])
			{
				if(visited[A[i][m]-1] == false)
				{
					visited[A[i][m]-1] = true;
					order[(cnt+1)%N] = A[i][m];
					i = A[i][m]-1;
					cnt++;
					break;
				}
			}
		}
	}
	for(int n = 0; n<N; n++)
	{
		cout<<order[n]<<" ";
	}
	cout<<endl;
	return 0;
}