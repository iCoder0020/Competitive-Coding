/*
ID: ishan_sang
PROG: SECPASS
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int N;
	string S;
	char first_letter;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		cin>>S;
		first_letter = S[0];
		vector<int>index;
		for(int n = 0; n<N; n++)
		{
			if(S[n] == first_letter)
			{
				index.push_back(n);
			}
		}
		if(index.size() == 1)
		{
			cout<<S<<endl;
		}
		else
		{
			int ans = 0;
			bool cont = true;
			for(int i = 1; i<=index[1]-index[0]; i++)
			{
				for(int j = 1; j<index.size(); j++)
				{
					if(index[j] + i >= N || (S[index[0] + i] != S[index[j] + i]))
					{
						ans = i-1;
						cont = false;
						break;
					}
				}
				if(cont == false)
				{
					break;
				}
			}
			for(int n = 0; n<=ans; n++)
			{
				cout<<S[n];
			}
			cout<<endl;
		}
	}
	return 0;
}