/*
ID: ishan-sang
PROG: Spiral Order Matrix II
LANG: C++                  
*/

vector<vector<int> > Solution::generateMatrix(int A) 
{
    vector<vector<int>>v(A, vector<int>(A, 0));
    int cnt = 1;
    int t = 0, l = 0, r = A-1, b = A-1;
    int move = 0;
    while(cnt <= A*A)
    {
        if(move == 0)
        {
            for(int i = l; i<=r; i++, cnt++)
                v[t][i] = cnt;
            move = 1;
            t++;
        }
        else if(move == 1)
        {
            for(int i = t; i<=b; i++, cnt++)
                v[i][r] = cnt;
            move = 2;
            r--;
        }
        else if(move == 2)
        {
            for(int i = r; i>=l; i--, cnt++)
                v[b][i] = cnt;
            move = 3;
            b--;
        }
        else
        {
            for(int i = b; i>=t; i--, cnt++)
                v[i][l] = cnt;
            move = 0;
            l++;
        }
    }
    return v;
}
