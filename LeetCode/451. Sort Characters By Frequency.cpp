/*
ID: iCoder0020
PROG: Sort Characters By Frequency
LANG: C++                  
*/

class Solution {
public:
    static bool mysort(pair<char,int>&A, pair<char,int>&B)
    {
        return A.second > B.second;
    }
    string frequencySort(string s) 
    {
        vector<pair<char,int>> freq;
        for(int n = 0; n<256; n++)
            freq.push_back({(char)n, 0});
        for(auto it: s)
            freq[(int)it].second++;
        sort(freq.begin(), freq.end(), mysort);
        string S = "";
        for(auto it: freq)
        {
            if(it.second == 0)
                break;
            for(int n = 0; n<it.second; n++)
                S += it.first;
        }
        return S;
    }
};