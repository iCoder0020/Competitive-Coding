/*
ID: ishan-sang
PROG: Longest Arithmetic Progression
LANG: C++                  
*/

int Solution::solve(const vector<int> &A) 
{
    int N = A.size();
    if(N == 0)
        return 0;
    vector<map<long long, long long >> las(N);
    for(int i = 1; i<N; i++)
    {
        for(int j = 0; j<i; j++)
        {
            if(las[j].find(A[i]-A[j]) == las[j].end())
                las[i][A[i]-A[j]] = 2;
            else
                las[i][A[i]-A[j]] = 1+las[j][A[i]-A[j]];
        }
    }
    long long maxm = 1;
    for(auto it: las)
        for(auto jt: it)
            maxm = max(maxm, jt.second);
    return maxm;
}
