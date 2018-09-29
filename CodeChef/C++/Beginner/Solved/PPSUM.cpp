/*
ID: ishan_sang
PROG: PPSUM
LANG: C++                  
*/
 
#include <iostream>
 
using namespace std;
 
typedef long long int ll;
 
ll sum(ll K, ll N)
{
	if(K == 1)
	{
		return (N*(N+1)/2);
	}
	else
	{
		return sum(K-1, (N*(N+1))/2);
	}
}
 
int main()
{
	int T;
	cin>>T;
	ll K, N;
	for(int t = 0; t<T; t++)
	{
		cin>>K>>N;
		cout<<sum(K, N)<<"\n";		
	}
	return 0;
} 