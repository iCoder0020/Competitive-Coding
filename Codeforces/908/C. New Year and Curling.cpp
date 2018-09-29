#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

typedef long double ld;

int main()
{
	int N;
	ld R;
	cin>>N>>R;
	vector< pair<ld, ld> >X_RANGE(N);
	ld X[N];
	ld Y[N];
	ld max_y, max_x;
	for(int i = 0; i<N; i++)
	{
		cin>>X[i];
		X_RANGE[i].first = X[i] - R;
		X_RANGE[i].second = X[i] + R;
		if(i == 0)
		{
			Y[i] = R;
		}
		else
		{
			Y[i] = R;
			for(int j = 0; j<i; j++)
			{
				if((X_RANGE[i].first <= X_RANGE[j].first && X_RANGE[i].second >= X_RANGE[j].first) || (X_RANGE[i].first <= X_RANGE[j].second && X_RANGE[i].second >= X_RANGE[j].second) || (X_RANGE[i].first == X_RANGE[j].first && X_RANGE[i].second == X_RANGE[j].second))
				{
					if(Y[j] + sqrt(4*R*R - (X[i]-X[j])*(X[i]-X[j]))> Y[i])
					{
						Y[i] = Y[j] + sqrt(4*R*R - (X[i]-X[j])*(X[i]-X[j]));
					}
				}
			}
		}
		cout<<fixed<<setprecision(10)<<Y[i]<<" ";
	}
	cout<<"\n";
	return 0;
}