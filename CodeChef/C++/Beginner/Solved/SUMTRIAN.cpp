/*
ID: ishan_sang
PROG: SUMTRIAN
LANG: C++                  
*/
 
#include <iostream>
 
using namespace std;
 
int find_max(int a, int b)
{
	if(a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	int T,N;
	int max;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		int A[N][N];
		max = 0;
 		for(int i = 0; i<N; i++)
 		{
 			for(int j = 0; j<=i; j++)
 			{
 				cin>>A[i][j];
 				if(i == 0)
 				{
 					max = A[i][j];
 				}
 				else
 				{
	 				if(j == 0)
	 				{
	 					A[i][j] = A[i][j] + A[i-1][j];
	 				}
	 				else if(j == i)
	 				{
	 					A[i][j] = A[i][j] + A[i-1][j-1];
	 				}
	 				else
	 				{
	 					A[i][j] = find_max(A[i][j] + A[i-1][j], A[i][j] + A[i-1][j-1]);
	 				}
		 			if(i == N-1)
		 			{
		 				max = find_max(max, A[i][j]);
		 			}
 				}
	 		}
 		}
		cout<<max<<"\n";
	}
	return 0;
}