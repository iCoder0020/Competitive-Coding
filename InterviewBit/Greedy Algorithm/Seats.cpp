/*
ID: ishan-sang
PROG: Seats
LANG: C++                  
*/

#define MOD 10000003
int Solution::seats(string A) 
{
    int N = A.size();
    vector<int> v;
    for(int n = 0; n<N; n++)
        if(A[n] == 'x')
            v.push_back(n);
    N = v.size();
    if(N<=1)
        return 0;
    long long int ans1 = 0, ans2 = 0;
    int i1 = N/2-1, j1 = N/2+1, x = v[N/2], i2 = N/2-2, j2 = N/2, y = v[N/2-1];
    int cnt = 1;
    while(1)
    {
        if (i1<0 && j1>=N && i2<0 && j2>=N)
            break;
        if(i1>=0)
            ans1 = (ans1 + (x - v[i1] - cnt))%MOD;
        if(j1<N)
            ans1 = (ans1 + (v[j1] - x - cnt))%MOD;
        if(i2>=0)
            ans2 = (ans2 + (y - v[i2] - cnt))%MOD;
        if(j2<N)
            ans2 = (ans2 + (v[j2] - y - cnt))%MOD;
        i1--, i2--, j1++, j2++, cnt++;
    }
    return min(ans1, ans2);
}
