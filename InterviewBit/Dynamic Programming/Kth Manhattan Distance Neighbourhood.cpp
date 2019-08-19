/*
ID: ishan-sang
PROG: Kth Manhattan Distance Neighbourhood
LANG: C++                  
*/

vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) 
{
    int N = B.size();
    int M = B[0].size();
    vector<vector<int>>temp = B;
    for(int k = 0; k<A; k++)
    {
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<M; j++)
            {
                if(i-1>=0)
                    B[i][j] = max(B[i][j], temp[i-1][j]);
                if(i+1<N)
                    B[i][j] = max(B[i][j], temp[i+1][j]);
                if(j-1>=0)
                    B[i][j] = max(B[i][j], temp[i][j-1]);
                if(j+1<M)
                    B[i][j] = max(B[i][j], temp[i][j+1]);
            }
        }
        temp = B;
    }
    return B;
}
