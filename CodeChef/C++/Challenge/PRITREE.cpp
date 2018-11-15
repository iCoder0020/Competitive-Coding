/*
ID: ishan_sang
PROG: PRITREE
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define N_MAX 20000
int primes[N_MAX+1];

void find_primes()
{
	primes[0] = 0;
	primes[1] = 0;
	for(int i = 2; i<N_MAX+1; i++)
	{
		primes[i] = i;
	}
	for(int i = 2; i<=N_MAX/2+1; i++)
	{
		for(int j = 2; i*j<=N_MAX+1; j++)
		{
			primes[i*j] = 0;
		}
	}
}

int main()
{
	int N;
	cin>>N;
	find_primes();
	int temp;
	vector <pair<int,int>> prime_node;
	vector <pair<int,int>> composite_node;
	int num_2 = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>temp;
		if(temp == 2)
		{
			num_2++;
		}
		if(primes[temp]!=0)
		{
			prime_node.push_back(make_pair(n,temp));
		}
		else
		{
			composite_node.push_back(make_pair(n,temp));
		}
	}
	if(prime_node.size() == 0)
	{
		for(int n = 0; n<N-1; n++)
		{
			cout<<n+1<<" "<<n+2<<endl;
		}
	}
	else if(composite_node.size() == 0)
	{
		int first_element = 1;
		if(N%2 == 1 && num_2 == 1)
		{
			for(int n = 0; n<prime_node.size(); n++)
			{
				if(prime_node[n].second == 2)
				{
					first_element = prime_node[n].first + 1;
				}
			}
			for(int n = 0; n<N; n++)
			{
				if(n+1 != first_element)
				{
					cout<<first_element<<" "<<n+1<<endl;
				}
			}
		}
		else
		{
			for(int n = 0; n<prime_node.size(); n++)
			{
				if(prime_node[n].second != 2)
				{
					first_element = prime_node[n].first + 1;
					break;
				}
			}
			for(int n = 0; n<N; n++)
			{
				if(n+1 != first_element)
				{
					cout<<first_element<<" "<<n+1<<endl;
				}
			}	
		}
	}
	else
	{
		for(int n = 0; n<N; n++)
		{
			if(n+1 != composite_node[0].first + 1)
			{
				cout<<composite_node[0].first+1<<" "<<n+1<<endl;
			}
		}
	}
	return 0;
}