// https://codeforces.com/gym/101628/problem/K

#include <bits/stdc++.h>

using namespace std;

#define temp root->child[S[j]-'a']

struct node
{
	set<int>index;
	node* child[26];
	set<int>is_end;
	node()
	{
		for(int i = 0; i<26; i++)
			child[i] = NULL;
	}
};

void add(node* root, int i, string &S, int j)
{
	root->index.insert(i);
	if(j == S.length())
	{
		root->is_end.insert(i);
		return;
	}
	if(!temp)
		temp = new node;
	add(temp, i, S, j+1);
}

void remove(node* root, int i, string &S, int j)
{
	if(!root)
		return;
	root->index.erase(i);
	if(j == S.length())
	{
		root->is_end.erase(i);
		return;
	}
	remove(temp, i, S, j+1);
	if(temp && temp->index.size() == 0)
	{
		temp = NULL;
		delete temp;
	}
}

bool vprefix(node* root, int l, int r, string &S, int j)
{
	if(!root || j == S.length()+1)
		return false;
	if(root->is_end.size()!=0)
	{
		auto it = root->is_end.lower_bound(l);
		if(it != root->is_end.end())
		{
			int i = *it;
			if(i>=l && i<=r)
				return true;
		}
	}
	return vprefix(temp, l, r, S, j+1);
}

bool sprefix(node *root, int l, int r, string &S, int j)
{
	if(!root || j == S.length()+1)
		return false;
	if(j == S.length() && root->index.size()!=0)
	{
		auto it = root->index.lower_bound(l);
		if(it != root->index.end())
		{
			int i = *it;
			if(i>=l && i<=r)
				return true;
		}
	}
	return sprefix(temp, l, r, S, j+1);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin>>N;
	node *root = new node;
	string S[N+1];
	for(int n = 1; n<=N; n++)
	{
		cin>>S[n];
		add(root, n, S[n], 0);
	}
	int M; 
	cin>>M;
	while(M--)
	{
		int t;
		cin>>t;
		if(t == 1)
		{
			int i;
			string newS;
			cin>>i>>newS;
			remove(root, i, S[i], 0);
			add(root, i, newS, 0);
			S[i] = newS;
		}
		else
		{
			int l,r;
			string newS;
			cin>>l>>r>>newS;
			bool ans = (t == 2)?vprefix(root, l, r, newS, 0):sprefix(root, l, r, newS, 0);
			if(ans)
				cout<<"Y";
			else
				cout<<"N";
			cout<<endl;
		}
	}
	return 0;
}