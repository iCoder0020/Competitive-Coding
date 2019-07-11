/*
ID: ishan-sang
PROG: Find Duplicate in Array
LANG: C++                  
*/

int Solution::repeatedNumber(const vector<int> &A) 
{
    int N = A.size();
    int sq_N = sqrt(N);
    int sq_N2 = (int)(ceil(sqrt((double)N)));
    vector<int>cnt(sq_N+2, 0);
    int bl, last;
    if(N < sq_N*sq_N2)
    {
        bl = sq_N;
        last = N-sq_N*sq_N;
    }
    else
    {
        bl = sq_N+1;
        last = N - sq_N*sq_N2; 
    }
    for(auto it: A)
    {
        int b = (it-1)/sq_N;
        cnt[b]++;
        if( (cnt[b] > sq_N) || ( (cnt[b] > last) && (b == sq_N+1) ) )
        {
            bl = b;
            break;
        }
    }
    unordered_map<int,int>M;
    for(auto it: A)
    {
        if((it-1)/sq_N == bl)
        {
            if(M.find(it) == M.end())
                M[it] = 1;
            else
                return it;
        }
    }
    return -1;
}
