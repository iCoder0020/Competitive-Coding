/*
ID: iCoder0020
PROG: Largest palindrome product
LANG: C++                  
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_palindrome(int N)
{
	int M = 0, N_saved;
	N_saved = N;
	while(N)
	{
		M*=10;
		M+=N%10;
		N/=10;
	}
	return (M==N_saved);
}

int main()
{
	int T;
	int N;
	int k;
	vector<int> palindrome;
	for(int i=100;i<1000;i++)
	{
		for(int j=100;j<1000;j++)
		{
			if((i*j)/1000000 == 0 && (i*j)/100000 !=0)
			{
				if(check_palindrome(i*j))
				{
					for(k = 0; k<palindrome.size(); k++)
					{
						if(palindrome[k] == i*j)
						{
							break;
						}
					}
					if(k == palindrome.size())
					{
						palindrome.push_back(i*j);
					}
				}
			}
		}
	}
	sort(palindrome.begin(),palindrome.end());
	
	cin>>T;
	int min, mid, max;
	bool found_answer;
	for(int t = 0; t<T; t++)
	{
		cin>>N;
		found_answer = false;
		min = 0;
		max = palindrome.size() - 1;
		while(1)
		{
			mid = (min + max)/2;
			if(palindrome[mid] == N)
			{
				cout<<palindrome[mid - 1]<<"\n";
				found_answer = true;
			}
			else if(palindrome[mid] > N)
			{
				max = mid - 1;
			}
			else
			{
				if(mid + 1 == palindrome.size() || palindrome[mid + 1] >= N)
				{
					cout<<palindrome[mid]<<"\n";
					found_answer = true;
				}
				else
				{
					min = mid + 1;
				}
			}
			if(found_answer)
			{
				break;
			}
		}
	}
	return 0;
}