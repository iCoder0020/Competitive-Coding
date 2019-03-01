/*
ID: icoder_0020
PROG: Square Transaction
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int T;
	cin>>T;
	int A[T];
	int B[T];
	for(int t = 0; t<T; t++)
	{
		cin>>A[t];
		if(t == 0)
		{
			B[t] = A[t];
		}
		else
		{
			B[t] = B[t-1] + A[t];
		}
	}
	int Q;
	cin>>Q;
	int target;
	for(int q = 0; q<Q; q++)
	{
		cin>>target;
		if(target > B[T-1])
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<lower_bound(B, B+T, target) - B + 1<<endl;
		}
	}
	return 0;
}
