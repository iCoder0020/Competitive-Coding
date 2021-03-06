/*
ID: iCoder0020
PROG: Reverse String
LANG: C++                  
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size()-1;
        char c;
        while(i<j)
        {
            c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
    }
};