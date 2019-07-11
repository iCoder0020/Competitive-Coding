/*
ID: ishan-sang
PROG: Merge Intervals
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
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) 
{
    vector<Interval> ans;
    int N = intervals.size();
    int idx = 0;
    int i,j,s,e;
    while(idx<N && intervals[idx].start < newInterval.start)
        idx++;
    i = idx-1;
    j = idx;
    s = newInterval.start;
    while(i>=0 && intervals[i].end >= s)
    {
        s = min(s, intervals[i].start);
        i--;
    }
    e = newInterval.end;
    while(j<N && intervals[j].start <= e)
    {
        e = max(e, intervals[j].end);
        j++;
    }
    for(int n = 0; n<=i; n++)
        ans.push_back(intervals[n]);
    ans.push_back(Interval(s,e));
    for(int n = j; n<N; n++)
        ans.push_back(intervals[n]);
    return ans;
}
