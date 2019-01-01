/*
ID: iCoder0020
PROG: B. New Year and the Treasure Geolocation
LANG: C++                  
*/

#include <bits/stdc++.h>

typedef long long int li;

using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<pair<int,int>> O;
	vector<pair<int,int>> C;
	int a,b;
	for(int n = 0; n<N; n++)
	{
		cin>>a>>b;
		O.push_back({a,b});
	}
	for(int n = 0; n<N; n++)
	{
		cin>>a>>b;
		C.push_back({a,b});
	}
	sort(O.begin(), O.end());
	sort(C.begin(), C.end());
	cout<<O[0].first+C[N-1].first<<" "<<O[0].second+C[N-1].second<<endl;
	return 0;
}