/*
ID: ishan-sang
PROG: Diffk II
LANG: C++                  
*/

int Solution::diffPossible(const vector<int> &A, int B) 
{
    int N = A.size();
    unordered_map<int,int> M;
    for(int n = 0; n<N; n++)
        M[A[n]] = n;
    for(int n = 0; n<N; n++)
    {
        int C = A[n]-B;
        if(M.find(C) != M.end())
        {
            if(M[C] != n)
                return 1;
        }
    }
    return 0;
}
