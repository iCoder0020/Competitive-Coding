/*
ID: ishan-sang
PROG: Hotel Bookings Possible
LANG: C++                  
*/

bool comp(pair<int,char> &A, pair<int,char>&B)
{
    if(A.first == B.first)
        return (A.second == 's');
    else
        return A.first<B.first;
}
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) 
{
    vector<pair<int,char>>events;
    int N = arrive.size();
    for(int i = 0; i<N; i++)
        events.push_back({arrive[i], 's'});
    int M = depart.size();
    for(int i = 0; i<M; i++)
        events.push_back({depart[i], 'd'});
    sort(events.begin(), events.end());
    int k = 0;
    for(int i = 0; i<N+M; i++)
    {
        if(events[i].second == 's')
            k++;
        if(k>K)
            return 0;
        if(events[i].second == 'd')
            k--;
    }
    return 1;
}
