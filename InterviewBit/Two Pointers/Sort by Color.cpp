/*
ID: ishan-sang
PROG: Sort by Color
LANG: C++                  
*/

void swap(int &a, int &b)
{
    a += b;
    b = a-b;
    a -=b;
}
void Solution::sortColors(vector<int> &A) 
{
    int N = A.size();
    int i = 0, j, k = N-1;
    while(i<N && A[i] == 0)
        i++;
    while(k>=0 && A[k] == 2)
        k--;
    if(i>k)
        return;
    j = i;
    while(j<=k)
    {
        if(A[j] == 1)
            j++;
        else if(A[j] == 0)
        {
            swap(A[i], A[j]);
            i++;
            j++;
        }
        else if(A[j] == 2)
        {
            swap(A[j], A[k]);
            k--;
        }
    }
}
