/*
ID: iCoder0020
PROG: Vasya And Password
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
		string S;
		vector <int> indices[3];
		cin>>S;
		for(int n = 0; n<S.length(); n++)
		{
			if(S[n]>='a' && S[n]<='z')
			{
				indices[0].push_back(n);
			}
			else if(S[n]>='A' && S[n]<='Z')
			{
				indices[1].push_back(n);
			}
			else if(S[n]>='0' && S[n]<='9')
			{
				indices[2].push_back(n);
			}
		}
		char temp[3] = {'a', 'A', '0'};
		for(int i = 0; i<3; i++)
		{
			if(indices[i].size() == 0)
			{
				if(i!=0 && indices[0].size() > 1)
				{
					S[indices[0].back()] = temp[i];
					indices[0].pop_back();
				}
				else if(i!=1 && indices[1].size() > 1)
				{
					S[indices[1].back()] = temp[i];
					indices[1].pop_back();
				}
				else if(i!=2 && indices[2].size() > 1)
				{
					S[indices[2].back()] = temp[i];
					indices[2].pop_back();
				}
			}
		}
		cout<<S<<endl;
	}
	return 0;
}