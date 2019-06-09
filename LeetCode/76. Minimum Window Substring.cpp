/*
ID: iCoder0020
PROG: Minimum Window Substring
LANG: C++                  
*/

class Solution {
public:
    
        string minWindow(string s, string t) {
        int S = s.size();
        int T = t.size();
        int i = 0, j = 0;
        int minm = INT_MAX;
        int a = -1, b = -1;
        string ans = "";
        int char_freq[129] = {0};
        int char_present[129] = {0};
        for(int n = 0; n<T; n++)
        {   
            char_present[(int)(t[n])] = 1;
            char_freq[(int)t[n]]++;
        }
        bool got_it = false;
        int l_ind = S-1;
        while(l_ind>=0 && char_present[s[l_ind]] == 0)
            l_ind--;
        
        while(i<=S-T && char_present[(int)(s[i])] == 0)
            i++;
        if(i<=S-T)
            char_freq[(int)(s[i])]--;
        j = i;
        
        while(i<=S-T && j<l_ind)
        {
            for(int n = 1; n<=128; n++)
            {
                if(char_freq[n] > 0)
                    break;
                if(n == 128)
                {
                    got_it = true;
                    if(j-i < minm)
                    {
                        a = i;
                        b = j;
                        minm = j-i;
                    }
                }
            }
            if(got_it)
            {
                char_freq[(int)(s[i])]++;
                i++;
                while(i<=S-T && char_present[(int)(s[i])] == 0)
                    i++;
                if(i>j)
                    char_freq[(int)(s[i])]--;
                got_it = false;
            }            
            else
            {
                j++;
                while(j<l_ind && char_present[(int)(s[j])] == 0)
                    j++;
                char_freq[(int)(s[j])]--;
            }   
        }
        while(i<=S-T)
        {
            for(int n = 1; n<=128; n++)
            {
                if(char_freq[n] > 0)
                    break;
                if(n == 128)
                {
                    if(j-i < minm)
                    {
                        a = i;
                        b = j;
                        minm = j-i;
                    }
                }
            } 
            char_freq[(int)(s[i])]++;
            i++;
            while(i<=S-T && char_present[(int)(s[i])] == 0)
                i++;
            
        }

        if(a != -1 && b != -1)
            for(int i = a; i<=b; i++)
                ans.push_back(s[i]);
        return ans;
    }
};