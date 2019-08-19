/*
ID: ishan-sang
PROG: Capture Regions on Board
LANG: C++                  
*/

bool capture;
void visit(vector<vector<char>> &A, vector<vector<bool>> &vis, int x, int y, int N, int M)
{
    if(vis[x][y])
        return;
    vis[x][y] = true;
    if(x+1>=N || y+1>=M || x-1<0 || y-1<0)
        capture = false;
    if(x+1<N && A[x+1][y] == 'O')
        visit(A, vis, x+1, y, N, M);
    if(y+1<M && A[x][y+1] == 'O')
        visit(A, vis, x, y+1, N, M);
    if(x-1>=0 && A[x-1][y] == 'O')
        visit(A, vis, x-1, y, N, M);
    if(y-1>=0 && A[x][y-1] == 'O')
        visit(A, vis, x, y-1, N, M);
}
void capt(vector<vector<char>> &A, vector<vector<bool>> &vis2, int x, int y, int N, int M)
{
    if(vis2[x][y])
        return;
    vis2[x][y] = true;
    A[x][y] = 'X';
    if(x+1<N && A[x+1][y] == 'O')
        capt(A, vis2, x+1, y, N, M);
    if(y+1<M && A[x][y+1] == 'O')
        capt(A, vis2, x, y+1, N, M);
    if(x-1>=0 && A[x-1][y] == 'O')
        capt(A, vis2, x-1, y, N, M);
    if(y-1>=0 && A[x][y-1] == 'O')
        capt(A, vis2, x, y-1, N, M);
}
void Solution::solve(vector<vector<char> > &A) 
{
    int N = A.size(), M = A[0].size();
    vector<vector<bool>> vis (N, vector<bool>(M, false));
    vector<vector<bool>> vis2 (N, vector<bool>(M, false));
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            if(A[i][j] == 'O' && !vis[i][j])
            {
                capture = true;       
                visit(A, vis, i, j, N, M);
                if(capture)
                    capt(A, vis2, i, j, N, M);
            }
        }
    }
}
    