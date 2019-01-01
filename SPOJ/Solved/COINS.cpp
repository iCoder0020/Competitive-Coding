/*
ID: icoder_0020
PROG: COINS
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

#define N_MAX 100001

li answer[N_MAX];

li maxm(li a, li b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

li recurse(li N)
{
	if(N <= 11)
	{
		return N;
	}
	else if(N<N_MAX && answer[N]!=-1)
	{
		return answer[N];	
	}
	else
	{
		li sum = maxm(N, recurse(N/2)+recurse(N/3)+recurse(N/4));
		if(N<N_MAX)
		{
			answer[N] = sum;
		}
		return sum;
	}
}

int main()
{
	li N;
	for(int n = 0; n<N_MAX; n++)
	{
		answer[n] = -1;
	}
	while(cin>>N)
	{
		cout<<recurse(N)<<endl;
	}
	return 0;
}