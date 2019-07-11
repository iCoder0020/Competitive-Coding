/*
ID: ishan-sang
PROG: Rotate Matrix
LANG: C++                  
*/

void Solution::rotate(vector<vector<int> > &A) 
{
    int N = A.size();
    for(int i = 0; i<N; i++)
    {
        for(int j = i; j<N-i-1; j++)
        {
            int temp1, temp2, temp3, temp4;
            temp1 = A[i][j];
            temp2 = A[j][N-1-i];
            temp3 = A[N-1-i][N-1-j];
            temp4 = A[N-1-j][i];
            
            A[i][j] = temp4;
            A[j][N-1-i] = temp1;
            A[N-1-i][N-1-j] = temp2;
            A[N-1-j][i] = temp3;
        }
    }
}