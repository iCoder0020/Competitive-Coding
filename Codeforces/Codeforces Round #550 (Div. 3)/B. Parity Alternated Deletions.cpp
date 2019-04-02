/*
ID: iCoder0020
PROG: Parity Alternated Deletions
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long 

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	priority_queue<int>odd;
	priority_queue<int>even;
	int sum = 0;
	int total_sum = 0;
	for(int n = 0; n<N; n++)
	{
		int temp;
		cin>>temp;
		if(temp&1)
			odd.push(temp);
		else
			even.push(temp);
		total_sum += temp;
	}
	int move;
	if(even.size()>odd.size())
		move = 0;
	else
		move = 1;
	while(odd.size() || even.size())
	{
		if(move&1)
		{
			if(odd.size() == 0)
				break;
			int s = odd.top();
			sum += s;
			odd.pop();
		}
		else
		{
			if(even.size() == 0)
				break;
			int s = even.top();
			sum += s;
			even.pop();
		}
		move++;
	}
	cout<<total_sum-sum<<endl;
	return 0;
}