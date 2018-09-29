/*
ID: iCoder0020
PROG: Equalize
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	string A,B;
	cin>>N;
	cin>>A>>B;
	int edits = 0;
	for(int n = 0; n<N; n++)
	{
		if(A[n] != B[n])
		{
			if(n != N-1)
			{
				if((A[n+1] != B[n+1]) && (A[n] != A[n+1]))
				{
					A[n+1] = B[n+1];
				}
			}
			edits++;
			A[n] = B[n];
		}
	}
	cout<<edits<<"\n";
	return 0;
}