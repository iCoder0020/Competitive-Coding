/*
ID: icoder_0020
PROG: Simple Search
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;

int main()
{
	int N;
	cin>>N;
	long long int A[N];
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
	}
	long long int K;
	cin>>K;
	for(int n = 0; n<N; n++)
	{
		if(A[n] == K)
		{
			cout<<n<<endl;
			break;
		}
	}
	return 0;
}
