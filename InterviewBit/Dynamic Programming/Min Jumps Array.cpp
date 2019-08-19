/*
ID: ishan-sang
PROG: Min Jumps Array
LANG: C++                  
*/

int Solution::jump(vector<int> &A) 
{
    int N = A.size();
    if(N<=1)
        return 0;
    if(A[0] == 0)
        return -1;
    int reach = A[0];
    int step = A[0];
    int jump = 1;
    for(int i = 1; i<N; i++)
    {
        if(i == N-1)
            return jump;
        reach = max(reach, i + A[i]);
        step--;
        if(step == 0)
        {
            jump++;
            if(i >= reach)
                return -1;
            step = reach-i;
        }
    }
    return -1;
}
