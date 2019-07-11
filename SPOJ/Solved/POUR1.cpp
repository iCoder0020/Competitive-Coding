/*
ID: icoder_0020
PROG: POUR1
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int pour(int A, int B, int C) 
{
	int move = 1, a = A, b = 0, temp;
	while (a != C && b != C) 
	{
		temp = min(a, B - b);
		b += temp;
		a -= temp;
		move++;
		if(a == C || b == C)
		  break;
		if(a == 0) 
		{
			a = A;
			move++;
		}
		if(b == B) 
		{
	  		b = 0;
	  		move++;
		}
	}
	return move;
}

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a<b)
		{
			a = a+b;
			b = a-b;
			a = a-b;
		}
		if(c>a && c>b || c%(__gcd(a,b))!=0)
			cout<<-1;
		else if(c == 0)
			cout<<0;
		else if(c == a || c == b)
			cout<<1;
		else
		{
			cout<<min(pour(a,b,c), pour(b,a,c));
		}
		cout<<endl;
	}	
	return 0;
}