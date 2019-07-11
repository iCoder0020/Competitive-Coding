/*
ID: ishan-sang
PROG: Remove Element from Array
LANG: C++                  
*/

int Solution::removeElement(vector<int> &A, int B) 
{
    int N = A.size();
    int put = 0;
    for(int n = 0; n<N; n++)
    {
        while(n<N && A[n] == B)
            n++;
        if(n<N)
        {
            A[put] = A[n];
            put++;
        }
    }
    A.resize(put);
    return put;
}

