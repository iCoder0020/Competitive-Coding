/*
ID: iCoder0020
PROG: Lemonade Change
LANG: C++                  
*/

class Solution 
{
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int c5 = 0, c10 = 0;
        if(bills[0] != 5)
            return false;
        for(auto it: bills)
        {
            if(it == 5)
                c5++;
            if(it == 10)
            {
                c10++;
                c5--;
            }
            else if(it == 20)
            {
                if(c10 > 0)
                {
                    c10--;
                    c5--;
                }
                else
                    c5 -= 3;
            }
            if(c5 < 0)
                return false;
        }     
        return true;
    }
};