/*
ID: iCoder0020
PROG: Largest product in a series
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	int N,K;
	cin>>T;
	int max;
	int product;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>K;
		char number[N];
		cin>>number;
		max = 0;
		for(int i = 0; i<N-K; i++)
		{
			product = 1;
			for(int j = i; j<i+K; j++)
			{
				product*=((int)(number[j])-48);
			}
			max = (max>product)?max:product;
		}
		cout<<max<<"\n";
	}
	return 0;
}