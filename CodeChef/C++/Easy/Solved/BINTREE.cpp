/*
ID: ishan_sang
PROG: BINTREE
LANG: C++                  
*/

#include <iostream>
#include <iterator>
#include <vector> 

using namespace std;

int main()
{
	int N;
	int i,j;
	vector< int > A;
	vector <int > B;
	vector <int>::iterator a;
	vector <int>::iterator b;
	int count_a, count_b;
	int intersection_num;
	bool flag;
	cin>>N;
	for(int n = 0; n<N; n++)
	{
		flag = false;
		cin>>i>>j;
		while(i)
		{
			A.push_back(i);
			i/=2;
		}
		while(j)
		{
			B.push_back(j);
			j/=2;
		}
		for(a=A.begin(); a<A.end(); a++)
		{
			for(b=B.begin(); b<B.end(); b++)
			{
				if(*a == *b)
				{
					flag = true;
					break;
				}
			}
			if(flag)
			{
				intersection_num = *a;
				break;
			}
		}
		count_a = 0;
		count_b = 0;
		for(a=A.begin(); *a!=intersection_num; a++)
		{
			count_a++;
		}
		for(b=B.begin(); *b!=intersection_num; b++)
		{
			count_b++;
		}
		cout<<count_a + count_b<<"\n";
		A.erase(A.begin(), A.end());
		B.erase(B.begin(), B.end());
	}
	return 0;
}