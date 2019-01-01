/*
ID: iCoder0020
PROG: Substring Removal
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

#define MOD 998244353

using namespace std;

int main()
{
	int N;
	cin>>N;
	string S;
	cin>>S;
	li count;

	li startf, endf, startr, endr;
	char cf, cr;

	cf = S[0];
	cr = S[N-1];

	startf = 0;
	endr = N-1;

	for(int n = 0; n<N; n++)
	{
		if(S[n] != cf)
		{
			endf = n-1;
			break;
		}
		if(n == N-1)
		{
			endf = N-1;
		}
	}

	for(int n = N-1; n>=0; n--)
	{
		if(S[n] != cr)
		{
			startr = n+1;
			break;
		}
		if(n == 0)
		{
			startr = 0;
		}
	}

	if(startr == startf)
	{
		count = 2*(N-1) + 1;
	}

	else if(cr == cf)
	{
		count = (endf-startf+2)*(endr-startr+2);
	}

	else
	{
		count = endf-startf+1;
		count += endr-startr+1;
		count++;
 	}

	cout<<count%MOD<<endl;
	return 0;
}