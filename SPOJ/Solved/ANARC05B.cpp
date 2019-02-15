/*
ID: icoder_0020
PROG: ANARC05B
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	while(cin>>N)
	{
		if(N!=0)
		{
			int A,B;
			A = N;

			int arr1[A];
			int dp1[A];
			for(int a = 0; a<A; a++)
			{
				cin>>arr1[a];
				if(a == 0)
				{
					dp1[a] = arr1[a];
				}
				else
				{
					dp1[a] = dp1[a-1] + arr1[a];
				}
			}

			cin>>B;
			int arr2[B];
			int dp2[B];
			for(int b = 0; b<B; b++)
			{
				cin>>arr2[b];
				if(b == 0)
				{
					dp2[b] = arr2[b];
				}
				else
				{
					dp2[b] = dp2[b-1] + arr2[b];
				}
			}
			
			vector<pair<int,int>>common;

			for(int a = 0; a<A; a++)
			{
				if(binary_search(arr2, arr2+B, arr1[a]))
				{
					auto it = lower_bound(arr2, arr2+B, arr1[a]);
					common.push_back({a, it-arr2});
				}
			}	
			common.push_back({A-1, B-1});

			int sum = 0;

			int curr_a, curr_b, prev_a, prev_b;

			for(int n = 0; n<common.size(); n++)
			{
				curr_a = common[n].first;
				curr_b = common[n].second;
				if(n == 0)
				{
					if(dp1[curr_a] > dp2[curr_b])
					{
						sum += dp1[curr_a];
					}
					else
					{
						sum += dp2[curr_b];
					}
				}
				else
				{
					sum += max(dp1[curr_a] - dp1[prev_a], dp2[curr_b] - dp2[prev_b]);	
				}
				prev_a = curr_a;
				prev_b = curr_b;
			}
			cout<<sum<<endl;
		}
		else
		{
			break;
		}
	}
	return 0;
}