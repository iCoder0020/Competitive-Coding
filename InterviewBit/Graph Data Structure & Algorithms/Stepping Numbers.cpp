/*
ID: ishan-sang
PROG: Stepping Numbers
LANG: C++                  
*/

void dfs(vector<vector<int>> &g, vector<int> &ans, int num, int A, int B)
{
    if(num > B)
        return;
    if(num >=A)
        ans.push_back(num);
    for(auto it: g[num%10])
        dfs(g, ans, num*10+it, A, B);
}
vector<int> Solution::stepnum(int A, int B) 
{
    int num = 0;
    vector<vector<int>>g(10);
    vector<int>ans;
    for(int i = 0; i<=9; i++)
    {
        if(i-1 >= 0)
            g[i].push_back(i-1);
        if(i+1 <= 9)
            g[i].push_back(i+1);
    }
    for(int i = 1; i<=9; i++)
        dfs(g, ans, i, A, B);
    if(A == 0)
        ans.push_back(0);
    sort(ans.begin(), ans.end());
    return ans;
}
