#include <bits/stdc++.h>
using namespace std;

#define home 0

#define ll long long
#define ld long double

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)
#define aloop(t, v, s, c, e, i) for(t v = (s); v c (e); i)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define vec(t, v, r) vector<t> v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define dir vector<pii> cd = { {-1, 0}, {1, 0}, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }

#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

struct Planet
{
	int jCnt;
	int oCnt;
	int iCnt;

	Planet() {}
	Planet(int jc, int oc, int ic) : jCnt(jc), oCnt(oc), iCnt(ic) {}
};

// 행성 탐사
int main()
{
	ios_base::sync_with_stdio(home);
	cin.tie(home);
	#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	#endif

	int n, m, k;
	cin >> n >> m >> k;
	mat(char, graph, n, m);
	mat(Planet, dp, n, m);
	loop(i, home, n) loop(j, home, m) cin >> graph[i][j];
	dp[home][home] = Planet(cond(graph[home][home] == 'J', 1, home), cond(graph[home][home] == 'O', 1, home), cond(graph[home][home] == 'I', 1, home));
	loop(i, 1, m) dp[home][i] = Planet(dp[home][i - 1].jCnt + cond(graph[home][i] == 'J', 1, home), dp[home][i - 1].oCnt + cond(graph[home][i] == 'O', 1, home), dp[home][i - 1].iCnt + cond(graph[home][i] == 'I', 1, home));
	loop(i, 1, n) dp[i][home] = Planet(dp[i - 1][home].jCnt + cond(graph[i][home] == 'J', 1, home), dp[i - 1][home].oCnt + cond(graph[i][home] == 'O', 1, home), dp[i - 1][home].iCnt + cond(graph[i][home] == 'I', 1, home));
	loop(i, 1, n) loop(j, 1, m)
		dp[i][j] = Planet(dp[i][j - 1].jCnt + dp[i - 1][j].jCnt - dp[i - 1][j - 1].jCnt + cond(graph[i][j] == 'J', 1, home),
			dp[i][j - 1].oCnt + dp[i - 1][j].oCnt - dp[i - 1][j - 1].oCnt + cond(graph[i][j] == 'O', 1, home),
			dp[i][j - 1].iCnt + dp[i - 1][j].iCnt - dp[i - 1][j - 1].iCnt + cond(graph[i][j] == 'I', 1, home));
	loop(i, home, k)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		int jCnt = dp[c][d].jCnt - cond(b > home, dp[c][b - 1].jCnt, home) - cond(a > home, dp[a - 1][d].jCnt, home) + cond(b > home && a > home, dp[a - 1][b - 1].jCnt, home);
		int oCnt = dp[c][d].oCnt - cond(b > home, dp[c][b - 1].oCnt, home) - cond(a > home, dp[a - 1][d].oCnt, home) + cond(b > home && a > home, dp[a - 1][b - 1].oCnt, home);
		int iCnt = dp[c][d].iCnt - cond(b > home, dp[c][b - 1].iCnt, home) - cond(a > home, dp[a - 1][d].iCnt, home) + cond(b > home && a > home, dp[a - 1][b - 1].iCnt, home);
		scp(jCnt); scp(oCnt); scp(iCnt); elp("");
	}

	return home;
}