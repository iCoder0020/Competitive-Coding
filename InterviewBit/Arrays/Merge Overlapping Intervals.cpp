/*
ID: ishan-sang
PROG: Merge Overlapping Intervals
LANG: C++                  
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval A, Interval B)
{
    if(A.start == B.start)
        return A.end < B.end;
    return A.start<B.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) 
{
    int N = A.size();
    int s,e;
    vector<Interval>ans;
    sort(A.begin(), A.end(), cmp);
    for(int n = 0; n<N; )
    {
        s = A[n].start;
        e = A[n].end;
        n++;
        while(n<N && A[n].start <= e)
        {
            e = max(e, A[n].end);
            n++;
        }
        ans.push_back(Interval(s,e));
    }
    return ans;
}
