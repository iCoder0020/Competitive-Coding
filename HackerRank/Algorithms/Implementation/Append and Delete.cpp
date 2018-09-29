/*
ID: iCoder0020
PROG: Append and Delete
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

bool check_validity(int min_conversions, int K)
{
	while(K>=min_conversions)
	{
		if(K == min_conversions)
		{
			return true;
		}
		K -= 2;
	}
	return false;
}

int main()
{
	string S_old, S_new;
    int K;
    string ans;
    int min_conversions;
    cin>>S_old>>S_new;
    cin>>K;
    int len = (S_old.length()<S_new.length())?S_old.length():S_new.length();
    for(int i=0; i<len; i++)
    {
    	if(S_old[i]!=S_new[i])
    	{
    		min_conversions = (S_old.length()-i) + (S_new.length()-i);
    		break;
    	}
    	if(i == len-1)
    	{
    		min_conversions = ((S_new.length()-i-1) == 0)?(S_old.length()-i-1):(S_new.length()-i-1);
    	}
    }
    if(K<min_conversions)
    {
    	ans = "No";
    }
    else if(S_old.length() + S_new.length() <= K)
    {
    	ans = "Yes";
    }
    else if(check_validity(min_conversions, K))
    {
    	ans = "Yes";
    }
    else
    {
    	ans = "No";
    }
    cout<<ans<<"\n";
	return 0;
}
