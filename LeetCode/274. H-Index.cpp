/*
ID: iCoder0020
PROG: H-Index
LANG: C++                  
*/

class Solution 
{
public:
	int hIndex(vector<int>& citations) 
	{
		int N = citations.size();
		vector<int> buckets(N+1,0);
		for(int n = 0; n<N; n++)
            buckets[min(citations[n], N)]++;
        int sum = 0;
        for(int i = N; i>=0; i--)
        {
            sum += buckets[i];
            if(sum >= i)
                return i;
        }
		return 0;	
	}
};