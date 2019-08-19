/*
ID: ishan-sang
PROG: Equal
LANG: C++                  
*/

vector<int> Solution::equal(vector<int> &A) 
{
    int N = A.size();
    unordered_map<int,vector<int>> MAP;
    for(int n = 0; n<N; n++)
        MAP[A[n]].push_back(n);
    vector<int> ans;
    for(int i = 0; i<N-3; i++)
    {
        for(int j = i+1; j<N; j++)
        {
            for(int k = i+1; k<N-1; k++)
            {
                if(j == k)
                    continue;
                int t = A[i]+A[j]-A[k];
                if(MAP.find(t) != MAP.end())
                {
                    int r = upper_bound(MAP[t].begin(), MAP[t].end(), k) - MAP[t].begin();
                    while(r<MAP[t].size())
                    {
                        int it = MAP[t][r];
                        if(it>k && it!=j)
                        {
                            ans.insert(ans.begin(), {i,j,k,it});
                            return ans;
                        }
                        r++;
                    }
                        
                }
            }
        }
    }
    return ans;
}
