/*
ID: ishan_sang
PROG: MAXEP
LANG: C++
*/

#include <bits/stdc++.h>
 
using namespace std;

void ask(int V)
{
	cout<<"1 "<<V<<endl;
}

void repair()
{
	cout<<"2 "<<endl;
}

void answer(int ans)
{
	cout<<"3 "<<ans<<endl;
}

int main()
{
    int N,c;
    cin>>N>>c;
    int balance = 1000;
    int min = 1;
    int max = N;
    int guess;
    int input;
    bool found = false;
    while(!found)
    {
    	if(max-min+1 <= balance - c)
    	{
    		for(guess = min; guess<=max; guess++)
    		{
    			ask(guess);
    			cin>>input;
    			if(input == 1)
    			{
    				repair();
    				found = true;
    				break;
    			}
    		}
    	}
    	else
    	{
    		guess = (9*min + max)/10;
    		ask(guess);
    		cin>>input;
    		if(input == 0)
    		{
    			min = guess + 1;
    			balance--;
    		}
    		else
    		{
    			repair();
    			max = guess;
    			balance -= c+1;
    		}
    	}
    }
    answer(guess);
    return 0;
} 