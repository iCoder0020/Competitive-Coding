/*
ID: ishan-sang
PROG: Flip Array
LANG: C++                  
*/

#define off 10000
int Solution::solve(const vector<int> &A) 
{
    int N = A.size();
    vector<vector<int>> v(N, vector<int>(2*off+1, -1));
    v[0][A[0]+off] = 0;
    v[0][-A[0]+off] = 1;
    for(int i = 1; i<N; i++)
    {
        for(int n = 0; A[i]+n<=2*off; n++)
        {
            if(v[i-1][n] != -1)
            {
                if(v[i][A[i]+n] == -1)
                    v[i][A[i]+n] = v[i-1][n];
                else
                    v[i][A[i]+n] = min(v[i][A[i]+n], v[i-1][n]);
            }
        }
        for(int n = A[i]; n<=2*off; n++)
        {
            if(v[i-1][n] != -1)
            {
                if(v[i][n-A[i]] == -1)
                    v[i][n-A[i]] = v[i-1][n]+1;
                else
                    v[i][n-A[i]] = min(v[i][n-A[i]], v[i-1][n]+1);
            }
        }
    }
    for(int n = off; n<=2*off; n++)
        if(v[N-1][n] != -1)
            return v[N-1][n];
}
