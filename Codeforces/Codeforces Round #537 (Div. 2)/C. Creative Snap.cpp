/*
ID: iCoder0020
PROG: Creative Snap
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

li power2[35];

li lpower2(li N)
{
	li pos = floor(log2(N));
	return power2[pos];
}

li upower2(li N)
{
	li pos = ceil(log2(N));
	return power2[pos];
}

int main()
{
	li N,K,A,B;
	cin>>N>>K>>A>>B;
	power2[0] = 1;
	for(int n = 1; n<35; n++)
	{
		power2[n] = 2*power2[n-1];
	}
	map<li, li> pos;
	int p;
	for(li k = 0; k<K; k++)
	{
		cin>>p;
		if(pos.find(p) == pos.end())
		{
			pos[p] = 1;
		}
		else
		{
			pos[p]++;
		}
	}
	li lower = 1;
	for(auto it: pos)
	{

	}
	return 0;
}