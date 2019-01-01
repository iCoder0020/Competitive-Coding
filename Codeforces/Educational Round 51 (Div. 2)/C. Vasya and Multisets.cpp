/*
ID: iCoder0020
PROG: Vasya and Multisets
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int count[101] = {0};
	int N;
	int nice = 0;
	cin>>N;
	int A[N];
	bool possible = false;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n];
		count[A[n]]++;
	}
	for(int n = 1; n<=100; n++)
	{
		if(count[n] == 1)
		{
			nice++;
		}
		if(count[n] >= 3)
		{
			possible = true;
		}
	}
	if(nice%2 == 0)
	{
		cout<<"YES"<<endl;
		int cnt = 0;
		for(int n = 0; n<N; n++)
		{
			if(count[A[n]] == 1)
			{
				if(cnt%2 == 0)
				{
					cout<<"A";
				}
				else
				{
					cout<<"B";
				}
				cnt++;
			}
			else
			{
				cout<<"A";
			}
		}
		cout<<endl;
	}
	else
	{
		if(possible)
		{
			int index;
			cout<<"YES"<<endl;
			int a = 0;
			int b = 0;
			string temp;
			for(int n = 0; n<N; n++)
			{
				if(count[A[n]] >= 3)
				{
					index = n;
					break;
				}
			}
			for(int n = 0; n<N; n++)
			{
				if(n!=index && A[n] == A[index])
				{
					cout<<temp;
				}
				else if(count[A[n]] == 1 || index == n)
				{
					if(b<a)
					{
						cout<<"B";
						b++;
						if(index == n)
						{
							temp ="A";
						}
					}
					else
					{
						cout<<"A";
						a++;
						if(index == n)
						{
							temp = "B";
						}
					}
				}
				else
				{
					cout<<"A";
				}
			}
			cout<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}