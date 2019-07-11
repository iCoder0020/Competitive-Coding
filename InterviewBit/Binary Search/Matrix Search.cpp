/*
ID: ishan-sang
PROG: Matrix Search
LANG: C++                  
*/

int Solution::searchMatrix(vector<vector<int> > &A, int B) 
{
    int N = A.size();
    int M = A[0].size();
    int i,j;
    for(i = 0; i<N; i++)
    {
        for(j = M-1; j>=0; j--)
        {
            if(A[i][j] == B)
                return 1;
            if(A[i][j] < B)
                break;
            if(A[i][j] > B)
                M--;
        }
    }
    return 0;
}
