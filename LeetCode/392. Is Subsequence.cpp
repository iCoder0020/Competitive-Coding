/*
ID: iCoder0020
PROG: Is Subsequence
LANG: C++                  
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for(auto it: t)
            if(it == s[i])
                i++;
        return (i == s.size());
    }
};