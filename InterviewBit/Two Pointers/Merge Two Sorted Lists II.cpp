/*
ID: ishan-sang
PROG: Merge Two Sorted Lists II
LANG: C++                  
*/

void Solution::merge(vector<int> &A, vector<int> &B) 
{
    int a = A.size();
    int b = B.size();
    vector<int> C (a+b);
    A.resize(a+b);
    int i = 0, j = 0, k = 0;
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
    A = C;
}
