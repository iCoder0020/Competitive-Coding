/*
ID: ishan-sang
PROG: PRETTYPRINT
LANG: C++                  
*/

vector<vector<int> > Solution::prettyPrint(int A) 
{
    int N = 2*A-1;
    vector<vector<int>>arr(N, vector<int>(N, 0));
    int t = 0, l = 0, r = N-1, b = N-1;
    int num = A;
    int cnt = 0;
    while(cnt < N*N)
    {
        for(int i = l; i<=r; i++)
            arr[t][i] = num;
        cnt += r-l+1;
        t++;
        for(int i = t; i<=b; i++)
            arr[i][r] = num;
        cnt += b-t+1;
        r--;
        for(int i = r; i>=l; i--)
            arr[b][i] = num;
        cnt += r-l+1;
        b--;
        for(int i = b; i>=t; i--)
            arr[i][l] = num;
        cnt += b-t+1;
        l++;
        num--;
    }
    return arr;
}
