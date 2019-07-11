/*
ID: ishan-sang
PROG: Min XOR value
LANG: C++                  
*/

int Solution::findMinXor(vector<int> &A) 
{
    int N = A.size();
    int minm = INT_MAX;
    sort(A.begin(), A.end());
    for(int i = 0; i<N-1; i++)
        minm = min(minm, A[i]^A[i+1]);
    return minm;
}
