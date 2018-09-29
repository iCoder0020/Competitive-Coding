/*
ID: iCoder0020
PROG: Even Fibonacci numbers
LANG: C++                  
*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

#define N_MAX 40000000000000000

int main()
{
	int T;
	ll N;
	cin>>T;
	ll a = 1, b = 1, c = a+b, sum = 0;
	vector< pair <ll, ll> >NUM_FIBSUM;
	while(c <= N_MAX)
	{
		if(c%2 == 0)
		{
			sum += c;
			NUM_FIBSUM.push_back(make_pair(c, sum));
		}
		a = b;
		b = c;
		c = a+b;
	}
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		if(N < 2)
		{
			cout<<0<<"\n";
		}
		else
		{
			for(int j = 0; j<NUM_FIBSUM.size(); j++)
			{
				if(NUM_FIBSUM[j].first > N)
				{
					cout<<NUM_FIBSUM[j-1].second<<"\n";
					break;
				}
				if(j == NUM_FIBSUM.size()-1)
				{
					cout<<NUM_FIBSUM[j].second<<"\n";
					break;
				}
			}
		}
	}
	return 0;
}