/*
ID: ishan-sang
PROG: Sliding Window Maximum
LANG: C++                  
*/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    deque<int>DQ;
    int N = A.size();
    vector<int>ans;
    for(int n = 0; n<N; n++)
    {
        if(DQ.empty())
            DQ.push_front(n);
        else
        {
            if(A[DQ.front()] < A[n])
                DQ.push_front(n);
            else
            {
                while(!DQ.empty() && A[DQ.back()] < A[n])
                    DQ.pop_back();
                DQ.push_back(n);
            }
        }
        if(n>=B-1)
        {
            while(DQ.front() < n-(B-1))
                DQ.pop_front();
            ans.push_back(A[DQ.front()]);
        }
    }
    if(ans.size() == 0)
        ans.push_back(DQ.front());
    return ans;
}
