/*
ID: ishan_sang
PROG: ASHIGIFT
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

bool check(li X, li dishes[][2], li B, li clans[][3], li C, li initial)
{
	li people = initial;
	li b = 0;
	li c = 0;
	while(1)
	{
		if(people <= 0)
		{
			return false;
		}
		else if(b == B)
		{
			return true;
		}
		else if(c == C)
		{
			people -= dishes[b][1];
			b++;
		}
		else if(dishes[b][0] < clans[c][0])
		{
			people -= dishes[b][1];
			b++;
		}
		else
		{
			if(people >= clans[c][1])
			{
				people += clans[c][2];
			}
			c++;
		}
	}
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		li X;
		cin>>X;
		li B;
		cin>>B;
		li dishes[B][2];
		for(li b = 0; b<B; b++)
		{
			cin>>dishes[b][0]>>dishes[b][1];
		}
		li C;
		cin>>C;
		li clans[C][3];
		for(li c = 0; c<C; c++)
		{
			cin>>clans[c][0]>>clans[c][1]>>clans[c][2];
		}
		li low = 1;
		li high = 1e18;
		li initial;
		while(1)
		{
			initial = (low+high)/2;
			if(high - low <= 1)
			{
				if(check(X,dishes,B,clans,C,low))
				{
					initial = low;
				}
				else
				{
					initial = high;
				}
				break;
			}
			else if(check(X,dishes,B,clans,C,initial))
			{
				high = initial;
			}
			else
			{
				low = initial + 1;
			}
		}
		cout<<initial<<endl;
	}
	return 0;
}