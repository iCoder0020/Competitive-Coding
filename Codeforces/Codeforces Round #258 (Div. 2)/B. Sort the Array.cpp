/*
ID: iCoder0020
PROG: Sort the Array
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	int A[N+1];
	int index1, index2;
	for(int n = 1; n<=N; n++)
		cin>>A[n];
	int n = 1;
	while(n+1<=N && A[n+1] - A[n] >= 0)
	{
		n++;
	}
	index1 = n;
	if(index1 == N)
	{
		cout<<"yes"<<endl<<"1 1"<<endl;
	}
	else
	{
		n = index1;
		while(n+1<=N && A[n+1] - A[n] <= 0)
		{
			n++;
		}
		index2 = n;
		// cout<<index1<<" "<<index2<<endl;
		if(index2 == N)
		{
			if(index1 == 1 || A[N] > A[index1-1])
			{
				cout<<"yes"<<endl<<index1<<" "<<N<<endl;
			}
			else
			{
				cout<<"no"<<endl;
			}
		}
		else
		{
			if(A[index2+1] > A[index1] && (index1 == 1 || A[index2] > A[index1-1]))
			{
				bool is_sorted = true;
				for(int i = index2+1; i<N; i++)
				{
					if(A[i+1] - A[i] < 0)
					{
						is_sorted = false;
						break;
					}
				}
				if(is_sorted)
				{
					cout<<"yes"<<endl<<index1<<" "<<index2<<endl;
				}
				else
				{
					cout<<"no"<<endl;
				}
			}
			else
			{
				cout<<"no"<<endl;
			}
		}
	}
	return 0;
}