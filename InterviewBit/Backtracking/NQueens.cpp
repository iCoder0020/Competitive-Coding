/*
ID: ishan-sang
PROG: NQueens
LANG: C++                  
*/

bool check_safety(vector<string> &curr, int x, int y, int N)
{
    int d1 = y-x;
    int d2 = y+x;
    for(int n = 0; n<N; n++)
    {
        if(curr[x][n] == 'Q')
            return false;
        if(curr[n][y] == 'Q')
            return false;
        if(n+d1<N && n+d1>=0 && curr[n][n+d1] == 'Q')
            return false;
        if(d2-n>=0 && d2-n<N && curr[n][d2-n] == 'Q')
            return false;
    }
    return true;
}
void f(vector<vector<string>> &ans, vector<string> &curr, int cnt, int N)
{
    if(cnt >= N)
    {
        ans.push_back(curr);
        return;
    }
    for(int i = 0; i<N; i++)
    {
        if(check_safety(curr, cnt, i, N))
        {
            curr[cnt][i] = 'Q';
            f(ans, curr, cnt+1, N);
            curr[cnt][i] = '.';
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int A) 
{
    vector<vector<string>> ans;
    ans.clear();
    string empty = "";
    for(int n = 0; n<A; n++)
        empty += '.';
    vector<string> curr(A, empty);
    f(ans, curr, 0, A);
    return ans;
}
