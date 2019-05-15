/*
ID: ishan_sang
PROG: FENCE
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int K;
    	cin>>K;
    	map<pair<int,int>, int> M;
    	while(K--)
    	{
    		int r,c;
    		cin>>r>>c;
    		M[{r,c}] = 4;
    		if(M.find({r-1,c})!=M.end())
    		{
    			M[{r-1,c}]--;
    			M[{r,c}]--;
    		}
    		if(M.find({r,c-1})!=M.end())
    		{
    			M[{r,c-1}]--;
    			M[{r,c}]--;
    		}
    		if(M.find({r+1,c})!=M.end())
    		{
    			M[{r+1,c}]--;
    			M[{r,c}]--;
    		}
    		if(M.find({r,c+1})!=M.end())
    		{
    			M[{r,c+1}]--;
    			M[{r,c}]--;
    		}
    	}
    	int sum = 0;
    	for(auto it: M)
    		sum += it.second;
    	cout<<sum<<endl;
    }
}