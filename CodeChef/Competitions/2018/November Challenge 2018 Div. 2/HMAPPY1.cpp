/*
ID: ishan_sang
PROG: HMAPPY1
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long int

using namespace std;

int32_t main()
{
	int N,Q,K;
	cin>>N>>Q>>K;

	int A[N];
	int count_zero, count_one;
	char query[Q];

	count_zero = 0;
	count_one = 0;

	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		if(A[n] == 0)
		{
			count_zero++;
		}
		else
		{
			count_one++;
		}
	}

	if(count_zero == 0)
	{
		for(int q = 0; q<Q; q++)
		{
			cin>>query[q];
			if(query[q] == '?')
			{
				if(N>K)
				{
					cout<<K<<endl;
				}
				else
				{
					cout<<N<<endl;
				}
			}
		}
	}
	else if(count_one == 0)
	{
		for(int q = 0; q<Q; q++)
		{
			cin>>query[q];
			if(query[q] == '?')
			{
				cout<<"0"<<endl;
			}
		}
	}
	else
	{
		int left,right,left_backup;
		int left2, right2;

		int dpA[N] = {0};
		int maxdp;
		int maxdp2;

		dpA[0] = A[0];
		maxdp = dpA[0];
		maxdp2 = dpA[0];
		left = 0;
		right = 0;
		left_backup = 0;
		left2 = 0;
		right2 = 0;

		for(int i = 1; i<N; i++)
		{
			if(A[i] == 1)
			{
				if(A[i-1] == 0)
				{
					left_backup = i;
				}
				dpA[i] = dpA[i-1] + 1;
			}
			if(dpA[i] > maxdp)
			{
				maxdp = dpA[i];
				left = left_backup;
				right = i;
			}
		}

		for(int i = 0; i<N; i++)
		{
			dpA[i] = 0;
		}

		for(int i = 1; i<left; i++)
		{
			if(A[i] == 1)
			{
				if(A[i-1] == 0)
				{
					left_backup = i;
				}
				dpA[i] = dpA[i-1] + 1;
			}
			if(dpA[i] > maxdp2)
			{
				maxdp2 = dpA[i];
				left2 = left_backup;
				right2 = i;
			}
		}
		for(int i = 0; i<N; i++)
		{
			dpA[i] = 0;
		}
		for(int i = right+1; i<N; i++)
		{
			if(A[i] == 1)
			{
				if(A[i-1] == 0)
				{
					left_backup = i;
				}
				dpA[i] = dpA[i-1] + 1;
			}
			if(dpA[i] > maxdp2)
			{
				maxdp2 = dpA[i];
				left2 = left_backup;
				right2 = i;
			}
		}
		if(!(A[0] == 1 && A[N-1] == 1))
		{
			for(int q = 0; q<Q; q++)
			{
				int ans1,ans3,ans;
				cin>>query[q];
				if(query[q] == '!')
				{
					left = (left+1)%N;
					right = (right+1)%N;
					left2 = (left2+1)%N;
					right2 = (right2+1)%N;
				}
				else
				{
					if(left > right)
					{
						ans1 = max(right+1, N-left);
					}
					else
					{
						ans1 = right-left+1;
					}
					if(left2 > right2)
					{
						ans3 = max(right2+1, N-left2);
					}
					else
					{
						ans3 = right2-left2+1;
					}
					ans = max(ans1,ans3);
					if(ans>K)
					{
						cout<<K<<endl;
					}
					else
					{
						cout<<ans<<endl;
					}
				}
			}
		}

		else 
		{
			int index1, index2;
			
			index1 = N-1;
			index2 = 0;
			while(A[index1] == 1)
			{
				index1--;
			}
			index1++;
			while(A[index2] == 1)
			{
				index2++;
			}
			index2--;

			for(int q = 0; q<Q; q++)
			{
				int ans1, ans2, ans3, ans;
				cin>>query[q];
				if(query[q] == '!')
				{
					index1 = (index1+1)%N;
					index2 = (index2+1)%N;
					left = (left+1)%N;
					right = (right+1)%N;
					left2 = (left2+1)%N;
					right2 = (right2+1)%N;
				}
				else
				{
					if(left > right)
					{
						ans1 = max(right+1, N-left);
					}
					else
					{
						ans1 = right-left+1;
					}
					if(left2 > right2)
					{
						ans3 = max(right2+1, N-left2);
					}
					else
					{
						ans3 = right2-left2+1;
					}
					if(index1 > index2)
					{
						ans2 = max(index2+1, N-index1);
					}
					else
					{
						ans2 = index2-index1+1;
					}
					ans = max(ans1, ans2);
					ans = max(ans, ans3);
					if(ans>K)
					{
						cout<<K<<endl;
					}
					else
					{
						cout<<ans<<endl;
					}
				}
			}
		}
	}
	return 0;
}