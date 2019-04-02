/*
ID: iCoder0020
PROG: Nirvana
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N;
	cin>>N;
	int power10[11];
	power10[0] = 1;
	for(int n = 1; n<11; n++)
	{
		power10[n] = power10[n-1]*10;
	}
	
	int product = 1;
	int product_temp;
	for(int t = 0; t<=10; t++)
	{
		int base = power10[t];
		int M = N - ((N%base + 1)%base);
		if(M<0)
			break;
		int product_temp = 1;
		while(M)
		{
			product_temp *= M%10;
			M/=10;
		}
		product = max(product, product_temp);
	}
	cout<<product<<endl;
	return 0;
}