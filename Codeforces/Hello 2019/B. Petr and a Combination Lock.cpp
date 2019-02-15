/*
ID: iCoder0020
PROG: Petr and a Combination Lock
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N;
	cin>>N;
	int arr[N];
	bool answer = false;
	for(int n = 0; n<N; n++)
	{
		cin>>arr[n];
	}
	for(int i = 0; i<(1<<N); i++)
	{
		int angle = 0;
		for(int n = 0; n<N; n++)
		{
			if(i&(1<<n))
			{
				angle += arr[n];
			}
			else
			{
				angle -= arr[n];
			}
		}
		if(angle % 360 == 0)
		{
			cout<<"YES"<<endl;
			answer = true;
			break;
		}
	}
	if(answer == false)
	{
		cout<<"NO"<<endl;
	}
	return 0;
}