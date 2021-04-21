#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int TC;
	cin>>TC;
	while(TC--)
	{
		string T;
		cin>>T;
		bool diff = false;
		char c = T[0];
		for(int n = 1; n<T.length(); n++)
		{
			if(c != T[n])
			{
				diff = true;
				break;
			}
		}
		if(!diff)
			cout<<T<<endl;
		else
		{
			int i = 1;
			string S = "";
			char p = T[0];
			while(1)
			{
				S+=p;
				p = (p == '0')?'1':'0';
				if(i == T.length())
					break;
				if(p == T[i])
					i++;
			}
			cout<<S<<endl;
		}
	}
	return 0;
}
