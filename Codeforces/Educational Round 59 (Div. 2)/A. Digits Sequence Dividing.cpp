/*
ID: iCoder0020
PROG: Digits Sequence Dividing
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		string S;
		cin>>S;
		if(N == 2 && S[0] >= S[1])
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl<<2<<endl;
			cout<<S[0]<<" ";
			for(int i = 1; i<N; i++)
			{
				cout<<S[i];
			}
			cout<<endl;
		}
	}
	return 0;
}