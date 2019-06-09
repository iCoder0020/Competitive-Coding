/*
ID: iCoder0020
PROG: Jewels and Stones
LANG: C++                  
*/

class Solution 
{
public:
    int numJewelsInStones(string J, string S) 
    {
		set<char> SET;
		for(auto it: J)
			SET.insert(it);
		int cnt = 0;
		for(auto it: S)
			if(SET.find(it) != SET.end())
				cnt++;
		return cnt;        
    }
};