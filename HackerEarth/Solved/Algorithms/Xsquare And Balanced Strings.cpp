/*
ID: icoder_0020
PROG: Xsquare And Balanced Strings
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
		string S;
		cin>>S;
		int ch_count[26] = {0};
		for(int s = 0; s<S.length(); s++)
		{
			ch_count[(int)(S[s])-97]++;
		}
		for(int n = 0; n<26; n++)
		{
			if(ch_count[n]&1)
			{
				cout<<-1<<endl;
				break;
			}
			if(n == 25)
			{
				cout<<1<<endl;
			}
		}
	}
}