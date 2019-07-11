/*
ID: ishan-sang
PROG: Wave Array
LANG: C++                  
*/

vector<int> Solution::wave(vector<int> &A) 
{
    sort(A.begin(), A.end());
    int N = A.size();
    vector<int> B(N);
    int i = 0, j = 1;
    for(int n = 0; n<N; n++)
    {
        if(n&1)
        {
            B[n] = A[i];
            i+=2;
        }
        else
        {
            if(j<N)
            {
                B[n] = A[j];
                j+=2;
            }
            else
            {
                B[n] = A[i];
                i++;
            }
        }
    }
    return B;
}
