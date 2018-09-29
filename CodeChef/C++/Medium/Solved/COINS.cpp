/*
ID: ishan_sang
PROG: COINS
LANG: C++                  
*/
 
#include <bits/stdc++.h>
 
using namespace std;

#define N_MAX 100001

long long int sum;
long long int pre_computed_sum[N_MAX];

long long int max(long long int a, long long int b)
{
	return (a>b)?a:b;
}

long long int coins(long long int N)
{
	if(N<N_MAX && pre_computed_sum[N] != -1)
	{
		return pre_computed_sum[N];
	}
    if(N>=12)
    {	
        sum = coins(N/2) + coins(N/3) + coins(N/4);
    }
    else
    {
    	pre_computed_sum[N] = N;
        return N;
    }
    if(N<N_MAX)
    {
    	pre_computed_sum[N] = sum;
    }
    return sum;
}

int main()
{
    long long int N;
    for(int n = 0; n<N_MAX; n++)
    {
    	pre_computed_sum[n] = -1;
    	sum = 0;
    	coins(n);
    }
    while(cin>>N)
    {
    	if(N<N_MAX)
    	{
    		cout<<max(N, pre_computed_sum[N])<<"\n";
    	}
    	else
    	{
        	sum = 0;
   			coins(N);
        	cout<<max(N, sum)<<"\n";
        }
    }
    return 0;
} 