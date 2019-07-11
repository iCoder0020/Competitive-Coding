/*
ID: ishan-sang
PROG: Pascal Triangle
LANG: C++                  
*/

vector<vector<int> > Solution::solve(int A) 
{
    vector<vector<int>>ans;
    if(A == 0)
        return ans;
    for(int n = 1; n<=A; n++)
    {
        vector<int>v;
        for(int m = 1; m<=n; m++)
        {
            if(m == n || m == 1)
                v.push_back(1);
            else
                v.push_back(ans[n-2][m-2] + ans[n-2][m-1]);
        }
        ans.push_back(v);
    }
    return ans;
}
