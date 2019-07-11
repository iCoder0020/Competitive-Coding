/*
ID: iCoder0020
PROG: Email from Polycarp
LANG: C++                  
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main()
{
	int N;
	cin>>N;
	while(N--)
	{
		string S,T;
		cin>>S>>T;
		bool poss = true;
		int i = 0, j = 0;
		while(1)
		{
			// cout<<i<<" "<<j<<endl;
			if(i<T.size() && j<S.size() && T[i] == S[j])
			{
				i++;
				j++;
			}
			else if(i>0 && i<T.size() && T[i] == T[i-1])
			{
				i++;
			}
			else
			{
				if(i == T.size() && j == S.size())
					break;
				else
				{
					poss = false;
					break;
				}
			}
		}
		if(poss)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0; 
}