/*
ID: ishan-sang
PROG: Square Root of Integer
LANG: C++                  
*/

int Solution::sqrt(int A) 
{
    long long int low = 0;
    long long int high = 100000;
    long long int mid;
    while(low<high)
    {
        mid = low + (high-low+1)/2;
        if(mid*mid <= A)
            low = mid;
        else
            high = mid-1;
    }
    return low;
}
