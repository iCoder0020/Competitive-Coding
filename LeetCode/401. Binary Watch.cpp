/*
ID: iCoder0020
PROG: Binary Watch
LANG: C++                  
*/

class Solution {
public:
    void bt(string &s, vector<string>&res, int start, int num)
    {
        int hours = bitset<4>(s.substr(6,4)).to_ulong();
        if(hours > 11)
            return;
        int minutes = bitset<6>(s.substr(0,6)).to_ulong();
        if(minutes > 59)
            return;
        if(num == 0)
        {
            res.push_back(to_string(hours) + ":" + ((minutes<=9)?"0":"")+ to_string(minutes));
            return;
        }
        if(start == s.length())
            return;
        for(int i = start; i<s.length(); i++)
        {
            s[i] = '1';
            bt(s, res, i+1, num-1);
            s[i] = '0';
        }
    }
    vector<string> readBinaryWatch(int num) 
    {
        vector<string> res;
        string s = "0000000000";
        bt(s, res, 0, num);
        return res;
    }
};