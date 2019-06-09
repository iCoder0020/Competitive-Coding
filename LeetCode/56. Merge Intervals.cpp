/*
ID: iCoder0020
PROG: Merge Intervals
LANG: C++                  
*/

class Solution {
public:
    static bool mysort(vector<int>&A, vector<int>&B)
    {
        if(A[0] == B[0])
            return A[1]<B[1];
        else
            return A[0]<B[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int N = intervals.size();
        vector<vector<int>> ans;
        if(N<=0)
            return ans;
        sort(intervals.begin(), intervals.end(), mysort);
        int first = intervals[0][0];
        int second = intervals[0][1];
        for(int n = 1; n<N; n++)
        {
            if(intervals[n][0] > second)
            {
                ans.push_back({first, second});
                first = intervals[n][0];
                second = intervals[n][1];
            }
            else
            {
                second = max(second, intervals[n][1]);
            }
        }
        ans.push_back({first, second});
        return ans;
    }
};