/*
ID: iCoder0020
PROG: Highly divisible triangular number
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define N_MAX 1000

int main()
{
	int count;
	for(long long int n = 400000000000000; n<=500000000000000; n+=10)
	{
		count = 0;
		for(int j = 1; j<=int(sqrt(n)); j++)
		{
			if(n%j == 0)
			{
				count+=2;
			}
		}
		if(count > 100)
		{
			cout<<n<<": "<<count<<endl;
		}
	}
	return 0;
}