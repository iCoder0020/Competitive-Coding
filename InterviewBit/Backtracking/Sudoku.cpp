/*
ID: ishan-sang
PROG: Sudoku
LANG: C++                  
*/

vector<vector<char>> ans;

bool check(vector<vector<char>> &A, char ch, int i, int j, int N)
{
    for(int n = 0; n<N; n++)
    {
        if(A[i][n] == ch)
            return false;
        if(A[n][j] == ch)
            return false;
    }
    int sq_N = sqrt(N);
    int i_bl = (i/sq_N)*sq_N;
    int j_bl = (j/sq_N)*sq_N;
    for(int n = i_bl; n<i_bl+sq_N; n++)
        for(int m = j_bl; m<j_bl+sq_N; m++)
            if(A[n][m] == ch)
                return false;
    return true;
}
bool check_all(vector<vector<char>> &A)
{
    for(auto it: A)
        for(auto it1: it)
            if(it1 == '.')
                return false;
    return true;
}
void print(vector<vector<char>> &A)
{
    for(auto it: A)
    {
        for(auto it1: it)
            cout<<it1<<" ";
        cout<<endl;
    }
}
void f(vector<vector<char>> &A, vector<vector<set<char>>> &choices, vector<vector<bool>> &vis, int i, int j, int N)
{
    if(j == N)
    {
        if(i == N-1)
        {
            if(check_all(A))
                ans = A;
            return;
        }
        f(A, choices, vis, i+1, 0, N);
        return;
    }
    if(vis[i][j])
    {
        f(A, choices, vis, i, j+1, N);
        return;
    }
    for(auto it: choices[i][j])
    {
        if(check(A, it, i, j, N))
        {
            A[i][j] = it;
            f(A, choices, vis, i, j+1, N);
            A[i][j] = '.';
        }
    }
}
void Solution::solveSudoku(vector<vector<char> > &A) 
{
    ans.clear();
    int N = A.size();
    set<char> base;
    for(char i = '1'; i<='9'; i++)
        base.insert(i);
    vector<vector<bool>> vis(N, vector<bool>(N, false));
    vector<vector<set<char>>> choices(N, vector<set<char>>(N, base));
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            if(A[i][j] != '.')
                vis[i][j] = true;
    f(A, choices, vis, 0, 0, N);
    A = ans;
}
