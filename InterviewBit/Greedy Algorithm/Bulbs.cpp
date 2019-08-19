/*
ID: ishan-sang
PROG: Bulbs
LANG: C++                  
*/

int Solution::bulbs(vector<int> &A) 
{
    int cnt = -1;
    int idx = -1;
    int N = A.size();
    for(int n = 0; n<N; n++)
    {
        if(A[n] == 0)
        {
            idx = n;
            break;
        }
    }
    if(idx!=-1)
    {
        cnt = 0;
        for(int n = idx+1; n<N; n++)
        {
            if(A[n] != A[n-1])
                cnt++;
        }
    }
    return cnt+1;
}
