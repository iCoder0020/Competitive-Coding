/*
ID: ishan-sang
PROG: Set Matrix Zeros
LANG: C++                  
*/

void Solution::setZeroes(vector<vector<int> > &A) 
{
    int N = A.size();
    int M = A[0].size();
    int sum;
    for(int i = 0; i<N; i++)
    {
        sum = 0;
        for(int j = 0; j<M; j++)
            sum += abs(A[i][j]);
        if(sum < M)
            for(int j = 0; j<M; j++)
                if(A[i][j] == 1)
                    A[i][j] = -1;
    }
    for(int j = 0; j<M; j++)
    {
        sum = 0;
        for(int i = 0; i<N; i++)
            sum += abs(A[i][j]);
        if(sum < N)
            for(int i = 0; i<N; i++)
                if(A[i][j] == 1)
                    A[i][j] = -1;
    }
    for(int i = 0; i<N; i++)
        for(int j = 0; j<M; j++)
            if(A[i][j] == -1)
                A[i][j] = 0;
}
