/*
ID: ishan_sang
PROG: AVG
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
	int T;
	cin>>T;	
	for(int t = 0; t<T; t++)
	{
		int N,K,V;
		cin>>N>>K>>V;
		int A[N];
		int sum = 0;
		
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];		
			sum += A[n];
		}
		
		int temp = V*(N+K) - sum;

		if(temp % K == 0 && temp > 0)
		{
			cout<<temp/K;
		}
		else
		{
			cout<<-1;
		}
		cout<<endl;
	}
	return 0;
}