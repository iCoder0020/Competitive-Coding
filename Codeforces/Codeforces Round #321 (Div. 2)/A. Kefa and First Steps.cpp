/*
ID: iCoder0020
PROG: Kefa and First Steps
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N];
	int nds = 0;
	int max_nds = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(n == 0)
		{
			max_nds++;
			nds++;
		}
		else
		{
			if(A[n]<A[n-1])
			{
				if(nds > max_nds)
				{
					max_nds = nds;
				}
				nds = 1;
			}
			else
			{
				nds++;
			}
		}
		if(n == N-1)
		{
			max_nds = max(nds, max_nds);
		}
	}
	cout<<max_nds<<endl;
	return 0;
}