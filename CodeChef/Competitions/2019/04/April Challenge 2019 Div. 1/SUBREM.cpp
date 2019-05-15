/*
ID: ishan_sang
PROG: SUBREM
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Node
{
	int ID;
	int data;
	set<Node*>children;
	int s_sum;
	Node(int id, int x)
	{
		ID = id;
		data = x;
		s_sum = x;
	}

};

map<Node*, Node*> parent;

void remove_duplicate_links(Node* &root)
{
	queue <Node*> Q;
	Q.push(root);
	while(!Q.empty())
	{
		Node* temp = Q.front();
		for(auto it: temp->children)
		{
			Q.push(it);
			parent[it] = temp;
			it->children.erase(temp);
		}
		Q.pop();
	}	
}

int traverse(Node* &root)
{
	for(auto it: root->children)
		root->s_sum += traverse(it);
	return root->s_sum;
}

int32_t main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int N,X;
    	cin>>N>>X;
    	Node* nodes[N+1];
    	set<int> del;
    	for(int n = 1; n<=N; n++)
    	{
    		int x;
    		cin>>x;
    		nodes[n] = new Node(n, x);
    	}
    	for(int n = 0; n<N-1; n++)
    	{
    		int u,v;
    		cin>>u>>v;
    		nodes[u]->children.insert(nodes[v]);
    		nodes[v]->children.insert(nodes[u]);
    	}
    	Node* root = nodes[1];
    	remove_duplicate_links(root);
    	traverse(root);

    	int total_sum = root->s_sum;

    	int ans1 = max(root->s_sum, -1*X);

    	priority_queue<pair<int, Node*>>max_heap;

    	for(int n = 2; n<=N; n++)
    		max_heap.push({-1*(nodes[n]->s_sum), nodes[n]});
    	int k = 0;
    	while(!max_heap.empty() && X*(k+1) < max_heap.top().first)
    	{
    		pair<int, Node*> p = max_heap.top();
    		cout<<p.second<<endl;
     		total_sum += p.first;
    		del.insert(p.second);
    		for(auto it: nodes[p.second]->children)
    			del.insert(it->ID);
    		int i = p.second;
    		while(parent.find(i) != parent.end())
    		{
    			parent[i] -= p.first;
    			i = parent[i];
    		}
    		k++;
    		while(!max_heap.empty() && del.find(max_heap.top().second) != del.end())
    			max_heap.pop();
    	}
    	cout<<max(ans1, total_sum-X*k)<<endl;
    }
}