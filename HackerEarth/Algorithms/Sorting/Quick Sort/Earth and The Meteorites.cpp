/*
ID: icoder_0020
PROG: Earth and The Meteorites
LANG: C++                  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,M,Q;
		cin>>N>>M>>Q;
		set<li> XS;
		set<li> YS;

		XS.insert(1);
		XS.insert(N);

		YS.insert(1);
		YS.insert(M);

		int x_impact, y_impact;

		while(Q--)
		{
			cin>>x_impact>>y_impact;

			XS.insert(x_impact);
			YS.insert(y_impact);
		}

		li a = 0;
		li b = 100000;

		vector <li> X;
		vector <li> Y;

		for(auto it: XS)
		{
			X.push_back(it);
		}

		for(auto it: YS)
		{
			Y.push_back(it);
		}

		for(int x = 1; x<X.size(); x++)
		{
			a = max(a, X[x] - X[x-1]);
			b = min(b, X[x] - X[x-1]);
		}

		li c = 0;
		li d = 100000;

		sort(Y.begin(), Y.end());

		for(int y = 1; y<Y.size(); y++)
		{
			c = max(c, Y[y] - Y[y-1]);
			d = min(d, Y[y] - Y[y-1]);
		}


		li num = (X.size() - 1) * (Y.size() - 1);

		li minm = b*d;
		li maxm = a*c;

		cout<<num<<" "<<minm<<" "<<maxm<<endl;
	}
	return 0;
}