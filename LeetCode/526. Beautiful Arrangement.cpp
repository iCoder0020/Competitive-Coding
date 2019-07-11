/*
ID: iCoder0020
PROG: Beautiful Arrangement
LANG: C++                  
*/

class Solution 
{
public:
	
    string makeLargestSpecial(string S) 
    {
        if(S.size()==0)
            return "";
        vector<string>substrings;
        int bal = 0, last = -1;
        for(int i = 0; i<S.size(); i++)
        {
            if(S[i] == '0')
                bal--;
            else
                bal++;
            if(bal == 0)
            {
                substrings.push_back("1" + makeLargestSpecial(S.substr(last+2, i-last-2)) + "0");
                last = i;
            }
        }
        sort(substrings.rbegin(), substrings.rend());
        
        string final_string = "";
        for(auto it: substrings)
            final_string += it;
        return final_string;
    }
};