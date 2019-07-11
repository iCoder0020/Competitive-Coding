/*
ID: ishan-sang
PROG: vNext Permutation
LANG: C++                  
*/

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}
void Solution::nextPermutation(vector<int> &A) 
{
    int N = A.size();
    int n;
    for(n = N-2; n>=0; n--)
        if(A[n] < A[n+1])
            break;
    if(n == -1)
        reverse(A.begin(), A.end());
    else
    {
        int i;
        for(i = N-1; i>n; i--)
            if(A[i] > A[n])
                break;
        swap(A[i], A[n]);
        reverse(A.begin()+n+1, A.end());
    }
}

