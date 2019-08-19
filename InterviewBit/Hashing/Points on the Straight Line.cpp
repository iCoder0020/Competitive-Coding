/*
ID: ishan-sang
PROG: Points on the Straight Line
LANG: C++                  
*/

int Solution::maxPoints(vector<int> &A, vector<int> &B) 
{
    int N = A.size();
    if(N == 0)
        return 0;
    if(N == 1)
        return 1;
    map<pair<int,int>, int>MAP;
    set<pair<int,int>> S;
    for(int n = 0; n<N; n++)
    {
        S.insert({A[n], B[n]});
        MAP[{A[n],B[n]}]++;
    }
    vector<pair<int,int>> v(S.begin(), S.end());
    map<double,int> M;
    N = v.size();
    if(N == 1)
        return MAP[{v[0].first, v[0].second}];
    int max_cnt = 0;
    for(int i = 0; i<N; i++)
    {
        M.clear();
        for(int j = 0; j<N; j++)
        {
            if(i==j)
                continue;
            if(v[j].first == v[i].first)
                M[INT_MAX]++;
            else
            {
                double m = (double)(v[j].second - v[i].second)/((double)(v[j].first - v[i].first));
                M[m]++;
            }
        }
        for(auto it: M)
            max_cnt = max(max_cnt, it.second+MAP[{v[i].first, v[i].second}]);
    }
    return max_cnt;
}
