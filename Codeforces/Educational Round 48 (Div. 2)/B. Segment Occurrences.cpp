/*
ID: iCoder0020
PROG: Segment Occurrences
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N,M,Q;
	cin>>N>>M>>Q;
	bool A[N];
	for(int n = 0; n<N; n++)
	{
		A[n] = true;
	}
	string S,T;
	cin>>S>>T;
	int count ;
	for(int i = 0; i<=N-M; i++)
	{
		for(int j = i; j<i+M; j++)
		{
			if(S[j] != T[j-i])
			{
				A[i] = false;
				break;
			}
		}
	}
	int l,r;
	for(int q = 0; q<Q; q++)
	{
		cin>>l>>r;
		count = 0;
		for(int i = l-1; i<=r-M; i++)
		{
			if(A[i])
			{
				count++;
			}
		}
		cout<<count<<"\n";
	}
	return 0;
}