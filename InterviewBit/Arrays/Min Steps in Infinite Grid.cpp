/*
ID: ishan-sang
PROG: Min Steps in Infinite Grid
LANG: C++                  
*/

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int sum = 0;
    for(int n = 0; n<A.size()-1; n++)
    {
        sum += max(abs(A[n+1] - A[n]), abs(B[n+1]-B[n]));
    }
    return sum;
}
