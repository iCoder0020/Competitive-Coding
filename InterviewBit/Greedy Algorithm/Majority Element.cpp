/*
ID: ishan-sang
PROG: Majority Element
LANG: C++                  
*/

int Solution::majorityElement(const vector<int> &A) 
{
    int N = A.size();
    int num = A[0];
    int cnt = 1;
    for(int n = 1; n<N; n++)
    {
        if(A[n] == num)
            cnt++;
        else
            cnt--;
        if(cnt == 0)
        {
            num = A[n];
            cnt = 1;
        }
    }
    return num;
}
