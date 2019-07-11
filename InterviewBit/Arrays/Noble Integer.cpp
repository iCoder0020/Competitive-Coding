/*
ID: ishan-sang
PROG: Noble Integer
LANG: C++                  
*/

int Solution::solve(vector<int> &A) 
{
    int N = A.size();
    sort(A.begin(), A.end());
    int ans = -1;
    for(int n = 0; n<N; n++)
    {
        while(n+1<N && A[n] == A[n+1])
            n++;
        if(n<N && N-n-1 == A[n])
            ans = 1;
    }
    return ans;
}
