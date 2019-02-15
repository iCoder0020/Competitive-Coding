/*
ID: ishan_sang
PROG: FANCY
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d\n", &T);
	string S;
	for(int t = 0; t<T; t++)
	{	
		getline(cin, S);
		bool fancy = false;
		int len = S.length();
		for(int n = 0; n<len; n++)
		{
			if(S[n] == 'n')
			{
				if(n+2 < len)
				{
					if(S[n+1] == 'o' && S[n+2] == 't' && (n+3 == len || S[n+3] == ' ') && (n-1 == -1 || S[n-1] == ' '))
					{
						fancy = true;
						break;
					}
				}
			}
		}
		if(fancy)
		{
			cout<<"Real Fancy";
		}
		else
		{
			cout<<"regularly fancy";
		}
		cout<<endl;
	}
	return 0;
}