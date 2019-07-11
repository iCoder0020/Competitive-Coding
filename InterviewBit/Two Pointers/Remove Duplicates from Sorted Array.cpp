/*
ID: ishan-sang
PROG: Remove Duplicates from Sorted Array
LANG: C++                  
*/

int Solution::removeDuplicates(vector<int> &A) 
{
    int N = A.size();
    int put = 0;
    for(int i = 0; i<N; i++)
    {
        while(i+1<N && A[i] == A[i+1])
            i++;
        A[put] = A[i];
        put++;
    }
    return put;
}
