/*
ID: iCoder0020
PROG: Sum of Two Integers
LANG: C++                  
*/

class Solution 
{
    public:
        int getSum(int A, int B) 
        {
            int result = 0;
            int mask, a, b, c = 0, s;
            for(int i = 0; i<32; i++)
            {
                mask = 1<<i;
                a = (A&mask)?1:0;
                b = (B&mask)?1:0;
                s = a^b^c;
                c = (a&b&c) | (~a&b&c) | (a&~b&c) | (a&b&~c);
                if(s)
                  result |= mask;  
                cout<<a<<" "<<b<<" "<<s<<" "<<c<<" "<<result<<endl;
            }
            return result;
        }
};