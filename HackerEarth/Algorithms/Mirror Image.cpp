/*
ID: icoder_0020
PROG: Mirror Image
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node *left;
	Node *right;
	int data;
	Node(int x)
	{
		left = NULL;
		right = NULL;
		data = x;
	}
};

int main()
{
	int N,Q;
	cin>>N>>Q;
	Node *arr[N+1];
	for(int n = 1; n<=N; n++)
		arr[n] = new Node(n);
	int a,b;
	char c;
	for(int n = 1; n<=N-1; n++)
	{
		cin>>a>>b>>c;
		if(c == 'L')
			arr[a]->left = arr[b];
		else 
			arr[a]->right = arr[b];
	}
	while(Q--)
	{
		int tmp;
		cin>>tmp;
		if(tmp == 1)
		{
			cout<<1;
		}
		else
		{
			queue <Node*> Q;
			vector<char>v[N+1];
			vector<char>ans;
			
			Q.push(arr[1]);

			while(!Q.empty())
			{
				Node* temp = Q.front();
				Q.pop();

				if(temp->data == tmp)
				{
					ans = v[temp->data];
					break;
				}

				if(temp->left)
				{
					Q.push(temp->left);
					v[temp->left->data] = v[temp->data];
					v[temp->left->data].push_back('L');
				}
				if(temp->right)
				{
					Q.push(temp->right);
					v[temp->right->data] = v[temp->data];
					v[temp->right->data].push_back('R');
				}
			}

			Node* current = arr[1];
			for(auto it: ans)
			{
				if(!current)
				{
					break;
				}
				if(it == 'L')
				{
					current = current->right;
				}
				else
				{
					current = current->left;
				}
			}
			if(current)
			{
				cout<<current->data;
			}
			else
			{
				cout<<-1;
			}
		}
		cout<<endl;
	}
	return 0;
}