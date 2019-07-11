/*
ID: ishan-sang
PROG: Remove Duplicates from Sorted Array II
LANG: C++                  
*/

int Solution::removeDuplicates(vector<int> &A) 
{
    int N = A.size();
    int put = 0;
    int cnt;
    for(int i = 0; i<N; i++)
    {
        cnt = 1;
        while(i+1<N && A[i] == A[i+1])
        {
            i++;
            cnt++;
        }
        if(cnt == 1)
        {
            A[put] = A[i];
            put++;
        }
        else
        {
            A[put] = A[i];
            A[put+1] = A[i];
            put += 2;
        }
    }
    return put;
}
