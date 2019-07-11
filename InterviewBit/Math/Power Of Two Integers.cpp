/*
ID: ishan-sang
PROG: Power Of Two Integers
LANG: C++                  
*/

#define MOD 1000000007

int Solution::cntBits(vector<int> &A) 
{
    int N = A.size();
    long long int cnt[32] = {0};
    for(int n = 0; n<N; n++)
    {
        for(int i = 0; i<32; i++)
        {
            if(A[n]&(1<<i))
                cnt[i]++;
        }
    }
    long long int count = 0;
    for(int i = 0; i<32; i++)
        count = (count + cnt[i]*(N-cnt[i]))%MOD;
    count = (2*count)%MOD;
    return count;
}
