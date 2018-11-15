/*
ID: iCoder0020
PROG: Candies Distribution
LANG: C++                  
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int L[N], R[N];
	int arr[N];
	for(int l = 0; l<N; l++)
	{
		cin>>L[l];
	}
	for(int r = 0; r<N; r++)
	{
		cin>>R[r];
	}
	if(L[0]!=0 || R[N-1]!=0)
	{
		cout<<"NO\n";
	}
	else
	{
		for(int n = 0; n<N; n++)
		{
			if(L[n]+R[n] >= N)
			{
				cout<<"NO\n";
				return 0;
			}
			else
			{
				arr[n] = N-(L[n]+R[n]);
			}
		}
		int count;
		bool not_possible = false;
		for(int n = 0; n<N-1; n++)
		{
			count = 0;
			for(int m = n+1; m<N; m++)
			{
				if(arr[n] < arr[m])
				{
					count ++;
				}
			}
			if(count != R[n])
			{
				not_possible = true;
			}
		}
		for(int n = N-1; n>0; n--)
		{
			count = 0;
			for(int m = n-1; m>=0; m--)
			{
				if(arr[n] < arr[m])
				{
					count ++;
				}
			}
			if(count != L[n])
			{
				not_possible = true;
			}
		}

		if(not_possible)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
			for(int n = 0; n<N; n++)
			{
				cout<<arr[n]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}