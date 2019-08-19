/*
ID: ishan-sang
PROG: INVERSIONS
LANG: C++                  
*/

int cntl;
void merge_sort_combine(vector<int> &arr, int l, int m, int r)
{
    int a = m-l;
    int b = r-m;
    int c = r-l;
    long long int A[a], B[b], C[c];
    int i = 0, j = 0, k = 0;
    for(int n = l; n<r; n++)
    {
        if(n<m)
            A[i++] = arr[n];
        else
            B[j++] = arr[n];
    }
    i = 0, j = 0;
    int idx = 0;
    int cnt = 0;
    for(int n = l; n<m; n++)
    {
        while(idx<b && B[idx] < A[n-l])
        {
            cnt++;
            idx++;
        }
        cntl+=cnt;
    }
    while(i<a && j<b)
    {
        if(A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    while(i<a)
        C[k++] = A[i++];
    while(j<b)    
        C[k++] = B[j++];
        
    for(int n = l; n<r; n++)
        arr[n] = C[n-l];
}

void merge_sort(vector<int> &A, int l, int r)
{
    if(r-l<=1)
        return;
    else
    {
        int m = (r+l)/2 + (r-l)%2;
        merge_sort(A, l, m);
        merge_sort(A, m, r);
        merge_sort_combine(A, l, m, r);
    }
}
int Solution::countInversions(vector<int> &A) 
{
    cntl = 0;
    int N = A.size();
    merge_sort(A, 0, N);
    return cntl;
}
