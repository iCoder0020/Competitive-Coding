/*
ID: ishan_sang
PROG: PRINDRAG
LANG: C++                  
*/

#include <iostream>
#include <algorithm>

using namespace std;

bool Compare(int a, int b)
{
	return (a>b);
}

int main()
{
	int T;
	cin>>T;
	int N,P,P_copy;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>P;
		P_copy = P;
		int S[N];
		int S_index;
		int count_safety[N];
		int left_sum = 0;
		int right_sum = 0;
		for(int n = 0; n<N; n++)
		{
			cin>>S[n];
			count_safety[n] = N;
		}
		sort(S, S+N, Compare);
		for(int n = 0; n<N; n++)
		{
			cout<<S[n];
		}
		for(int F = 0; F<N; F++)
		{	
			P = P_copy;		
			S_index = 0;
			P -= S[S_index];
			S_index++;

			if(P>0)
			{

				if(F<=N/2)
				{
					right_sum += S[S_index];
					S_index++;
					while(1)
				}
			}			
		}
		for(int i = 0; i<N; i++)
		{
			cout<<count_safety[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}