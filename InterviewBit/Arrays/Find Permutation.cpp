/*
ID: ishan-sang
PROG: Find Permutation
LANG: C++                  
*/

vector<int> Solution::findPerm(const string A, int N) 
{
    vector<int>arr(N,0);
    int cnt = 1;
    for(int n = N-1; n>0; n--)
    {
        if(A[n-1] == 'D')
        {
            arr[n] = cnt;
            cnt++;
        }
    }
    for(int  n = 1; n<N; n++)
    {
        if(A[n-1] == 'I')
        {
            arr[n] = cnt;
            cnt++;
        }
    }
    if(A[0] == 'I')
    {
        arr[0] = 0;
        for(int n = 0; n<N; n++)
            arr[n] = arr[n]+1;
    }
    else
    {
        arr[0] = N;
    }
    return arr;
}
