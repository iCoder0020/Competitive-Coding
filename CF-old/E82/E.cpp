#include<bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1000

int32_t main()
{
    int TC;
    cin>>TC;
    while(TC--)
    {
        string S,T;
        cin>>S>>T;
        int N = S.length();
        int M = T.length();
        vector<vector<int>>next(N, vector<int>(26, INF));
        if(N == 1)
        {
        	if(S == T)
        		cout<<"YES";
        	else
        		cout<<"NO";
        	cout<<endl;
        	continue;
        }
        for(int n = N-2; n>=0; n--)
        {
            for(int i = 0; i<26; i++)
            {
                if(S[n+1]-'a' == i)
                    next[n][i] = n+1;
                else
                    next[n][i] = next[n+1][i];
            }
        }
        vector< vector< vector< vector<int> > > >dp(M, vector<vector<vector<int>>>(2));
 
		//dp[i][j] -> 	vector of sequences of indices 
		//				for making T[0...(i-1)] using j+1 operations
 
        for(int i = 0; i<M; i++)
        {
        	int x = T[i]-'a';
            int k;
            if(i == 0)
            {
                if(S[0] == T[i])
                    k = 0;
                else
                    k = next[i][x];
                while(k != INF)
                {
                    dp[i][0].push_back({k});
                    dp[i][1].push_back({k});
                    k = next[k][x];
                }
            }
            else
            {
            	//dp[i-1][0] -> dp[i][0]
 				for(auto it: dp[i-1][0])
 				{
 					auto jt = it.back();
 					k = next[jt][x];
 					vector<int> X;
 					vector<int> prev = it;
 					while(k != INF)
 					{
						X.push_back(k); 						
	                    k = next[k][x];
 					}	
 					for(auto kt: X)
 					{
 						vector<int> temp = prev;
 						temp.push_back(kt);
 						dp[i][0].push_back(temp);
 					}
 				}

 				//dp[i-1][0] -> dp[i][1]
 				for(auto it: dp[i-1][0])
 				{
 					if(S[0] == T[i])
                    	k = 0;
               		else
                    	k = next[0][x];
                    vector<int> X;
 					vector<int> prev = it;
                    while(k != INF)
 					{
						if(find(it.begin(), it.end(), k) == it.end())
							X.push_back(k);
						k = next[k][x];
 					}	
 					for(auto kt: X)
 					{
 						vector<int> temp = prev;
 						temp.push_back(kt);
 						dp[i][1].push_back(temp);
 					}
 				}

 				//dp[i-1][1] -> dp[i][1]
 				for(auto it: dp[i-1][1])
 				{
 					auto jt = it.back();
 					k = next[jt][x];
 					vector<int> X;
 					vector<int> prev = it;
 					while(k != INF)
 					{
						if(find(it.begin(), it.end(), k) == it.end())
							X.push_back(k);			
	                    k = next[k][x];
 					}	
 					for(auto kt: X)
 					{
 						vector<int> temp = prev;
 						temp.push_back(kt);
 						dp[i][1].push_back(temp);
 					}
 				}

 				for(int j = 0; j<2; j++)
 					dp[i-1][j].clear();
            }
        }
        // for(int i = 0; i<M; i++)
        // {
        // 	for(int j = 0; j<2; j++)
        // 	{
        		
        // 		for(int k = 0; k<dp[i][j].size(); k++)
        // 		{
        // 			cout<<i<<" "<<j<<" "<<k<<": ";
        // 			for(auto it: dp[i][j][k])
        // 				cout<<it<<" ";
        // 			cout<<endl;
        // 		}
        // 	}
        // }

        if(dp[M-1][0].size()>=1 || dp[M-1][1].size()>=1)
        	cout<<"YES";
        else
        	cout<<"NO";
        cout<<endl;
    }   
    return 0;
}