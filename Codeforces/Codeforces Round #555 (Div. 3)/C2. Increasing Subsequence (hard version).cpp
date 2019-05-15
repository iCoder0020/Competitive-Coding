/*
ID: iCoder0020
PROG: Increasing Subsequence (hard version)
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	int A[N];
	for(int n = 0; n<N; n++)
		cin>>A[n];
	int l = 0;
	int r = N-1;
	int temp = 0;
	string ans = "";
	while(1)
	{
		if(l == r)
		{
			if(A[l] > temp)
				ans+='R';
			l++;
		}
		if(l>r)
			break;
		if(A[l] <= temp && A[r] <= temp)
			break;
		if(A[l] <= temp)
		{
			temp = A[r];
			ans+='R';
			r--;
		}
		else if(A[r] <= temp)
		{
			temp = A[l];
			ans+='L';
			l++;
		}
		else
		{
			if(A[l] < A[r])
			{
				temp = A[l];
				ans+='L';
				l++;
			}
			else if(A[r] < A[l])
			{
				temp = A[r];
				ans+='R';
				r--;
			}
			else
			{
				 // cout<<l<<" "<<r<<endl;

				string ans1 = ans;
				string ans2 = ans;

				int temp1 = temp;

				for(int i = l; i<=r; i++)
				{
					if(A[i] > temp1)
					{
						ans1+='L';
						temp1 = A[i];
					}
					else
					{
						break;
					}
				}

				temp1 = temp;

				for(int i = r; i>=l; i--)
				{
					if(A[i] > temp1)
					{
						ans2+='R';
						temp1 = A[i];
					}
					else
					{
						break;
					}
				}

				// cout<<ans1<<" "<<ans2<<endl;

				ans = (ans1.size()>ans2.size())?ans1:ans2;

				break;
			}
		}
	}
	cout<<ans.length()<<endl<<ans<<endl;
	return 0;
}