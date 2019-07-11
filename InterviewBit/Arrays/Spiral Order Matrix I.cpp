/*
ID: ishan-sang
PROG: Spiral Order Matrix I
LANG: C++                  
*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) 
{
    vector<int>ans;
    int N = A.size();
    int M = A[0].size();
    int t = 0, b = N-1, l = 0, r = M-1;
    int dir = 0;
    while(ans.size() != N*M)
    {
        if(dir == 0)
        {
            for(int i = l; i<=r; i++)
                ans.push_back(A[t][i]);
            t++;
            dir = 1;
        }
        else if(dir == 1)
        {
            for(int i = t; i<=b; i++)
                ans.push_back(A[i][r]);
            r--;
            dir = 2;
        }
        else if(dir == 2)
        {
            for(int i = r; i>=l; i--)
                ans.push_back(A[b][i]);
            b--;
            dir = 3;
        }
        else 
        {
            for(int i = b; i>=t; i--)
                ans.push_back(A[i][l]);
            l++;
            dir = 0;
        }
    }
    return ans;
}
