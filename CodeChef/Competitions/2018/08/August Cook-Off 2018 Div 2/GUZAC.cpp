/*
ID: ishan_sang
PROG: GUZAC
LANG: C++                  
*/

#include <iostream>
#include <algorithm>

long int max(long int a, long int b)
{
	return (a>b)?a:b;
}

using namespace std;

int main()
{
	int T;
	int N,K,X;
	int extra_students;
	int P_max;
	int P_min;
	long int sum[2];
	int index;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		cin>>N>>K>>X;

		sum[0] = 0;
		sum[1] = 0;

		int P[K];
		for(int k = 0; k<K; k++)
		{
			cin>>P[k];
			sum[0] += P[k];
			sum[1] += P[k];
		}
		sort(P, P+K);

		extra_students = N-K;
		if(extra_students > 0)
		{
			index = K-1;
			P_max = P[0] + X;
			if(P_max > P[index])
			{
				if(extra_students >= P_max - P[index])
				{
					sum[0] += ((P_max)*(P_max + 1))/2 - ((P[index] - 1)*(P[index]))/2;
					extra_students -= P_max - P[index];
				}
				else
				{
					sum[0] += ((P_max)*(P_max + 1))/2 - ((P_max - extra_students - 1)*(P_max - extra_students))/2;
					extra_students = 0;
				}
			}
			while(extra_students>0 || index == -1)
			{
				if(index>0)
				{
					if(extra_students >= P[index] - P[index-1])
					{
						sum[0] += ((P[index] - 1)*(P[index]))/2 - ((P[index-1] - 1)*(P[index-1]))/2;
						extra_students -= P[index] - P[index-1] - 1;
					}
	  				else
	  				{
	  					sum[0] += ((P[index] - 1)*(P[index]))/2 - ((P[index] - extra_students - 1)*(P[index] - extra_students))/2;
	  					extra_students = 0;
	  				}
				}
				else
				{ 
					if(extra_students >= P[index] - 1)
					{
						sum[0] += ((P[index] - 1)*(P[index]))/2;
						extra_students -= P[index] - extra_students - 1;
					}
					else
	  				{
	  					sum[0] += ((P[index] - 1)*(P[index]))/2 - ((P[index] - extra_students - 1)*(P[index] - extra_students))/2;
	  					extra_students = 0;
	  				}  
				}
				index--;
			}
		}

		
		extra_students = N-K;
		if(extra_students > 0)
		{
			index = 0;
			P_min = P[K-1] - X;
			if(P_min < P[index])
			{
				if(extra_students >= P[index] - P_min)
				{
					sum[1] += ((P[index] - 1)*(P[index]))/2 - ((P_min)*(P_min + 1))/2;
					extra_students -= P[index] - P_min;
				}
				else
				{
					sum[1] += ((P_min + extra_students -1)*(P_min + extra_students))/2;
					extra_students = 0;
				}
			}
			while(extra_students>0 || index == K-1)
			{
				if(index<K-1)
				{
					if(extra_students >= P[index+1] - P[index])
					{
						sum[1] += ((P[index + 1] - 1)*(P[index + 1]))/2 - ((P[index] - 1)*(P[index]))/2;
						extra_students -= P[index + 1] - P[index] - 1;
					}
	  				else
	  				{
	  					sum[1] += ((P[index] + extra_students - 1)*(P[index] + extra_students))/2 - ((P[index] - 1)*(P[index]))/2;
	  					extra_students = 0;
	  				}
				}
				index++;
			}
		}
		cout<<max(sum[0], sum[1])<<"\n";
	}
	return 0;
}