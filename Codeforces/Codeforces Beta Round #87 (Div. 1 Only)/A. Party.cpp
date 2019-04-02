/*
ID: iCoder0020
PROG: Party
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node* parent;
	int data;
	Node(int x)
	{
		parent = NULL;
		data = x;
	}
};

int main()
{
	int N;
	cin>>N;
	Node *arr[N+1];
	for(int n = 1; n<=N; n++)
	{
		arr[n] = new Node(n);
	}
	int temp;
	for(int n = 1; n<=N; n++)
	{
		cin>>temp;
		if(temp != -1)
		{
			arr[n]->parent = arr[temp];
		}
	}
	int count;
	int max_count = 0;
	for(int n = 1; n<=N; n++)
	{
		Node *start = arr[n];
		count = 0;
		while(start!=NULL)
		{
			count++;
			start = start->parent;
		}
		if(count > max_count)
		{
			max_count = count;
		}
	}
	cout<<max_count<<endl;
	return 0;
}