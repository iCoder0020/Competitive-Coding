/*
ID: ishan_sang
PROG: ABGAME
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
    	int count_r = 0;
    	int count_g = 0;
    	int count = 0;
    	if(S.length() == 1)
    	{
    		cout<<"yes\n";
    		continue;
    	}
    	for(int s = 0; s<S.length(); s++)
    	{
    		if(S[s] == 'R')
    		{
    			count_r++;
    		}
    		else
    		{
    			count_g++;
    		}
    		if(S[s] == S[(s+1)%S.length()])
    		{
    			count++;
    		}
    	}
    	if(count_g == count_r && (count == 0 || count == 2))
    	{
    		cout<<"yes\n";
    	}
    	else
    	{
    		cout<<"no\n";
    	}
    }
    return 0;
} 