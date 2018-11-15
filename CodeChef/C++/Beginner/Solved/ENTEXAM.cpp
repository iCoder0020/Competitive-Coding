/*
ID: ishan_sang
PROG: ENTEXAM
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{ 
		long long int N,K,E,M;
		cin>>N>>K>>E>>M;
		long long int exam_result[N][E];
		long long int total[N-1]={0};
		long long int total_chef = 0;
		long long int max;
		long long int temp;
		for(long long int n = 0; n<N; n++)
		{
			for(long long int e = 0; e<E; e++)
			{
				if(n == N-1)
				{
					if(e != E-1)
					{
						cin>>temp;
						total_chef += temp;
					}
				}
				else
				{
					cin>>exam_result[n][e];
					total[n] += exam_result[n][e];
				}
			}
		}
		sort(total, total+N-1);
		max = total[N-K-1];
		long long int answer = max+1-total_chef;
		if(answer > M)
		{
			cout<<"Impossible\n";
		}
		else
		{
			if(answer < 0)
			{
				cout<<"0\n";
			}
			else
			{
				cout<<answer<<"\n";
			}
		}
	}
	return 0;
}