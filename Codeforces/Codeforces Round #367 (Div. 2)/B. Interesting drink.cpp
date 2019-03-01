/*
ID: iCoder0020
PROG: Interesting drink
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<int> price(N);
	for(int n = 0; n<N; n++)
	{
		cin>>price[n];
	}
	sort(price.begin(), price.end());
	int Q;
	cin>>Q;
	int temp;
	while(Q--)
	{
		cin>>temp;
		if(temp < price[0])
		{
			cout<<0;
		}
		else if(temp > price[N-1])
		{
			cout<<N;
		}
		else
		{
			int index = upper_bound(price.begin(), price.end(), temp) - price.begin();
			cout<<index;
		}
		cout<<endl;
	}
	return 0;
}