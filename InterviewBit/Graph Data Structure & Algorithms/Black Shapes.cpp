/*
ID: ishan-sang
PROG: Black Shapes
LANG: C++                  
*/

int cnt;

void visit(vector<vector<char>> &grid, vector<vector<bool>> &vis, int x, int y, int N, int M)
{
    if(vis[x][y])
        return;
    vis[x][y] = true;
    if(x+1<N && grid[x+1][y] == 'X')
        visit(grid, vis, x+1, y, N, M);
    if(y+1<M && grid[x][y+1] == 'X')
        visit(grid, vis, x, y+1, N, M);
    if(x-1>=0 && grid[x-1][y] == 'X')
        visit(grid, vis, x-1, y, N, M);
    if(y-1>=0 && grid[x][y-1] == 'X')
        visit(grid, vis, x, y-1, N, M);
}

int Solution::black(vector<string> &A) 
{
    cnt = 0;
    int N = A.size(), M = A[0].size();
    vector<vector<char>> grid(N);
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    for(int n = 0; n<N; n++)
        for(auto it: A[n])
            grid[n].push_back(it);
    for(int n = 0; n<N; n++)
    {
        for(int m = 0; m<M; m++)
        {
            if(grid[n][m] == 'X' && !vis[n][m])
            {
                visit(grid, vis, n, m, N, M);
                cnt++;
            }
        }
    }
    return cnt;
}
