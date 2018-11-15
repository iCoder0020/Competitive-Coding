/*
ID: iCoder0020
PROG: Math
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int nearest_square(int a)
{
	if(a == 1 )
	{
		return 0;
	}
	if(a<=2)
	{
		return 1;
	}
	else if(a<=4)
	{
		return 2;
	}
	else if (a<=8)
	{
		return 3;
	}
	else if(a<=16)
	{
		return 4;
	}
	else if(a<=32)
	{
		return 5;
	}
}

int main()
{
	long long int N;
	cin>>N;
	
	if(N <=3 )
	{
		cout<<N<<" 0\n";
	}
	else
	{
		int prime[N-1];
		for(int i = 0; i<N-1; i++)
		{
			prime[i] = i+2;
		}
		for(int i = 2; i<=N/2; i++)
		{
			for(int j = 2; i*j<=N; j++)
			{
				prime[i*j-2] = 0;
			}
		}
		
		int prime_power_count[N-1] = {0};
		long long int min_possible = 1;

		vector <pair<int,int>> prime_power_count_vec;

		for(int n = 2; n<=N; n++)
		{
			if(prime[n-2])
			{
				int N_copy = N;
				while(N_copy%n == 0)
				{
					prime_power_count[n-2]++;
					N_copy/=n;
				}
				if(N%n == 0)
				{
					prime_power_count_vec.push_back(make_pair(n,prime_power_count[n-2]));
				}
			}
		}

		for(int n = 0; n<prime_power_count_vec.size(); n++)
		{
			min_possible *= prime_power_count_vec[n].first;
		}

		int count = 0;
		long long int N_copy = N;
		int max_power = 0;

		int count2 = 0;

		for(int n = 0; n<prime_power_count_vec.size(); n++)
		{
			max_power = (max_power>prime_power_count_vec[n].second)?max_power:prime_power_count_vec[n].second;
		}

		int temp = nearest_square(max_power);
		
		count2 = temp+1;

		max_power = 0;

		while(N_copy!=min_possible)
		{
			if(sqrt(double(N_copy)) == (int)(sqrt(N_copy)))
			{
				N_copy = sqrt(N_copy);
		
				for(int n = 0; n<prime_power_count_vec.size(); n++)
				{
					prime_power_count_vec[n].second /= 2;
				}
				count++;
			}
			else
			{
				for(int n = 0; n<prime_power_count_vec.size(); n++)
				{
					max_power = (max_power>prime_power_count_vec[n].second)?max_power:prime_power_count_vec[n].second;
				}
				int temp = nearest_square(max_power);
				count = count + 1 + temp;				
				N_copy = min_possible;
			}
		}
		cout<<min_possible<<" "<<min(count,count2)<<endl;
	}
	return 0;
}