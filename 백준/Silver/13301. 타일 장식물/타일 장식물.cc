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

// 타일 장식물
int main()
{
	init;

	// 4 6 10 16 26
	//(dp[n] + dp[n - 1]) * 2 + (dp[n - 1] + dp[n - 2]) * 2
	int n; cin >> n;
	if (n == 1) { cout << 4 << '\n'; return home; }
	if (n == 2) { cout << 6 << '\n'; return home; }
	vec(ll, dp, n + 1);
	dp[1] = 1;
	loop(i, 2, n + 1) dp[i] = dp[i - 1] + dp[i - 2];
	//loop(i, home, n + 1) cout << dp[i] << ' '; // 0 1 1 2 3 5
	cout << (dp[n] + dp[n - 1]) * 2 + (dp[n - 1] + dp[n - 2]) * 2 << '\n';

	return home;
}