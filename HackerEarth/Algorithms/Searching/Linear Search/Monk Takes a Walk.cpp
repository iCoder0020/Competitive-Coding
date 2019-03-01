/*
ID: icoder_0020
PROG: Monk Takes a Walk
LANG: C++                  
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int T;
	cin>>T;
	string S;
	for(int t = 0; t<T; t++)
	{
		cin>>S;
		int count = 0;
		for(int n = 0; n<S.length(); n++)
		{
			if(S[n] == 'a' || S[n] == 'e' || S[n] == 'i' || S[n] == 'o' || S[n] == 'u')
			{
				count++;
			}
			if(S[n] == 'A' || S[n] == 'E' || S[n] == 'I' || S[n] == 'O' || S[n] == 'U')
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
}