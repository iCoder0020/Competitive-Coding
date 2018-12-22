/*
ID: ishan_sang
PROG: MMPROD
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

#define MOD 1000000007

li modded_product(li a, li b)
{
	return (((a*b)%MOD + MOD)%MOD);
}

bool desc(li a, li b)
{
	return (a>b);
}

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int N,K;
		cin>>N>>K;

		li A[N];
		vector <li> pos;
		vector <li> neg;
		vector <li> zero;

		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n] > 0)
			{
				pos.push_back(A[n]);
			}
			else if(A[n] == 0)
			{
				zero.push_back(0);
			}
			else
			{
				neg.push_back(A[n]);
			}
		}

		if(zero.size()!=0)
		{
			if 	( 
				(K > pos.size() + neg.size()) ||
				((pos.size() == 0) && (K%2 == 1)) ||
				((K == pos.size() + neg.size()) && (neg.size()%2 == 1))
				)
			{
				cout<<0<<endl;
			}
		}
		else
		{
			sort(pos.begin(), pos.end(), desc);
			sort(neg.begin(), neg.end());

			li product = 1;

			int pos_index = 0;
			int neg_index = 0;

			
		}
	}
	return 0;
}