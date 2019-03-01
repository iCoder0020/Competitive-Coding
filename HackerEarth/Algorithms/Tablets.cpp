/*
ID: icoder_0020
PROG: Tablets
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int N;
	cin>>N;
	int health[N];
	int tablets[N];
	long long int sum = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>health[n];
		tablets[n] = 1;
	}
	for(int n = 1; n<N; n++)
	{
		if(health[n] > health[n-1])
		{
			tablets[n] = tablets[n-1] + 1;
		}
	}
	for(int n = N-2; n>=0; n--)
	{
		if(health[n] > health[n+1] && tablets[n] <= tablets[n+1])
		{
			tablets[n] = tablets[n+1] + 1;
		}
	}
	for(int n = 0; n<N; n++)
	{
		sum += tablets[n];
	}
	cout<<sum<<endl;
	return 0;
}