/*
ID: iCoder0020
PROG: Powers Of Two
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int set_bits(int N)
{
	int cnt = 0;
	while(N)
	{
		if(N%2 == 1)
		{
			cnt++;
		}
		N/=2;
	}
	return cnt;
}

int nearest_set_bit(int N)
{
	int cnt = 0;
	while(N)
	{
		if(N%2 == 1)
		{
			return cnt;
		}
		N/=2;
		cnt++;
	}
}

int main()
{
	int N,K;
	cin>>N>>K;
	int minm = set_bits(N);
	int maxm = N;
	int pow[30];
	pow[0] = 1;
	for(int n = 1; n<30; n++)
	{
		pow[n] = 2*pow[n-1];
	}
	if(K>=minm && K<=maxm)
	{
		cout<<"YES"<<endl;
		while(K)
		{
			int cnt;
			if(K == minm)
			{
				while(N)
				{
					cnt = nearest_set_bit(N);
					cout<<pow[cnt]<<" ";
					N-=pow[cnt];
				}
				break;
			}
			cnt = nearest_set_bit(N);
			int temp = pow[cnt];
			N -= temp;
			minm--;
			multiset<int> print_list; 
			print_list.insert(temp);
			K--;
			int temp2 = temp;
			while(print_list.size()!=temp2 && K!=max(0,minm))
			{
				auto it = print_list.find(temp);
				if(it == print_list.end())
				{
					if(temp <= 2)
					{
						break;
					}
					else
					{
						temp /= 2;
					}
				}
				else
				{
					print_list.erase(it);
					print_list.insert(temp/2);
					print_list.insert(temp/2);
					K--;	
				}
			}
			for(auto it = print_list.begin(); it!=print_list.end(); it++)
			{
				cout<<*it<<" ";
			}
		}
	}
	else
	{
		cout<<"NO";
	}
	cout<<endl;
	return 0;
}