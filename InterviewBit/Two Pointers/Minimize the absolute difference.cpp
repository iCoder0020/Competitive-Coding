/*
ID: ishan-sang
PROG: Minimize the absolute difference
LANG: C++                  
*/

int min3(int a, int b, int c)
{
    return min(a, min(b,c));
}
int max3(int a, int b, int c)
{
    return max(a, max(b,c));
}
int ans(int a, int b, int c)
{
    return max3(a,b,c) - min3(a,b,c);
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) 
{
    int a = A.size(), b = B.size(), c = C.size();
    int i = 0,j = 0,k = 0, s;
    int minm = ans(A[i], B[j], C[k]);
    while(1)
    {
        if(i+1<a && A[i]<B[j] && A[i]<C[k])
            i++;
        else if(j+1<b && B[j]<C[k])
            j++;
        else if(k+1<c)
            k++;
        else
            break;
        minm = min(minm, ans(A[i], B[j], C[k]));
    }
    return minm;
}
