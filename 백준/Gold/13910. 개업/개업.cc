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

// 개업
int main()
{
	init;

	int n, m; cin >> n >> m;
	vec(int, sz, m);
	loop(i, home, m) cin >> sz[i];
	vector<int> dp(n + 1, 2147000000);
	dp[home] = home;

	loop(i, home, m)
	{
		loop(j, i + 1, m)
		{
			if (sz[i] + sz[j] > n) continue;
			sz.push_back(sz[i] + sz[j]);
		}
	}

	loop(i, home, sz.size())
	{
		loop(j, sz[i], n + 1)
		{
			dp[j] = min(dp[j], dp[j - sz[i]] + 1);
		}
	}

	elp(cond(dp[n] == 2147000000, -1, dp[n]));

	return home;
}