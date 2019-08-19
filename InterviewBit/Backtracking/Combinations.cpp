/*
ID: ishan-sang
PROG: Combinations
LANG: C++                  
*/

void recurse(vector<vector<int>> &ans, vector<bool> &include, int x, int cnt, int N, int K)
{
    if(cnt >= K)
    {
        vector<int>temp;
        for(int n = 1; n<=N; n++)
            if(include[n])
                temp.push_back(n);
        ans.push_back(temp);
        return;
    }
    if(x>N)
        return;
    include[x] = true;
    recurse(ans, include, x+1, cnt+1, N, K);
    include[x] = false;
    recurse(ans, include, x+1, cnt, N, K);
}

vector<vector<int> > Solution::combine(int A, int B) 
{
    vector<vector<int>> ans;
    vector<bool> include(A+1, false);
    recurse(ans, include, 1, 0, A, B);
    sort(ans.begin(), ans.end());
    return ans;
}
