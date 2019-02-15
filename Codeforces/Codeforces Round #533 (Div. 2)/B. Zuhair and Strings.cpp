/*
ID: iCoder0020
PROG: Zuhair and Strings
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N,K;
	cin>>N>>K;
	string S;
	cin>>S;
	int x[26] = {0};
	int k;
	for(int n = 0; n<S.length(); n++)
	{
		char c = S[n];
		for(k = 0; k<K; k++)
		{
			if(n+k<S.length())
			{
				if(S[n+k] == c)
				{
					if(k == K-1)
					{
						x[c-'a']++;
					}
				}
				else
				{
					break;
				}
			}
		}
		n+=k-1;
	}
	/*for(int n = 0; n<26; n++)
	{
		cout<<x[n]<<" ";
	}
	cout<<endl;*/
	cout<<*max_element(x, x+26)<<endl;
	return 0;
}