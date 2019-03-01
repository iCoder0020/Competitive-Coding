/*
ID: icoder_0020
PROG: Last Occurrence
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int N,M;
	cin>>N>>M;
	int A[N];
	int index = -1;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(A[n] == M)
		{
			index = n+1;
		}
	}
	cout<<index<<endl;
}