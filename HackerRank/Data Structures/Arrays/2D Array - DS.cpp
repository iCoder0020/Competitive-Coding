/*
ID: iCoder0020
PROG: 2D Array - DS
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A[6][6];
	for(int n = 0; n<6; n++)
	{
		for(int m = 0; m<6; m++)
		{
			cin>>A[n][m];
		}
	}
	int sum;
	int max_sum = -63;
	for(int n = 0; n<4; n++)
	{
		sum = 0;
		for(int m = 0; m<4; m++)
		{
			sum = A[n][m] + A[n][m+1] + A[n][m+2] + A[n+1][m+1] + A[n+2][m] + A[n+2][m+1] + A[n+2][m+2]; 
			max_sum = (max_sum>sum)?max_sum:sum;
		}
	}
	cout<<max_sum<<endl;
	return 0;
}