/*
ID: ishan_sang
PROG: HP18
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int t = 0; t<T; t++)
	{
		int N,A,B;
		cin>>N>>B>>A;
		int alice = 0, bob = 0, common = 0;
		int arr[N];
		for(int n = 0; n<N; n++)
		{
			cin>>arr[n];
			if(arr[n]%A == 0 && arr[n]%B == 0)
			{
				common++;
			}
			else if(arr[n]%A == 0)
			{
				alice++;
			}
			else if(arr[n]%B == 0)
			{
				bob++;
			}
		}
		if((common == 0 && bob <= alice) || (common != 0 && bob+1<=alice))
		{
			cout<<"ALICE"<<endl;
		}
		else
		{
			cout<<"BOB"<<endl;
		}
	}
	return 0;
}