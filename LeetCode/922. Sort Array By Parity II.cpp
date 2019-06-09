/*
ID: iCoder0020
PROG: Sort Array By Parity II
LANG: C++                  
*/

class Solution 
{
public:
	void swap(int &a, int &b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

    vector<int> sortArrayByParityII(vector<int>& A) 
    {
    	int N = A.size();
    	int odd,even;
    	for(int n = 0; n<N; n++)
    	{
    		if(A[n]&1)
    		{
    			odd = n;
    			break;
    		}
    	}
    	for(int n = 0; n<N; n++)
    	{
    		if(!(A[n]&1))
    		{
    			even = n;
    			break;
    		}
    	}
    	for(int n = 0; n<N; n++)
    	{
    		if((n&1) && !(A[n]&1))
    		{
    			swap(A[n], A[odd]);
    			for(int n = odd+1; n<N; n++)
    			{
    				if(A[n]&1)
    				{
    					odd = n;
    					break;
    				}
    			}
    		}
    		else if(!(n&1) && (A[n]&1))
    		{
    			swap(A[n], A[even]);
    			for(int n = even+1; n<N; n++)
    			{
    				if(!(A[n]&1))
    				{
    					even = n;
    					break;
    				}
    			}
    		}
    		if(n>=odd)
    		{
    			for(int n = odd+1; n<N; n++)
    			{
    				if(A[n]&1)
    				{
    					odd = n;
    					break;
    				}
    			}
    		}
    		if(n>=even)
    		{
    			for(int n = even+1; n<N; n++)
    			{
    				if(!(A[n]&1))
    				{
    					even = n;
    					break;
    				}
    			}
    		}
    	}
    	return A;
    }
};