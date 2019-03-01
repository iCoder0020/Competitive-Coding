/*
ID: ishan_sang
PROG: SUMNCR
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int T;
	cin>>T;
	for(long long int t = 0; t<T; t++)
	{
		long long int N;
		cin>>N;
		long int A[N];
		long long int count1_3 = 0;
		long long int even = 0;
		long long int oddmod4_1 = 0;
		vector<long long int>oddmod4_3;
		long long int pow[35];
		pow[0] = 1;
		for(long long int n = 1; n<35; n++)
		{
			pow[n] = 2*pow[n-1];
		}
		for(long long int n = 0; n<N; n++)
		{
			cin>>A[n];
			if(A[n] == 1 || A[n] == 3)
			{
				count1_3++;
			}
			else if(A[n]%2 == 0)
			{
				even++;
			}
			else if(A[n]%4 == 1)
			{
				oddmod4_1++;
			}
			else
			{
				oddmod4_3.push_back(A[n]);
			}
		}
		if(count1_3 == N)
		{
			if(N%2 == 0)
			{
				cout<<"0"<<endl;
			}
			else
			{
				cout<<"-1"<<endl;
			}
		}
		else if(N%2 == 0)
		{
			cout<<"0"<<endl;
		}
		else
		{
			if(even!=0)
			{
				cout<<"1"<<endl;
			}
			else if(oddmod4_1!=0)
			{
				cout<<"2"<<endl;
			}
			else
			{
				long long int min = 50;
				for(auto it = oddmod4_3.begin(); it!=oddmod4_3.end(); it++)
				{
					long long int num = 50;
					long long int temp = *it;
					long long int cnt = 0;
					while(temp)
					{
						if(temp%2 == 0)
						{
							num = cnt;
							break;
						}
						cnt++;
						temp/=2;
					}
					if(num < min)
					{
						min = num;
					}	
					if(min == 2)
					{
						break;
					}
				}
				if(min == 50)
				{
					cout<<"-1"<<endl;
				}
				else
				{
					cout<<pow[min]<<endl;
				}
			}
		}
	}
	return 0;
}