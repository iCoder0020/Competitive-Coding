/*
ID: iCoder0020
PROG: Longest Word in Dictionary through Deleting
LANG: C++                  
*/

class Solution 
{
public:
	static bool mysort(const string &A, const string &B)
	{
		if(A.size() == B.size())
			return A<B;
		else
			return A.size()>B.size();
	}

    string findLongestWord(string s, vector<string>& d) 
    {
    	sort(d.begin(), d.end(), mysort);
    	for(auto it: d)
    	{
    		int i = 0;
    		for(int j = 0; j<s.size(); j++)
    		{
    			if(it[i] == s[j])
    				i++;
    		}
    		if(i == it.size())
    			return it;
    	}
        return "";
    }
};