/*
ID: icoder_0020
PROG: Monk at the Graph Factory
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int N;
	cin>>N;
	int deg[N];
	int sum = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>deg[n];
		sum += deg[n];
	}
	if(sum == 2*(N-1))
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}
	return 0;
}