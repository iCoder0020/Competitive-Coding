/*
ID: ishan-sang
PROG: Assign Mice to Holes
LANG: C++                  
*/

int Solution::mice(vector<int> &A, vector<int> &B) 
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int N = A.size();
    int ans = 0;
    for(int n = 0; n<N; n++)
        ans = max(ans, abs(A[n]-B[n]));
    return ans;
}
