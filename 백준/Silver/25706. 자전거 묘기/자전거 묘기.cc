#include <bits/stdc++.h>
using namespace std;

#define home 0

#ifdef ONLINE_JUDGE
#define init ios_base::sync_with_stdio(home); cin.tie(home)
#else
#define init ios_base::sync_with_stdio(home); cin.tie(home); ifstream cin("input.txt")
#endif

#define ll long long
#define ld long double

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define tvec(t, v) vector<t> v
#define vec(t, v, r) vector<t> v((r))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

// 자전거 묘기
int main()
{
	init;

	int n; cin >> n;
	vec(int, h, n + 1);
	loop(i, 1, n) cin >> h[i];

	// 높이 X => 한칸 앞 dp값 + 1
	// 높이 O => i + h[i] + 1 > n ? 현재 dp값 : 현재 dp값 + dp[i + h[i] + 1]
	// 3 3 2 1 3 2 1 3 2 1
	vector<int> dp(n + 1, 1);
	rloop(i, n - 1, home)
	{
		if (h[i] == home) dp[i] = dp[i + 1] + 1;
		else dp[i] = cond(i + h[i] + 1 > n, dp[i], dp[i] + dp[i + h[i] + 1]);
	}
	loop(i, 1, n + 1) scp(dp[i]);

	return home;
}