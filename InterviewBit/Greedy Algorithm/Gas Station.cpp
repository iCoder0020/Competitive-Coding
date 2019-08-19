/*
ID: ishan-sang
PROG: Gas Station
LANG: C++                  
*/

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) 
{
    int N = A.size();
    vector<int> pre(N, A[0]-B[0]);
    for(int n = 1; n<N; n++)
        pre[n] = pre[n-1] + (A[n]-B[n]);
    if(pre[N-1] < 0)
        return -1;
    int idx = 0, sum = 0;
    for(int i = 0; i<N; i++)
    {
        sum = -1;
        if(A[i]>=B[i])
        {
            idx = i;
            sum = 0;
            while(i<N && sum >= 0)
            {
                sum += A[i]-B[i];
                i++;
            }
            if(sum < 0)
                i--;
        }
        // if(sum >=0)
        // {
        //     if(sum + pre[idx]-pre[0] >= 0) 
        //         break;
        //     else
        //         i = idx;
        // }
    }
    return idx;
}
