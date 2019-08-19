/*
ID: ishan-sang
PROG: NUMRANGE
LANG: C++                  
*/

int Solution::numRange(vector<int> &A, int B, int C) 
{
    int N = A.size();
    int i = 0, j = 0, k = 0;
    int sumj = -1, sumk = -1;
    int cnt = 0;
    while(i<N)
    {
        while(j<N && (sumj<B || sumj == -1))
        {
            if(sumj == -1)
                sumj = A[j];
            else
                sumj += A[j];
            j++;
        }
        while(k<N && (sumk<=C || sumk == -1))
        {
            if(sumk == -1)
                sumk = A[k];
            else
                sumk += A[k];
            k++;
        }
        if(sumk>C)
        {
            k--;
            sumk -= A[k];
        }
        if(sumj >= B && sumk <= C)
            cnt += k-j+1;
        // cout<<i<<" "<<j<<" "<<sumj<<" "<<k<<" "<<sumk<<" "<<cnt<<endl;
        sumj-=A[i];
        sumk-=A[i];
        i++;
    }
    return cnt;
}



