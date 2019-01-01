/*
ID: iCoder0020
PROG: New Year and the Sphere Transmission
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	li N;
	cin>>N;
	set <li> fun;
	fun.insert(1);
	fun.insert((N*(N+1))/2);
	for(int k = 2; k<=sqrt(N)+1; k++)
	{
		if(N%k == 0)
		{
			li temp = N/k;
			fun.insert((temp) + k*((temp-1)*(temp))/2);
			fun.insert((k) + temp*((k-1)*(k))/2);
		}
	}
	for(auto it = fun.begin(); it!=fun.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}