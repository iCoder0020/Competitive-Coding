/*
ID: iCoder0020
PROG: Superhero Transformation
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	string S,T;
	cin>>S>>T;
	if(S.length() != T.length())
	{
		cout<<"No"<<endl;
	}
	else
	{
		bool possible = true;
		for(int n = 0; n<S.length(); n++)
		{
			if(S[n] == 'a' || S[n] == 'e' || S[n] == 'i' || S[n] == 'o' || S[n] == 'u')
			{
				if(T[n] != 'a' && T[n] != 'e' && T[n] != 'i' && T[n] != 'o' && T[n] != 'u')
				{
					possible = false;
					break;
				}
			}
			else
			{
				if(T[n] == 'a' || T[n] == 'e' || T[n] == 'i' || T[n] == 'o' || T[n] == 'u')
				{
					possible = false;
					break;
				}
			}
		}
		if(possible)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}