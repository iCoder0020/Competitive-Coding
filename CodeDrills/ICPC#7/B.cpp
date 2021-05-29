#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define x first
#define y second
#define lb(v, z) lower_bound(all(v), z)
#define ub(v, z) upper_bound(all(v), z)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define rdp(i, a, b) for (int i = (a); i >= (b); i--)
#define rlt(i, a, b) for (int i = (a); i < (b); i++)
#define cns(z) cout << (z) << ' '
#define cnl(z) cout << (z) << '\n'
#define M1 1000000007
#define M2 998244353
#define MAXN 300005
#define INF (1ll << 60)
#define endl "\n"
#define garr(ip)       \
    for (auto &x : ip) \
        cin >> x;
#define parr(ip)          \
    for (auto &x : ip)    \
        cout << x << " "; \
    cout << endl;
#define nl cout << endl
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vp;

void solve(int testCaseNumber = 1)
{
    int n;
	cin >> n;
	vp arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	sort(all(arr));
	int cnt = 1, time = arr[0].x + 1;
	int i = 1;
	multiset<int> endPoints;
	while(i < n) {
		while(i < n and arr[i].x <= time) {
			endPoints.insert(arr[i].y);
			i++;	
		}
		if(endPoints.empty()) {
			time = arr[i].x + 1;
			cnt++;
		} else {
			time++;
			cnt++;
			endPoints.erase(endPoints.begin());
		}
		while(endPoints.size() and *endPoints.begin() < time) {
			endPoints.erase(endPoints.begin());
		}
		i++;
	}
	while(!endPoints.empty()) {
		time++;
		cnt++;
		endPoints.erase(endPoints.begin());
		while(!endPoints.empty() and *endPoints.begin() < time) {
			endPoints.erase(endPoints.begin());
		}
	}
	cnl(cnt);
	
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int _t = 1;
    cin >> _t;
    rep(t, 1, _t)
    {
        solve(t);
    }
}