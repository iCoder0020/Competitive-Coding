/*
ID: ishan-sang
PROG: Largest area of rectangle with permutations
LANG: C++                  
*/

int Solution::solve(vector<vector<int> > &A) 
{
    int N = A.size();
    int M = A[0].size();
    vector<vector<int>>pre = A;
    for(int n = 1; n<N; n++)
        for(int m = 0; m<M; m++)
            if(pre[n][m] == 1)
                pre[n][m] += pre[n-1][m];
    int max_area = 0;
    for(int n = 0; n<N; n++)
    {
        sort(pre[n].begin(), pre[n].end(), greater<int>());
        for(int m = 0; m<M; m++)
            max_area = max(max_area, (m+1)*pre[n][m]);
    }
    return max_area;
}
