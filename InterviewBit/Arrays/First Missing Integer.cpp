/*
ID: ishan-sang
PROG: First Missing Integer
LANG: C++                  
*/

void swap(int &a, int &b)
{
    a+=b;
    b=a-b;
    a-=b;
}
int segregate(vector<int> &A, int N)
{
    int j = 0;
    for(int i = 0; i<N; i++)
    {
        if(A[i]>N || A[i]<=0)
        {
            swap(A[i], A[j]);
            j++;
        }
    }
    return j;
}
int find_missing(vector<int> &A, int N, int shift)
{
    for(int n = shift; n<N; n++)
    {
        int d = abs(A[n])-1;
        if(d>=0 && d<N-shift)
            A[d+shift] = - A[d+shift];
    }
    for(int n = shift; n<N; n++)
    {
        if(A[n] > 0)
            return n+1-shift;
    }
    return N+1-shift;
}
int Solution::firstMissingPositive(vector<int> &A) 
{
    int N = A.size();
    int shift = segregate(A, N);
    return find_missing(A, N, shift);
}
