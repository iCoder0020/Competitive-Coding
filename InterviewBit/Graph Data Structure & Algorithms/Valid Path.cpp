/*
ID: ishan-sang
PROG: Valid Path
LANG: C++                  
*/

bool safe(int N, int R, vector<int>&x, vector<int>&y, int i, int j)
{
    for(int n = 0; n<N; n++)
    {
        int dx = x[n]-i;
        int dy = y[n]-j;
        if(dx*dx + dy*dy <= R*R)
            return false;
    }
    return true;
}
string Solution::solve(int X, int Y, int N, int R, vector<int> &x, vector<int> &y) 
{
    vector<vector<bool>> vis(X+1, vector<bool>(Y+1, false));
    queue<pair<int,int>>Q;
    Q.push({0,0});
    vis[0][0]=true;
    while(!Q.empty())
    {
        int i = Q.front().first;
        int j = Q.front().second;
        Q.pop();
        
        if(i == X && j == Y)
            return "YES";
            
        if(i+1<=X)
        {
            if(j-1>=0 && !vis[i+1][j-1] && safe(N, R, x, y, i+1, j-1))
            {
                Q.push({i+1, j-1});
                vis[i+1][j-1] = true;
            }
            if(!vis[i+1][j] && safe(N, R, x, y, i+1, j))
            {
                Q.push({i+1, j});
                vis[i+1][j] = true;
            }
            if(j+1<=Y && !vis[i+1][j+1] && safe(N, R, x, y, i+1, j+1))
            {
                Q.push({i+1, j+1});
                vis[i+1][j+1] = true;
            }
        }
        
        if(j-1>=0 && !vis[i][j-1] && safe(N, R, x, y, i, j-1))
        {
            Q.push({i, j-1});
            vis[i][j-1] = true;
        }
        if(j+1<=Y && !vis[i][j+1] && safe(N, R, x, y, i, j+1))
        {
            Q.push({i, j+1});
            vis[i][j+1] = true;
        }
        
        if(i-1>=0)
        {
            if(j-1>=0 && !vis[i-1][j-1] && safe(N, R, x, y, i-1, j-1))
            {
                Q.push({i-1, j-1});
                vis[i-1][j-1] = true;
            }
            if(!vis[i-1][j] && safe(N, R, x, y, i-1, j))
            {
                Q.push({i-1, j});
                vis[i-1][j] = true;
            }
            if(j+1<=Y && !vis[i-1][j+1] && safe(N, R, x, y, i-1, j+1))
            {
                Q.push({i-1, j+1});
                vis[i-1][j+1] = true;
            }
        }
    }
    return "NO";
}
